// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std; 

string recur(long long currHeight, string order, long long *buildMax, vector<long long> heights, long long index);


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n;
    for (long long i = 0; i < n; i++){
        cin >> m;
        vector<long long> height;
        for (long long k = 0; k < m; k++){
            long long temp = 0;
            cin >> temp;
            height.push_back(temp);
        }
        string temp = recur(0, "", 0, height, 0);
        if (temp.compare("")) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << temp << "\n";
        }
    }
    return 0;
}

string recur(long long currHeight, string order, long long *buildMax, vector<long long> heights, long long index) {
    if (index >= heights.size()) {
        if (currHeight != 0) {
            return "";
        }
        return order;
    }
    if (currHeight == 0) {
        *buildMax = heights[index];
        return recur(heights[index], order, buildMax, heights, index + 1);
    } else if (currHeight == heights[index]) {
        // go down
        order.append("D");
        return recur(currHeight - heights[index], order, buildMax, heights, index + 1);
    } else if (currHeight < heights[index]){
        // go up, update max building
        order.append("U");
        if ((currHeight + heights[index]) > *buildMax) {
            *buildMax = (currHeight + heights[index]);
        }
        return recur(currHeight + heights[index], order, buildMax, heights, index + 1);
    } else {
        //go both ways, compare answer
        string s1 = "";
        long long buildCurr = *buildMax;
        if ((currHeight + heights[index]) > *buildMax) {
            *buildMax = currHeight + heights[index];
        }
        s1 = recur(currHeight + heights[index], order + "U", buildMax, heights, index + 1);
        long long build1 = *buildMax;
        string s2 = recur(currHeight - heights[index], order + "D", &buildCurr, heights, index + 1);
        long long build2 = buildCurr;
        if (s1.compare("")) {
            return s2;
        } else if (s2.compare("")) {
            return s1;
        } else {
            if (build1 > build2) {
                return s2;
            } else {
                return s1;
            }
        }
    }
    return "";
}