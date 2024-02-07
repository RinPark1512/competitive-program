// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int day;
    long bank = 100; // we start with $100
    int todays;
    int tomorrow;

    cin >> day;

    cin >> todays; // get initial value
    for (int i = 1; i < day; i++) {
        // if today's stock < tomorrow's stock, buy today and sell at tomorrow's price
        cin >> tomorrow;
        if (tomorrow > todays) {
            // as much as we can
            long div =  (bank / todays);
            // can't buy more that 100,000 shares
            if (div > 100000){
                div = 100000;
            }
            bank -= (div * todays); // buy as much as we can
            bank += (div * tomorrow); // sell as much as we can
        } 
        todays= tomorrow;
    }
    cout << bank << "\n";
    return 0;
}