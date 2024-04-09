// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
/* Reflection:
    Version of GenAI: 3.5
    https://chat.openai.com/share/2835f3d0-daf5-4056-818f-037ce49419a2
*/
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct option {
    long long profit;
    long long cost;
};

int maxProfit(vector<int>& prices);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, retire;
    cin >> n >> retire;
    vector<option> stonk(n);
    for (long long i =0; i < n; i++){
        cin >> stonk[i].profit >> stonk[i].cost;
    }
    vector<long long> day;
    // (retire + cost) / profit = how many days it takes to pay it off
    // how to find all combinations?
    for (long long i = 0; i < n; i ++){
        // find days for indiv
        long long total_cost = stonk[i].cost + retire;
        long long total_profit = stonk[i].profit;
        if (total_cost % stonk[i].profit != 0){
            day.push_back((total_cost/stonk[i].profit) + 1);
        } else {
            day.push_back((total_cost/stonk[i].profit));
        }
        for (long long k = (i + 1); k < n; k++){
            total_cost += stonk[k].cost;
            total_profit += stonk[k].profit;
            if (total_cost % total_profit != 0){
                day.push_back((total_cost/total_profit) + 1);
            } else {
                day.push_back((total_cost/total_profit));
            }
        }
    }
    sort(day.begin(), day.end());
    cout << day[0] << "\n";
    return 0;
}