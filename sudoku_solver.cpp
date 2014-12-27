#include <iostream>
#include <stdlib.h>
using namespace std;
/*Devruth Khanna
Sudoku Solver
Uses Backtracking/Constraint satisfaction algo to solve sudoku puzzle of any difficulty.
*/

int num_nodes = 0;

bool is_same_digit_in_row(int puzzle[9][9], int row, int num){
	for (int i = 0; i < 9; ++i){
		if (puzzle[row][i] == num) return true;
	}
	return false;
}

bool is_same_digit_in_col(int puzzle[9][9], int col, int num){
	for (int i = 0; i < 9; ++i){
		if (puzzle[i][col] == num) return true;
	}
	return false;
}

bool is_same_digit_in_region(int puzzle[9][9], int row, int col, int num){

	int row_low = 0;
	int row_hi = 0;
	int col_low = 0;
	int col_hi = 0;
	if ((row >= 0) && (row <= 2)){
		row_low = 0;
		row_hi = 2;
	} else if ((row >= 3) && (row <= 5)){
		row_low = 3;
		row_hi = 5;
	} else if ((row >= 6) && (row <= 8)){
		row_low = 6;
		row_hi = 8;
	}
	if ((col >= 0) && (col <= 2)){
		col_low = 0;
		col_hi = 2;
	} else if ((col >= 3) && (col <= 5)){
		col_low = 3;
		col_hi = 5;
	} else if ((col >= 6) && (col <= 8)){
		col_low = 6;
		col_hi = 8;
	}
	for (int i = row_low; i <= row_hi; ++i){
		for (int j = col_low; j <= col_hi; ++j){
			if (puzzle[i][j] == num)
				return true;
		}
	}
	return false;
}

bool find_next_empty_slot(int puzzle[9][9], int* row, int* col){
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			if (puzzle[i][j] == 0){
				*row = i;
				*col = j;
				return true;
			}
		}
	}
	return false;
}



bool safe_move(int puzzle[9][9], int row, int col, int num){
	if (is_same_digit_in_row(puzzle, row, num) ||
		is_same_digit_in_col(puzzle, col, num) ||
		is_same_digit_in_region(puzzle, row, col, num))
		return false;
	return true;

}


bool soduku(int puzzle[9][9]){

	++num_nodes;
	int posn_row, posn_col;
	if (!find_next_empty_slot(puzzle, &posn_row, &posn_col)){
		cout << "Number of Iterations: " << num_nodes << endl;
		return true;
	}

	for (int i = 1; i <= 9; ++i){
		if (safe_move(puzzle, posn_row, posn_col, i)){
			puzzle[posn_row][posn_col] = i;
			if (soduku(puzzle)) return true;
			else puzzle[posn_row][posn_col] = 0;
		}
	}
	return false;
}



int main(int argc, char** argv){


	int easy[9][9] =
	{
		{ 0, 3, 0, 0, 8, 0, 0, 0, 6 },
		{ 5, 0, 0, 2, 9, 4, 7, 1, 0 },
		{ 0, 0, 0, 3, 0, 0, 5, 0, 0 },
		{ 0, 0, 5, 0, 1, 0, 8, 0, 4 },
		{ 4, 2, 0, 8, 0, 5, 0, 3, 9 },
		{ 1, 0, 8, 0, 3, 0, 6, 0, 0 },
		{ 0, 0, 3, 0, 0, 7, 0, 0, 0 },
		{ 0, 4, 1, 6, 5, 3, 0, 0, 2 },
		{ 2, 0, 0, 0, 4, 0, 0, 6, 0 }
	};

	int medium[9][9] =
	{
		{ 3, 0, 8, 2, 9, 6, 0, 0, 0 },
		{ 0, 4, 0, 0, 0, 8, 0, 0, 0 },
		{ 5, 0, 2, 1, 0, 0, 0, 8, 7 },
		{ 0, 1, 3, 0, 0, 0, 0, 0, 0 },
		{ 7, 8, 0, 0, 0, 0, 0, 3, 5 },
		{ 0, 0, 0, 0, 0, 0, 4, 1, 0 },
		{ 1, 2, 0, 0, 0, 7, 8, 0, 3 },
		{ 0, 0, 0, 8, 0, 0, 0, 2, 0 },
		{ 0, 0, 0, 5, 4, 2, 1, 0, 6 }
	};


	int hard[9][9] =
	{
		{ 7, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 6, 0, 0, 4, 1, 0, 2, 5, 0 },
		{ 0, 1, 3, 0, 9, 5, 0, 0, 0 },
		{ 8, 6, 0, 0, 0, 0, 0, 0, 0 },
		{ 3, 0, 1, 0, 0, 0, 4, 0, 5 },
		{ 0, 0, 0, 0, 0, 0, 0, 8, 6 },
		{ 0, 0, 0, 8, 4, 0, 5, 3, 0 },
		{ 0, 4, 2, 0, 3, 6, 0, 0, 7 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 9 }

	};

	int evil[9][9] =
	{
		{ 0, 6, 0, 8, 0, 0, 0, 0, 0 },
		{ 0, 0, 4, 0, 6, 0, 0, 0, 9 },
		{ 1, 0, 0, 0, 4, 3, 0, 6, 0 },
		{ 0, 5, 2, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 8, 6, 0, 9, 3, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 5, 7, 0 },
		{ 0, 1, 0, 4, 8, 0, 0, 0, 5 },
		{ 8, 0, 0, 0, 1, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 5, 0, 4, 0 }
	};

	int sample[9][9] =
	{
		{ 0, 6, 0, 8, 0, 0, 0, 0, 0 },
		{ 0, 0, 4, 0, 6, 0, 0, 0, 9 },
		{ 1, 0, 0, 0, 4, 3, 0, 6, 0 },
		{ 0, 5, 2, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 8, 6, 0, 9, 3, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 5, 7, 0 },
		{ 0, 1, 0, 4, 8, 0, 0, 0, 5 },
		{ 8, 0, 0, 0, 1, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 5, 0, 4, 0 }
	};

	soduku(evil);
	for (int i = 0; i < 9; ++i){

		for (int j = 0; j < 9; ++j){
			cout << evil[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}
