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

public:
    int count(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
            
        }
        return cnt;
    }
    void circular(ListNode* head){
        ListNode* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0){return head;}

        int num=count(head);
        k=k%num;
        if(k==0){return head;}

         circular(head);
         ListNode* end=nullptr;
         ListNode* start=nullptr;

        for(int i=1; i<num-k;i++){
            head=head->next;
        }
        end=head;
        start=head->next;
        end->next=nullptr;
        return start;
    }
};