#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;
////not ACC for this one. no idea why. Tried all trivial and nontrivial test cases (see below)
//// must be an i/o issue. extra blank line or some shit like that

int MaxRec(vector<vector<int>> matrix){
	int num_rows = matrix.size();
	int num_cols = matrix[0].size();

	vector<vector<int>> heights(num_rows, vector<int>(num_cols));

	for (int i = 0; i < num_rows; ++i){
		for (int j = 0; j < num_cols; ++j){
			if (i == 0){
				heights[i][j] = matrix[i][j];
			}
			else{
				if (matrix[i][j] == 1){
					heights[i][j] = heights[i - 1][j] + 1;
				}
				else heights[i][j] = 0;
			}
		}
	}

	vector<vector<int>> widths(num_rows, vector<int>(num_cols));
	for (int i = 0; i < num_rows; ++i){
		for (int j = 0; j < num_cols; ++j){
			if (j == 0){
				widths[i][j] = matrix[i][j];
			}
			else{
				if (matrix[i][j] == 1){
					widths[i][j] = widths[i][j - 1] + 1;
				}
				else{
					widths[i][j] = 0;
				}
			}
		}
	}

	vector<vector<int>> area(num_rows, vector<int>(num_cols));

	int _max = INT_MIN;

	for (int i = 0; i < num_rows; ++i){
		for (int j = 0; j < num_cols; ++j){
			if (j == 0){
				area[i][j] = heights[i][j] * widths[i][j];
			}
			else{
				int height = min(heights[i][j - 1], heights[i][j]);
				int width;
				if (i == 0){
					width = widths[i][j];
				} else width = min(widths[i][j], widths[i-1][j]);
				area[i][j] = height * width;
			}
			_max = max(_max, area[i][j]);

		}
	}

	return _max;
}





int main(void){

	int num_cases = 0;
	cin >> num_cases;
	string buffer;
	string shit;
	cin.ignore();
	getline(cin, shit);

	vector<string> str_matrix;
	int n = 0;

	for (int cur = 1; cur <= num_cases; ++cur){
		cin >> buffer;
		n = buffer.size();
		str_matrix.assign(n, "");
		vector<vector<int>> matrix(n, vector<int>(n));
		str_matrix[0] = buffer;
		for (int i = 1; i < n; ++i){
			cin >> buffer;
			str_matrix[i] = buffer;
		}

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				matrix[i][j] = str_matrix[i][j] - '0';
			}
		}

		if (cur > 1)
			cout << endl;
		cout << MaxRec(matrix) << endl;


	}
	
	return 0;
}



/*
Input:

6

111000
111111
111111
111111
111111
011110

11
01

10111000
00010100
00111000
00111010
00111111
01011110
01011110
00011110

1010
0101
1010
0101

0000
0000
0000
0000

111
111
111

Output:
24

2

16

1

0

9


*/
