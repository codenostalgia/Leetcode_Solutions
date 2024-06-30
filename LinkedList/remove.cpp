// https://leetcode.com/problems/remove-linked-list-elements/

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

// Using Recursion
class Solution
{
public:
    ListNode *removeElements(ListNode *node, int val)
    {
        if (node == NULL)
            return NULL;

        ListNode *nextValidNode = removeElements(node->next, val);

        if (node->val == val)
            return nextValidNode;
        else
        {
            node->next = nextValidNode;
            return node;
        }
    }
};