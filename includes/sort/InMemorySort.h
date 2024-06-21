#ifndef InMemorySort_H
#define InMemorySort_H

#include "utils/DataTable.h"
#include "utils/stringutils.h"
#include "sort/CsvSort.h"

using namespace std;

namespace CSVTitan
{
	/*
	* * This class implements an in-memory sort, utilizing std::sort from algorithm.h
	*/
	class InMemorySort
	{
	protected:
	public:
		/*
		* Compares two rows of data based on the sort column index and sort type
		*/
		inline bool compare(const string* a, const string* b, const vector<CSVTitan::SortColumn>& sortColumns);
		/*
		* Sorts a chunk of data in memory
		*/
		virtual void sortChunk(DataTable* data, vector<CSVTitan::SortColumn> sortColumns);
	};
}

inline bool CSVTitan::InMemorySort::compare(const string* a, const string* b, const vector<CSVTitan::SortColumn>& sortColumns)
{
	for (int i = 0; i < sortColumns.size(); i++)
	{
		if (sortColumns[i].data_type == ColumnDataType::INT) // int
		{
			if (a[sortColumns[i].index] == "" || b[sortColumns[i].index] == "")
				return false;
			int a_i = stoi(a[sortColumns[i].index]);
			int b_i = stoi(b[sortColumns[i].index]);
			if (a_i == b_i)
				continue;
			if (sortColumns[i].sort_type == SortType::ASC)
				return a_i < b_i;
			else
				return a_i > b_i;
		}
		else if (sortColumns[i].data_type == ColumnDataType::DOUBLE) // double
		{
			if (a[sortColumns[i].index] == "" || b[sortColumns[i].index] == "")
				return false;
			double a_i = stod(a[sortColumns[i].index]);
			double b_i = stod(b[sortColumns[i].index]);
			if (a_i == b_i)
				continue;
			if (sortColumns[i].sort_type == SortType::ASC)
				return a_i < b_i;
			else
				return a_i > b_i;
		}
		else if (sortColumns[i].data_type == ColumnDataType::DATETIME) // date time
		{
			if (a[sortColumns[i].index] == "" || b[sortColumns[i].index] == "")
				return false;
			string left = simpleParseDate(&(a[sortColumns[i].index]), &(sortColumns[i].format));
			string right = simpleParseDate(&(b[sortColumns[i].index]), &(sortColumns[i].format));

			if (sortColumns[i].sort_type == SortType::ASC)
				return left < right;
			return left > right;
		}
		else // string
		{
			if (a[sortColumns[i].index] == b[sortColumns[i].index]) continue;
			if (sortColumns[i].sort_type == SortType::ASC)
				return a[sortColumns[i].index] < b[sortColumns[i].index];
			return a[sortColumns[i].index] > b[sortColumns[i].index];
		}
	}

	return false;
}

#endif