#ifndef CsvSort_H
#define CsvSort_H

#include <vector>
#include <string>
#include "utils//constant.h"

// Chunk size in phase 1 of the external merge sort algorithm
constexpr auto SORT_CHUNK_SIZE = 1000000;
// Chunk size in phase 2 of the external merge sort algorithm
constexpr auto OUT_CHUNK_SIZE = 100000;

// The number of threads used to sort chunks in parallel
constexpr auto CHUNKS_SORT_PARALLEL_COUNT = 4;

using namespace std;
using namespace CSVTitan;

namespace CSVTitan
{
	enum SortType
	{
		ASC,
		DESC
	};

	/*
	* Structure to store the column index, data type, and sorting order of a column.
	*/
	struct SortColumn
	{
		int index; // index of the column in the CSV file
		SortType sort_type; // data type of the column: 1: int, 2: double, 3: string, 4: date
		ColumnDataType data_type; // sorting order: true for ascending, false for descending
		string format; // format datetime
	};

	/*
	 * This class implements external merge sort using a k-way merging algorithm.
	 * Initially, chunks of data are sorted using the in-memory sort algorithm
	 * (specifically, std::sort from <algorithm>).
	 * The in-memory sort is implemented in the InMemorySort class,
	 * feel free to review and change it to any in-memory sort algorithm that suits your needs.
	 * These sorted chunks are then merged together using k-way merging to produce the final sorted result file.
	 */
	class CsvSort
	{
	public:
		// Constructor: initializes the in-memory sort object
		CsvSort();
		~CsvSort();

		/*
		* Sorts a CSV file.
		*
		* @param in_file Path of the source file.
		* @param out_file Path of the destination file.
		* @param sortColumns Array of column indices used for comparison to sort (priority is determined by the order of indices in the array).
		* @param chunk_size Size of the chunk in phase 1 of the external merge sort algorithm.
		* @param parallel_count Number of threads used to sort chunks in parallel.
		*/
		string doSort(const char* in_file, const char* out_file, vector<SortColumn> sortColumns, int chunk_size = -1, short parallel_count = -1);
	};
}

#endif