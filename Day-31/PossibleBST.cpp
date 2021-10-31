#include <iostream>
#include <vector>

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

vector<Node *> constructTree(int start, int end)
{
    vector<Node *> Tree;
    if (start > end)
    {
        Tree.push_back(NULL);
        return Tree;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> left = constructTree(start, i - 1);
        vector<Node *> right = constructTree(i + 1, end);
        for (int j = 0; j < left.size(); j++)
        {
            Node *l = left[j];
            for (int k = 0; k < right.size(); k++)
            {
                Node *r = right[k];
                Node *node = new Node(i);
                node->left = l;
                node->right = r;
                Tree.push_back(node);
            }
        }
    }
    return Tree;
}

void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<Node *> totalTree = constructTree(1, 3);
    for (int i = 0; i < totalTree.size(); i++)
    {
        cout << (i + 1) << " : ";
        preOrder(totalTree[i]);
        cout << endl;
    }
    return 0;
}