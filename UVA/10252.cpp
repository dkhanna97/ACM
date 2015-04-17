#include <iostream>
#include <limits.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

//Longest common permutation
/////http://uva.onlinejudge.org/external/102/p10252.pdf



int main(void){

	string a, b;
	while (getline(cin, a) && getline(cin, b)){
		
		if (a == b){
			cout << a << endl;
			continue;
		}
		string res = "";
		int i = 0; int j = 0;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		while (1){
			while (a[i] < b[j]){
				if (i > a.size() - 1) break;
				++i;
			}
			if (a[i] == b[j]) res += a[i++];
			++j;
			if (i > a.size() - 1) break;
			if (j > b.size() - 1) break;
		}
		cout << res << endl;
	}

	return 0;
}
