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
    int C[] = {};
    int D[] = {1};
    res = Solution::findMedianSortedArrays(C, 0, D, 1);
    EXPECT_EQ(1.0, res);
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

TEST(RemoveElementTest, TestCase) {
    int A1[] = {4,5};
    int res = Solution::removeElement(A1, 2, 4);
    EXPECT_EQ(1, res);
    int A2[] = {1,2,3,2,3,4,5};
    res = Solution::removeElement(A2, 7, 2);
    EXPECT_EQ(5, res);
}

TEST(PascalTriangleIITest, TestCase) {
    vector<int> res0 = {1};
    vector<int> res1 = {1,1};
    vector<int> res2 = {1,2,1};
    vector<int> res3 = {1,3,3,1};
    EXPECT_EQ(res0, Solution::getRow(0));
    EXPECT_EQ(res1, Solution::getRow(1));
    EXPECT_EQ(res2, Solution::getRow(2));
    EXPECT_EQ(res3, Solution::getRow(3));
}

TEST(MaxDepthTest, HandleOneNode) {
    Solution::TreeNode node0(0);
    EXPECT_EQ(1, Solution::maxDepth(&node0));
}

TEST(MinDepthTest, HandleOneNode) {
    Solution::TreeNode node0(0);
    EXPECT_EQ(1, Solution::minDepth(&node0));
}

TEST(ZigZagTest, TestCase) {
    string test = "PAYPALISHIRING";
    string res =  "PAHNAPLSIIGYIR";
    EXPECT_EQ(res, Solution::convert(test, 3));
}

TEST(MajorityTest, TestCase) {
    vector<int> iv ({1});
    EXPECT_EQ(1, Solution::majorityElement(iv));
    iv = {1,1,2};
    EXPECT_EQ(1, Solution::majorityElement(iv));
    iv = {1,2,1,3};
    EXPECT_EQ(1, Solution::majorityElement(iv));
}
#endif
