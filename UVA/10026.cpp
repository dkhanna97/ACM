#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <unordered_map>
#include <map>
using namespace std;

//Shoe Maker's Problem 
//////http://uva.onlinejudge.org/external/100/p10026.pdf

bool pair_compare(pair<int, double> a, pair<int, double> b){
	if (a.second == b.second){
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main(){

	int num_cases = 0;
	cin >> num_cases;
	
	while (num_cases--){
		vector<pair<int, double>> jobs;

		int num_jobs = 0;
		cin >> num_jobs;

		for (int i = 1; i <= num_jobs; ++i){
			int days = 0;
			int fine = 0;
			cin >> days;
			cin >> fine;
			jobs.push_back(make_pair(i, (double) (fine / (double)days)));
		}

		sort(jobs.begin(), jobs.end(), pair_compare);
		cout << jobs[0].first;
		for (int i = 1; i < jobs.size(); ++i){
			cout << " " << jobs[i].first;
		}
		cout << endl;
		if (num_cases) { cout << endl; }

	}
	return 0;
}
