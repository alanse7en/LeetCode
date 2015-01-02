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
#include <string>
#include <sstream>

using namespace std;

namespace Solution {
    
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };
    
    /*  Helper Functions    */
    // For addTwoNumbers
    int getValueAndMoveNext(ListNode* & l) {
        int x = 0;
        if (l != NULL) {
            x = l->val;
            l = l->next;
        }
        
        return x;
    }
    // For median of two sorted arrays. Find the k-th element of two sorted arrays
    // 重点在于舍弃不可能出现第k大的部分，被舍弃的部分的数全都小于第k大的数
    double findKth(int A[], int m, int B[], int n, int k) {
        if (m > n)
            return findKth(B, n, A, m, k);
        if (m == 0)
            return B[k-1];
        if (k == 1)
            return min(A[0],B[0]);
        
        int pa = min(k/2,m); int pb = k-pa;
        
        if (A[pa-1] < B[pb-1])
            return findKth(A+pa, m-pa, B, n, k-pa);
        else if (A[pa-1] > B[pb-1])
            return findKth(A, m, B+pb, n-pb, k-pb);
        else
            return A[pa-1];
    }
/*  Functions to solve LeetCode problems    */
    /*
     Two Sum
     把剩余的值存入tmp的map中，利用map搜索的速度的优势降低复杂度
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
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
    /*
     Add two Numbers
     注意t的连接node的作用，以及不要忘记最后有可能进位
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode** t = &result;
        int carry = 0; int tmp = 0;
        
        while (l1 != NULL || l2 != NULL) {
            tmp = carry + getValueAndMoveNext(l1) + getValueAndMoveNext(l2);
            carry = tmp/10;
            ListNode* node = new ListNode (tmp%10);
            *t = node;
            t = &(node->next);
        }
        
        if (carry > 0) {
            ListNode* node = new ListNode (carry);
            *t = node;
        }
        
        return result;
    }
    
    /*
     Length of longest sub-string
     将字符的位置存入map中，通过在map中查询是否出现过当前的字符判断是否重复，注意是否更新lastRepeatPos还取决于当前的LRP和重复字符的位置
     */
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int lastRepeatPos = -1;
        map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i])!=m.end() && lastRepeatPos<m[s[i]])
                lastRepeatPos = m[s[i]];
            if (i-lastRepeatPos > result)
                result = i - lastRepeatPos;
            m[s[i]] = i;
        }
        
        return result;
    }
    
    /*
     Find median of two sorted arrays
     难点在于对复杂度的要求是log(m+n)，解决寻找第k大的问题之后，中位数的问题自然解决
     */
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ( (m+n)%2 == 0 )
            return (findKth(A, m, B, n, (m+n)/2)+
                    findKth(A, m, B, n, (m+n)/2+1))/2;
        else
            return findKth(A, m, B, n, (m+n)/2+1);
    }
    
    /*
     Count and say
     比较简单的一题，只需注意将最后的结果读入到字符串中
     */
    string countAndSay(int n) {
        string seq = "1";
        int ite = 1;
        while (ite < n) {
            stringstream newSeq;
            char last = seq[0];
            int count = 0;
            for (size_t i = 0; i < seq.size(); ++i) {
                if (last == seq[i])
                    ++count;
                else {
                    newSeq << count << last;
                    last = seq[i];
                    count = 1;
                }
            }
            newSeq << count << last;
            seq = newSeq.str();
            ++ite;
        }
        
        return seq;
    }
    
    // End of namespace
};

#endif