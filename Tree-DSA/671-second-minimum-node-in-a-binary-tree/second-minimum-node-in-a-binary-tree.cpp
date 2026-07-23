/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long dfs(TreeNode* root, int minValue) {
        if (root == NULL)
            return -1;

        if (root->val > minValue)
           return root->val;

        long left = dfs(root->left, minValue);
        long right = dfs(root->right, minValue);

        if(left==-1) return right;
        if(right==-1) return left;

        return min(left,right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root,root->val);
    }
};