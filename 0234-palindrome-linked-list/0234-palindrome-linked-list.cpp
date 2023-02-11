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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        //slow is the middlle
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // for odd case
        if(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
        }
        ListNode* prev=NULL;
        // revrese halfback
        while(slow!=NULL && slow->next!=NULL){
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        if(slow!=NULL){
            slow->next=prev;
        }
        fast=head;
        while(slow!=NULL and fast!=NULL ){
            if(slow->val!=fast->val){
                return false;
            }
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};