#include <iostream>
#include <vector>
#include <set>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int x = 0, y = 0;
    int maxDist = 0, direction = 1;
    set<pair<int,int>> obst;
        
    for(auto &obs : obstacles) { obst.insert({obs[0], obs[1]}); }

    for(auto &itr : obst) {
        cout << itr.first << "," << itr.second << endl;
    }

    for(auto &command : commands) {
        
        if(command == -1){
            direction = (direction+1) % 5;
            if(direction == 0) { direction = 1; }
        }
        
        else if(command == -2) {
            direction = (direction-1);
            if(direction == 0) { direction = 4; }
        }
        
        else {
            int distance = command;
            
            while(distance > 0) {
                if(direction == 1) {
                    if(obst.find({x, y + 1}) != obst.end()) break;
                    y++;
                }
                    
                else if(direction == 2) {
                    if(obst.find({x + 1, y}) != obst.end()) break;
                    x++;
                }
                    
                else if(direction == 3) {
                    if(obst.find({x, y - 1}) != obst.end()) break;
                    y--;
                }
                    
                else {
                    if(obst.find({x - 1, y}) != obst.end()) break;
                    x--;
                }

                maxDist = max(maxDist, x*x + y*y);
                distance--;
            }
        }
    }
    
    return maxDist;
}

int main() {
    vector<int> commands = {9,-1,9,-2,3};
    vector<vector<int>> obstacles = {{4,8}, {5,6}, {7,7}, {8,4}};

    int sol = robotSim(commands, obstacles);

    return 0;
}
