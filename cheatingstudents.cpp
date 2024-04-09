// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
/* Reflection: Version 3.5 
*/
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int students;
    cin >> students;
    // int graph[students][students] = {0};
    vector<pair<int, int> > g;
    for (int i = 0; i < students; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;
        pair<int, int> p(x, y);
    }

    // vector<vector<int> > graph()

    return 0;
}