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

TEST(MedianOfTwoSortedArraysTest, TestCase) {
    int A[] = {2,3,4};
    int B[] = {1};
    double res = Solution::findMedianSortedArrays(A, 3, B, 1);
    EXPECT_EQ(2.5, res);
    
}

TEST(CountAndSayTest, TestCase) {
    string s0 = "1";
    string s1 = "11";
    string s2 = "21";
    string s3 = "1211";
    string s4 = "111221";
    string s5 = "312211";
    string s6 = "13112221";
    
    EXPECT_EQ(s0, Solution::countAndSay(1));
    EXPECT_EQ(s1, Solution::countAndSay(2));
    EXPECT_EQ(s2, Solution::countAndSay(3));
    EXPECT_EQ(s3, Solution::countAndSay(4));
    EXPECT_EQ(s4, Solution::countAndSay(5));
    EXPECT_EQ(s5, Solution::countAndSay(6));
    EXPECT_EQ(s6, Solution::countAndSay(7));
}

#endif
