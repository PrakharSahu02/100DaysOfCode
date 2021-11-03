// https://leetcode.com/problems/binary-tree-right-side-view/

#include <iostream>
#include <queue>

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
    vector<int> ans;
    vector<int> rightSideView(TreeNode *root)
    {

        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (i == n - 1)
                {
                    ans.push_back(node->val);
                }
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    Solution rt;
    vector<int> v = rt.rightSideView(root);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}