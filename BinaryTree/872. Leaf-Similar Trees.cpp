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




class Solution {
private:
    int nextLeaf(stack<TreeNode*>& st){
        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();
            if(top->left == NULL && top->right == NULL) return top->val;
            if(top->right)st.push(top->right);
            if(top->left)st.push(top->left);
        }
        return -1;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        st1.push(root1);
        st2.push(root2);
        while(!st1.empty() && !st2.empty()){
            if(nextLeaf(st1) != nextLeaf(st2)){
                return false;
            }
        }
        return st1.empty() && st2.empty();
    }
};