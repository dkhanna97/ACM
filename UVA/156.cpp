#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <unordered_map>
using namespace std;

int main(){

	string word, orig;
	cin >> word;
	unordered_map<string, pair<string, int>> dictionary;
	unordered_map<string, pair<string, int>>::iterator it;

	while (word != "#"){
		orig = word;
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		sort(word.begin(), word.end());
		it = dictionary.find(word);
		if (it == dictionary.end()){ 
			dictionary[word] = make_pair(orig, 0);
		}
		else{
			++it->second.second;
		}
		cin >> word;
	}
	vector<string> ananagrams_cap;
	vector<string> ananagrams_low;

	for (auto& x : dictionary){
		if (x.second.second == 0){
			string cur = x.second.first;
			if (isupper(cur[0])){
				ananagrams_cap.push_back(cur);
			}
			else{
				ananagrams_low.push_back(cur);
			}
		}
	}
	sort(ananagrams_cap.begin(), ananagrams_cap.end());
	sort(ananagrams_low.begin(), ananagrams_low.end());
	for (int i = 0; i < ananagrams_cap.size(); ++i){
		cout << ananagrams_cap[i] << endl;
	}
	for (int i = 0; i < ananagrams_low.size(); ++i){
		cout << ananagrams_low[i] << endl;
	}

	return 0;
}
