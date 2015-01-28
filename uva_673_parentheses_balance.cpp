#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
using namespace std;

bool balance(string str){
	stack<char> st;
	for (int i = 0; i < str.size(); ++i){
		char cur = str[i];
		if (cur == '(' || cur == '['){
			st.push(cur);
		} else if (cur == ')' || cur == ']'){
			if (st.empty()) return false;
			char top = st.top();
			if ((top == '(' && cur == ')') || (top == '[' && cur == ']')) st.pop();
			else return false;
		}
	}
	return st.size() == 0;
}


void main(){

	int n;
	string str;
	cin >> n;
	while(n--){
		cin >> str;
		balance(str) == true ? cout << "yes" << endl : cout << "no" << endl;
	}

}
