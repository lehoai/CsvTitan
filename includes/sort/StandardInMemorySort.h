#ifndef StandardInMemorySort_H
#define StandardInMemorySort_H
#include <algorithm>
#include "InMemorySort.h"

namespace CSVTitan
{
	///<summary>
	///Implement in memory sort using merge sort
	/// </summary>
	class StandardInMemorySort : public InMemorySort
	{
	public:
		void sortChunk(DataTable* data, vector<CSVTitan::SortColumn> sortColumns) override;
	};
}

#endif // !StandardInMemorySort_H

