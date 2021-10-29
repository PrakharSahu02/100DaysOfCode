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

void PrintSubTree(Node *root, int k)
{

    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    PrintSubTree(root->left, k - 1);
    PrintSubTree(root->right, k - 1);
}

int PrintNodeAtK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root == target)
    {
        PrintSubTree(root, k);
        return 0;
    }
    int dl = PrintNodeAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            PrintSubTree(root->right,  k - dl - 2);
        }
    }
    int dr = PrintNodeAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            PrintSubTree(root->left,  k - dl - 2);
        }
    }
    return -1;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    PrintNodeAtK(root, root->left, 1);
    cout << endl;
    return 0;
}