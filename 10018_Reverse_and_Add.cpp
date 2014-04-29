#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
using namespace std;

//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=959

int result = 0;

bool IsPalindrome(int num){
	char buff[33];
	_itoa_s(num, buff, 10);
	string str = buff;
	int first = 0;
	int last = str.size() - 1;
	while (last != 0){
		if (str.at(first) != str.at(last)) return false;
		++first; --last;
	}
	return true;
}

int ReverseNum(int num){
	char buff[33];
	_itoa_s(num, buff, 10);
	string str = buff;
	int first = 0;
	int last = str.size() - 1;
	while (first < last){
		int temp = str.at(first);
		str.at(first) = str.at(last);
		str.at(last) = temp;
		++first;
		--last;
	}
	int res = atoi(str.c_str());
	return res;
}


int ReverseAndAdd(int num){

	int num_iterations = 0;

	while (!IsPalindrome(num)){
		int reversed = ReverseNum(num);
		num += reversed;
		++num_iterations;
	}
	result = num;
	return num_iterations;
}


void main(int argc, char** argv){

	vector<pair<int, int>> answers;
	int nums;
	cin >> nums;

	for (int i = 0; i < nums; ++i){
		int cur;
		cin >> cur;
		int res = ReverseAndAdd(cur);
		pair<int, int> p = make_pair(res, result);
		answers.push_back(p);
	}

	for (int i = 0; i < answers.size(); ++i){
		cout << answers.at(i).first << " " << answers.at(i).second << endl;
	}

}