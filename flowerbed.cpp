#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for(int i = 0; i < flowerbed.size(); i = i+2) {
        if(n == 0) 
            return true;

        if((i == 0 && flowerbed[i] == 0) && flowerbed[i + 1] == 0) {
            n--;
        } else if((i == flowerbed.size() - 1 && flowerbed[i] == 0) && flowerbed[i - 1] == 0) {
            n--;
        }else {
            if(flowerbed[i] == 0 && (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)) {
                n--;
            }
        }
    }

    if(n == 0) 
        return true;

    return false;
}

int main() {
    vector<int> flowerbed = {0,1,0};
    cout << canPlaceFlowers(flowerbed, 1);
    return 0;
}