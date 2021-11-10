// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/submissions/

#include <iostream>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> order;
    TreeNode *insertNode(TreeNode *cur, int val)
    {
        if (!cur)
            return new TreeNode(val);
        if (order[val] < order[cur->val])
            cur->left = insertNode(cur->left, val);
        else
            cur->right = insertNode(cur->right, val);
        return cur;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
            order[inorder[i]] = i;
        TreeNode *head = nullptr;
        for (int i = postorder.size() - 1; i >= 0; i--)
        {
            head = insertNode(head, postorder[i]);
        }
        return head;
    }
};

int main()
{
    vector<int> post = {4, 2, 5, 3, 1};
    vector<int> in = {4, 2, 1, 5, 3};
    Solution bld;
    TreeNode *root = bld.buildTree(in, post);
    return 0;
}