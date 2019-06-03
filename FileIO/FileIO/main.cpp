//
//  main.cpp
//  FileIO
//
//  Created by Thomas Briggs on 23/10/2017.
//  Copyright © 2017 Thomas Briggs. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write(){
    ofstream myfile;
    myfile.open("example.txt", ios::app);
    myfile << "Writing this to a text file.\n";
    myfile.close();
}

void read(){
    string line;
    ifstream myfile;
    myfile.open("example.txt");
    while (getline(myfile,line)){
        cout << line << endl;
    }
    myfile.close();
}

void empty(){
    ofstream myfile;
    myfile.open("example.txt");
    myfile.close();
}

int main(){
    empty();
    return 0;
}
