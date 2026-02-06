// TC: O(n), SC: O(l) :: l -> number of leafs

class Solution {
private:
    void getLeafs(TreeNode* root, vector<int>& leaf){
        if(root == nullptr) return;
        if(root->left == NULL && root->right == NULL){
            leaf.push_back(root->val);
        }
        getLeafs(root->left,leaf);
        getLeafs(root->right,leaf);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1 , leaf2;
        getLeafs(root1,leaf1);
        getLeafs(root2,leaf2);
        int n = leaf1.size(), m = leaf2.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            if(leaf1[i]!=leaf2[i]){
                return false;
            }
        }
        return true;
    }
};