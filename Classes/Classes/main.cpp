//
//  main.cpp
//  Classes
//
//  Created by Thomas Briggs on 24/10/2017.
//  Copyright © 2017 Thomas Briggs. All rights reserved.
//

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

void bubbleSort(int inputArray[], int length){
    int i, j, temp;
    int n = length-1;
    for(i = 0; i < (n); i++){
        for(j = 0; j < (n-i); j++){
            if(inputArray[j] > inputArray[j+1]){
                temp = inputArray[j];
                inputArray[j] = inputArray[j+1];
                inputArray[j+1] = temp;
            }
        }
    }
}

void bubbleSortRec(int inputArray[], int n){
    if (n == 1){
        return;
    }
    for(int i = 0; i < n-1; i++){
        if(inputArray[i] > inputArray[i+1]){
            int temp = inputArray[i];
            inputArray[i] = inputArray[i+1];
            inputArray[i+1] = temp;
        }
    }
    bubbleSortRec(inputArray, n-1);
}

void insertionSort(int inputArray[], int length){
    int n;
    for(int i = 1; i < length; i++){
        n = i;
        while(inputArray[n] < inputArray[n-1] && n > 0){
            int temp = inputArray[n];
            inputArray[n] = inputArray[n-1];
            inputArray[n-1] = temp;
            n--;
        }
    }
}

int main() {

    int a[] = {9, 6, 0, 3, 8, 4, 5, 7, 1, 2};
    
    for(int i = 0; i < sizeof(a)/sizeof(a[0])-1; i++){
        cout << a[i] << ",";
    }
    cout << a[sizeof(a)/sizeof(a[0])-1] << endl;

    
    insertionSort(a, sizeof(a)/sizeof(a[0]));
    
    for(int i = 0; i < sizeof(a)/sizeof(a[0])-1; i++){
        cout << a[i] << ",";
    }
    cout << a[sizeof(a)/sizeof(a[0])-1] << endl;

    return 0;
}
