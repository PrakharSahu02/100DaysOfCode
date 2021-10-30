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

bool isBST(Node *root, Node *min = NULL, Node *max = NULL)
{

    if (root == NULL)
    {
        return true;
    }

    if (min != NULL && root->data <= min->data)
    {
        return false;
    }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid and rightValid;
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(13);
    root->left->left = new Node(1);
    root->right->left = new Node(11);
    root->left->right = new Node(3);
    root->right->right = new Node(14);
    if (isBST(root))
    {
        cout << "is valid";
    }
    else
    {
        cout << "not valid";
    }
    cout << endl;
    return 0;
}