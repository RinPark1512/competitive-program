// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //use long long to avoid overflow
    long long mongers, n;
    vector<long long> fish; // tracks the weight of the fish we have
    vector<long long> monies; // tracks the price per kilo each monger will pay
    long long howmany[100001]; // array to map price to how many fish we can sell at each price
    long long fishLimit = 0; // variable to track the total number of fish we can sell

    // initialize array
    for (long long i = 0; i < 100001; i++){
        howmany[i] = 0;
    }

    cin >> n;
    cin >> mongers;
    for (long long i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        fish.push_back(temp);
    }
    // sort fish weight
    sort(fish.begin(), fish.end());
    for (long long i = 0; i < mongers; i++){
        long long amount, monie;
        cin >> amount;
        cin >> monie;
        monies.push_back(monie); // track the highest val
        howmany[monie] += amount; // only track how many fish we can sell at that amount
        fishLimit += amount;
    }
    // sort price per kilo
    sort(monies.begin(), monies.end());
    long long bank = 0;
    while(fish.size() > 0 && monies.size() > 0 && fishLimit > 0){
        // get highest price
        long long price = monies[monies.size() - 1];
        monies.pop_back();
        // get how many fish we can sell
        long long fishToSell = howmany[price];
        for (long long i = fishToSell; i > 0 && fish.size() > 0 && fishLimit > 0; i--){
            // get fish weight
            long long kilo = fish[fish.size() - 1];
            fish.pop_back();
            bank += kilo * price;
            // decrement how many fish we can sell at said price
            howmany[price]--;
            // since we sold a fish, decrement the total amount of fish we can sell
            fishLimit--;
        }
    }
    cout << bank << "\n";
    return 0;
}