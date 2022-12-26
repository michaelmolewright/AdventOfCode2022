#include <cstdio>
#include <iostream>
#include <vector>
#include "elf.hpp"
#include "dataprep.hpp"

using namespace std;

vector<elf> elfs;

vector< vector<bool> > processRound(vector< vector<bool> > map1){
    for(int j = 0; j < elfs.size(); j++){
        elfs[j].checkDir(map1);
    }
    
    bool same = false;
    for(int i = 0; i < elfs.size(); i++){
        same = false;
        for(int j = 0; j < elfs.size(); j++){
            if(j != i){
                if ( elfs[i].proposedLoc.x == elfs[j].proposedLoc.x && elfs[i].proposedLoc.y == elfs[j].proposedLoc.y ){
                    same = true;
                }
            }
        }
        if(same == false){
            map1[elfs[i].loc.y][elfs[i].loc.x] = false;
            elfs[i].loc = elfs[i].proposedLoc;
            map1[elfs[i].loc.y][elfs[i].loc.x] = true;
        }
    }
    return map1;
}

void printMap(vector< vector<bool> > map){
    printf("\n");
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j]){
                printf("#");
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
}

int main(){

    elfs = parseData("data.txt");

    vector< vector<bool> > map = initialMap;

    

    bool noMove = true;
    int count = 0;
    while(noMove){
        vector< vector<bool> > perviousMap = map;
        map = processRound(perviousMap);
        if(map == perviousMap){
            noMove = false;
        }
        count += 1;
        if(count == 9){
            noMove = false;
        }
        printf("iteration %d -------\n", count);
    }
   


    int smallestX, smallestY, largestX, largestY;
    smallestX = elfs[0].loc.x;
    largestX = elfs[0].loc.x;
    smallestY = elfs[0].loc.y;
    largestY = elfs[0].loc.y;

    for(int i = 1; i < elfs.size(); i++)
    {
        if(elfs[i].loc.x < smallestX)
            smallestX = elfs[i].loc.x;
        if(elfs[i].loc.x > largestX)
            largestX = elfs[i].loc.x;
        if(elfs[i].loc.y < smallestY)
            smallestY = elfs[i].loc.y;
        if(elfs[i].loc.y > largestY)
            largestY = elfs[i].loc.y;
    }

    int width = largestX - smallestX;
    int height = largestY - smallestY;

    int rect = (width+1) * (height+1);

    int result = rect - elfs.size();

    printf("%d, %d, %d, %d", result, width, height, count);



    
    
    
    
    return 0;
}
