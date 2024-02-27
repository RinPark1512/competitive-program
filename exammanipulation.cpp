// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int recur (vector<string> arr, vector<int> scores, int indexChar, int q);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int stud, q;
    cin >> stud;
    cin >> q;
    vector<string> allStud;
    vector<int> scores;
    for (int i = 0; i < stud; i++){
        string ans;
        cin >> ans;
        allStud.push_back(ans);
        // initialize scores with 0s
        scores.push_back(0);
    }
    // call recursive function
    int maxScore = recur(allStud, scores, 0, q);
    cout << maxScore << "\n";

    return 0;
}

int recur (vector<string> arr, vector<int> scores, int indexChar, int q){
    if (indexChar == q){
        // finished creating the array, so no need to track indexes
        sort(scores.begin(), scores.end());
        // return smallest score = the lowest score a student scores
        return scores[0];
    }
    // make copy of scores
    vector<int> score2 = scores;
    // there is no need to actually make a string of "TTFTFT..."
    // we can just imply that it is T/F, and grade from there
    //if answer is T
    for (int i = 0; i < arr.size(); i++){ // go thorugh each test
        if (arr[i].at(indexChar) == 'T'){
            scores[i]++;
        }
    }
    // recurse as if we graded the current question as "T"
    int min1 = recur(arr, scores, indexChar+1, q);

    // if answer is F
    // which is why we need a copy of the array, 
    // so we dont try to recurse with the altered array
    for (int i = 0; i < arr.size(); i++){ // go thorugh each test
        if (arr[i].at(indexChar) == 'F'){
            score2[i]++;
        }
    }
    // recurse as if we graded the current question as "F"
    int min2 = recur(arr, score2, indexChar+1, q);
    // return the highest "lowest" score
    return max(min1, min2);
}