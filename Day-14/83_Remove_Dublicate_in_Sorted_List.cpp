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

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *temp1 = head;
        ListNode *temp2 = head->next;

        while (temp2 != NULL)
        {
            if (temp2->val == temp1->val)
            {
                temp2 = temp2->next;
                Delete(temp1->next);
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return head;
    };

    void Delete(ListNode *&head)
    {

        ListNode *todelete = head;
        head = head->next;
        delete todelete;
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
    Insert(head, 1);
    Insert(head, 1);
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 3);
    display(head);
    Solution code;
    ListNode *newhead = code.deleteDuplicates(head);
    display(newhead);
    return 0;
}