// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long children, candy;
    cin >> candy;
    cin >> children;
    vector<long long> greed;
    for (int i = 0; i < children; i++){
        int temp;
        cin >> temp;
        greed.push_back(temp);
    }
    sort(greed.begin(), greed.end());
    while (candy > 0){
        candy -= greed[greed.size() - 1];
        if (candy >= 0) {
            greed.pop_back();
        } else {
            greed[greed.size() - 1] = abs(candy);
            break;
        }
    }
    int anger = 0;
    for (int i = 0; i < greed.size(); i++) {
        anger += (greed[i] * greed[i]);
    }
    cout << anger << "\n";
    return 0;
}