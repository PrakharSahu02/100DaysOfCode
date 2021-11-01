#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void calpointer(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }
    calpointer(root->left, first, mid, last, prev);

    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calpointer(root->right, first, mid, last, prev);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recover(Node *root)
{
    Node *first, *mid, *last, *prev;
    first = NULL;
    prev = NULL;
    mid = NULL;
    last = NULL;

    calpointer(root, &first, &mid, &last, &prev);
    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(13);
    root->left->left = new Node(9);
    root->right->left = new Node(11);
    root->left->right = new Node(7);
    root->right->right = new Node(14);
    inOrder(root);
    cout << endl;
    recover(root);
    inOrder(root);
    cout << endl;
    return 0;
}