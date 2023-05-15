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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr) {
            if(!prev and curr->val == val) {
                ListNode* temp = head->next;
                head = temp;
                curr = temp;
            } else if(curr->val == val) {
                ListNode* temp = curr->next;
                prev->next = curr->next;
                curr = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};