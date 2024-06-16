#include "csv/CsvReader.h"
#include "utils/stringutils.h"

using namespace CSVTitan;

CSVTitan::CsvReader::CsvReader(const char* file_path)
{
	this->col_num = -1;
	this->file = ifstream(file_path);
	if (!file.is_open())
	{
		throw "Failed to open the file";
	}
}

CSVTitan::CsvReader::~CsvReader()
{
	this->file.close();
}

string CSVTitan::CsvReader::getHeaders()
{
	string header_line;
	if (!getline(this->file, header_line))
	{
		throw "File is empty or failed to read";
	}

	// count columns
	this->col_num = 1;
	for (char& c : header_line)
	{
		if (c == ',')
		{
			this->col_num++;
		}
	}

	return header_line;
}

DataTable* CSVTitan::CsvReader::getRows(int count, int col_num)
{
	if(col_num != -1)
	{
		this->col_num = col_num;
	}
	DataTable* result = new DataTable(count, this->col_num);
	std::string line;
	int current = 0;
	while (getline(file, line))
	{
		if (line == "")
		{
			continue;
		}
		auto arr = splitStr(line, this->col_num);
		result->append(arr);
		//delete[] arr;
		current++;
		if (current == count)
		{
			break;
		}
	}

	return result;
}

int CSVTitan::CsvReader::getColNum()
{
	return this->col_num;
}
