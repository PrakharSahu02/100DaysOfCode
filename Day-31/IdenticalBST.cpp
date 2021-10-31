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

bool isIdentical(Node *root1, Node *root2)
{

    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);
        return cond1 && cond2 && cond3;
    }
}

int main()
{
    struct Node *root1 = new Node(10);
    struct Node *root2 = new Node(10);
    root1->left = new Node(2);
    root2->left = new Node(2);
    root1->right = new Node(13);
    root2->right = new Node(13);
    root1->left->left = new Node(1);
    root2->left->left = new Node(1);
    root1->right->left = new Node(11);
    root2->right->left = new Node(11);
    root1->left->right = new Node(3);
    root2->left->right = new Node(3);
    root1->right->right = new Node(14);
    root2->right->right = new Node(14);
    if (isIdentical(root1, root2))
    {
        cout << "is Identical";
    }
    else
    {
        cout << "not Identical";
    }
    cout << endl;
    return 0;
}