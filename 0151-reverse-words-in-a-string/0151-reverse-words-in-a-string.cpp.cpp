/*
Problem: Reverse Words in a String

Approach:
- Reverse entire string
- Traverse string and extract words
- Reverse each word individually
- Ignore extra spaces
- Build final answer

Time: O(n)
Space: O(n)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {

    int n = s.length();

    // Reverse whole string
    reverse(s.begin(), s.end());

    string ans = "";

    for(int i = 0; i < n; i++) {

        string word = "";

        // Extract word
        while(i < n && s[i] != ' ') {

            word += s[i];
            i++;
        }

        // Reverse current word
        reverse(word.begin(), word.end());

        // Ignore extra spaces
        if(word.length() > 0) {

            ans += " " + word;
        }
    }

    // Remove leading space
    return ans.substr(1);
}