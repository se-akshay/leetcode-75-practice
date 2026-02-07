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
    void solve(TreeNode* root, int sum, int targetSum,
               vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr) return;

        // include current node
        path.push_back(root->val);
        sum += root->val;

        // check leaf
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                ans.push_back(path);
            }
        } else {
            solve(root->left, sum, targetSum, path, ans);
            solve(root->right, sum, targetSum, path, ans);
        }

        // backtrack
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        vector<vector<int>> ans;
        solve(root,0,targetSum,vec,ans);
        return ans;
    }
};