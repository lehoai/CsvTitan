#ifndef CsvReader_H
#define CsvReader_H

#include <fstream>
#include "utils/DataTable.h"
#include "utils/stringutils.h"

namespace CSVTitan
{
	using namespace std;

	class CsvReader
	{
	private:
		ifstream file;
		int col_num;
	public:
		CsvReader(const char* file_path);
		~CsvReader();
		string getHeaders();
		/*
		 * Since the file is read sequentially, line by line,
		 * it's important to call getHeaders before getRows in order to retrieve the rows correctly
		*/
		DataTable* getRows(int count, int col_num = -1);

		int getColNum();
	};
}

#endif