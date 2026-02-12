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
    
    int countPath(TreeNode* root, long long targetSum) {
        if (!root) return 0;
        
        int count = 0;
        
        if (root->val == targetSum)
            count++;
        
        count += countPath(root->left, targetSum - root->val);
        count += countPath(root->right, targetSum - root->val);
        
        return count;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        int count = 0;
        
        count += countPath(root, targetSum);           // start from current
        count += pathSum(root->left, targetSum);       // start from left
        count += pathSum(root->right, targetSum);      // start from right
        
        return count;
    }
};