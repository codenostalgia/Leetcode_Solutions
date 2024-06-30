// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
            return NULL;

        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode *head, *tail;

        if (list1->val <= list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }

        tail = head;

        while (!(list1 == NULL || list2 == NULL))
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }

            cout << tail->val << endl;
        }

        if (list1 == NULL && list2 != NULL)
        {
            tail->next = list2;
        }
        if (list2 == NULL && list1 != NULL)
        {
            tail->next = list1;
        }

        return head;
    }
};