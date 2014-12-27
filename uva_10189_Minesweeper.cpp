#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;

int rows = 0;
int cols = 0;

vector<vector<int>> sweep(vector<vector<char>> grid){
	vector<vector<int>> res(rows, vector<int>(cols));
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j) res[i][j] = 0;
	}
	
	bool go_north, go_south, go_east, go_west, go_northwest, go_northeast, go_southwest, go_southeast;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){

			if (grid[i][j] == '*') { res[i][j] = -1; continue; }
			go_north = go_south = go_east = go_west = true;

			if (i == 0){ 
				go_north = false;
			}
			if (j == 0){ 
				go_west = false;
			}
			if (i == rows-1){ 
				go_south = false;
			}
			if (j == cols-1){ 
				go_east = false;
			}
			if (go_north){ 
				if (grid[i - 1][j] == '*') 
					res[i][j] += 1;
			}
			if (go_south){ 
				if (grid[i + 1][j] == '*') 
					res[i][j] += 1;
			}
			if (go_west){
				if (grid[i][j - 1] == '*') 
					res[i][j] += 1;
			}
			if (go_east){ 
				if (grid[i][j + 1] == '*') 
					res[i][j] += 1;
			}
			if (go_north && go_west){
				if (grid[i - 1][j - 1] == '*') 
					res[i][j] += 1;
			}
			if (go_north && go_east){
				if (grid[i - 1][j + 1] == '*') 
					res[i][j] += 1;
			}
			if (go_south && go_west){
				if (grid[i + 1][j - 1] == '*') 
					res[i][j] += 1;
			}
			if (go_south && go_east){
				if (grid[i + 1][j + 1] == '*') 
					res[i][j] += 1;
			}

		}
	}

	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			if (res[i][j] == -1) cout << "*" ;
			else cout << res[i][j];
		}
		cout << endl;
	}
	return res;
}



void main(int argc, char** argv){
	
	while (1){
		cin >> rows;
		if (rows == 0) break;
		cin >> cols;
		vector<vector<char>> a(rows, vector<char>(cols));
		for (int i = 0; i < rows; ++i){
			for (int j = 0; j < cols; ++j){
				cin >> a[i][j];
			}
		}
		vector<vector<int>> res = sweep(a);
	}
	
}
