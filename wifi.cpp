// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        double points, houses;
        cin >> points;
        cin >> houses;
        vector<double> houseNum;
        for (double k = 0; k < houses; k++){
            double temp;
            cin >> temp;
            houseNum.push_back(temp);
        }
        sort(houseNum.begin(), houseNum.end());
        double min = 0.0;
        double max = houseNum[houseNum.size() - 1];
        // we only care about the max distance, so we start with the biggest distance and 
        // see if we can cover enough houses with it
        while (max > min) {
            double mid = (max + min) / 2.0;
            // given ^ distance from the access point, how many houses can NOT be reached?
            double housesNotCovered = 0;
            double dis = houseNum[0] + mid; // assume we place the access point x distance form the very first house
            for (double k = 1; k < houses; k++){
                // if it is not covered, count
                if ((houseNum[k] - dis) > mid) {
                    housesNotCovered++;
                    // set a new access point at the house not reached
                    dis = houseNum[k] + mid; 
                }
                // since it can be reached at curr dis, we move on because there is the possibility of
                // finding other houses reachable at this dis
            }
            // if we cover less houses than points we have, we need a smaller distance
            if (housesNotCovered <= points) {
                max = mid;
            } else {
                // if we cover need more points to cover the houses, we need bigger distance
                min = mid;
            }
        }
        cout << fixed;
        cout.precision(1);
        // should converge at an answer
        cout << max << "\n";
    }
    return 0;
}