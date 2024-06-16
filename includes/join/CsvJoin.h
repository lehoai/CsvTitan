//#ifndef CsvJoin_H
//#define CsvJoin_H
//
//#include <vector>
//#include "utils/constant.h"
//#include "sort/StandardInMemorySort.h"
//
//using namespace std;
//
//namespace CSVTitan
//{
//	// Enum to specify the type of join
//	enum JoinType
//	{
//		INNER,
//		LEFT,
//		RIGHT,
//		FULL
//	};
//
//	// Structure to store the column index and data type of a column used for joining
//	struct JoinColumn
//	{
//		int index;// index of the column in the CSV file
//		ColumnDataType data_type;// data type of the column
//	};
//
//	/**
//	 * This class implements a join operation using the merge sort join algorithm.
//	 *
//	 * The merge sort join algorithm efficiently joins two csv files by first sorting them on the join keys
//	 * and then merging the sorted data. If the input data are already sorted on the join keys,
//	 * the sorting step can be skipped, significantly improving performance.
//	 *
//	 * Key features:
//	 * - Supports inner, left, right, and full outer joins.
//	 * - Utilizes merge sort for efficient sorting of large datasets.
//	 * - If the datasets are sorted (`is_sorted = true`), the sorting step is bypassed.
//	 * - Handles various data types for join keys, including integers, doubles, strings, and datetime.
//	 */
//	class CsvJoin
//	{
//	private:
//		void join(const char* in_file1, const char* in_file2, const char* out_file, vector<SortColumn> sortColumns, JoinType joinType);
//		void sortInput(const char* in_file1, const char* in_file2, string& out_file1, string& out_file2, vector<SortColumn> sortColumns);
//	public:
//		// Constructor: initializes the in-memory sort object
//		CsvJoin();
//		~CsvJoin();
//
//		/*
//		* Joins two CSV files.
//		*
//		* @param in_file1 Path of the first source file.
//		* @param in_file2 Path of the second source file.
//		* @param out_file Path of the destination file.
//		* @param joinColumns Array of column indices used for comparison to join
//		* @param joinType Type of join to perform.
//		* @apram is_sorted Flag to indicate if the input files are already sorted.
//		*/
//		void doJoin(const char* in_file1, const char* in_file2, const char* out_file, vector<JoinColumn> joinColumns, JoinType joinType, bool is_sorted = false);
//	};
//}
//
//#endif // !CsvJoin_H