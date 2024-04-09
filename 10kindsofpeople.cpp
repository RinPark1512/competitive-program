// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
/* Reflection: Version 3.5 https://chat.openai.com/share/7c6ab41f-372e-42db-a354-fe5f99738cff
ChatGPT was used initially to get a skeleton code, and then it would not improve it as it kept TLE,
So I took matter into my own hands and fixed it. It was fed the code prompt and test code.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

const int MAX_SIZE = 1000;
int visited[MAX_SIZE][MAX_SIZE] = {0}; // check which is visited
int regions[MAX_SIZE][MAX_SIZE] = {0}; // track regions

// Function to check if given coordinates are valid
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

// Function to perform BFS to check if it's possible to move between two locations
void isReachable(vector<string>& map, int startRow, int startCol, char type, int r, int c, int count) {
    queue<pair<int, int> > q;
    pair<int, int> p (startRow, startCol); // create point, push into queue
    q.push(p);
    visited[startRow][startCol] = 1; // mark as visited
    regions[startRow][startCol] = count;
    // int count = 1;
    while (!q.empty()) { // while the queue is not empty
        pair<int, int> current = q.front(); // consider the point at the front
        q.pop();
        int x = current.first;
        int y = current.second;
        //         up  down right left
        int dx[] = {0,   0,   1,   -1}; 
        int dy[] = {1,  -1,   0,    0};
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            // check all directions, add to the queue
            if (isValid(newX, newY, r, c) && (!visited[newX][newY]) && map[newX][newY] == type) {
                pair<int, int> p2(newX, newY);
                q.push(p2);
                visited[newX][newY] = 1;
                // regions are numbered; whenever we start bfs we explore a new region 1-n
                regions[newX][newY] = count;
                
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int row;
    int col;
    cin >> row;
    cin >> col;

    vector<string> map(row);
    for (int i = 0; i < row; ++i) {
        cin >> map[i];
    }
    int n;
    cin >> n;
    memset(visited, 0, sizeof(visited)); 
    memset(regions, 0, sizeof(regions)); 
    // the purpose of the regions is to see the "islands" of people, 
    // aka everything reachable from one spot as binary/decimal

    int count = 1;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --b; --c; --d;

        char type1 = map[a][b];
        char type2 = map[c][d];
        if (type1 != type2) {
            cout << "neither\n";
        } else {
            if (regions[a][b] == 0 && regions[c][d] == 0) {
                // run bfs
                isReachable(map, a, b, type1, row, col, count); // if the section has not been searched, bfs
                count++;
            }
            if (regions[a][b] != regions[c][d]) { // if from different regions, not reachable
                cout << "neither\n";
            } else {
                cout << (type1 == '0' ? "binary\n" : "decimal\n");
            }
        }
    }
    return 0;
}
