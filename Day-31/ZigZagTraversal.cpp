#include <iostream>
#include <stack>

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

void zigZag(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> curr;
    stack<Node *> next;
    bool leftToright = true;
    curr.push(root);
    while (!curr.empty())
    {
        Node *temp = curr.top();
        curr.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (leftToright)
            {
                if (temp->left)
                {
                    next.push(temp->left);
                }
                if (temp->right)
                {
                    next.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    next.push(temp->right);
                }
                if (temp->left)
                {
                    next.push(temp->left);
                }
            }
        }
        if (curr.empty())
        {
            leftToright = !leftToright;
            swap(curr, next);
        }
    }
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
    zigZag(root);
    cout << endl;
    return 0;
}