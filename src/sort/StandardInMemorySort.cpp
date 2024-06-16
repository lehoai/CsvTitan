#include <algorithm>
#include <string>
#include "sort/StandardInMemorySort.h"

void CSVTitan::StandardInMemorySort::sortChunk(DataTable* data, vector<CSVTitan::SortColumn> sortColumns)
{
	auto compareRecords = [&sortColumns, this](const std::string* a, const std::string* b) -> bool
		{
			return this->compare(a, b, sortColumns);
		};
	std::sort(data->begin(), data->end(), compareRecords);
}

void CSVTitan::InMemorySort::sortChunk(DataTable* data, vector<CSVTitan::SortColumn> sortColumns)
{
}
