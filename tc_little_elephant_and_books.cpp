#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;


/*
Easy solution is to just sort pages array and return sum from 0...number, excluding number-1 in the sum..
This is O(nlogn) algorithm.
Better solution is to use Selection algorithm. Selection algorithm finds the kth smallest number in an array.
So, just use Selection algorithm to select number_th smallest number. Selection sort runs in O(n) time.
Then, go through the array, and each time you encounter a number smaller number than the number_th smallest number, add it to an
accumulated sum. Return the accumulated sum.
Total running time is O(n).
This problem basically is a variant of finding the kth smallest element in an array.
*/

int Partition(vector<int>& v, int pivot){

    int pivotElem = v.at(pivot);
    int i = -1;

    for(int j = 0; j < v.size(); j++){
        if(v.at(j) <= pivotElem){
            i++;
            swap(v.at(i), v.at(j));
        }
    }
    
    int j = 0;
    for(j = 0; j < v.size(); j++){
        if(v.at(j) == pivotElem)
            break;
    }

    swap(v.at(j), v.at(i));
   
    for(int i = 0; i < v.size(); i++){
        cout << v.at(i) << endl;
    }
    return i;
}


int LittleElephantAndBooks(vector<int> pages, int number){

    Partition(pages, number-1);
    int sum = 0;
    int i = 0;

    for(i = 0; i < pages.size(); i++){
        if(pages.at(i) < pages.at(number-1)){
            sum += pages.at(i);
        }
    }
    vector<int> pages2;
    for(int j = number; j < pages.size(); ++j){
        pages2.push_back(pages.at(j));
    }
    Partition(pages2, 0);
    sum += pages2.at(0);
    cout << "SUM " << sum << endl;
    return 0;
}




int main(){

    vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(9);
    v.push_back(7);
    v.push_back(2);
    v.push_back(8);
    v.push_back(6);
    v.push_back(4);
    v.push_back(5);
    LittleElephantAndBooks(v, 7);
   
    system("PAUSE");
    return 0;
}
