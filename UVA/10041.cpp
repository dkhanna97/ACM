#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

//http://uva.onlinejudge.org/external/100/p10041.pdf

int main(void){

	int num_cases = 0;
	cin >> num_cases;

	for (int i = 0; i < num_cases; ++i){
		int num_relatives;
		cin >> num_relatives;
		vector<int> distances(num_relatives);
		for (int i = 0; i < num_relatives; ++i) {
			cin >> distances[i];
		}
		int distance = 0;
		sort(distances.begin(), distances.end());

		int median;
		if (distances.size() % 2 != 0) median = distances[distances.size() / 2];
		else{
			int mid = distances.size() / 2;
			median = (distances[mid] + distances[mid - 1]) / 2;
		}

		for (int i = 0; i < distances.size(); ++i){
			distance += abs(median - distances[i]);
		}

		cout << distance << endl;
	}
	
	return 0;
}
