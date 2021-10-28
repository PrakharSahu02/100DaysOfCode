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

void leftview(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node *node = q.front();
            q.pop();
            if (i == 1)
            {
                cout << node->data << " ";
            }
            if (node->left!=NULL)
            {
                q.push(node->left);
            }
            if (node->right!=NULL)
            {
                q.push(node->right);
            }
        }
    }
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
    leftview(root);
    return 0;
}