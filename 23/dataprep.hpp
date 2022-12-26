#ifndef DATAPREP_GUARD
#define DATAPREP_GUARD

#include <fstream>
#include <vector>
#include <iostream>
#include "elf.hpp"

using namespace std;

vector< vector<bool> > initialMap;

vector<elf> parseData(string file){
    
    fstream fileStream;

    vector<elf> elfs;

    fileStream.open(file);
    
    int extra = 32;
    int xCount = extra;
    int yCount = extra;  

    string tp;
    while( getline(fileStream, tp) ) {
        vector<bool> newLine;
        for(char& c : tp) {
            if (c == '#'){
                elfs.push_back(elf(xCount, yCount));
                newLine.push_back(true);
            }
            else if (c == '.'){
                newLine.push_back(false);
            }
            xCount += 1;
        }
        initialMap.push_back(newLine);
        yCount += 1;
        xCount = extra;
        cout << tp << "\n"; //print the data of the string
    }


    for(int i = 0; i < initialMap.size(); i++){
        for(int j = 0; j < extra; j++){
            initialMap[i].push_back(false);
            initialMap[i].push_back(false);
            initialMap[i].insert(initialMap[i].begin(), false);
        }
    }

    
    vector<bool> top;

    for(int i = 0; i < initialMap[0].size(); i++){
        top.push_back(false);
    }

    for(int i = 0; i < extra; i++){
        initialMap.push_back(top);
        initialMap.push_back(top);
        initialMap.insert(initialMap.begin(), top);
    }



    fileStream.close();
    return elfs;
}  


#endif