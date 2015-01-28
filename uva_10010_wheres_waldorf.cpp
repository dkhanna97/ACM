#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

bool search_horizontal(vector<vector<char>> grid, string word, int row, int col){
	int ind = 0; 
	for (int i = 0; col+i < grid[0].size() && ind < word.size() && word[ind++] == grid[row][col+i]; ++i){
		if (ind == word.size()) return true;
	}
	return false;
}

bool search_vertical(vector<vector<char>> grid, string word, int row, int col){
	int ind = 0;
	for (int i = 0; row+i < grid.size() && ind < word.size() && word[ind++] == grid[row+i][col]; ++i){
		if (ind == word.size()) return true;
	}
	return false;
}


bool search_diagonal(vector<vector<char>> grid, string word, int row, int col){
	int ind = 0;
	
	for (int i = 0, j = 0; row+i < grid.size() && col+j < grid[0].size() && ind < word.size() && word[ind++] == grid[row + i][col + j]; ++i, ++j){
		if (ind == word.size()) return true;
	}
	return false;
}

int main(){
	
	int num_rows, num_cols, num_words;
	cin >> num_rows;
	cin >> num_cols;

	vector<vector<char>> grid(num_rows, vector<char>(num_cols));

	for (int i = 0; i < num_rows; ++i){
		string str;
		cin >> str;
		for (int j = 0; j < num_cols; ++j){grid[i][j] = str[j];}
	}

	cin >> num_words;

	vector<string> words;
	for (int i = 0; i < num_words; ++i){
		string word;
		cin >> word;
		words.push_back(word);
	}
	
	for (int iword = 0; iword < words.size(); ++iword){
		string word = words[iword];
		int count = 0;
		for (int i = 0; count <= 0 && i < grid.size(); ++i){
			for (int j = 0; count <= 0 && j < grid[0].size(); ++j){
				if (search_vertical(grid, word, i, j) || search_horizontal(grid, word, i, j) || search_diagonal(grid, word, i, j)){
					cout << i << " " << j << endl;
					++count;
				}
			}
		}
	}

	return 0;
}
