// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return ans;
        }

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 1; i <= n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node != NULL)
                {
                    res.push_back(node->val);

                    if (node->left)
                    {
                        q.push(node->left);
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                    }
                }
            }
            ans.push_back(res);
            res.clear();
        }
        reverse(ans.begin(), ans.end());
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
    Solution lo;
    vector<vector<int>> vect = lo.levelOrderBottom(root);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}