// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode *root)
    {

        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        if (root->left != NULL)
        {
            flatten(root->left);

            TreeNode *temp = root->right;
            root->right = root->left;
            root->left = NULL;

            TreeNode *T = root->right;
            while (T->right != NULL)
            {
                T = T->right;
            }
            T->right = temp;
        }
        flatten(root->right);
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
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    inOrder(root);
    cout << endl;
    Solution bt;
    bt.flatten(root);
    inOrder(root);
    cout << endl;
    return 0;
}