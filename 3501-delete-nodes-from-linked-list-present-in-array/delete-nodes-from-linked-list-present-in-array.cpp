class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());

        
        while (head && st.find(head->val) != st.end()) {
            head = head->next;
        }

        ListNode* temp = head;
        
        while (temp) {
           
            if (temp->next && st.find(temp->next->val) != st.end()) {
                temp->next = temp->next->next;  
            } else {
                temp = temp->next;  
            }
        }

        return head;
    }
};