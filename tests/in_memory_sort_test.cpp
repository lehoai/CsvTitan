#include <gtest/gtest.h>
#include <vector>
#include <sort/StandardInMemorySort.h>
#include "csv/CsvReader.h"

using namespace CSVTitan;
using namespace std;

namespace CSVTitanTest
{
	TEST(InMemorySort, 1_col_int_asc)
	{
		// test data
		CsvReader reader(CSV_DATA_TEST_SORT);
		reader.getHeaders();
		auto data = reader.getRows(1000);

		// sort condition
		vector<SortColumn> sortColumns;
		SortColumn sortColumn;
		sortColumn.index = 2;
		sortColumn.sort_type = SortType::ASC;
		sortColumn.data_type = ColumnDataType::INT;
		sortColumns.push_back(sortColumn);

		InMemorySort* sorter = new StandardInMemorySort();
		sorter->sortChunk(data, sortColumns);

		bool check = true;
		for (int i = 0; i < data->size() - 1; i++)
		{
			if (stoi((*data)[i][2]) > stoi((*data)[i + 1][2]))
			{
				check = false;
				break;
			}
		}
		EXPECT_TRUE(check);
	}

	TEST(InMemorySort, 1_col_int_desc)
	{
		// test data
		CsvReader reader(CSV_DATA_TEST_SORT);
		reader.getHeaders();
		auto data = reader.getRows(1000);

		// sort condition
		vector<SortColumn> sortColumns;
		SortColumn sortColumn;
		sortColumn.index = 2;
		sortColumn.sort_type = SortType::DESC;
		sortColumn.data_type = ColumnDataType::INT;
		sortColumns.push_back(sortColumn);

		InMemorySort* sorter = new StandardInMemorySort();
		sorter->sortChunk(data, sortColumns);

		bool check = true;
		for (int i = 0; i < data->size() - 1; i++)
		{
			if (stoi((*data)[i][2]) < stoi((*data)[i + 1][2]))
			{
				check = false;
				break;
			}
		}
		EXPECT_TRUE(check);
	}

	TEST(InMemorySort, 2_col_int_asc_desc)
	{
		// test data
		CsvReader reader(CSV_DATA_TEST_SORT);
		reader.getHeaders();
		auto data = reader.getRows(1000);

		// sort condition
		vector<SortColumn> sortColumns;
		SortColumn sortColumn;
		sortColumn.index = 2;
		sortColumn.sort_type = SortType::DESC;
		sortColumn.data_type = ColumnDataType::INT;
		sortColumns.push_back(sortColumn);

		SortColumn sortColumn1;
		sortColumn1.index = 0;
		sortColumn1.sort_type = SortType::ASC;
		sortColumn1.data_type = ColumnDataType::INT;
		sortColumns.push_back(sortColumn1);

		InMemorySort* sorter = new StandardInMemorySort();
		sorter->sortChunk(data, sortColumns);

		bool check = true;
		for (int i = 0; i < data->size() - 1; i++)
		{
			if (stoi((*data)[i][2]) == stoi((*data)[i + 1][2]))
			{
				if (stoi((*data)[i][0]) > stoi((*data)[i + 1][0]))
				{
					check = false;
					break;
				}
			}
			if (stoi((*data)[i][2]) < stoi((*data)[i + 1][2]))
			{
				check = false;
				break;
			}
		}
		EXPECT_TRUE(check);
	}

	TEST(InMemorySort, 1_col_double_asc)
	{
		// test data
		CsvReader reader(CSV_DATA_TEST_SORT);
		reader.getHeaders();
		auto data = reader.getRows(1000);

		// sort condition
		vector<SortColumn> sortColumns;
		SortColumn sortColumn;
		sortColumn.index = 3;
		sortColumn.sort_type = SortType::ASC;
		sortColumn.data_type = ColumnDataType::DOUBLE;
		sortColumns.push_back(sortColumn);

		InMemorySort* sorter = new StandardInMemorySort();
		sorter->sortChunk(data, sortColumns);

		bool check = true;
		for (int i = 0; i < data->size() - 1; i++)
		{
			if (stoi((*data)[i][3]) > stoi((*data)[i + 1][3]))
			{
				check = false;
				break;
			}
		}
		EXPECT_TRUE(check);
	}
}