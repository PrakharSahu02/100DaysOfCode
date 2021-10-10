// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode((l1->val) + (l2->val));
        ListNode *temp = l3;
        int carry = 0;
        for (carry = 0; l3->val > 9;)
        {
            l3->val = (l3->val) - 10;
            carry++;
        }
        while (l1->next != NULL && l2->next != NULL)
        {
            l1 = l1->next;
            l2 = l2->next;
            ListNode *sum = new ListNode((l1->val) + (l2->val) + (carry));
            for (carry = 0; sum->val > 9;)
            {
                sum->val = (sum->val) - 10;
                carry++;
            }
            temp->next = sum;
            temp = temp->next;
        }
        while (l1->next != NULL)
        {
            l1 = l1->next;
            ListNode *sum = new ListNode((l1->val) + (carry));
            for (carry = 0; sum->val > 9;)
            {
                sum->val = (sum->val) - 10;
                carry++;
            }
            temp->next = sum;
            temp = temp->next;
        }
        while (l2->next != NULL)
        {
            l2 = l2->next;
            ListNode *sum = new ListNode((l2->val) + (carry));
            for (carry = 0; sum->val > 9;)
            {
                sum->val = (sum->val) - 10;
                carry++;
            }
            temp->next = sum;
            temp = temp->next;
        }
        if (carry == 1)
        {
            ListNode *sum = new ListNode((carry));
            temp->next = sum;
            temp = temp->next;
        }
        return l3;
    }
};

void InsertAtTail(ListNode *&head, int val)
{

    ListNode *n = new ListNode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    ListNode *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    InsertAtTail(l1, 1);
    InsertAtTail(l1, 2);
    InsertAtTail(l1, 3);
    InsertAtTail(l1, 4);
    InsertAtTail(l2, 7);
    InsertAtTail(l2, 2);
    InsertAtTail(l2, 3);
    InsertAtTail(l2, 4);
    Solution sum;
    ListNode *newhead = sum.addTwoNumbers(l1, l2);
    display(newhead);
    return 0;
}