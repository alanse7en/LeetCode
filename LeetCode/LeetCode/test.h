//
//  test.h
//  LeetCode
//
//  Created by deng on 15/1/1.
//  Copyright (c) 2015年 deng. All rights reserved.
//

#ifndef LeetCode_test_h
#define LeetCode_test_h

#include <gtest/gtest.h>
#include "algorithms.h"
#include <vector>

using namespace std;

TEST(TwoSumTest, TestCase) {
    vector<int> testVec({2,7,11,15});
    vector<int> trueRes({1,2});
    vector<int> result = Solution::twoSum(testVec, 9);
    EXPECT_EQ(trueRes, result);
    trueRes = {2,4};
    result = Solution::twoSum(testVec, 15+7);
    EXPECT_EQ(trueRes, result);
}


#endif
