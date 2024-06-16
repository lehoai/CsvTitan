//#include <vector>
//#include <string>
//#include "csv/CsvReader.h"
//#include "csv/CsvWriter.h"
//#include "join/CsvJoin.h"
//
//CSVTitan::CsvJoin::CsvJoin()
//{
//}
//
//CSVTitan::CsvJoin::~CsvJoin()
//{
//}
//
//void CSVTitan::CsvJoin::join(const char* in_file1, const char* in_file2, const char* out_file, vector<SortColumn> sortColumns, JoinType joinType)
//{
//	//CsvWriter writer(out_file);
//	//CsvReader reader1(in_file1);
//	//CsvReader reader2(in_file2);
//
//	////DataTable outBuffer();
//	//DataTable inBuffer1(500, reader1.getColNum());
//	//DataTable inBuffer2(500, reader1.getColNum());
//	//auto h1 = reader1.getHeaders();
//	//auto h2 = reader2.getHeaders();
//
//	//inBuffer1 = reader1.getRows(500);
//	//inBuffer2 = reader2.getRows(500);
//
//	InMemorySort* inMemorySort = new StandardInMemorySort();
//
//	/*while (true)
//	{
//		if (inMemorySort->compare(inBuffer1[0], inBuffer2[0], sortColumns))
//		{
//
//		}
//	}*/
//
//
//	delete inMemorySort;
//}
//
//void CSVTitan::CsvJoin::doJoin(const char* in_file1, const char* in_file2, const char* out_file, vector<JoinColumn> joinColumns, JoinType joinType, bool is_sorted)
//{
//	vector<SortColumn> sortColumns(joinColumns.size());
//	for (int i = 0; i < joinColumns.size();i++)
//	{
//		sortColumns[i].data_type = joinColumns[i].data_type;
//		sortColumns[i].index = joinColumns[i].index;
//		sortColumns[i].sort_type = SortType::ASC;
//	}
//
//	if (!is_sorted)
//	{
//		string out_file1, out_file2;
//		sortInput(in_file1, in_file2, out_file1, out_file2, sortColumns);
//		this->join(out_file1.c_str(), out_file2.c_str(), out_file, sortColumns, joinType);
//	}
//	else
//	{
//		this->join(in_file1, in_file2, out_file, sortColumns, joinType);
//	}
//}
//
//void CSVTitan::CsvJoin::sortInput(const char* in_file1, const char* in_file2, string& out_file1, string& out_file2, vector<SortColumn> sortColumns)
//{
//
//	out_file1 = in_file1;
//	out_file1 + ".sorted";
//	out_file2 = in_file2;
//	out_file2 + ".sorted";
//
//	// sort input files
//	CSVTitan::CsvSort csvSort;
//	csvSort.doSort(in_file1, out_file1.c_str(), sortColumns);
//	csvSort.doSort(in_file2, out_file2.c_str(), sortColumns);
//}
