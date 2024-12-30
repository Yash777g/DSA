#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool closeStrings(string s, string p) {
    int n=s.size();
    int m=p.size();

    if(n!=m) return false;
    int arr[26]={0}, arr2[26]={0};
    for(int i=0;i<n;i++){
        arr[s[i]-'a']++;
        arr2[p[i]-'a']++;
    }
    unordered_map<int, int>mp1;
    for(int i=0;i<26;i++){
        if(arr[i]==0) continue;
        if(arr[i]==0&&arr2[i]!=0||arr[i]>0&&arr2[i]==0) return false;
        mp1[arr[i]]++;
    }
    for(int i=0;i<26;i++){
        if(arr2[i]==0) continue;
        if(mp1.find(arr2[i])==mp1.end()||mp1[arr2[i]]==0) return false;
        mp1[arr2[i]]--;
    }
    return true;
}

int main() {
    string a = "abbccc", b = "aaabbc";
    cout << closeStrings(a, b);
    return 0;
}