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
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node *root)
{

    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }
    Info leftInfo = largestBST(root->left);
    Info rightInfo = largestBST(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    struct Node *root= new Node(10);
    root->left = new Node(2);
    root->right = new Node(13);
    root->left->left = new Node(1);
    root->right->left = new Node(11);
    root->left->right = new Node(3);
    root->right->right = new Node(14);
    cout<<largestBST(root).ans<<endl;
    return 0;
}