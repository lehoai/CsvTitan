#include "csv/CsvWriter.h"
#include <numeric>

CSVTitan::CsvWriter::CsvWriter(const char* file_path)
{
	this->file = ofstream(file_path);
	if (!file.is_open())
	{
		throw "Failed to open file";
	}
}

CSVTitan::CsvWriter::~CsvWriter()
{
	this->file.close();
}

void CSVTitan::CsvWriter::write(vector<vector<string>>& data)
{
	string buffer;
	buffer.reserve(1024 * 1024 * 3); // Reserve 3MB buffer

	for (const auto& row : data)
	{
		for (const auto& cell : row)
		{
			buffer.append(cell);
			buffer.append(",");
		}
		buffer.pop_back(); // Remove the last comma
		buffer.append("\n");
		if (buffer.size() > 1024 * 1024 * 10) // 10MB
		{
			this->file << buffer;
			this->file.flush();
			buffer.clear();
		}
	}

	if (!buffer.empty()) {
		file << buffer;
	}
}

void CSVTitan::CsvWriter::write(DataTable* dt)
{
	string buffer;
	buffer.reserve(1024 * 1024 * 3); // Reserve 3MB buffer

	for (int i = 0; i < dt->size();i++)
	{
		for (int j = 0; j < dt->colNum(); j++)
		{
			buffer.append((*dt)[i][j]);
			buffer.append(",");
		}
		buffer.pop_back(); // Remove the last comma
		buffer.append("\n");
		if (buffer.size() > 1024 * 1024 * 3)
		{
			this->file << buffer;
			this->file.flush();
			buffer.clear();
		}
	}

	if (!buffer.empty()) {
		file << buffer;
	}
}



void CSVTitan::CsvWriter::write(string& data)
{
	file << data << "\n";
}
