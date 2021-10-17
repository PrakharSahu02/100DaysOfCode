// https://leetcode.com/problems/reverse-nodes-in-k-group/

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

void Insert(ListNode *&head, int val)
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

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *&head, int k)
    {
        if (countNodes(head) < k)
        {
            return head;
        }
        ListNode *prevptr = NULL;
        ListNode *currptr = head;
        ListNode *nextptr;

        int count = 0;
        while (currptr != NULL && count < k)
        {
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        if (nextptr != NULL)
        {
            head->next = reverseKGroup(nextptr, k);
        }
        return prevptr;
    }

    int countNodes(ListNode *head)
    {
        ListNode *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            i++;
            temp = temp->next;
        }
        return i;
    }
};

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
    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 4);
    Insert(head, 5);
    display(head);
    Solution rev;
    ListNode *newhead = rev.reverseKGroup(head, 2);
    display(newhead);
    return 0;
}