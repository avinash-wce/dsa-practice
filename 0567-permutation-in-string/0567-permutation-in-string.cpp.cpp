/* BRUTE FORCE
Problem: Permutation in String

Approach:
- Store frequency of characters of s1
- Check every substring of size s1.length() in s2
- Build frequency array for every window
- Compare both frequency arrays

Time: O(k * n)
Space: O(k)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> freq1(26, 0);

        // Store frequency of s1
        for(int i = 0; i < s1.length(); i++) {

            freq1[s1[i] - 'a']++;
        }

        // Check every possible window
        for(int i = 0; i + s1.length() <= s2.length(); i++) {

            vector<int> freq2(26, 0);

            int j = 0;
            int k = i;

            // Build frequency for current window
            while(j < s1.length() && k < s2.length()) {

                freq2[s2[k] - 'a']++;
                j++;
                k++;
            }

            bool same = true;

            // Compare frequencies
            for(int x = 0; x < 26; x++) {

                if(freq1[x] != freq2[x]) {

                    same = false;
                    break;
                }
            }

            // Permutation found
            if(same) {

                return true;
            }
        }

        return false;
    }
};


/* OPTIMAL SLIDING WINDOW APPROACH
Problem: Permutation in String

Approach:
- Store frequency of s1
- Maintain sliding window of size s1.length()
- Add incoming character
- Remove outgoing character
- Compare frequency arrays at each step

Time: O(n)
Space: O(k)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int k = s1.length();
        int n = s2.length();

        // Invalid case
        if(n < k) {

            return false;
        }

        vector<int> freq1(26, 0);

        // Frequency of s1
        for(int i = 0; i < k; i++) {

            freq1[s1[i] - 'a']++;
        }

        vector<int> freq2(26, 0);

        // Build first window
        for(int i = 0; i < k; i++) {

            freq2[s2[i] - 'a']++;
        }

        // Check first window
        if(freq1 == freq2) {

            return true;
        }

        // Sliding window
        for(int i = k; i < n; i++) {

            // Add incoming character
            freq2[s2[i] - 'a']++;

            // Remove outgoing character
            freq2[s2[i - k] - 'a']--;

            // Compare frequencies
            if(freq1 == freq2) {

                return true;
            }
        }

        return false;
    }
};