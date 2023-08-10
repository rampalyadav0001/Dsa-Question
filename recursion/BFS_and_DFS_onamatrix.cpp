Breadth-First Search (BFS):
BFS is a graph traversal algorithm that explores all the vertices of a graph in breadth-first order, i.e., it visits all the vertices at the same level before moving to the next level. When applied to a matrix, BFS visits all cells in a level before moving to cells in the next level.

Here's how BFS using recursion works on a matrix:

1.Start at the initial cell (usually the starting point).
2.Enqueue the initial cell into a queue.
3.While the queue is not empty, do the following:
3.1.Dequeue a cell from the front of the queue.
3.2.Process the cell (perform the desired operation).
3.3.Enqueue all valid neighboring cells that havenot been visited yet.




Recursive BFS on a matrix is a bit tricky because BFS is typically implemented using a queue. However, you can simulate the BFS behavior by using recursion and mimicking the queue behavior with function calls.


code::-->>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};  // Offsets for neighboring cells (up, right, down, left)
int dy[] = {0, 1, 0, -1};

void bfsRecursive(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        // Process the cell here (print or do something with matrix[currX][currY])

        for (int i = 0; i < 4; i++) {
            int newX = currX + dx[i];
            int newY = currY + dy[i];

            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY]) {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Initialize the matrix and visited arrays

    int startX, startY;
    cin >> startX >> startY;

    bfsRecursive(matrix, visited, startX, startY);

    return 0;
}

Depth-First Search::-->>

Sure, let's explain both Breadth-First Search (BFS) and Depth-First Search (DFS) using recursion on a matrix.

Breadth-First Search (BFS):
BFS is a graph traversal algorithm that explores all the vertices of a graph in breadth-first order, i.e., it visits all the vertices at the same level before moving to the next level. When applied to a matrix, BFS visits all cells in a level before moving to cells in the next level.

Here's how BFS using recursion works on a matrix:

Start at the initial cell (usually the starting point).
Enqueue the initial cell into a queue.
While the queue is not empty, do the following:
Dequeue a cell from the front of the queue.
Process the cell (perform the desired operation).
Enqueue all valid neighboring cells that haven't been visited yet.
Recursive BFS on a matrix is a bit tricky because BFS is typically implemented using a queue. However, you can simulate the BFS behavior by using recursion and mimicking the queue behavior with function calls.

Depth-First Search (DFS):
DFS is a graph traversal algorithm that explores as far as possible along a branch before backtracking. When applied to a matrix, DFS explores as deep as possible along one path before backtracking to explore other paths.

Here's how DFS using recursion works on a matrix:

Start at the initial cell (usually the starting point).
Mark the current cell as visited.
Explore the neighbors of the current cell recursively:
For each unvisited neighbor, call the DFS function on that neighbor.
Once all neighbors are visited or the desired condition is met, backtrack (return from the recursion).
Recursive DFS on a matrix is more intuitive compared to recursive BFS since DFS naturally works with recursion. You can use a recursive function to traverse the matrix while marking visited cells and exploring neighbors.

Keep in mind that both BFS and DFS have their advantages and use cases. BFS is generally used when you want to find the shortest path between two points or explore a graph layer by layer. DFS is often used when you want to exhaustively explore all possible paths in a graph or when you are looking for specific solutions.

Remember that recursion depth is limited, so for large matrices or graphs, you might need to consider iterative implementations or other optimizations.

code::-->>
#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};  // Offsets for neighboring cells (up, right, down, left)
int dy[] = {0, 1, 0, -1};

void dfsRecursive(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int x, int y) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    visited[x][y] = true;

    // Process the cell here (print or do something with matrix[x][y])

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY]) {
            dfsRecursive(matrix, visited, newX, newY);
        }
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Initialize the matrix and visited arrays

    int startX, startY;
    cin >> startX >> startY;

    dfsRecursive(matrix, visited, startX, startY);

    return 0;
}
