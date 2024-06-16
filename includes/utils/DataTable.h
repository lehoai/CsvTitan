#ifndef DataTable_H
#define DataTable_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using namespace std;

namespace CSVTitan
{
	/**
	 * This class implements a 2D array of strings with optimized performance.
	 *
	 * The class is designed to avoid using `vector<vector<string>>`, which can be inefficient due to
	 * multiple dynamic memory allocations and pointer indirections. By knowing the row and column
	 * counts in advance, this class allocates a single contiguous block of memory to store the 2D array
	 * of strings. This approach significantly improves cache locality and reduces memory fragmentation,
	 * leading to better performance.
	 */
	class DataTable
	{
	private:
		int row, col, _size, _originalSize;
		string** data;
		string** original;
		// pointer to the next available slot in the data array
		int data_ptr = 0;
	public:
		DataTable(int row, int col);
		~DataTable();
		string* operator[](int row);
		void append(string* data);
		void popTop();
		int size();
		int colNum();
		string** begin();
		string** end();
	};
}

#endif // !DataTable_H
