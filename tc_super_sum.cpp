#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

//http://community.topcoder.com/stat?c=problem_statement&pm=10239

/*
SuperSum(0 , n) = n, for all positive n.
SuperSum(k , n) = SuperSum(k-1 , 1) + SuperSum(k-1 , 2) + ... + SuperSum(k-1 , n), for all positive k, n.

SuperSum(1 , 3) 
    = SS(0, 1) + SS(0, 2) + SS(0, 3) = 1 + 2 + 3

SuperSum(2, 3)
    = SS(1, 1) + SS(1, 2) + SS(1, 3)
    = SS(0, 1) + SS(0, 1) + SS(0, 2) + SS(0, 1) + SS(0, 2) + SS(0, 3)
*/


int SuperSum(int k, int n){
   
    int **table = (int**)calloc(n + 1, sizeof(int*));
    for(int i = 0; i < n + 1; ++i)
        table[i] = (int*)calloc(k + 1, sizeof(int*));
    
    for(int i = 0; i < k + 1; ++i){
        for(int j = 0; j < n + 1; ++j){
            if(j == 0)
                continue;
            else if(i == 0)
                table[i][j] = j;
            else if(j == 1)
                table[i][j] = table[i-1][j];
            else
                table[i][j] = table[i][j-1] + table[i-1][j];
        }
    } 
    
    return table[k][n];
}

int main(){

    int res = SuperSum(10, 10);
    cout << res << endl;
	return 0;
}
