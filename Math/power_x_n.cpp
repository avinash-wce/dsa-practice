/*
Problem: Pow(x, n)

Approach:
- Use Binary Exponentiation
- If n is even → (x * x)^(n/2)
- If n is odd → x * power(x, n-1)
- Handle negative powers

Time: O(log n)
Space: O(1)
*/

#include <iostream>
using namespace std;

double myPow(double x, int n) {
    long long binform = n;   // handle INT_MIN case
    if (binform < 0) { // Handle negative powers
        x = 1 / x;
        binform = -binform;
    }

    double ans = 1;

    while (binform > 0) {
        if (binform % 2 == 1) {
            ans *= x;
        }
        x *= x;
        binform /= 2;
    }

    return ans;
}