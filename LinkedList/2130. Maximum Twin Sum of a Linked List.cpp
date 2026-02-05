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


// optimal :: TC-> O(n), SC-> O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private :
    ListNode* reverse(ListNode* head){
        if(head == NULL) return head;
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = reverse(slow);
        int ans = 0;
        ListNode* first = head;

        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};