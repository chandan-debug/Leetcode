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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);  
        ListNode* prev = dummy;
        
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        
        // Attach the remaining nodes (if any) from either list
        if (list1 != NULL) {
            prev->next = list1;
        } else {
            prev->next = list2;
        }
        
        return dummy->next;  // Return the merged list starting from the next of dummy node
    }
};
