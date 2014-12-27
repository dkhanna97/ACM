#include <iostream>
using namespace std;

//Compute how many times the 13th of every month falls under each day of the week from the year 1900 to (1900 + N-1),
//where N is input given by user

int days[7];
int N;

//Given a starting day of the month (0-6 for Sun-Sat), find the day the thirteenth falls under
int Find_Date(int day){
    return ((day + 12) % 7);
}

bool IsLeapYear(int year){

	if(year % 100 == 0){
		if(year % 400 == 0) return true;
		return false;
	}
	if(year % 4 == 0) return true;
	return false;
}

void FridayTheThirteenth(){
	int curday = 1;
	++days[1];
	curday += 31;
	for(int i = 0; i < N; ++i){
		int year = 1900+i;
		for(int j = 1; j <= 12; ++j){
			if(j == 1 && year == 1900) continue;
			++days[Find_Date(curday % 7)];			
			switch(j){
			case 2:
				if(IsLeapYear(year)) curday += 29;
				else curday += 28;
				break;
			case 1: //January
			case 3: //March
			case 5: //May
			case 7: //July
			case 8: //August
			case 10: //October
			case 12: //December
				curday +=31;
				break;
			default:
				curday += 30;
				break;
			}		
		}
	}
}

int main(){

	cin >>  N;
	for(int i = 0; i < 7; ++i) days[i] = 0;
	FridayTheThirteenth();
	cout << days[6] << " " << days[0] << " " << days[1] 
	<< " " << days[2] << " " << days[3] << " " << days[4] 
	<< " " << days[5] << endl;

	return 0;
}
