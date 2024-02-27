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
    long long n, m, c;
    bool output = false;
    cin >> n;
    cin >> m; // length of silence
    cin >> c; // level/ difference
    vector<long long> samples;
    for (long long i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        samples.push_back(temp);
    }
    long long minInd = 0;
    long long maxInd = 0;
    for (long long i = 1; i < m; i++) {
        // find max/min in initial set
        if (samples[i] < samples[minInd]) {
            minInd = i;
        } else if (samples[i] > samples[maxInd]) {
            maxInd = i;
        }
    }
    for (long long i = 0; i <= (n - m); i++) {
        // if we left curr min/max, find new min/max
        // else, consider wat we just found
        if (minInd < i || maxInd < i){
            if (minInd < i) {
                minInd = i;
                // find new min
                for (long long k = i; k < (i + m); k++){
                    if (samples[k] < samples[minInd]){
                        minInd = k;
                    }
                }
            }
            if (maxInd < i) {
                // find new max
                maxInd = i;
                for (long long k = i; k < (i + m); k++){
                    if (samples[k] > samples[maxInd]){
                        maxInd = k;
                    }
                }
            }
        }
            // consider new
            // cout << samples[i + m - 1] << "\n";
            if (samples[i + m - 1] < samples[minInd]) {
                minInd = i + m - 1;
            } else if (samples[i + m - 1] > samples[maxInd]){
                maxInd = i + m - 1;
            }
        // }
        // calculate diff
        // cout << maxInd << " " << minInd << "\n";
        if (abs(samples[maxInd] - samples[minInd]) <= c) {
            output = true;
            cout << (minInd + 1) << "\n";
        }
    }
    if (!output) {
        cout << "NONE\n";
    }
    return 0;
}