// https://leetcode.com/problems/linked-list-cycle/description/

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
    bool hasCycle(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return false;

        ListNode *slow, *fast;
        slow = head;
        fast = head;

        while (slow != NULL && fast != NULL)
        {
            slow = slow->next;
            if (!fast->next)
                break;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};