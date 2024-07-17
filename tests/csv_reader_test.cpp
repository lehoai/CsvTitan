#include <gtest/gtest.h>
#include <csv/CsvReader.h>

using namespace CSVTitan;

namespace CSVTitanTest
{
	TEST(CsvReaderTest, GetHeader)
	{
		auto csv_path = CSV_DATA_TEST_SORT;
		CsvReader reader(csv_path);
		auto headers = reader.getHeaders();

		EXPECT_EQ(headers, "id,name,age,height,date");
	};

	TEST(CsvReaderTest, GetRows)
	{
		auto csv_path = CSV_DATA_TEST_SORT;
		CsvReader reader(csv_path);
		reader.getHeaders();
		DataTable* rows = reader.getRows(2);

		EXPECT_EQ(rows->size(), 2);
		EXPECT_EQ((*rows)[0][0], "1");
		EXPECT_EQ((*rows)[1][0], "2");

		delete rows;
	};

	TEST(CsvReaderTest, GetRowsMoreThanTotal)
	{
		auto csv_path = CSV_DATA_TEST_SORT;
		CsvReader reader(csv_path);
		reader.getHeaders();
		auto rows = reader.getRows(2000);

		EXPECT_EQ(rows->size(), 100);

		delete rows;
	}
}