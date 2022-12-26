#ifndef ELF_GUARD
#define ELF_GUARD

#include <vector>

using namespace std;

struct vec2 {
    int x;
    int y;
};

class elf{
    public:
        vec2 loc;
        int checkFirst;
        vec2 proposedLoc;

        void updateLoc(vec2 newLoc);
        elf(int x, int y);
        void checkDir(vector< vector<bool> > map);
};

void elf::updateLoc(vec2 newLoc){
    loc = newLoc;
};

elf::elf(int x, int y){
    loc.x = x;
    loc.y = y;
    proposedLoc.x = x;
    proposedLoc.y = y;
    checkFirst = -1;
}

void elf::checkDir(vector< vector<bool> > map){
    checkFirst  += 1;

    if( !map[loc.y-1][loc.x-1] && !map[loc.y-1][loc.x] && 
        !map[loc.y-1][loc.x+1] && !map[loc.y][loc.x+1] &&
        !map[loc.y+1][loc.x+1] && !map[loc.y+1][loc.x] && 
        !map[loc.y+1][loc.x-1] && !map[loc.y][loc.x-1]){
            proposedLoc.x = loc.x;
            proposedLoc.y = loc.y;

            //checkFirst +=1;
            return;
    }
    
    for (int i = 0; i < 4; i++){
        if((checkFirst + i) % 4 == 0){
            if( map[loc.y-1][loc.x-1] == false && map[loc.y-1][loc.x] == false && map[loc.y-1][loc.x+1] == false ){
                proposedLoc.x = loc.x;
                proposedLoc.y = loc.y - 1;
                //checkFirst += 1;
                return;
            }
        }
        if((checkFirst + i) % 4 == 1){
            if( map[loc.y+1][loc.x-1] == false && map[loc.y+1][loc.x] == false && map[loc.y+1][loc.x+1] == false ){
                proposedLoc.x = loc.x;
                proposedLoc.y = loc.y + 1;
                //checkFirst += 1;
                return;
            }
        }
        if((checkFirst + i) % 4 == 2){
            if( map[loc.y+1][loc.x-1] == false && map[loc.y][loc.x-1] == false && map[loc.y-1][loc.x-1] == false ){
                proposedLoc.x = loc.x - 1;
                proposedLoc.y = loc.y;
                //checkFirst += 1;
                return;
            }
        }
        if((checkFirst + i) % 4 == 3){
            if( map[loc.y+1][loc.x+1] == false && map[loc.y][loc.x+1] == false && map[loc.y-1][loc.x+1] == false ){
                proposedLoc.x = loc.x + 1;
                proposedLoc.y = loc.y;
                //checkFirst += 1;
                return;
            }
        }
    }
    //checkFirst +=1;

}

#endif
