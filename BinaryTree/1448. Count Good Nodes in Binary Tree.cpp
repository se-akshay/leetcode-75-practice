// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.


class Solution {
private:
    void helper(TreeNode* root, int maxSoFar, int& count) {
        if (root == nullptr) return;

        if (root->val >= maxSoFar) {
            count++;
            maxSoFar = root->val;
        }

        helper(root->left, maxSoFar, count);
        helper(root->right, maxSoFar, count);
    }

public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        helper(root, INT_MIN, count);
        return count;
    }
};


// TC:: O(n)
// SC:: O(h)