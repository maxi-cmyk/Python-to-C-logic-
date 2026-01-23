// Practice for: 0056_merge_intervals.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

//always wrap variables
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if(intervalsSize <= 0){
        *returnSize = 0;
        return NULL;
    }

    //sort by firsat index 
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** res = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int count = 0;

    res[count] = (int*)malloc(2 *sizeof(int));
    res[count][0] = intervals[0][0];
    res[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count++;

    for(int i = 1; i < intervalsSize; i++){
        if(intervals[i][0] <= res[count-1][1]){
            res[count-1][1] = MAX(res[count-1][1], intervals[i][1]);
        } else {
            res[count] = (int*)malloc(2 * sizeof(int));
            res[count][0] = intervals[i][0];
            res[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }
    *returnSize = count;
    return res;
}

void print_result(int** res, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("[%d,%d]%s", res[i][0], res[i][1], (i == size - 1) ? "" : ", ");
    }
    printf("]\n");
}

void run_test(int rows, int data[rows][2], char* testName) {
    printf("Running %s... ", testName);

    // 1. Setup Input: Allocate the "Spine" and "Ribs"
    int** intervals = (int**)malloc(rows * sizeof(int*));
    int* colSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        intervals[i] = (int*)malloc(2 * sizeof(int));
        intervals[i][0] = data[i][0];
        intervals[i][1] = data[i][1];
        colSizes[i] = 2;
    }

    int returnSize;
    int* returnColSizes;

    // 2. Call your function
    int** res = merge(intervals, rows, colSizes, &returnSize, &returnColSizes);

    // 3. Output results
    print_result(res, returnSize);

    // 4. CLEANUP (The anti-leak routine)
    for (int i = 0; i < rows; i++) free(intervals[i]);
    free(intervals);
    free(colSizes);

    for (int i = 0; i < returnSize; i++) free(res[i]);
    free(res);
    free(returnColSizes);
    
    printf("Memory cleared.\n-------------------\n");
}

int main() {
    int t1[][2] = {{1,3}, {2,6}, {8,10}, {15,18}};
    run_test(4, t1, "Test 1: Chain Merge");

    int t2[][2] = {{1,4}, {2,3}};
    run_test(2, t2, "Test 2: Enclosure");

    int t3[][2] = {{1,4}, {4,5}};
    run_test(2, t3, "Test 3: Touching Edges");

    int t4[][2] = {{1,4}, {0,0}};
    run_test(2, t4, "Test 4: Out of Order (Sorting)");

    return 0;
}