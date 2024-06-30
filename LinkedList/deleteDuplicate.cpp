// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *currentNode, int val = -200)
    {
        if (currentNode == NULL)
            return NULL;

        if (currentNode->val == val)
        {
            return deleteDuplicates(currentNode->next, val);
        }
        else
        {
            currentNode->next = deleteDuplicates(currentNode->next, currentNode->val);
            return currentNode;
        }
    }
};