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

int diameter(Node *root,int *height)
{
    if (root == NULL)
    {
        *height=0;
        return 0;
    }

    int lh = 0;
    int rh = 0;
    int ldiameter = diameter(root->left,&lh);
    int rdiameter = diameter(root->right,&rh);
    int currdiameter = lh + rh + 1;
    *height=max(lh,rh)+1;
    return max(currdiameter, max(ldiameter, rdiameter));
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
    cout << diameter(root,0) << endl;
    return 0;
}