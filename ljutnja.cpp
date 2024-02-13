// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long children, candy;
    cin >> candy;
    cin >> children;
    vector<long long> greed;
    for (long long i = 0; i < children; i++) {
        long long temp;
        cin >> temp;
        greed.push_back(temp);
    }
    // sort greed/how many candy each children want
    sort(greed.begin(), greed.end());
    long long min = 0;
    long long max = greed[greed.size() - 1];
    long long noCandy, trackCandy, maxNoCan;
    // keep track of the most amount of candy we can give the children
    long long maxCan = max;
    // tracks the smallest amount we can withold from the children
    maxNoCan = max;
    while (min < max) {
        noCandy = (min + max) / 2; // choose how much to withhold from the children
        trackCandy = 0;
        for (long long i = 0; i < greed.size(); i++) {
            if (greed[i] > noCandy) {
                trackCandy += greed[i] - noCandy; // add together how much candy we give out
            }
        }
        if (trackCandy > candy) {
            // give less candy aka withhold more
            min = noCandy + 1;
        } else {
            if (maxNoCan > noCandy) { // track the smallest amount of candy we can withhold from the children
                maxCan = trackCandy; // if we found a smaller value, update
                maxNoCan = noCandy;
            }
            max = noCandy; // give more candy aka withhold less
        }
    }
    long long diff = candy - maxCan; // see if we have leftover candy
    long long anger = 0;
    for (long long g = 0; g < greed.size(); g++){
        if (greed[g] > maxNoCan) {
            greed[g] = maxNoCan; // give the children candy, track remaining greed
        }            
    }
    if (diff > 0) { // if we have leftover candy, distribute
        long long ind = greed.size() - 1; // start at the most greed
        while (diff > 0) { // while we still have candy to give out
            if (ind < 0) { 
                // if we hit the end, loop back around
                ind = greed.size() - 1;
            }
            // if we can, give candy one at a time
            if (greed[ind] > 0) {
                greed[ind]--;
                diff--;
            }
            ind--;
        }
    }
    // calculate total anger
    for (long long g = 0; g < greed.size(); g++) {
        anger += (greed[g] * greed[g]); // the Math function is weird, so we doing this manually
    }
    cout << anger << "\n";
    return 0;
}