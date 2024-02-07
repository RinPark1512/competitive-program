// Author: Taehoon Hwang, Catherine Park
// It is ok to share my code anonymously for educational purposes.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    while (true) {
        int n = 0;
        cin >> n;

        if (n == 0) break;

        vector<vector<int>> first_list;
        vector<vector<int>> second_list;

//      push the values into the different lists
        for (int i = 0; i < n; i++) {
            int temp = 0;
            cin >> temp;

            vector<int> temp_vec; // track the original index of the lists

            temp_vec.push_back(temp); 
            temp_vec.push_back(i); // like a 2D array, value maps to the original index
            first_list.push_back(temp_vec);
        }

        for (int i = 0; i < n; i++) {
            int temp = 0;
            cin >> temp;

            vector<int> temp_vec; // track the original index of the lists

            temp_vec.push_back(temp); 
            temp_vec.push_back(-1); // no need to track initial index for now
            second_list.push_back(temp_vec);
        }

        // Custom sort code taken from Stackoverflow, Evan Teran's answer
        // [https://stackoverflow.com/questions/279854/how-do-i-sort-a-vector-of-pairs-based-on-the-second-element-of-the-pair]
        sort(first_list.begin(), first_list.end(), [](auto &left, auto &right) { return left[0] < right[0]; });
        sort(second_list.begin(), second_list.end(), [](auto &left, auto &right) { return left[0] < right[0]; });

        // taking the sorted lists, match the value to each other
        for (int i = 0; i < n; i++) {
            second_list[i][1] = first_list[i][1]; // match up indexes
        }

//      sort by the proper index
        sort(second_list.begin(), second_list.end(), [](auto &left, auto &right) { return left[1] < right[1]; });

        for (int i = 0; i < n; i++) {
            cout << second_list[i][0] << "\n"; // print the values
        }

        cout << "\n";
    }

    return 0;
}