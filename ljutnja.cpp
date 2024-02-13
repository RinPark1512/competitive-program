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
    for (long long i = 0; i < children; i++){
        long long temp;
        cin >> temp;
        greed.push_back(temp);
    }
    sort(greed.begin(), greed.end());
    long long min = 0;
    long long max = greed[greed.size() - 1];
    long long noCandy, trackCandy, maxNoCan;
    long long maxCan = max;
    maxNoCan = max;
    // how many candy we can not give the children
    while (min < max) {
        noCandy = (min + max) / 2;
        trackCandy = 0;
        for (long long i = 0; i < greed.size(); i++){
            if (greed[i] > noCandy) {
                trackCandy += greed[i] - noCandy;
            }
        }
        if (trackCandy > candy) {
            //give less
            min = noCandy + 1;
        } else {
            // give more
            if (maxNoCan > noCandy){
                maxCan = trackCandy;
                maxNoCan = noCandy;
            }
            max = noCandy;
        }
    }
    long long diff = candy - maxCan;
    long long anger = 0;
    for (long long g= 0; g < greed.size(); g++){
        if (greed[g] > maxNoCan) {
            greed[g] = maxNoCan;
        }            
    }
    if (diff != 0) {
        long long ind = greed.size() - 1;
        while (diff > 0){
            if (ind < 0){
                ind = greed.size() - 1;
            }
            if (greed[ind] != 0){
                greed[ind]--;
                diff--;
            }
            ind--;
        }
    }
    for (long long g= 0; g < greed.size(); g++){
        anger += (greed[g] * greed[g]);  
    }
    cout << anger << "\n";
    return 0;
}