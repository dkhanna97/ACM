#include <iostream>
#include <limits.h>
using namespace std;

//http://uva.onlinejudge.org/external/1/100.html 

int NumCycles(int n){
	int cycles = 1;

	while (n != 1){
		if (n % 2 != 0) n = (3 * n) + 1;
		else n /= 2;
		++cycles;
	}

	return cycles;
}

int main(void){
	int a;  int b;

	while (cin >> a >> b){
		cout << a << " " << b << " ";
		if (a > b){
			int temp = a;
			a = b;
			b = temp;
		}

		int max = INT_MIN;
		for (int i = a; i <= b; ++i){
			int cycles = NumCycles(i);
			if (cycles > max) max = cycles;
		}
		cout << max << endl;
	}
	return 0;
}
