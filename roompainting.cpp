// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

long long getObs(vector<long long> obs, long long n, long long search);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long paintCanSizeN, colorNeededN;
    cin >> paintCanSizeN; // how many sizes there are
    cin >> colorNeededN; // how many colors are needed

    vector<long long> paintCanSize; // store all the paint can sizes
    for (long long i = 0; i < paintCanSizeN; i++){
        long long temp;
        cin >> temp;
        paintCanSize.push_back(temp);
    }

    vector<long long> colorNeeded; // store the amount of colors needed
    for (int i = 0; i < colorNeededN; i++){
        int temp = 0;
        cin >> temp;
        colorNeeded.push_back(temp);
    }
//  sort the can sizes, no need to sort the color amounts
    sort(paintCanSize.begin(), paintCanSize.end());

    // binary search the can sizes for every color needed
    long long waste = 0;
    for (long long i = 0; i < colorNeeded.size(); i++){
        long long high = paintCanSize.size() - 1;
        long long low = 0;
        long long mid = 0;
        while (high >= low) {
            mid = (high + low) / 2;
            if (paintCanSize[mid] > colorNeeded[i]){
                // change high
                high = mid - 1;
            } else if (paintCanSize[mid] < colorNeeded[i]){
                // change low
                low = mid + 1;
            } else{
                // equal too
                break;
            }
        }
        // because we want more paint than less, if we find a can that it less than, 
        // we choose the next biggest can
        if (paintCanSize[mid] < colorNeeded[i]){
            mid++;
        }
        // add the difference between the can size and how much paint we actually need
        waste += paintCanSize[mid] - colorNeeded[i];
    }
    cout << waste << "\n";
    return 0;
}