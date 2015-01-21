#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stack>
using namespace std;

stack<int> st;

int solution(string &S) {
	for (int i = 0; i < S.size(); ++i){
		if (isdigit(S.at(i))){
			st.push(S.at(i)-'0');
		}
		else if (S.at(i) == '+'){
			try{
				if (st.size() < 2){
					return -1;
				}
				int v1 = st.top();
				st.pop();
				int v2 = st.top();
				st.pop();
				int res = v1 + v2;
				st.push(res);
			}
			catch (exception e){ return -1; }
		}
		else if (S.at(i) == '*'){
			try{
				if (st.size() < 2){
					return -1;
				}
				int v1 = st.top();
				st.pop();
				int v2 = st.top();
				st.pop();
				int res = v1 * v2;
				st.push(res);
			}
			catch (exception e){ return -1; }
		}
	}
	return st.top();
}




void main(){
	//string str = "12++++*****";
	string str = "13+62*7+*";
	cout << solution(str) << endl;

}
