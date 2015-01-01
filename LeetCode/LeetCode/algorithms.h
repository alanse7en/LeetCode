//
//  algorithms.h
//  LeetCode
//
//  Created by deng on 15/1/1.
//  Copyright (c) 2015年 deng. All rights reserved.
//

#ifndef LeetCode_algorithms_h
#define LeetCode_algorithms_h

#include <vector>
#include <map>

using namespace std;

class Solution {
    
public:
    /*
     把剩余的值存入tmp的map中，例如map搜索的速度的优势降低复杂度
     */
    static vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int> tmp;
        vector<int> result;
        
        int size = (int)numbers.size();
        for (int idx = 0; idx < size; ++idx) {
            if (tmp.find(numbers[idx]) == tmp.end()) {
                tmp[target-numbers[idx]] = idx;
            } else {
                result.push_back(tmp[numbers[idx]]+1);
                result.push_back(idx+1);
                break;
            }
        }
        
        return result;
    }
};

#endif