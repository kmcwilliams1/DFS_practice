#include <cstdio>

using namespace std;


// Global variables
typedef struct {
    char type;        // 'R' for residential, 'I' for industrial, 'C' for commercial, '-' for road, 'T' for powerline, '#' for powerline over a road, 'P' for power plant
    int population;   // Population of the cell
    int row;          // Row index of the cell
    int col;          // Column index of the cell
    bool visited;     // Flag to indicate if the cell has been visited
} Cell;
int *ROWS;
int *COLS;


// Depth First Search
void dfs(int row, int col) {
    if (row < 0 || row >= *ROWS || col < 0 || col >= *COLS) {
        // Out of bounds or already visited, terminate recursion
        return;
    }

    printf("Visiting cell (%d, %d) \n", row, col);


    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newRow = row + i;
            int newCol = col + j;

            dfs(newRow, newCol);
        }
    }
}

int main() {
    // Read input
    Cell region[*ROWS][*COLS];



    // Call DFS from a starting point
    dfs(0, 0);


    return 0;
}
