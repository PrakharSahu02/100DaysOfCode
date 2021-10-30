// https://leetcode.com/problems/binary-tree-inorder-traversal

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

TreeNode *insert(TreeNode *root, int data)
{

    if (root == NULL)
    {
        return new TreeNode(data);
    }

    if (data < root->val)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

class Solution
{
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return ans;
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        return ans;
    }
};

int main()
{
    TreeNode *root = NULL;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    Solution bt;
    bt.inorderTraversal(root);
    for (int i = 0; i < bt.ans.size(); i++)
    {
        cout << bt.ans[i] << " ";
    }
    cout << endl;
    return 0;
}