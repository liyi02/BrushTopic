//
//  main.cpp
//  39-2
//
//  Created by Yi Li on 2021/4/17.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>>combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int>tempVector;
        appropriateSum(candidates, tempVector, target, 0, result);
        return result;
    }
    
    void appropriateSum(vector<int> &candidates,vector<int>tempVector, int target, int begin, vector<vector<int>> &result) {
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            result.push_back(tempVector);
            return;
        }
        
        for (int i = begin; i < candidates.size(); i++) {
            tempVector.push_back(candidates[i]);
            appropriateSum(candidates, tempVector, target - candidates[i], i, result);
            tempVector.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution s1;
    
    vector<int>array;
    array.push_back(2);
    array.push_back(3);
    array.push_back(6);
    array.push_back(7);

    vector<vector<int>> v1 = s1.combinationSum(array, 7);
    
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1[i].size(); j++) {
            cout << v1[i][j] << endl;
        }
    }
    return 0;
}
