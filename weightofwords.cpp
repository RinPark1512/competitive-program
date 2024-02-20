// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long space, weight;
    cin >> space;
    cin >> weight;
    string result = "";
    if (space == 0 && weight == 0){
        cout << "" << "\n";
        return 0;
    }
    // find the average word weight
    // for example, if the weight is 100, and the length is 10, then each letter can be 10 each
    long long temp = weight / space;
    // if there is overflow after 
    // Given the example above, if the weight is 101, 9 letters are weight 10, one letter is weight 11
    long long mod = weight % space; 
    // for easy access of letters
    string alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    // if the weight is too small/large, impossible
    if (temp == 0 ||((temp >= 26) && (mod > 0)) || (temp > 26)) {
        cout << "impossible\n";
        return 0;
    }
    
    vector<long long> arr;
    // set the word to be the average weight, -1 for array indexing
    for (long long i = 0; i < space; i++){
        arr.push_back(temp - 1);
    }
    long long index = 0;
    while (mod > 0) {
        // given the leftovers, increment each letter when we can
        if (arr[index] < 25) { // 25, because again array indexing, starts at 0
            arr[index]++;
            mod--;
        }
        index++;
    }
    // build the word
    for (long long i = 0; i < space; i++){
        result.append(alphabet[arr[i]]);
    }
    cout << result << "\n";
    return 0;
}