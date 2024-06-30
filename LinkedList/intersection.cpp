// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        if (headA == NULL)
            return headB;
        if (headB == NULL)
            return headA;

        ListNode *node1, *node2;
        node1 = headA;
        node2 = headB;

        while (true)
        {
            if (node1 == node2 && node1 != NULL)
                return node1;
            if (node1->next == NULL && node2->next == NULL)
                return NULL;
            if (node1->next == NULL)
                node1 = headB;
            else
                node1 = node1->next;
            if (node2->next == NULL)
                node2 = headA;
            else
                node2 = node2->next;
        }

        return NULL;
    }
};




