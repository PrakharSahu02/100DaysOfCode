// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/submissions/

#include <iostream>
#include <stack>
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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
        {
            return ans;
        }

        stack<TreeNode *> curr;
        stack<TreeNode *> next;
        bool leftToright = false;
        curr.push(root);
        while (!curr.empty())
        {
            TreeNode *temp = curr.top();
            curr.pop();
            if (temp)
            {
                res.push_back(temp->val);
                if (leftToright)
                {
                    if (temp->right)
                    {
                        next.push(temp->right);
                    }
                    if (temp->left)
                    {
                        next.push(temp->left);
                    }
                }
                else
                {
                    if (temp->left)
                    {
                        next.push(temp->left);
                    }
                    if (temp->right)
                    {
                        next.push(temp->right);
                    }
                }
            }
            if (curr.empty())
            {
                ans.push_back(res);
                res.clear();
                leftToright = !leftToright;
                swap(curr, next);
            }
        }
        return ans;
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
    Solution trvsl;
    vector<vector<int>> vect = trvsl.zigzagLevelOrder(root);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}