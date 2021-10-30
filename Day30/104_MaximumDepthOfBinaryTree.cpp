// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <iostream>
#include <vector>

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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lheight = maxDepth(root->left);
        int rheight = maxDepth(root->right);
        return max(lheight, rheight) + 1;
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
    Solution dep;
    cout << dep.maxDepth(root) << endl;
    return 0;
}