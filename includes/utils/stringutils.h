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
string* splitStr(string& str, int col_num, string delimiter = ",");

/**
*
*/
string simpleParseDate(const string* date_str, const string* format);

#endif // !StringUtils_H
