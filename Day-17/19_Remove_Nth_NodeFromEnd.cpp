// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (countNodes(head) > n)
        {
            head->next = removeNthFromEnd(head->next, n);
            return head;
        }
        else
        {
            ListNode *todelete = head;
            ListNode *temp = head->next;
            head->next = NULL;
            delete todelete;
            return temp;
        }
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

int amin()
{
    int n;
    cin >> n;
    ListNode *head = NULL;
    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 4);
    Insert(head, 5);
    display(head);
    Solution rem;
    ListNode *newhead = rem.removeNthFromEnd(head, n);
    display(newhead);
    return 0;
}