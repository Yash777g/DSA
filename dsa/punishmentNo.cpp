#include <iostream>
#include <vector>
using namespace std;

bool canPartition(int num, int target) {
    if (target < 0 || num < 0) return false;
    if (num == target) return true;
    
    return (num >= 10 && canPartition(num / 10, target - num % 10)) || (num >= 100 && canPartition(num / 100, target - num % 100)) || (num >= 1000 && canPartition(num / 1000, target - num % 1000));
}

int punishmentNumber(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        int sq = i * i;
        if (canPartition(sq, i)) {
            sum += sq;
        }
    }
    return sum;
}

 
/* int punishmentNumber(int n) {
    int sum = 0;        
    vector<int> nums = {1,9,10,36,45,55,82,91,99,100,235,297,369,370,379,414,657,675,703,756,792,909,918,945,964,990,991,999,1000};

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] <= n) {
            sum += nums[i]*nums[i];
        }
    }
    return sum;
}*/

int main() {
    cout << punishmentNumber(37);
    return 0;
}