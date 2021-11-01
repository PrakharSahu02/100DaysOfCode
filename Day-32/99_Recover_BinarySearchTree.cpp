// https://leetcode.com/problems/recover-binary-search-tree/

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *first, *mid, *last, *prev;
        first = NULL;
        prev = NULL;
        mid = NULL;
        last = NULL;

        calpointer(root, &first, &mid, &last, &prev);
        if (first && last)
        {
            swap(&(first->val), &(last->val));
        }
        else if (first && mid)
        {
            swap(&(first->val), &(mid->val));
        }
    }
    void calpointer(TreeNode *root, TreeNode **first, TreeNode **mid, TreeNode **last, TreeNode **prev)
    {
        if (root == NULL)
        {
            return;
        }
        calpointer(root->left, first, mid, last, prev);

        if (*prev && root->val < (*prev)->val)
        {
            if (!*first)
            {
                *first = *prev;
                *mid = root;
            }
            else
            {
                *last = root;
            }
        }
        *prev = root;
        calpointer(root->right, first, mid, last, prev);
    }

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

void inOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main()
{
    struct TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    inOrder(root);
    cout << endl;
    Solution bst;
    bst.recoverTree(root);
    inOrder(root);
    cout << endl;
    return 0;
}