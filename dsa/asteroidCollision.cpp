#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    vector<int>::iterator it = asteroids.begin();

    for(auto &asteroid : asteroids) {
        bool destroyed = false;

        while (!ans.empty() && asteroid < 0 && ans.back() > 0) {
            if (abs(asteroid) > ans.back()) {
                ans.pop_back(); 
            } else if (abs(asteroid) == ans.back()) {
                ans.pop_back();
                destroyed = true;
                break;
            } else {
                destroyed = true;
                break;
            }
        }

        if (!destroyed) {
            ans.push_back(asteroid);
        }
    }
  
    return ans;
}

int main() {
    vector<int> asteroids = {5,10,-5};
    vector<int> result = asteroidCollision(asteroids);

    for(auto &i : result) {
        cout << i << " ";
    }
    return 0;
}