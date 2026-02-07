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
class Solution {
private:
    bool solve(TreeNode* root, int sum, int targetSum){
        if(root == NULL) return false;

        // check for the leaf
        if(root->left == NULL && root->right == NULL){
            sum += root->val;
            return sum == targetSum;
        }

        return solve(root->left, sum+root->val,targetSum) || solve(root->right, sum+root->val,targetSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,0,targetSum);
    }
};


// TC :: O(n) -> SC:: O(h)