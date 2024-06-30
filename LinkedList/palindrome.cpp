// https://leetcode.com/problems/palindrome-linked-list/

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
    ListNode *reverse(ListNode *prev, ListNode *current)
    {
        if (!current)
            return prev;
        ListNode *next = current->next;
        current->next = prev;
        return reverse(current, next);
    }

    bool isPalindrome(ListNode *head)
    {

        if (!head || !head->next)
            return true;

        ListNode *slow, *fast;
        slow = head;
        fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *reversed;

        if (!fast)
            reversed = reverse(NULL, slow);
        else
            reversed = reverse(NULL, slow->next);

        while (reversed)
        {
            if (reversed->val == head->val)
            {
                reversed = reversed->next;
                head = head->next;
            }
            else
                return false;
        }

        return true;
    
    }
};