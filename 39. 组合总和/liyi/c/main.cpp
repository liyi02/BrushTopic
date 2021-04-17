//
//  main.cpp
//  39
//
//  Created by Yi Li on 2021/4/17.
//

#include <iostream>
using namespace std;

int *copyIntArray(int *array, int arrayLength) {
    int *newArray = (int *)malloc(sizeof(int) *arrayLength);
    for (int i = 0; i < arrayLength; i ++ ) {
        newArray[i] = array[i];
    }
    return newArray;
}

void calculateSum(int position, int tempSum, int* candidates, int candidatesSize, int target,  int *tempArray, int tempCount, int **res, int resCount, int* returnSize, int** returnColumnSizes) {
    if (position > candidatesSize || tempSum > target) {
        return ;
    }
    
    tempSum = tempSum + candidates[position];
    tempArray[tempCount] = candidates[position];
    tempCount ++;
    
    if (tempSum == target) {
        int *newArray = copyIntArray(tempArray, tempCount);
        res[resCount] = (int *)malloc(sizeof(int)*tempCount);
        for (int i = 0; i < tempCount; i ++ ) {
            res[resCount][i] = tempArray[i];
        }
        resCount++;
        *returnSize = resCount;
//        *returnColumnSizes[resCount] = tempCount;
    }
    calculateSum(position, tempSum, candidates, candidatesSize, target, tempArray, tempCount, res, resCount ,returnSize, returnColumnSizes);
    calculateSum(position + 1, tempSum, candidates, candidatesSize, target, tempArray, tempCount, res, resCount, returnSize, returnColumnSizes);
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *)*200);
    int *tempArray = (int *)malloc(sizeof(int)*200);
    calculateSum (0, 0, candidates, candidatesSize, target, tempArray, 0, res, 0, returnSize, returnColumnSizes);
    return res;
}


int main(int argc, const char * argv[]) {
    int* candidates = (int *)malloc(sizeof(int)*4);
    candidates[0] = 2;
    candidates[1] = 3;
    candidates[2] = 6;
    candidates[3] = 7;
    int target = 7;
    int returnSize = 0;
    int *returnColumnSizes = (int *)malloc(sizeof(int *)*200);
    int **res = combinationSum(candidates, 4, target, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < 3; j++) {
            cout<< res[i][j]<<endl;
        }
    }
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
