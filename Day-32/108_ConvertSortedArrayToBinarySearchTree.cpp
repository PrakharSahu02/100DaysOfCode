// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return BST(nums, 0, nums.size() - 1);
    }

    TreeNode *BST(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = BST(nums, start, mid - 1);
        root->right = BST(nums, mid + 1, end);
        return root;
    }
};

void inOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Solution bst;
    TreeNode *root = bst.sortedArrayToBST(arr);
    inOrder(root);
    cout << endl;
    return 0;
}
