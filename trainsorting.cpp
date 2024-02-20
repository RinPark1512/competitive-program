// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, temp, min, max, trainLen;
    trainLen = 0;
    min = 10001;
    max = -1;
    cin >> n;
    for (n; n > 0; n--) {
        cin >> temp;
        if (trainLen == 0) {
            trainLen++;
            min = temp;
            max = temp;
        } else if (temp <= min) {
            min = temp;
            trainLen++;
        } else if (temp >= max) {
            max = temp;
            trainLen++;
        }
    }
    cout << trainLen << "\n";

    return 0;
}