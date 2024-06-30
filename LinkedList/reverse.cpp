// https://leetcode.com/problems/reverse-linked-list/

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

// iterative approach
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        if (!head || !head->next)
            return head;

        struct ListNode *prev, *next;
        prev = NULL;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

//recursive approach
// class Solution
// {
// public:
//     ListNode *reverse(ListNode *prev, ListNode *current)
//     {
//         if (current == NULL)
//             return prev;
//         ListNode *next = current->next;
//         current->next = prev;
//         return reverse(current, next);
//     }

//     ListNode *reverseList(ListNode *head)
//     {
//         if (!head || !head->next)
//             return head;
//         return reverse(NULL, head);
//     }
// };