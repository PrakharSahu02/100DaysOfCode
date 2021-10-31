// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        else if (p == NULL || q == NULL)
        {
            return false;
        }
        else
        {
            bool cond1 = p->val == q->val;
            bool cond2 = isSameTree(p->left, q->left);
            bool cond3 = isSameTree(p->right, q->right);
            return cond1 && cond2 && cond3;
        }
    }
};

int main()
{
    struct TreeNode *root1 = new TreeNode(10);
    struct TreeNode *root2 = new TreeNode(10);
    root1->left = new TreeNode(2);
    root2->left = new TreeNode(2);
    root1->right = new TreeNode(13);
    root2->right = new TreeNode(13);
    root1->left->left = new TreeNode(1);
    root2->left->left = new TreeNode(1);
    root1->right->left = new TreeNode(11);
    root2->right->left = new TreeNode(11);
    root1->left->right = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root1->right->right = new TreeNode(14);
    root2->right->right = new TreeNode(14);
    Solution ide;
    if (ide.isSameTree(root1, root2))
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