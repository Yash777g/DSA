#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int size = flowerbed.size();
    
    for (int i = 0; i < size; ++i) {
        if (n == 0) {
            return true; 
        }
        
        if (flowerbed[i] == 0) {
            bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0); 
            bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0); 
            
            if (leftEmpty && rightEmpty) {
                flowerbed[i] = 1; 
                --n;
                i++; 
            }
        }
    }
    
    return n == 0; 
}


int main() {
    vector<int> flowerbed = {0,1,0};
    cout << canPlaceFlowers(flowerbed, 1);
    return 0;
}