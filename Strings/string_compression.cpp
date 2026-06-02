/*
Problem: String Compression

Approach:
- Traverse string using pointer i
- Count frequency of consecutive characters
- Store character once
- Store count if greater than 1
- Use index pointer to modify array in-place

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars) {

    int n = chars.size();

    int idx = 0;
    int i = 0;

    while(i < n) {

        char current = chars[i];
        int count = 0;

        // Count consecutive characters
        while(i < n && chars[i] == current) {

            count++;
            i++;
        }

        // Store character
        chars[idx++] = current;

        // Store frequency if > 1
        if(count > 1) {

            string freq = to_string(count);

            for(char ch : freq) {
                chars[idx++] = ch;
            }
        }
    }

    return idx;
}