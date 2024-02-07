// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, h;
    // get the length (n) and height (h) of the cave
    cin >> n;
    cin >> h;
    vector<long long> floor;
    vector<long long> ceil;

    for (long long i = 0; i <n; i++) {
        long long temp;
        cin >> temp;
        // split input to the obstacle on the ceiling vs the floor
        if (i % 2) {
            // odd ceiling
            ceil.push_back(temp);
        } else {
            // even floor
            floor.push_back(temp);
        }
    }
    // sort the obstacles by height
    // the order of the obstacles do not affect how many are hit at a certain height
    sort(floor.begin(), floor.end());
    sort(ceil.begin(), ceil.end());
//  n (length of cave) also doubles as the toal number of obstacles
    long long minObs = n;
    long long count = 0;
    
    for (long long i = 1; i <= h; i++) {
        long long sum = 0;
        long long left = 0;
        long long right = floor.size() - 1;
        long long mid;

        // find how many floor obs are hit
        while (left <= right) { // binary search
            mid = (left + right) / 2;
            if (floor[mid] > i) {
                right = mid - 1;
            } else if (floor[mid] < i) {
                left = mid + 1;
            } else{
                break;
            }
        }
        // what we find is the index the value is suppose to be
        // we don't know if the value is actually what we expect
        if (floor[mid] > i) {
            // if obs is taller, we are going to hit it
            // if repeats exist, we need to get to the end so we can count them all
            while (mid > 0 && floor[mid - 1] == floor[mid]) {
                mid--;
            }
        } else if (floor[mid] < i) {
            // if obs is shorter, we are not going to hit it, so it needs to be excluded
            // if repeats exist, we need to get to the end so we can exclude them all
            while (mid < (floor.size() - 1) && floor[mid + 1] == floor[mid]) {
                mid++;
            }
            mid++;
        } 
        else {
            // if repeats exist, we need to get to the end so we can count them all
            while (mid != 0 && floor[mid - 1] == floor[mid]) {
                mid--;
            }
        }
        // index represents how many obs we don't hit
        sum = floor.size() - (mid);

        // find how many ceiling obs are hit
        long long inverse = h - i + 1; // take inverse of height
        // ceiling heights are reverse of the actual heights
        // for example, a height 1 translates to height of 5 if measured from the ceiling
        left = 0;
        right = ceil.size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (ceil[mid] > inverse) {
                right = mid - 1;
            } else if (ceil[mid] < inverse) {
                left = mid + 1;
            } else{
                break;
            }
        }
        // same logic as mentioned above
        if (ceil[mid] > inverse) {
            while (mid > 0 && ceil[mid - 1] == ceil[mid]) {
                mid--;
            }
        } else if (ceil[mid] < inverse) {
            while (mid < (ceil.size() - 1) && ceil[mid + 1] == ceil[mid]) {
                mid++;
            }
                mid++;
        } else {
            while (mid != 0 && ceil[mid - 1] == ceil[mid]) {
                mid--;
            }
        }
        sum += ceil.size() - (mid);
        
        // find the minimum sum
        if (sum < minObs) {
            count = 1; // resent count
            minObs = sum;
        } else if (sum == minObs) {
            count++;
        }
    }
    cout << minObs << " " << count << "\n";
    return 0;
}