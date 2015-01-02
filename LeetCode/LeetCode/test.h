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

TEST(LongestSubStringTest, TestCase) {
    string testStr1 = "abcabcbb";
    string testStr2 = "bbbb";
    string testStr3 = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    int res1 = Solution::lengthOfLongestSubstring(testStr1);
    int res2 = Solution::lengthOfLongestSubstring(testStr2);
    int res3 = Solution::lengthOfLongestSubstring(testStr3);
    EXPECT_EQ(3,res1);
    EXPECT_EQ(1, res2);
    EXPECT_EQ(12, res3);
}


#endif
