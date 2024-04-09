#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int recur(vector<int> fees, vector<int> dp, int index, int prevJump, int totalCost) ;
int main() {
    int N;
    cin >> N;

    vector<int> fees(N);
    vector<int> dp(N);
    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        fees[i] = temp;
        dp[i] = temp;
    }
    int ans = recur(fees, dp, 1, 1, fees[1]);
    cout << ans << endl;

    return 0;
}

int recur(vector<int> fees, vector<int> dp, int index, int prevJump, int totalCost) {
    // jump forward or back
    if (index >= fees.size() - 1) {
        return totalCost;
    }
    int r1, r2;
    r1 = r1 = 100000;
    if ((index + prevJump + 1) < fees.size()) {
        // jump forward
        r1 = recur(fees, dp, (index + prevJump + 1), (prevJump + 1), totalCost + fees[index + prevJump + 1]);
    } 
    if ((index - prevJump) >= 0) {
        // jump back
        r2 = recur(fees, dp, (index - prevJump), prevJump, totalCost + fees[index - prevJump]);
    }
    return min (r1, r2);
    // take min
}
