#include <gtest/gtest.h>
#include "utils/DataTable.h"

using namespace CSVTitan;

namespace CSVTitanTest
{
	TEST(DataTable, simple_assign)
	{
		DataTable dt(2, 2);
		string* data = new string[2];
		data[0] = "1";
		data[1] = "2";
		dt.append(data);
		string* data2 = new string[2];
		data2[0] = "3";
		data2[1] = "4";
		dt.append(data2);

		EXPECT_EQ(dt[0][0], "1");
		EXPECT_EQ(dt[1][0], "3");
		EXPECT_EQ(dt.size(), 2);
		EXPECT_EQ(dt.colNum(), 2);
	}
	TEST(DataTable, simple_append_and_pop)
	{
		DataTable dt(4, 2);
		string* data = new string[2];
		data[0] = "1";
		data[1] = "2";
		dt.append(data);
		string* data2 = new string[2];
		data2[0] = "3";
		data2[1] = "4";
		dt.append(data2);

		string* data3 = new string[2];
		data3[0] = "5";
		data3[1] = "6";
		dt.append(data3);

		EXPECT_EQ(dt[0][0], "1");
		EXPECT_EQ(dt[0][1], "2");
		EXPECT_EQ(dt[1][0], "3");
		EXPECT_EQ(dt[1][1], "4");
		EXPECT_EQ(dt[2][0], "5");
		EXPECT_EQ(dt[2][1], "6");
		EXPECT_EQ(dt.size(), 3);

		string* data4 = new string[2];
		data4[0] = "7";
		data4[1] = "8";
		dt.append(data4);

		EXPECT_EQ(dt[0][0], "1");
		EXPECT_EQ(dt[0][1], "2");
		EXPECT_EQ(dt[1][0], "3");
		EXPECT_EQ(dt[1][1], "4");
		EXPECT_EQ(dt[2][0], "5");
		EXPECT_EQ(dt[2][1], "6");
		EXPECT_EQ(dt[3][0], "7");
		EXPECT_EQ(dt[3][1], "8");
		EXPECT_EQ(dt.size(), 4);

		dt.popTop();
		EXPECT_EQ(dt[0][0], "3");
		EXPECT_EQ(dt[0][1], "4");
		EXPECT_EQ(dt.size(), 3);
	}
}