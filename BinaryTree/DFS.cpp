// iterative inorder
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> st;
            TreeNode* node = root;
            while(true){
                if(node){
                    st.push(node);
                    node = node->left;
                }else{
                    if(st.empty()) break;
                    node = st.top();
                    st.pop();
                    ans.push_back(node->val);
                    node = node->right;
                }
            }
            return ans;
        }
    };


// iterative preorder
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            stack<TreeNode*> st;
            if(root == NULL) return ans;
            st.push(root);
            while(!st.empty()){
                TreeNode* top = st.top();
                st.pop();
                ans.push_back(top->val);
                if(top->right) st.push(top->right);
                if(top->left) st.push(top->left);
            }
            return ans;
        }
    };


// iterative postorder
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            if(root == NULL) return ans;
            stack<TreeNode*> st1;
            stack<TreeNode*> st2;
            st1.push(root);
            while(!st1.empty()){
                TreeNode* temp = st1.top();
                st1.pop();
                st2.push(temp);
                if(temp->left) st1.push(temp->left);
                if(temp->right) st1.push(temp->right);
            }
            while(!st2.empty()){
                ans.push_back(st2.top()->val);
                st2.pop();
            }
            return ans;
        }
    };