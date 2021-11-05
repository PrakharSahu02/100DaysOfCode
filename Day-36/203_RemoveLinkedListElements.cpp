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

void InsertAtHead(ListNode *&head, int val)
{

    ListNode *n = new ListNode(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    ListNode *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void Insert(ListNode *&head, int val)
{

    ListNode *n = new ListNode(val);
    if (head == NULL)
    {
        InsertAtHead(head, val);
        return;
    }
    ListNode *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
        {
            return head;
        }

        while (head->val == val)
        {
            if (head->next == NULL)
            {
                return NULL;
            }
            else
                head = head->next;
        }
        ListNode *temp1 = head;
        ListNode *temp2 = head->next;

        while (temp2 != NULL)
        {
            if (temp2->val == val)
            {
                ListNode *todelete = temp2;
                if (temp2->next == NULL)
                {
                    temp1->next = NULL;
                    delete todelete;
                    return head;
                }
                temp1->next = temp2->next;
                temp2 = temp2->next;
                delete todelete;
            }
            else
            {
                temp2 = temp2->next;
                temp1 = temp1->next;
            }
        }
        return head;
    }

    void DeleteAtHead(ListNode *&head)
    {
        ListNode *temp = head;
        if (temp->next != NULL)
        {
            temp = temp->next;
        }
        ListNode *todelete = head;
        head = head->next;
        delete todelete;
    }
};

void display(ListNode *head)
{
    ListNode *temp = head;
    do
    {
        cout << temp->val << "->";
        temp = temp->next;
    } while (temp != head);
    cout <<"NULL"<< endl;
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
    Insert(head, 7);
    display(head);
    Solution dt;
    ListNode* ans=dt.removeElements(head, 5);
    display(ans);
    return 0;
}