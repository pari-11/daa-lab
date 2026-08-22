#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int tileNumber = 1;

void tileBoard(int top, int left, int size,
               int missingRow, int missingColumn) {
    // A 1 x 1 board needs no tromino.
    if (size == 1) {
        return;
    }

    int half = size / 2;

    int centerRow = top + half;
    int centerColumn = left + half;

    /*
        Quadrants:

        0: top-left
        1: top-right
        2: bottom-left
        3: bottom-right
    */

    int missingQuadrant =
        (missingRow >= centerRow ? 2 : 0) +
        (missingColumn >= centerColumn ? 1 : 0);

    // Inner corner cell of each quadrant.
    int centerRows[4] = {
        centerRow - 1, // top-left
        centerRow - 1, // top-right
        centerRow,     // bottom-left
        centerRow      // bottom-right
    };

    int centerColumns[4] = {
        centerColumn - 1, // top-left
        centerColumn,     // top-right
        centerColumn - 1, // bottom-left
        centerColumn      // bottom-right
    };

    /*
        Place one central L-tromino.

        The quadrant containing the original missing cell
        is skipped. The other three inner corner cells
        are covered by this tromino.
    */
    int currentTile = tileNumber++;

    for (int quadrant = 0; quadrant < 4; quadrant++) {
        if (quadrant != missingQuadrant) {
            board[centerRows[quadrant]]
                 [centerColumns[quadrant]] = currentTile;
        }
    }

    int quadrantTop[4] = {
        top,         // top-left
        top,         // top-right
        centerRow,   // bottom-left
        centerRow    // bottom-right
    };

    int quadrantLeft[4] = {
        left,             // top-left
        centerColumn,     // top-right
        left,             // bottom-left
        centerColumn      // bottom-right
    };

    /*
        Recursively tile each quadrant.

        The original missing cell is used for its quadrant.
        The central tromino cell is used as the missing cell
        for each of the other three quadrants.
    */
    for (int quadrant = 0; quadrant < 4; quadrant++) {
        int newMissingRow;
        int newMissingColumn;

        if (quadrant == missingQuadrant) {
            newMissingRow = missingRow;
            newMissingColumn = missingColumn;
        } else {
            newMissingRow = centerRows[quadrant];
            newMissingColumn = centerColumns[quadrant];
        }

        tileBoard(
            quadrantTop[quadrant],
            quadrantLeft[quadrant],
            half,
            newMissingRow,
            newMissingColumn
        );
    }
}

int main() {
    int n;

    cout << "Enter board size n: ";
    cin >> n;

    // The divide-and-conquer method requires n = 2^k.
    if (n <= 0 || (n & (n - 1)) != 0) {
        cout << "Board size must be a positive power of 2.\n";
        return 1;
    }

    int missingRow;
    int missingColumn;

    cout << "Enter uncovered cell coordinates ";
    cout << "(zero-based row and column): ";
    cin >> missingRow >> missingColumn;

    if (missingRow < 0 || missingRow >= n ||
        missingColumn < 0 || missingColumn >= n) {
        cout << "Invalid uncovered cell coordinates.\n";
        return 1;
    }

    // Initialize the board.
    board.assign(n, vector<int>(n, 0));

    // Mark the one cell that must remain uncovered.
    board[missingRow][missingColumn] = -1;

    // Start the recursive tiling.
    tileBoard(0, 0, n, missingRow, missingColumn);

    cout << "\nFinal Board:\n";

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            cout << board[row][column] << "\t";
        }
        cout << '\n';
    }

    return 0;
}