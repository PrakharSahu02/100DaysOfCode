// https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (fast == NULL || fast->next == NULL)
            return NULL;

        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};

void makeCycle(ListNode *&head, int pos)
{
    ListNode *temp = head;
    ListNode *startNode;
    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

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
    Insert(head, 2);
    Insert(head, 3);
    Insert(head, 4);
    Insert(head, 5);
    Insert(head, 6);
    display(head);
    makeCycle(head, 3);
    Solution cycle;
    ListNode*newHead=cycle.detectCycle(head);
    cout<<newHead->val<<endl;
    return 0;
}