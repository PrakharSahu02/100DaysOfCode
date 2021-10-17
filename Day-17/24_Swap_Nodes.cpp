// https://leetcode.com/problems/swap-nodes-in-pairs/

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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        static int k=2;
        
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
            head->next = swapPairs(nextptr);
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
    Solution swap;
    ListNode *newhead = swap.swapPairs(head);
    display(newhead);
    return 0;
}