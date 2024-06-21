#ifndef StringUtils_H
#define StringUtils_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

/// <summary>
/// Split a string by delimiter into a list
/// </summary>
/// <param name="str"></param>
/// <param name="delimiter"></param>
/// <returns></returns>
string* splitStr(string& str, int col_num, string delimiter = ",")
{
	auto tokens = new string[col_num];
	int startPos = 0;
	int endPos = str.find(delimiter);
	int index = 0;
	while (endPos != std::string::npos) {
		tokens[index] = std::string(&str[startPos], endPos - startPos);
		index++;
		startPos = endPos + 1;
		endPos = str.find(delimiter, startPos);
	}

	tokens[index] = str.substr(startPos); // Push the last token

	return tokens;
}

/**
*
*/
string simpleParseDate(const string* date_str, const string* format)
{
	int index = 0;
	ostringstream year;
	ostringstream month;
	ostringstream day;
	ostringstream hour;
	ostringstream min;
	ostringstream second;
	for each (auto & f in *format)
	{
		if (f == 'y') // year
		{
			year << (*date_str)[index];
		}
		else if (f == 'M') // month
		{
			month << (*date_str)[index];
		}
		else if (f == 'd') // day
		{
			day << (*date_str)[index];
		}
		else if (f == 'h') // hour
		{
			hour << (*date_str)[index];
		}
		else if (f == 'm') // min
		{
			min << (*date_str)[index];
		}
		else if (f == 's') // second
		{
			second << (*date_str)[index];
		}

		index++;
	}

	return year.str() + month.str() + day.str() + hour.str() + min.str() + second.str();
}

#endif // !StringUtils_H
