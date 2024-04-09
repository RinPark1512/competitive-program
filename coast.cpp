#include <iostream>
#include <vector>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
/* Reflection: Version 3.5 https://chat.openai.com/share/26f270ca-7a47-4aca-9b2b-697ff0df22e3

*/

using namespace std;

// Function to check if the given cell is within bounds and is water
bool isValid(int x, int y, int r, int c) {
    // if x and y are within bounds
    if (x >= 0 ){
        if( x < r) {
            if (y >= 0){
                if (y < c) {
                    return true;    
                }
            }
        } 
    } 
    return false;
}

// Function to perform DFS to count coast length
void bfs(int N, int M, vector<vector<bool> >& visited, vector<vector<int> >& grid, vector<vector<int> >& sea_bfs) {
    queue<pair<int, int> > q;
    pair<int, int> p (0, 0); // create point, push into queue
    q.push(p);
    visited[0][0] = 1; // mark as visited
    sea_bfs[0][0] = 0;
    // int count = 1;
    while (!q.empty()) { // while the queue is not empty
        
        pair<int, int> current = q.front(); // consider the point at the front
        q.pop();
        int x = current.first;
        int y = current.second;
        // cout << "loop x - "<<x<<" y - "<< y<<endl;
        //         up  down right left
        int dx[] = {0,   0,   1,   -1}; 
        int dy[] = {1,  -1,   0,    0};
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            // check all directions, add to the queue
            if (isValid(newX, newY, N, M) && (!visited[newX][newY]) && grid[newX][newY] == 0) {
                pair<int, int> p2(newX, newY);
                q.push(p2);
                visited[newX][newY] = 1;
                sea_bfs[newX][newY] = 0;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int> > grid(N + 1, vector<int>(M + 1));
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (char digit : line){
            int num = digit - '0';
            grid[i].push_back(num);
        }
        // for (int k = 0; k < M; k++) {
        //     cin >> grid[i + 1][k+1];
        // }
    }
    N++;
    M++;

    vector<vector<bool> > visited(N, vector<bool>(M, false));
    vector<vector <int> > sea_bfs(N, vector<int> (M, 1)); // initialize it all to land
    for (int i = 0; i < N; i ++){
        for (int k = 0; k < M; k++) {
            cout << grid[i][k];
        }
        cout << "\n";
    }
        bfs(N, M, visited, grid, sea_bfs); // mark all sea connections using bfs

    for (int i = 0; i < N; i ++){
        for (int k = 0; k < M; k++) {
            cout << sea_bfs[i][k];
        }
        cout << "\n";
    }
    int coast_length = 0;
    for (int i = 0; i < N; i ++){
        for (int k = 0; k < M; k++) {
            if (sea_bfs[i][k] == 0) {
                continue;
            }
            int dx[] = {0,   0,   1,   -1}; 
            int dy[] = {1,  -1,   0,    0};
            for (int y = 0; y < 4; ++y) {
                int newX = i + dx[y];
                int newY = k + dy[y];
                // check all directions, add to the queue
                if (isValid(newX, newY, N, M)) {
                    if (sea_bfs[newX][newY] == 1){
                        coast_length++;
                    } else {
                        coast_length--;
                    }
                    cout << coast_length << "\n";
                }
            }
        }
    }
    cout << coast_length << endl;

    return 0;
}
