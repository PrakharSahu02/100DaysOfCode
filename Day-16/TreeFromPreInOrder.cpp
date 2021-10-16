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

int search(int inOrder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *BuildTree(int preOrder[], int inOrder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preOrder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }

    int pos = search(inOrder, start, end, curr);
    node->left = BuildTree(preOrder, inOrder, start, pos - 1);
    node->right = BuildTree(preOrder, inOrder, pos + 1, end);
    return node;
}

void InOrder(struct Node *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    int preOrder[] = {1, 2, 4, 3, 5};
    int inOrder[] = {4, 2, 1, 5, 3};
    Node *root = BuildTree(preOrder, inOrder, 0, 4);
    InOrder(root);
    cout << endl;
    return 0;
}