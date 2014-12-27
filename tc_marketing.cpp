#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;

//Graph Coloring problem - use dfs to find # of components
//http://community.topcoder.com/tc?module=ProblemDetail&rd=4472&pm=1524

vector<vector<int>> g; 
vector<int> visited; //1 for visited, 0 for not visited
int n; // number of vertices


//color = {0,1} 0 - adult, 1 - teen
bool dfs(int cur, int color){
	visited[cur] = color;
	
	for (int i = 0; i < n; ++i){
		if (g[cur][i]){
				if (visited[i] == color) return false; 
				if (visited[i] == -1 && !dfs(i, 1 - color)) return false;
		}
	}
	return true;
}


//return number of components
long howMany(string complete[]){
	g = vector<vector<int>>(n, vector<int>(n));
	visited = vector<int>(n, -1);

	//create graph
	for (int i = 0; i < n; ++i){
		istringstream is(complete[i]);
		int next;
		while (is >> next){
			g[i][next] = 1;
			g[next][i] = 1;
		}
	}
	long result = 0;
	for (int j = 0; j < 2; ++j){
		for (int i = 0; i < n; ++i){
			if (visited[i] == -1){ 
				if (!dfs(i, j)) return -1;
				++result;
			}
		}
		visited = vector<int>(n, -1);
	}
	return (long)result;

}

int main(){

	//string strArray[] = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };
	//string strArray[] = {"1", "2", "0"};
	//string strArray[] =	{"1", "2", "3", "0", "5", "6", "4"};
	string strArray[] = { "1 4", "2", "3", "0", "" };
	n = sizeof(strArray) / sizeof(string);
	cout << howMany(strArray) << endl;
	
	return 0;
}
