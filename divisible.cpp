// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    for (n; n > 0; n--) {
        long long div, len, count;
        count = 0;
        cin >> div;
        cin >> len;
        long long currSum = 0;
        vector<long long> remainder;
        // initialize array with 0s
        for (long long i = 0; i < div; i++) {
            remainder.push_back(0);
        }
        // if the remainder is exact (aka mod == 0)
        remainder[0] = 1;
        for (long long i = 0; i < len; i++) {
            long long temp;
            cin >> temp;
            // track the sum of all the values we have seen so far
            currSum += temp;
            // get the remainder of the current sum
            // remainder of the target subarray will be the same as the remainder of this larger "subarray"
            temp = currSum % div;
            if (temp < 0) { // just in case, if its negative
                temp += div; 
                // only add once, since we divided its guarenteed to be smaller than div
            }
            // add up how many remainders we got so far
            count += remainder[temp];
            // increment to track how many of said remainder we get
            remainder[temp]++;
        }
        cout << count << "\n";
    }
    return 0;
}