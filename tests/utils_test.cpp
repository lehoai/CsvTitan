#include <gtest/gtest.h>
#include <string>
#include "utils/stringutils.h"

using namespace std;

namespace CSVTitanTest
{
	TEST(StringUtils, split_string)
	{
		string data = "1,2,3,4";
		auto arr = splitStr(data, 4);
		EXPECT_EQ(arr[0], "1");
		EXPECT_EQ(arr[1], "2");
		EXPECT_EQ(arr[2], "3");
		EXPECT_EQ(arr[3], "4");
	}

	TEST(StringUtils, simple_parse_date_simple_case)
	{
		string* d = new string("2024/06/06 20:24:33");
		string* format = new string("yyyy/MM/dd hh:mm:ss");
		auto parsed = simpleParseDate(d, format);
		EXPECT_EQ(parsed, "20240606202433");
	}

	TEST(StringUtils, simple_parse_date_opposite)
	{
		string* d = new string("06/07/2024 20:24:33");
		string* format = new string("dd/MM/yyyy hh:mm:ss");
		auto parsed = simpleParseDate(d, format);
		EXPECT_EQ(parsed, "20240706202433");
	}

	TEST(StringUtils, simple_parse_date_performance)
	{
		for (int i = 0; i < 1000000; i++)
		{
			string* d = new string("06/07/2024 20:24:33");
			string* format = new string("dd/MM/yyyy hh:mm:ss");
			auto parsed = simpleParseDate(d, format);
			EXPECT_EQ(parsed, "20240706202433");
		}
	}
}