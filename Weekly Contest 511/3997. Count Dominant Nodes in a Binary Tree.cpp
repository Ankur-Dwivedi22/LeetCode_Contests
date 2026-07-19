/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int ct = 0;
    int f(TreeNode *node)
    {
        if (!node)
        {
            return 0;
        }

        int left = f(node->left);
        int right = f(node->right);

        if (node->val >= left && node->val >= right)
        {
            ct++;
        }

        return max({node->val, left, right});
    }
    int countDominantNodes(TreeNode *root)
    {
        f(root);
        return ct;
    }
};