#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <unordered_map>
using namespace std;

void main(){

	string word, orig;
	cin >> word;
	unordered_map<string, pair<string, int>> dictionary;
	unordered_map<string, pair<string, int>>::iterator it;

	while (word != "#"){
		orig = word;
		transform(word.begin(), word.end(), word.begin(), tolower);
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
	for (auto& x : dictionary){
		if (x.second.second == 0) cout << x.second.first << endl;
	}
}
