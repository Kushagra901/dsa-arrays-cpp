/**
 * ============================================================================
 * PROBLEM: Game of Life (LeetCode 289)
 * ============================================================================
 * 
 * 📌 PROBLEM DESCRIPTION:
 *    According to Conway's Game of Life, the board is made up of an `m x n` 
 *    grid of cells, where each cell is either 0 (dead) or 1 (alive).
 *    Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
 *    using the following four rules:
 *      1. Any live cell with fewer than two live neighbors dies (under-population).
 *      2. Any live cell with two or three live neighbors lives on to the next generation.
 *      3. Any live cell with more than three live neighbors dies (over-population).
 *      4. Any dead cell with exactly three live neighbors becomes a live cell (reproduction).
 *    Compute the next state of the board in-place.
 * 
 * 💡 COMPLEXITY ANALYSIS:
 *    - 1. Brute Force Approach (Cloning the Board):
 *        • Time Complexity:  O(M * N) - Visiting each cell and its 8 neighbors
 *        • Space Complexity: O(M * N) - Auxiliary copy of the entire board
 *    - 2. Optimal Approach (2-Bit State Encoding In-Place):
 *        • Time Complexity:  O(M * N) - Two passes over the grid
 *        • Space Complexity: O(1) - Modifies cell values in-place without extra space
 * 
 * ----------------------------------------------------------------------------
 * 🎯 TOP INTERVIEW QUESTIONS & DEEP-DIVE CONCEPTS:
 * ----------------------------------------------------------------------------
 * 1. How does 2-Bit State Encoding enable O(1) in-place simulation?
 *    - Standard cells only use bit 0 (value 0 or 1).
 *    - We use bit 1 (value 2) to store the NEXT generation state:
 *        • `00` (0): Dead now, Dead next
 *        • `01` (1): Live now, Dead next
 *        • `10` (2): Dead now, Live next
 *        • `11` (3): Live now, Live next
 *    - Read current state using `board[i][j] & 1`.
 *    - Transition to next state using `board[i][j] >>= 1`.
 * 
 * 2. What if the board is infinite? (Follow-up question)
 *    - If the board is infinite and sparse, storing the entire grid is impossible.
 *    - Instead, use a Hash Set of coordinates `(row, col)` representing only currently LIVE cells.
 *    - Check only live cells and their immediate neighbors.
 * 
 * 3. How do we traverse all 8 directional neighbors cleanly?
 *    - Use delta arrays:
 *      `int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};`
 *      `int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};`
 * 
 * 4. What if the board cannot fit in memory?
 *    - If stored line-by-line on disk, we only need 3 rows in memory at any time (row i-1, i, i+1).
 * 
 * ----------------------------------------------------------------------------
 * 🔗 SIMILAR PROBLEMS FOR PRACTICE:
 * ----------------------------------------------------------------------------
 * 1. LeetCode 289: Game of Life (Medium)
 * 2. LeetCode 73: Set Matrix Zeroes (Medium)
 * 3. LeetCode 48: Rotate Image (Medium)
 * 4. LeetCode 661: Image Smoother (Easy)
 * ============================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

// 8 neighbor direction offsets
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// ============================================================================
// 1. BRUTE FORCE APPROACH: Using Cloned Copy of Board
// Time Complexity: O(M * N) | Space Complexity: O(M * N)
// ============================================================================

void gameOfLifeBruteForce(vector<vector<int>> &board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> copyBoard = board;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    liveNeighbors += copyBoard[ni][nj];
                }
            }

            // Apply Conway's rules
            if (copyBoard[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    board[i][j] = 0; // Rule 1 & Rule 3: dies
                }
            } else {
                if (liveNeighbors == 3) {
                    board[i][j] = 1; // Rule 4: reproduction
                }
            }
        }
    }
}

// ============================================================================
// 2. OPTIMAL APPROACH: In-Place 2-Bit State Encoding
// Time Complexity: O(M * N) | Space Complexity: O(1)
// ============================================================================

void gameOfLife(vector<vector<int>> &board) {
    int m = board.size();
    int n = board[0].size();

    // Step 1: Compute next state and encode into 2nd bit
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    // Read current state from the least significant bit (bit 0)
                    liveNeighbors += (board[ni][nj] & 1);
                }
            }

            int currentState = board[i][j] & 1;

            // Rule 2 & 4: Cell should be live in next generation
            if (currentState == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                board[i][j] |= 2; // Set bit 1 (next state = 1)
            } else if (currentState == 0 && liveNeighbors == 3) {
                board[i][j] |= 2; // Set bit 1 (next state = 1)
            }
        }
    }

    // Step 2: Finalize state by shifting right (bit 1 becomes bit 0)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] >>= 1;
        }
    }
}

// ============================================================================
// DRIVER CODE
// ============================================================================

int main() {
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    cout << "Original Board:\n";
    for (const auto &row : board) {
        for (int cell : row) cout << cell << " ";
        cout << "\n";
    }

    gameOfLife(board);

    cout << "\nNext Generation (Optimal In-Place):\n";
    for (const auto &row : board) {
        for (int cell : row) cout << cell << " ";
        cout << "\n";
    }

    return 0;
}