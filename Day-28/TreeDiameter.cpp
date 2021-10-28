#include <iostream>
#include <queue>

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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdiameter = lheight + rheight + 1;
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(currdiameter, max(ldiameter, rdiameter) + 1);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->left->right = new Node(6);
    root->right->right = new Node(7);
    cout << diameter(root) << endl;
    return 0;
}