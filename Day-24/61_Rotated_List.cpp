// https://leetcode.com/problems/rotate-list/

// https://leetcode.com/problems/delete-node-in-a-linked-list/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;
        int size = count(head);
        if (k >= size)
        {
            k %= size;
        }
        while (k != 0)
        {
            ListNode *temp = head;
            ListNode *prev = head;
            while (temp->next != NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            temp->next = head;
            head = prev->next;
            prev->next = NULL;
            k--;
        }
        return head;
    }

    int count(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count += 1;
            temp = temp->next;
        }
        return count;
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
    ListNode *head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    display(head);
    Solution del;
    ListNode *newHead = del.rotateRight(head, 3);
    display(newHead);
    return 0;
}