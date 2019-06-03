//
//  main.cpp
//  Test
//
//  Created by Thomas Briggs on 23/10/2017.
//  Copyright © 2017 Thomas Briggs. All rights reserved.
//

#include <iostream>
#include <array>
using namespace std;

bool linSearch(int input[], int target, int length){
    for (int i = 0; i < length; i++){
        if (input[i] == target){
            return true;
        }
    }
    
    return false;
    
}

int main() {
    int findme[] = {1, 7, 3, 7, 2, 8, 2, 5, 2, 6};
    cout << linSearch(findme, 99, sizeof(findme)/sizeof(findme[0])) << endl;
    
    char a[] = {'h'};
    cout << a << endl;
    
    return 0;
}
