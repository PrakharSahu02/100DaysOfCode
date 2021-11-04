// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode *root)
    {
        return symmetric(root, root);
    }
    bool symmetric(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
        {
            return true;
        }
        if (root1 == NULL || root2 == NULL)
        {
            return false;
        }
        return ((root1->val == root2->val) && symmetric(root1->left, root2->right) && symmetric(root2->left, root1->right));
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(11);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(14);
    Solution ide;
    if (ide.isSymmetric(root))
    {
        cout << "is Identical";
    }
    else
    {
        cout << "not Identical";
    }
    cout << endl;
    return 0;
}