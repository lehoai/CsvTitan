#ifndef CsvWriter_H
#define CsvWriter_H

#include <fstream>
#include <vector>
#include <string>
#include "utils/DataTable.h"

namespace CSVTitan
{
	using namespace std;

	class CsvWriter
	{
	private:
		ofstream file;
	public:
		CsvWriter(const char* file_path);
		~CsvWriter();
		void write(vector<vector<string>>& data);
		void write(DataTable* dt);
		void write(string& data);
	};
}


#endif