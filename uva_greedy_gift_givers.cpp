#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=55

int main(){

    int numFriends;
    string friends[10];
    int money[10];
    
    ifstream input;
    ofstream output;
    input.open("gift1.in");
    input >> numFriends;

    for(int i = 0; i < numFriends; ++i) {
        input >> friends[i];
        money[i] = 0;
    }
    for(int i = 0; i < numFriends; ++i) {
        string curFriend;
        int curFriendTotalGivingAmount;
        int numReceivingFriends;
        int receivingAmount = 0;

        input >> curFriend;
        input >> curFriendTotalGivingAmount;
        input >> numReceivingFriends;
        int j = 0;
        for(j = 0; j < numFriends; ++j){
            if(friends[j] == curFriend)
                break;
        }

        if(numReceivingFriends != 0) 
            receivingAmount = floor(curFriendTotalGivingAmount / numReceivingFriends);
        
        money[j] -= curFriendTotalGivingAmount;
        money[j] += curFriendTotalGivingAmount - (receivingAmount * numReceivingFriends);

        for(int i = 0; i < numReceivingFriends; ++i){
            string receivingFriend;
            input >> receivingFriend;
            for(j = 0; j < numFriends; ++j){
                if(friends[j] == receivingFriend)
					break;  
            }
            money[j] += receivingAmount;  
        }
        
    }

    output.open("gift1.out");
    for(int i = 0; i < numFriends; ++i) output << friends[i] << " " << money[i] << endl;
    
    input.close();
    output.close();
    return 0;
}
