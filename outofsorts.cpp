// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, a, c, init;
//  next x = (a * prev + c) mod m
    cin >> n;
    cin >> m;
    cin >> a;
    cin >> c;
    cin >> init; // initial value in the sequence
    vector<long long> seq;
    // dont push initial value; not needed in the sequence
    // instead push the 2nd value to start off the sequence
    seq.push_back(((a * init) + c) % m);
    for (long long i = 0; i < n - 1; i++) {
        seq.push_back(((a * seq[i]) + c) % m);
    }
    long long found = 0;
    for (long long i = 0; i < seq.size(); i++) {
        long long high = seq.size() - 1;
        long long low = 0;
        // binary search, find it in the index its suppose to be
        while (high >= low) {
            // calculate the middle
            long long mid = (high + low) / 2;
            if (seq[mid] > seq[i]) {
                // change to search high
                high = mid - 1;
            } else if (seq[mid] < seq[i]) {
                // change to search low
                low = mid + 1;
            } else {
                // equal too, increment and break
                found++;
                break;
            }
        }
    }
    cout << found << "\n";

    return 0;
}