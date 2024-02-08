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
    for (int i = 0; i < monkeys1; i++){
        int temp;
        cin >> temp;
        monkey1_find.push_back(temp);
        cin >> temp;
        monkey1_pick.push_back(temp);
    }
    cin >> monkeys2;
    vector<long long> monkey2_find;
    vector<long long> monkey2_break;
    for (int i = 0; i < monkeys2; i++){
        int temp;
        cin >> temp;
        monkey2_find.push_back(temp);
        cin >> temp;
        monkey2_break.push_back(temp);
    }
    long long min = 1;
    long long max = time; 
    bool tooSmall = false;
    long long mid = -1;
    long long maxtime = 0;
    while (min < max) {
        mid = (min + max + 1) / 2;
        long long coconuts = 0;
        tooSmall = false;
        for (int i = 0; i < monkey1_find.size(); i++) {
            if (mid >= monkey1_find[i]){
                coconuts++; // initial coconut found immidiently after picking tree spot
                coconuts += (mid - monkey1_find[i]) / monkey1_pick[i];
            }
        }
        long long leftoverTime = time - mid;
        for (int i = 0; i < monkey2_find.size(); i++) {
            if (leftoverTime >= monkey2_find[i]) {
                coconuts--;
                coconuts -= (leftoverTime - monkey2_find[i]) / monkey2_break[i];
            }
        }
        if (coconuts > 0) {
            // need less initial time
            max = mid - 1;
        } else  {
            min = mid;
        }
    }
    cout << min << "\n";
    return 0;
}