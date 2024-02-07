// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    int capacity;
    cin >> n;
    cin >>capacity;

    int dis, mailAmount;
    // Store the distances into 2 arrays, one for positive distances, the other for negative
    // the arrays are in the index of the distance to map distances to letters
    // for example, location at distance 2 that needs 100 letters, disToLetterPos[2] = 100
    int disToLetterPos[1501]; // distances are unique
    int disToLetterNeg[1501]; // distances are unique

    vector<int> distancePos;
    vector<int> distanceNeg;

    for (int i = 0; i < n; i++){
        cin >> dis;
        cin >> mailAmount;
        if (dis < 0){
            // even if its negative, it is calculated the same so store its abs value
            dis = abs(dis);
            disToLetterNeg[dis] = mailAmount;
            distanceNeg.push_back(dis);
        } else{
            disToLetterPos[dis] = mailAmount;
            distancePos.push_back(dis);
        }
    }
    sort(distanceNeg.begin(), distanceNeg.end());
    sort(distancePos.begin(), distancePos.end());
    int total = 0;
    int diff = capacity;
    // do this for each positive/negative array
    while (distanceNeg.size() > 0) {
        // if we are starting with the max letters, it means we have visited the post office
        // and have traveled to the farthest distance
        if (diff == capacity) {
            // takes into account the distance traveled to and from the location
            // if traveled to the farthest location, then the way back will be the farthest distance, 
            // as we can deliver letters to other locations along the way
            total += distanceNeg.back() * 2; 
        }
        diff -= disToLetterNeg[distanceNeg.back()];
        if (diff < 0) {
            // if negative, we need more letters, so travel back
            disToLetterNeg[distanceNeg.back()] = abs(diff); // the letters we still need to deliver
            diff = capacity; // restock letters
        } else if (dis > 0) {
            distanceNeg.pop_back(); // successfully delivered everything, we don't need the location
        } else{
            distanceNeg.pop_back();
            diff = capacity; // if we delivered the exact amount, restock
        }
    }

    // see above
    diff = capacity;
    while (distancePos.size() > 0) {
        if (diff == capacity){
            total += distancePos.back() * 2;
        }
        diff -= disToLetterPos[distancePos.back()];
        if (diff < 0){
            disToLetterPos[distancePos.back()] = abs(diff);
            diff = capacity;
        } else if (dis > 0){
            distancePos.pop_back();
        } else{
            distancePos.pop_back();
            diff = capacity;
        }
    }
    cout << total << "\n";
    return 0;
}