// Bruteforce :: TC -> O(n), SC-> O(n)

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp){
            v.push_back(temp);
            temp=temp->next;
        }
        int ans = INT_MIN;
        int n = v.size(), i = 0, j = n-1;
        while(i <= j){
            ans = max(ans,v[i]->val + v[j]->val);
            i++;
            j--;
        }
        return ans;
    }
};