// https://leetcode.com/problems/validate-binary-search-tree/submissions/

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
    bool isValidBST(TreeNode *root)
    {
        return isBST(root);
    }
    bool isBST(TreeNode *root, TreeNode *min = NULL, TreeNode *max = NULL)
    {

        if (root == NULL)
        {
            return true;
        }

        if (min != NULL && root->val <= min->val)
        {
            return false;
        }
        if (max != NULL && root->val >= max->val)
        {
            return false;
        }

        bool leftValid = isBST(root->left, min, root);
        bool rightValid = isBST(root->right, root, max);

        return leftValid and rightValid;
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
    Solution BST;
    if (BST.isValidBST(root))
    {
        cout << "is valid";
    }
    else
    {
        cout << "not valid";
    }
    cout << endl;
    return 0;
}