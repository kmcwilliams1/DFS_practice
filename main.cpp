#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

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


    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;

            dfs(newRow, newCol);
        }
    }
}

int main() {
    // Read input
  //  Cell region[*ROWS][*COLS];


    ifstream fin("data2.dat");
    if (!fin.is_open()) {
        cerr << "Failed to open data.dat" << endl;
        return 1;
    }
    string readingLine, readingPart;


    int pos = 1;

    while (getline(fin, readingLine)) {
        cout << "readingLine: " << readingLine << endl;

        //read each character of the readingLine line
        for (int i = 0; i < readingLine.length(); i++) {
            readingLine[i] == ',' && pos++;
            if (readingLine[i] != ' ' && readingLine[i] != ',')
            cout << "readingLine[" << i << "]: " << readingLine[i] << " at position " << pos << endl;
        }
        pos = 1;
        cout << endl;



    }


    fin.clear();
    fin.seekg(0, ios::beg);


        // Call DFS from a starting point
 //   dfs(0, 0);


    return 0;
}
