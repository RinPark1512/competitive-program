
// Author: Catherine Park
// It is ok to share my code anonymously for educational purposes
/* Reflection: Version 3.5 https://chat.openai.com/share/af9e9e3b-8d6c-4447-8099-29fbafb826e7 
After inputting the question prompt from Kattis, the first output used DFS to find the path. 
Since that would TLE, it wouldn't do. I knew that this was a minimum path problem, and therefore a 
Dijikstra problem, after asking ChatGPT to use Dijikstra's algorithm, the correct program was presented.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Struct to represent a cell in the grid
struct Cell {
    int row, col, depth;

    // Overloading comparison operator for priority queue
    bool operator<(const Cell& other) const {
        return depth > other.depth; // Priority queue sorts in ascending order, so we use greater than operator
    }
};

// Function to perform Dijkstra's algorithm to find the minimum depth of mud encountered
int dijkstra(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // Initializing distances array with maximum possible value
    vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));

    // Priority queue for Dijkstra's algorithm
    priority_queue<Cell> pq;

    // First, we add all the cells from the leftmost column to the priority queue
    // since we can start on any cell in the left column
    for (int i = 0; i < rows; ++i) {
        pq.push({i, 0, grid[i][0]});
        distances[i][0] = grid[i][0]; // set initial distances to the depth of mud in the cells
    }

    // Dijkstra's algorithm
    while (!pq.empty()) {
        Cell current = pq.top(); // get cell with the minimum depth from priority queue
        pq.pop();

        // Check if we reached the rightmost column, because we can end on any cell in the right column
        if (current.col == cols - 1) {
            return current.depth; 
        }

        //                                   (down,    up,     left,    right)
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& dir : directions) {
            int newRow = current.row + dir.first; // get the coordinates after the up/down.left/right shift
            int newCol = current.col + dir.second;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) { // if they are within grid bounds
                // Calculate new depth by taking the maximum of current depth and depth of the neighbor
                int newDepth = max(current.depth, grid[newRow][newCol]);
                if (newDepth < distances[newRow][newCol]) {
                    // If new depth is less than previously calculated depth, update distances array and push to priority queue
                    distances[newRow][newCol] = newDepth;
                    pq.push({newRow, newCol, newDepth});
                }
            }
        }
    }

    return -1;
}

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = dijkstra(grid);

    cout << result << endl;

    return 0;
}
