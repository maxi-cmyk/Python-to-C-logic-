// Practice for: 0057_insert_interval.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>

int** insert(int** intervals, int intervalsSize, int* intervalColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returncolumnSizes){
    int** res = (int**)malloc((intervalsSize + 1) *sizeof(int*));
    *returnColumnSizes = (int*)malloc((intervalsSize + 1) * sizeof(int));
    int count = 0;
    int i = 0;

    //add intervals smaller than new interval
    while (i < intervalsSize && intervals[i][1] < newInterval[0]){
        res[count] = (int*)malloc(2 * sizeof(int));
        res[count][0] = intervals[i][0];
        res[count][1] = intervals[i][1];
        (*returnColumnSizes)[count++] = 2;
        i++;
    }
    //merge overlap
    while (i < intervalsSize && intervals[i][0] <= newInterval[1]){
        newInterval[0] = (intervals[i][0] < newInterval[0]) ? intervals[i][0] : newInterval[0];
        newInterval[1] = (intervals[i][1] > newInterval[1]) ? intervals[i][1] : newInterval[1];
        i++;
    }
    //add merged interval
    res[count] = (int*)malloc(2 * sizeof(int));
    res[count][0] = newInterval[0];
    res[count][1] = newInterval[1];
    (*returnColumnSizes)[count++] = 2;

    //add the rest 
    while(i < intervalsSize){
        res[count] = (int*)malloc(2 * sizeof(int));
        res[count][0] = intervals[i][0];
        res[count][1] = intervals[i][1];
        (*returnColumnSizes)[count++] = 2;
        i++;
    }
    *returnSize = count;
    return res;
}
