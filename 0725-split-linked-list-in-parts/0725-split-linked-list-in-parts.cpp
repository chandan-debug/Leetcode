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
private:
    int length(ListNode* head){
        int len = 0;
        while(head){
            head = head -> next;
            len++;
        }
        return len;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int len = length(head);
        int parts = len/k;
        int remaining = len % k;

        ListNode* p = head;
        while(p){
            ans.push_back(p);
            int x = parts;
            ListNode* temp;
            while(p && x){
                --x;
                temp = p;
                p = p -> next;
            }
            if(remaining){
                remaining--;
                temp = p;
                p = p -> next;
            }
            temp -> next = NULL;
        }

        int s = ans.size();
        while(s != k){
            ans.push_back(NULL);
            s++;
        }

        return ans;

    }
};