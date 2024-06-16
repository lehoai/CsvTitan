#include <algorithm>
#include "utils/DataTable.h"

CSVTitan::DataTable::DataTable(int row, int col)
{
	this->_size = 0;
	this->_originalSize = 0;
	this->row = row;
	this->col = col;
	// init 2d data array
	this->original = new string * [row];
	/*for (int i = 0; i < row; i++)
		this->original[i] = new string[col];*/

	this->data = this->original;
}

CSVTitan::DataTable::~DataTable()
{
	for (int i = 0; i < this->_originalSize; i++)
		delete[] this->original[i];
	delete[] this->original;
}

string* CSVTitan::DataTable::operator[](int row)
{
	return this->data[row];
}

void CSVTitan::DataTable::append(string* source)
{
	// cant use memcpy because of string
	//copy(source, source + this->col, this->data[this->data_ptr]);
	this->data[this->data_ptr] = source;
	this->data_ptr++;
	this->_size++;
	this->_originalSize++;;
}

void CSVTitan::DataTable::popTop()
{
	this->data++;
	this->_size--;
}

int CSVTitan::DataTable::size()
{
	return this->_size;
}

int CSVTitan::DataTable::colNum()
{
	return this->col;
}

string** CSVTitan::DataTable::begin()
{
	return this->data;
}

string** CSVTitan::DataTable::end()
{
	return this->data + this->_size;
}