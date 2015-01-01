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

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    
public:
    /*
     Two Sum
     把剩余的值存入tmp的map中，利用map搜索的速度的优势降低复杂度
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
    /*
     Add two Numbers
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
    
private:
    // For addTwoNumbers
    int getValueAndMoveNext(ListNode* & l) {
        int x = 0;
        if (l != NULL) {
            x = l->val;
            l = l->next;
        }
        
        return x;
    }
};

#endif