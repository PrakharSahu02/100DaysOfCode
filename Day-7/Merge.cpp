#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void Insert(node *&head, int val)
{

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

node *MergeRecursion(node *&head1, node *&head2)
{

    if(head1==NULL){
        return head2;
    }

    if(head2==NULL){
        return head1;
    }

    node *result;
    if (head1->data < head2->data)
    {result=head1;
    result->next= MergeRecursion(head1->next,head2);
    }
    else
    {result=head2;
    result->next= MergeRecursion(head1,head2->next);
    }
    return result;
}

node *Merge(node *&head1, node *&head2)
{

    node *p1 = head1;
    node *p2 = head2;
    node *dummy = new node(-1);
    node *p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p1 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummy->next;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
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
    // node *newhead = Merge(head1, head2);
    node *newhead = MergeRecursion(head1, head2);
    display(head1);
    display(head2);
    display(newhead);
    return 0;
}