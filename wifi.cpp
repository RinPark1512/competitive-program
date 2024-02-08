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
        // double p = houses / points;
        double min = 0.0;
        double max = houseNum[houseNum.size() - 1];
        // double maxDis = 0.0;
        // we only care abt the max distance, so we start with the biggest distance and 
        // see if we can cover enough houses with it
        while (min < max) {
            double mid = (max + min) / 2;
            // given ^ distance from the access point, how many houses can not be reached
            double housesNotCovered = 0;
            double pHouseInd = 0;
            for (double k = 1; k < houses; k++){
                // if it is not covered, count
                if ((houseNum[k] - houseNum[pHouseInd]) > mid) {
                    housesNotCovered++;
                    pHouseInd = k;
                }
                // since it can be reached at curr dis, we move on because there is the possibility of
                // finding other houses reachable at this dis
            }
            if (housesNotCovered >= points) {
                // maxDis = mid;
                min = mid;
            } else {
                max = mid - 1;
            }
        }
        // cout << 1.0 << " ";
        cout << fixed;
        cout.precision(1);
        cout << min << "\n";
    }
    
    return 0;
}