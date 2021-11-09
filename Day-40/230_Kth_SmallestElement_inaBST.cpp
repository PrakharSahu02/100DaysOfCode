// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    vector<int> nums;
    int kthSmallest(TreeNode *root, int k)
    {
        inOrder(root);
        return nums[k - 1];
    }

    void inOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        nums.push_back(root->val);
        inOrder(root->right);
        return;
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
    Solution sm;
    int ans = sm.kthSmallest(root, 1);
    cout << ans << endl;
    return 0;
}