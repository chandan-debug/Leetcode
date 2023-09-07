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
    ListNode* reverseLL(ListNode* h) 
    {
        ListNode* prev = NULL;
        ListNode* curr = h;
        ListNode* nxt = h;

        while(curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* a = head;
        ListNode* p = head;
        if(left == 1)
        {
            a = head;
            p = head;
        }
        else{
            int i = 1;
            while(i<left - 1)
            {
                a = a->next;
                i++;
            }
            p = a->next;
        }

        ListNode* q = p;
        int s = right-left;
        int i = 0;
        while(i<s)
        {
            q = q->next;
            i++;
        }
        ListNode* b = q->next;

        q->next = NULL;
        ListNode* rev_head = reverseLL(p);

        if(left == 1)
        {
            p->next = b;
            return rev_head;
        }
        a->next = rev_head;
        p->next = b;
        return head;
    }
};