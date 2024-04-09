// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
/* Reflection: https://chat.openai.com/share/fac8dc6a-dba2-4843-abf7-05cf28a2e6b6 
    Version of GenAI: 3.5
    I started by just copy and pasting the kattiss problem prompt into it. It gave me wrong code
    (ie it failed kattis), even after I corrected it, and had it run a test case 
    (even for running the test case I'm not sure if it actauly ran it or it spat back the output). 
    I suspected that there may be too much jargon/fluff in the prompt, so 
    I tried again with a simpler summary of the problem and its constraints. It worked! 
    Looks like the extra info about Sarah and gamestop was unnecessary in formulating the solution.
    (please ignore the extra message at the bottom, I heard you had to compliment/ give
    positive affirmation to chatGPT so that it will work harder for you <(`-`<))
*/
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
int maxProfit(vector<int>& prices);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> stock;
    for (long long i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        stock.push_back(temp);
    }
    cout << maxProfit(stock) << "\n";
    return 0;
}
// recursive function
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1){
        return 0;
    }

    int buy = -prices[0]; // max profit if buy on day i
    int sell = 0; // max profit if sell on day i
    int cooldown = 0; // max profit if cooldown on day i

    for (int i = 1; i < n; i++) {
        int prev_buy = buy;
        // If we buy on day i, the maximum profit is either continuing to 
        // cooldown on the previous day or buy on day i-2 and pay the price
        buy = max(buy, cooldown - prices[i]);
        // Cooldown is the maximum profit of the previous day (either from selling or cooling down)
        cooldown = sell;
        // If we sell on day i, we must buy on day i-1, so the maximum profit is adding the price on day i
        sell = max(sell, prev_buy + prices[i]);
    }

    // The maximum profit can either be from selling or cooling down on the last day
    return max(sell, cooldown);
}
