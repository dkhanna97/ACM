#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

vector<int> digits_a;
vector<int> digits_b;

void GetDigits_A(int in){
	if (in >= 10) GetDigits_A(in / 10);
	int digit = in % 10;
	digits_a.push_back(digit);
}

void GetDigits_B(int in){
	if (in >= 10) GetDigits_B(in / 10);
	int digit = in % 10;
	digits_b.push_back(digit);
}

int concatenate(int x, int y) {
	int p = 10;
	while (y >= p) p *= 10;
	return (x * p) + y;
}


int solution(int A, int B) {

	int num_digits_a = 0;
	int copy_a = A;
	while (copy_a != 0) { copy_a /= 10; ++num_digits_a; }

	int num_digits_b = 0;
	int copy_b = B;
	while (copy_b != 0) { copy_b /= 10; ++num_digits_b; }
	copy_a = A; copy_b = B;

	GetDigits_A(A);
	GetDigits_B(B);
	int res = 0;
	int a = 0; int b = 0;
	
	while (true){
		if (a == digits_a.size() && b == digits_b.size()) break;
		if (a != digits_a.size()) res = concatenate(res, digits_a.at(a++));
		if (b != digits_b.size()) res = concatenate(res, digits_b.at(b++));
	}

	if (res > 100000000) return -1;

	return res;
}

void main(){

	//cout << concatenate(0, 2) << endl;
	//cout << solution(12, 56) << endl;

	cout << solution(12345, 678) << endl;
}
