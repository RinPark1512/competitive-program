// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
int recur (vector<string> arr, vector<int> scores, int indexChar, int q);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    vector<long long> arr;
    vector<long long> track;
    long long max = 0;
    cin >> n;
    // the logic is to track the local max as we move -> up the array
    for (long long i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        arr.push_back(temp);
        // when we encounter a new max, it means we found a new possible pivot, so we push that into the tracking array
        // we dont need to constantly check the entire subarray when we encounter a new number
        // if the given number is greater than the current max, we can say with confidence that it is the greatest number of that subarray
        if (temp > max) {
            track.push_back(temp);
            max = temp;
        }
    }
    // same logic applies for finding the min as we move <- down the array
    long long min = arr[arr.size() - 1];
    // push back initial value
    track.push_back(arr[arr.size() -1]);
    for (long long i = (arr.size() -1); i >= 0; i--){
        // if we find a value smaller than the local min, we are confident that it is the absolute local min
        if (arr[i] < min){
            // keep track of it
            track.push_back(arr[i]);
            min = arr[i];
        }
    }
    // count the number of repeats
    // we can then see if there is overlap; if a value is both the max and min at some point, it is a pivot
    // as it was the local max and local min
    long long count = 0;
    sort(track.begin(), track.end());
    for (long long i = 0; i < (track.size() - 1); i++) {
        // if there are the same values in a row
        if (track[i] == track[i + 1]){
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}