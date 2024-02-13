// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int time;
    cin >> time;
    int monkeys1, monkeys2;
    cin >> monkeys1;
    vector<long long> monkey1_find;
    vector<long long> monkey1_pick;
    for (int i = 0; i < monkeys1; i++) {
        int temp;
        cin >> temp;
        // theres no need to sort the values, so we can map them via index
        monkey1_find.push_back(temp);
        cin >> temp;
        monkey1_pick.push_back(temp);
    }
    cin >> monkeys2;
    vector<long long> monkey2_find;
    vector<long long> monkey2_break;
    for (int i = 0; i < monkeys2; i++) {
        int temp;
        cin >> temp;
        monkey2_find.push_back(temp);
        cin >> temp;
        monkey2_break.push_back(temp);
    }
    // there can be a minimum of 1 coconut picked/cracked
    long long min = 1;
    // there can be a max of n (time, if the time to pick/crack is 1 second) coconuts picked/cracked
    long long max = time; 
    long long mid;
    while (min < max) {
        // binary search
        mid = (min + max + 1) / 2;
        long long coconuts = 0;
        // calculate how many coconuts can be picked
        for (int i = 0; i < monkey1_find.size(); i++) {
            if (mid >= monkey1_find[i]) {
                coconuts++; // initial coconut found immidiently after picking tree spot
                coconuts += (mid - monkey1_find[i]) / monkey1_pick[i]; // coconuts picked after spot found 
            }
        }
        // if the picking monkeys took x amount of time, then the cracking monkeys take up the remainder time
        long long leftoverTime = time - mid; 
        for (int i = 0; i < monkey2_find.size(); i++) {
            if (leftoverTime >= monkey2_find[i]) {
                coconuts--; // initial coconut cracked open immidiently after finding a tool
                coconuts -= (leftoverTime - monkey2_find[i]) / monkey2_break[i]; // coconuts cracked after tool found
            }
        }
        if (coconuts > 0) {
            // means more coconuts have been picked than can be cracked
            // need less initial time aka less coconuts picked
            max = mid - 1;
        } else  {
            // possible answer
            // means more coconuts cracked than picked
            // need more initial time aka more coconuts picked
            min = mid;
        }
    }
    // should converge at an answer, so can use either max/min
    cout << min << "\n";
    return 0;
}