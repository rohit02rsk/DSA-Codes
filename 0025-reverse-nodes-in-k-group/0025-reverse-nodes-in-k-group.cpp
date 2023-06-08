class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        ListNode* temp = NULL;
        
        int count = k;
        
        while (curr != NULL) {
            if (count > 1) {
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;

                count--;
            } else {
                prev = curr;
                curr = curr->next;
                count = k;
                
                ListNode* end = curr;
                for (int i = 0; i < k; i++) {
                    if (end == NULL) {
                        return dummy->next;
                    }
                    end = end->next;
                }
            }
        }
        
        return dummy->next;
    }
};
