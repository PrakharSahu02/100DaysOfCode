// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        

    if(l1==NULL){
        return l2;
    }

    if(l2==NULL){
        return l1;
    }

    ListNode *result;
    if (l1->val < l2->val)
    {result=l1;
    result->next= mergeTwoLists(l1->next,l2);
    }
    else
    {result=l2;
    result->next= mergeTwoLists(l1,l2->next);
    }
    return result;

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
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    Insert(head1, 1);
    Insert(head1, 3);
    Insert(head1, 5);
    Insert(head1, 7);
    Insert(head1, 9);
    Insert(head1, 11);
    Insert(head2, 2);
    Insert(head2, 4);
    Insert(head2, 6);
    Insert(head2, 8);
    Insert(head2, 10);
    display(head1);
    display(head2);
    Solution code;
    ListNode *newhead = code.mergeTwoLists(head1, head2);
    display(newhead);
    return 0;
}