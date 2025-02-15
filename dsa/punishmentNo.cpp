#include <iostream>
#include <vector>
using namespace std;

int punishmentNumber(int n) {
    int sum = 0;        
    vector<int> nums = {1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000};

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] <= n) {
            sum += nums[i]*nums[i];
        }
    }
    return sum;
}

int main() {
    cout << punishmentNumber(37);
    return 0;
}