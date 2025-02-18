#include <iostream>
#include <vector>
using namespace std;

string smallestNumber(string pattern) {
    vector<int> st;
    st.push_back(1); 
    string ans = "";
    int i = 2;

    for (auto ch : pattern) {
        if (ch == 'I') {
            while (!st.empty()) {
                ans += to_string(st.back());
                st.pop_back();
            }
            st.push_back(i++);
        } else if (ch == 'D') {
            st.push_back(i++);
        }
    }

    while (!st.empty()) {
        ans += to_string(st.back());
        st.pop_back();
    } return ans;
}

int main() {
    cout << smallestNumber("IIIDIDDD");
    return 0;
}