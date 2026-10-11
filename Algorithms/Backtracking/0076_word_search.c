// Practice for: 0076_word_search.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

bool dfs (int rows, int cols, char board[rows][cols], const char *word, int r, int c, int k){
    // every letter has been matched
    if (word[k] == '\0'){
        return true;
    }
    // boundary check
    if (r < 0 || r >= rows || c < 0 || c >= cols){
        return false;
    }
    if (board[r][c] == '#' || board[r][c] != word[k]){
        return false;
    }

    char saved = board[r][c]; 
    // mark as visited
    board[r][c] = '#';
    bool found =
        dfs(rows, cols, board, word, r + 1, c, k + 1) ||
        dfs(rows, cols, board, word, r - 1, c, k + 1) ||
        dfs(rows, cols, board, word, r, c + 1, k + 1) ||
        dfs(rows, cols, board, word, r, c - 1, k + 1);

    board[r][c] = saved;
    return found;
}

bool exist (int rows, int cols, char board[rows][cols], const char *word){
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            // start recursion
            if (dfs(rows, cols, board, word, r, c, 0)){
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    char board[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    printf("%s\n",
           exist(3, 4, board, "ABCCED") ? "true" : "false");

    return 0;
}