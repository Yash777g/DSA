#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    vector<int> ans;
    unordered_map<int, int> mapping;
    unordered_map<int, int> colors;
    int distinct = 0;

    for(auto i: queries) {
        int ball = i[0];
        int color = i[1];

        if (mapping.count(ball)) {
            int oldColor = mapping[ball];
            colors[oldColor]--;
            if (colors[oldColor] == 0) {
                distinct--;
            }
        }

        mapping[ball] = color;
        
        if(colors[color] == 0) {
            distinct++;
        } colors[color]++;
        
        ans.push_back(distinct);
    } return ans;
}

int main() {
    vector<vector<int>> queries = {{0,1},{1,2},{2,2},{3,4},{4,5}};
    vector<int> result = queryResults(4, queries);

    for(auto i: result) {
        cout << i << " ";
    }
    return 0;
}