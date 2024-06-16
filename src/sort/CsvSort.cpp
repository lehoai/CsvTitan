#include <chrono>
#include <sstream>
#include <chrono>
#include <thread>
#include "sort/StandardInMemorySort.h"
#include "csv/CsvReader.h"
#include "csv/CsvWriter.h"

using namespace std::chrono;
CSVTitan::CsvSort::CsvSort()
{
}

CSVTitan::CsvSort::~CsvSort()
{
}

std::string CSVTitan::CsvSort::doSort(const char* in_file, const char* out_file, vector<SortColumn> sortColumns, int chunk_size, short parallel_count)
{
	if (chunk_size == -1) chunk_size = SORT_CHUNK_SIZE;
	if (parallel_count == -1) parallel_count = CHUNKS_SORT_PARALLEL_COUNT;

	InMemorySort* inMemorySort = new StandardInMemorySort();
	auto csvReader = new CsvReader(in_file);
	// read header
	auto headers = csvReader->getHeaders();

	// sort chunks phase 1
	vector<string> chunksFilesPaths;
	while (true)
	{
		vector<DataTable*> data;
		// get chunks
		for (int i = 0; i < parallel_count; i++)
		{
			auto rows = csvReader->getRows(chunk_size);
			// in case the total number of rows is a multiple of SORT_CHUNK_SIZE
			if (rows->size() == 0) break;
			data.push_back(rows);
			// end of file
			if (rows->size() < chunk_size)
			{
				break;
			}
		}
		if (data.size() == 0)
		{
			break;
		}

		vector<thread> threads;


		auto start = high_resolution_clock::now();

		// do sort chunks
		auto executor = [inMemorySort](DataTable* rows, vector<SortColumn>& sortColumns, string& tmp_file_path)
			{
				inMemorySort->sortChunk(rows, sortColumns);
				auto csvWriter = new CsvWriter(tmp_file_path.c_str());
				csvWriter->write(rows);
				delete csvWriter;
			};

		for (int i = 0; i < data.size();i++)
		{
			// generate temporary file path
			auto now = high_resolution_clock::now().time_since_epoch();
			stringstream tmp_file_path;
			tmp_file_path << out_file << "_" << duration_cast<nanoseconds>(now).count() << i << ".csv";
			auto tmp_file_path_str = tmp_file_path.str();
			chunksFilesPaths.push_back(tmp_file_path_str);
			threads.emplace_back(executor, data[i], sortColumns, tmp_file_path_str);
		}

		for (auto& thread : threads) {
			thread.join(); // Wait for the thread to finish
		}

		for (int i = 0; i < data.size();i++)
		{
			delete data[i];
		}
	}

	int col_num = csvReader->getColNum();
	delete csvReader;

	// phase 2: Merge chunks by k-way merging
	vector<CsvReader*> csvReaders;
	vector<DataTable*> buffers;
	DataTable* outBuffers = new DataTable(OUT_CHUNK_SIZE, col_num);
	CsvWriter csvWriter(out_file);
	// write header
	csvWriter.write(headers);

	int bufferCount = OUT_CHUNK_SIZE;

	for (auto& path : chunksFilesPaths)
	{
		CsvReader* csvReader = new CsvReader(path.c_str());
		csvReaders.push_back(csvReader);
		buffers.push_back(csvReader->getRows(bufferCount, col_num));
	}
	while (true)
	{
		int min = 0;
		
		for (int i = 1; i < csvReaders.size(); i++)
		{
			if (inMemorySort->compare((*buffers[i])[0], (*buffers[min])[0], sortColumns))
			{
				min = i;
			}
		}
		outBuffers->append((*buffers[min])[0]);
		buffers[min]->popTop();

		if (buffers[min]->size() == 0)
		{
			//delete buffers[min];
			buffers[min] = csvReaders[min]->getRows(bufferCount);
			if (buffers[min]->size() == 0) // end of file
			{
				//delete buffers[min];
				buffers.erase(buffers.begin() + min);
				delete csvReaders[min];
				csvReaders.erase(csvReaders.begin() + min);
			}
		}

		if (outBuffers->size() == OUT_CHUNK_SIZE)
		{
			csvWriter.write(outBuffers);
			delete outBuffers;
			outBuffers = new DataTable(OUT_CHUNK_SIZE, col_num);

		}
		if (buffers.size() == 1)
		{
			break;
		}
	}

	// write the remaining records
	if(outBuffers->size() > 0)
	{
		csvWriter.write(outBuffers);
	}
	csvWriter.write(buffers[0]);

	//delete buffers[0];
	delete inMemorySort;
	delete csvReaders[0];
	delete outBuffers;
	// delete temporary files
	for (auto& path : chunksFilesPaths)
	{
		remove(path.c_str());
	}

	return std::string();
}
