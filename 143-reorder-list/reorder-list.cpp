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

    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
         

        }

        return prev;

    }

    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL){
            return;
        }

        ListNode* mid = NULL;
        ListNode* slow  = head;
        ListNode* fast = head;
        int n  = 0;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            n++;
        }

        mid = slow;

        ListNode* last = reverse(mid->next);
        mid->next = NULL;
        ListNode* curr = head;
      

        while(last){
            ListNode* temp1 = curr->next;
            ListNode* temp2 = last->next;

            curr->next = last;
            last->next = temp1;
            curr = temp1;
            last = temp2;
        }






      

    }
};