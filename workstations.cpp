// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, whenLock;
    int temp, stay;
    int saves = 0;
    vector<int> arrival;
    vector<int> leaving;
    
    cin>> n;
    cin>>whenLock;

    for (int i = 0; i < n; i++){
        cin >> temp;
        cin>>stay;
        arrival.push_back(temp);
        leaving.push_back(stay + temp); // track the time people leave
    }

    // no need to track who is leaving, we just need the times and to see if they overlap
    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());

    int arrive, leave;
    arrive = leave = 0;
    while (arrive <= (arrival.size() -1) && leave <= (leaving.size()-1)) {
        if (arrival[arrive] >= leaving[leave]){
            // if the times overlap before the lock auto-locks, increment
            if ((arrival[arrive] - leaving[leave]) <= whenLock){
                saves++;
                // make sure not to go over
                if (arrive < arrival.size()){
                    arrive++;
                } else{
                    // if we are at the end (finished the list), we have finished
                    break; 
                }
                if (leave < leaving.size()){
                    leave++;
                } else{
                    // if we are at the end (finished the list), we have finished
                    break;
                }
            } else { // means the leaving time is not big enough, so we increment to find a bigger time
                // make sure not to go over
                if (leave < leaving.size()){
                    leave++;
                }
            }
        } else { // means the arrival time is not big enough, so we increment to find a bigger time
            if (arrive < arrival.size()){
                arrive++;
            }
        }
    } 
    cout<< saves<<"\n";
    return 0;
}