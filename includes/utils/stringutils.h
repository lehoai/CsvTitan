#ifndef COMMON_H
#define COMMON_H

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

#endif // !COMMON_H
