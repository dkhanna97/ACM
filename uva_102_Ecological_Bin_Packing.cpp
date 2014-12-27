#include <iostream>
#include <string>
using namespace std;
//http://acm.uva.es/p/v1/102.html

struct bin{
	int brown;
	int green;
	int clear;
};
bin bin1, bin2, bin3;

int findTotalMovements(string str){
	int total = 0;
	
	if (str[0] == 'B') total += bin2.brown + bin3.brown; 
	else if (str[0] == 'G') total += bin2.green + bin3.green; 
	else if (str[0] == 'C') total += bin2.clear + bin3.clear;
	
	if (str[1] == 'B') total += bin1.brown + bin3.brown;
	else if (str[1] == 'G') total += bin1.green + bin3.green;
	else if (str[1] == 'C') total += bin1.clear + bin3.clear;
	
	if (str[2] == 'B') total += bin2.brown + bin1.brown;
	else if (str[2] == 'G') total += bin2.green + bin1.green;
	else if (str[2] == 'C') total += bin2.clear + bin1.clear;
	
	return total;
}

void main(int argc, char** argv) {
	for (int i = 0; i < 9; i++) {
		switch (i){
		case(0) :
			cin >> bin1.brown;
			break;
		case(1) :
			cin >> bin1.green;
			break;
		case(2) :
			cin >> bin1.clear;
			break;
		case(3) :
			cin >> bin2.brown;
			break;
		case(4) :
			cin >> bin2.green;
			break;
		case(5) :
			cin >> bin2.clear;
			break;
		case(6) :
			cin >> bin3.brown;
			break;
		case(7) :
			cin >> bin3.green;
			break;
		case(8) :
			cin >> bin3.clear;
			break;
		}
	}
	int minTotal = 1000000;
	string minConfiguration;
	string configuration;
	for (int i = 0; i < 6; i++) {
		int total;
		switch (i) {
		case(0) :
			configuration = "BGC";
			total = findTotalMovements(configuration);
			cout << total << endl;
			break;
		case(1) :
			configuration = "BCG";
			total = findTotalMovements(configuration);
			cout << total << endl;
			break;
		case(2) :
			configuration = "GBC";
			total = findTotalMovements(configuration);
			cout << total << endl;
			break;
		case(3) :
			configuration = "GCB";
			total = findTotalMovements(configuration);
			cout << total << endl;
			break;
		case(4) :
			configuration = "CBG";
			total = findTotalMovements(configuration);
			cout << total << endl;
			break;
		case(5) :
			configuration = "CGB";
			total = findTotalMovements(configuration);
			cout << total << endl;
			break;
		}
		if (total < minTotal){
			minTotal = total;
			minConfiguration = configuration;
		}
	}
	cout << minTotal << " " << minConfiguration << endl;
}
