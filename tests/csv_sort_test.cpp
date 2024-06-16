#include <gtest/gtest.h>
#include <sort/CsvSort.h>
#include <csv/CsvReader.h>
#include "utils/stringutils.h"

using namespace CSVTitan;

namespace CSVTitanTest
{
	TEST(ExternalSort, 1_col_int_asc)
	{
		vector<SortColumn> sortColumns;
		SortColumn sortColumn;
		sortColumn.index = 2;
		sortColumn.sort_type = SortType::ASC;
		sortColumn.data_type = ColumnDataType::INT;
		sortColumns.push_back(sortColumn);

		CsvSort csvSort;
		string csv_out_path = CSV_FOLDER_DIR;
		csv_out_path += "normal_case_out.csv";
		csvSort.doSort(CSV_DATA_TEST_SORT, csv_out_path.c_str(), sortColumns, 10, 3);

		// test the result
		CsvReader csvReader(csv_out_path.c_str());
		csvReader.getHeaders();
		auto rows = csvReader.getRows(1000);

		for (int i = 0; i < rows->size() - 2; i++)
		{
			auto a = stoi((*rows)[i][2]);
			auto b = stoi((*rows)[i + 1][2]);
			EXPECT_LE(a, b);
		}

		// remove output file
		std::remove(csv_out_path.c_str());

	};

	TEST(ExternalSort, 1_col_double_asc)
	{
		vector<SortColumn> sortColumns;
		SortColumn sortColumn;
		sortColumn.index = 3;
		sortColumn.sort_type = SortType::ASC;
		sortColumn.data_type = ColumnDataType::DOUBLE;
		sortColumns.push_back(sortColumn);

		CsvSort csvSort;
		string csv_out_path = CSV_FOLDER_DIR;
		csv_out_path += "normal_case_out1.csv";
		csvSort.doSort(CSV_DATA_TEST_SORT, csv_out_path.c_str(), sortColumns, 10, 3);

		// test the result
		CsvReader csvReader(csv_out_path.c_str());
		csvReader.getHeaders();
		auto rows = csvReader.getRows(1000);

		for (int i = 0; i < rows->size() - 2; i++)
		{
			auto a = stod((*rows)[i][3]);
			auto b = stod((*rows)[i + 1][3]);
			EXPECT_LE(a, b);
		}

		// remove output file
		std::remove(csv_out_path.c_str());
	};

	TEST(ExternalSort, Performance)
	{
		GTEST_SKIP() << "Skipping this test because performance tests take time";

		vector<SortColumn> sortColumns;
		SortColumn sortColumn;
		sortColumn.index = 4;
		sortColumn.sort_type = SortType::ASC;
		sortColumn.data_type = ColumnDataType::DOUBLE;
		sortColumns.push_back(sortColumn);

		CsvSort csvSort;
		string csv_out_path = CSV_FOLDER_DIR;
		csv_out_path += "normal_case_out2.csv";
		csvSort.doSort("Path_to\\2021_Yellow_Taxi_Trip_Data.csv", csv_out_path.c_str(), sortColumns);

		// remove output file
		std::remove(csv_out_path.c_str());
	}
};