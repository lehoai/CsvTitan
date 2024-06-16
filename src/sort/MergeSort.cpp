//#include "sort/MergeSort.h"
//#include <iostream>
//
//using namespace CSVTitan;
//using namespace std;
///// <summary>
///// Compare 2 values in a string extracted by sort_idx_col
///// </summary>
//bool InMemoryMergeSort::compare(string& left, string& right)
//{
//	auto leftval = stod(left);
//	auto rightVal = stod(right);
//	return leftval <= rightVal;
//}
//void InMemoryMergeSort::merge(vector<vector<string>>& data, int const left, int const mid, int const right, int const sort_col_idx)
//{
//	int n1 = mid - left + 1;
//	int n2 = right - mid;
//
//	// temporary vectors
//	vector<vector<string>> L(n1), R(n2);
//	// copy data to temporary vectors
//	for (int i = 0; i < n1; i++)
//	{
//		L[i] = data[left + i];
//	}
//	for (int j = 0; j < n2; j++)
//	{
//		R[j] = data[mid + 1 + j];
//	}
//
//	int i = 0, j = 0, k = left;
//	// merge the temporary into the original data
//	while (i < n1 && j < n2)
//	{
//		string leftVal = L[i][sort_col_idx];
//		string rightVal = R[j][sort_col_idx];
//		if (compare(leftVal, rightVal))
//		{
//			data[k] = L[i];
//			++i;
//		}
//		else
//		{
//			data[k] = R[j];
//			++j;
//		}
//		++k;
//	}
//
//	// copy the remaining elements of L
//	while (i < n1)
//	{
//		data[k] = L[i];
//		++i;
//		++k;
//	}
//	// copy the remaining elements of R
//	while (j < n2)
//	{
//		data[k] = L[j];
//		++j;
//		++k;
//	}
//}
//void InMemoryMergeSort::mergeSort(vector<vector<string>>& data, int const left, int const right, int const sort_col_idx)
//{
//	if (left < right)
//	{
//		int mid = left + (right - left) / 2;
//
//		// sort the first and second arrays
//		mergeSort(data, left, mid, sort_col_idx);
//		mergeSort(data, mid + 1, right, sort_col_idx);
//
//		// merge the sorted chunks
//		merge(data, left, mid, right, sort_col_idx);
//
//	}
//}
//
//void InMemoryMergeSort::sortChunk(vector<vector<string>>& data, int const sort_col_idx, int const sort_type)
//{
//	mergeSort(data, 0, data.size() - 1, sort_col_idx);
//}