/*
Initialization: 
The program contains the necessary libraries (<iostream> to work with input and output, <vector> to use vectors, <limits> to stop any failures of reading input with non-numeric data).It consists of the functions of solving the problem (solveKnightTour, knightTour), security move checking (isSafe), and print the solution (printSolution). 

Board Representation: 
The chessboard is represented using a 2D vector (std:Initially the whole board is being set -1 (unvisited) for each cell in the vector of vectors (vector< vector<int>>). 

Knight's Moves: 
Knight moves are all possible and this is made possible by ensuring the relative x and y coordinates (x_axis[].y_axis []) for each move are defined 

Backtracking: 
The most important task completed with its help is solving the knightTour problem. It explores all possible moves by the examining each move from the original position of the knight recursively. If a movement is secure, it states visit as move and furtherly processes exploration. It is one of those instances where returning a 1 signifies that the solution has been found, but other marks are used to indicate that there is no solution and the backtracking process must continue by unmarking the cell as not visited and going for a different move. 

Solution Finding: 
Employ the solveKnightTour function to start resolving the task. It causes the knight to be put in a specific starting area where the knightTour() function can then begin looking all the way through to the end of the array. If a solution is identified, it prints "Puzzle Solved!" then displays the solution board using printSolution. If no solution exists, it tells the user" 
*/

#include <iostream> // displays and gets output/input
#include <vector> // assists with vectors

// declarations of the functions
int knightTour(int x, int y, int movei, std::vector<std::vector<int>>& board, int x_axis[], int y_axis[]); // function with its variables to solve this problem recursively
bool isSafe(int x, int y, const std::vector<std::vector<int>>& board); // function to check if a move is safe
void printSolution(const std::vector<std::vector<int>>& board); // function to print the solution board
int solveKnightTour(int G); // function to initiate solving the problem

// check if the next move is safe
bool isSafe(int x, int y, const std::vector<std::vector<int>>& board) {

    int N = board.size();  // define the size of the board

    // check if the next move is within the board boundaries and if the cell is not visited yet
    if (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1) {
        return true; // the move is safe
    } else {
        return false; // the move is not safe
    }
}

// print the solution board
void printSolution(const std::vector<std::vector<int>>& board) {
    std::cout << "Solution:\n";
    // repeat over each row of the board
    for (const std::vector<int>& row : board) {
        // repeat over each cell of the row
        for (int cell : row)
            // print each cell
            std::cout << cell << " ";
        std::cout << "\n";
    }
}

// solve the problem
int solveKnightTour(int G) {
    // board size that user has selected
    std::cout << "Solution for the Knight Tour problem for a " << G << "x" << G << " board.\n";

    // board with all cells as unvisited (-1)
    std::vector<std::vector<int>> board(G, std::vector<int>(G, -1));

    // declaring all moves that knight might do on a board with no obstacles on it
    int x_axis[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_axis[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // start the tour from the top-left corner
    board[0][0] = 0; // this can be adjusted so the user enters this position

    // solve the problem recursively
    if (knightTour(0, 0, 1, board, x_axis, y_axis) == 0) {
        // if no solution exists, inform the user
        std::cout << "There is no solution for a " << G << "x" << G << " board.\n";
        return 0;
    } else {
        // if a solution exists, print the solution
        printSolution(board);
        return 1;
    }
}

// ordered function to solve the problem
int knightTour(int x, int y, int movei, std::vector<std::vector<int>>& board, int x_axis[8], int y_axis[8]) {
    int G = board.size();
    int n, fx, fy; // following x and y

    // declare if all cells are visited, the solution is found
    if (movei == G * G)
        return 1;

    // all possible moves from the current cell in order
    for (n = 0; n < 8; n++) {
        fx = x + x_axis[n];
        fy = y + y_axis[n];

        // check if the next move is safe
        if (isSafe(fx, fy, board)) {
            // mark the next move and orderly continue exploring
            board[fx][fy] = movei;
            if (knightTour(fx, fy, movei + 1, board, x_axis, y_axis) == 1)
                return 1;
            else
                // if the current path doesn't lead to a solution, go back
                board[fx][fy] = -1;
        }
    }
    // no solution found from this position
    return 0;
}

int main() {
    while (true) {
        int G;
        std::cout << "Enter the size of the board, minimum 5x5 (enter 4 to exit):";
        std::cin >> G; // Read the input from the user

        if (G == 4) {
            std::cout << "Goodbye.\n";
            return 0;
        }

        if (G >= 5) {
            // solve the Knight Tour problem for the specified board size
            solveKnightTour(G);
        } else {
            // error due to the input of the board size
            std::cout << "Board size doesn't meet the required minimum.\n";
            std::cout << "Minimum size is 5x5.\n";
        }
    }
    return 0;
}
