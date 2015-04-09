#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

///////Find the largest submatrix sum within a matrix
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44


int LargestContiguousSum1D(vector<int> a){
	int max_sum = a[0];
	int max_acc = a[0];
	for (int i = 1; i < a.size(); ++i){
		max_acc = max(a[i], max_acc+a[i]);
		if (max_acc > max_sum) max_sum = max_acc;

	}
	return max_sum;
}

int MaximumSubarraySum(vector<vector<int>> matrix){
	int max_sum = INT_MIN;
	int num_rows = matrix.size();
	int num_cols = matrix[0].size();

	for (int row_s = 0; row_s < num_rows; ++row_s){
		for (int row_e = row_s; row_e < num_rows; ++row_e){
			vector<int> height_sums(num_cols, 0);
			for (int i = 0; i < num_cols; ++i){
				for (int j = row_s; j <= row_e; ++j){
					height_sums[i] += matrix[j][i];
				}
			}
			int largest_contig_sum = LargestContiguousSum1D(height_sums);
			if (max_sum < largest_contig_sum) max_sum = largest_contig_sum;
		}

	}
	return max_sum;
}

int main(void){

	/*vector<vector<int>> matrix = {
			{ 0, -2, -7, 0 },
			{ 9, 2, -6, 2 },
			{ -4, 1, -4, 1 }, 
			{ -1, 8, 0, -2 }
	};*/
	//cout << MaximumSubarraySum(matrix) << endl;

	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> matrix[i][j];
		}
	}

	cout << MaximumSubarraySum(matrix) << endl;
	return 0;
}
