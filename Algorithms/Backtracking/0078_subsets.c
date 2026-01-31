// Practice for: 0078_subsets.py
// Bridge logic from Python to C pointers here.

#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

//normal backtracking way

// void generate(int* nums, int numsSize, int index, int* current, int currentSize, int** result, int* returnSize, int* returnColumnSizes){
//     result[*returnSize] = (int*)malloc(currentSize * sizeof(int));

//     //every singe iteration
//     for (int i = 0; i < currentSize; i++){
//         result[*returnSize][i] = current[i];
//     }
//     returnColumnSizes[*returnSize] = currentSize;
//     (*returnSize)++;

//     //backtracking loop
//     for(int i = index; i < numsSize; i++){
//         current[currentSize] = nums[i];
//         generate(nums, numsSize, i + 1, current, currentSize + 1, result, returnSize, returnColumnSizes);
//     }
// }

// int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
//     //total combi, sum of n choose k = 2^n
//     int totalSubsets = pow(2, numsSize);
//     int** result = (int**)malloc(totalSubsets * sizeof(int*));
//     *returnColumnSizes = (int*)malloc(totalSubsets * sizeof(int));
//     *returnSize = 0;

//     int* current = (int*)malloc(numsSize * sizeof(int));
//     generate(nums, numsSize, 0, current, 0, result, returnSize, *returnColumnSizes);

//     free(current);
//     return result;
// }

//bit manipulation way 

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int total = 1 << numsSize;
    *returnSize = total;

    int** result = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));

    for(int i = 0; i < total; i++){
        int subsetSize = 0;
        for(int j = 0; j < numsSize; j++){
            //move jth bit to last position, &1 mask everything except last bit
            if ((i >> j) & 1){
                subsetSize++;
            }
            (returnColumnSizes)[i] = subsetSize;
            result[i] = (int*)malloc(subsetSize * sizeof(int));

            int currIdx = 0;
            for (int j = 0; j < numsSize; j++){
                if ((i >> j) & 1){
                    result[i][currIdx++] = nums[j];
                }
            }

        }
    }
    return result;
}