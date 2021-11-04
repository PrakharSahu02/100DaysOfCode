// https://leetcode.com/problems/unique-binary-search-trees-ii/

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

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return constructTree(1,n);
    }
    
    vector<TreeNode *> constructTree(int start, int end)
{
    vector<TreeNode *> Tree;
    if (start > end)
    {
        Tree.push_back(NULL);
        return Tree;
    }
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = constructTree(start, i - 1);
        vector<TreeNode *> right = constructTree(i + 1, end);
        for (int j = 0; j < left.size(); j++)
        {
            TreeNode *l = left[j];
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *r = right[k];
                TreeNode *node = new TreeNode(i);
                node->left = l;
                node->right = r;
                Tree.push_back(node);
            }
        }
    }
    return Tree;
}
};

void preOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    Solution gt;
    vector<TreeNode *> totalTree = gt.generateTrees(3);
    for (int i = 0; i < totalTree.size(); i++)
    {
        cout << (i + 1) << " : ";
        preOrder(totalTree[i]);
        cout << endl;
    }
    return 0;
}