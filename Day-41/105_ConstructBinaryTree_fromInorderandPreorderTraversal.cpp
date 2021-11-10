// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/

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
    int i = 0;
    TreeNode *fun(vector<int> &p, vector<int> &in, int s, int e, unordered_map<int, int> &m)
    {
        if (s > e)
            return NULL;

        int ele = p[i++];
        TreeNode *r = new TreeNode(ele);
        if (s == e)
            return r;
        int index = m[ele];

        r->left = fun(p, in, s, index - 1, m);
        r->right = fun(p, in, index + 1, e, m);

        return r;
    }
    TreeNode *buildTree(vector<int> &p, vector<int> &in)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < in.size(); i++)
            m[in[i]] = i;
        return fun(p, in, 0, in.size() - 1, m);
    }
};

int main()
{
    vector<int> pre = {1, 2, 4, 3, 5};
    vector<int> in = {4, 2, 1, 5, 3};
    Solution bld;
    TreeNode *root = bld.buildTree(pre, in);
    return 0;
}