#include <iostream>
#include <string>
using namespace std;

int isPrefixOfWord(string sentence, string searchWord) {
    int count = 1;
    string match = "";

    for(int i = 0; i < sentence.size(); i++) {
        match += sentence[i];

        if(sentence[i] == ' ') {
            count++;
            match = "";
        }

        if(match == searchWord) {
            return count;
        }
    }
    return -1;
}

int main() {
    string sentence = "this problem is an easy problem";
    string searchWord = "tis";

    cout << isPrefixOfWord(sentence, searchWord);
    return 0;
}