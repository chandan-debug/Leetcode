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
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find the middle of the linked list
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the linked list
        slow->next = reverselist(slow->next);
        slow = slow->next;
        
        // Compare the reversed second half with the first half
        while (slow != NULL) {
            if (slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
    
    ListNode* reverselist(ListNode* head) {
        ListNode* dummy = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
        }
        return dummy;
    }
};
