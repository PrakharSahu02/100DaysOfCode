// https://leetcode.com/problems/reverse-linked-list/

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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *newhead =reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
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
    Solution rev;
    ListNode* newhead= rev.reverseList(head);
    display(newhead);
    return 0;
}