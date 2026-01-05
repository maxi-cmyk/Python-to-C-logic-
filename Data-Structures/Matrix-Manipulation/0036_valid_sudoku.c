// Practice for: 0036_valid_sudoku.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

bool isValidSudoku(char **board, int boardSize, int* boardColSize){
    //2D frequency array
    int rows[9][9] = {0};
    int cols[9][9] = {0};
    int boxes[9][9] = {0};

    for (int r = 0; r < 9; r++){
        for (int c = 0; c < 9; c++){
            if (board[r][c] == '.'){
                continue;
            }
            int num = board[r][c] - '1'; //convert char to index 
            int box_index = (r/3) * 3 + (c/3); //flatten 2D array
            if (rows[r][num] || cols[c][num] || boxes[box_index][num]){
                return false; //return false if there is a repeat 
            }
            rows[r][num] = 1;
            cols[c][num] = 1;
            boxes[box_index][num] = 1; 
        }
    }
    return true;
}

// void printMapping(int r, int c) {
//     // The C "Flattening" Formula
//     int box_id = (r / 3) * 3 + (c / 3);
    
//     printf("Coord [%d][%d] -> Row: %d, Col: %d, Box ID: %d\n", 
//             r, c, r, c, box_id);
// }

// int main() {
//     printf("--- SUDOKU MAPPING TEST ---\n");

//     // Test Top-Left Corner
//     printMapping(0, 0); // Box 0
//     printMapping(2, 2); // Still Box 0

//     // Test a Middle cell
//     printMapping(4, 5); // Box 4 (Middle-Center)

//     // Test Bottom-Right Corner
//     printMapping(8, 8); // Box 8

//     printf("\n--- VISUALIZING THE BOXES ---\n");
//     for (int r = 0; r < 9; r++) {
//         for (int c = 0; c < 9; c++) {
//             int box_id = (r / 3) * 3 + (c / 3);
//             printf("%d ", box_id);
//             if ((c + 1) % 3 == 0) printf("  "); // Visual gap between boxes
//         }
//         printf("\n");
//         if ((r + 1) % 3 == 0) printf("\n"); // Visual gap between tiers
//     }

//     return 0;
// }

int main() {
    // A standard valid (but incomplete) board
    char* board1[] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    if (isValidSudoku(board1, 9, NULL)) {
        printf("Test 1 Passed: Board is valid!\n");
    } else {
        printf("Test 1 Failed: Board should be valid.\n");
    }
    
    return 0;
}
