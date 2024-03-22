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

    ListNode* reverse(ListNode* mid){
        ListNode* curr = mid;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;

        }

        return prev;

    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }
       ListNode* mid = NULL;
        ListNode* slow  = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        mid = slow;

        ListNode* last = reverse(mid);

        ListNode* curr = head;

        while(last != NULL){
            if(last->val != curr->val){
                return false;
            }
            last = last->next;
            curr = curr->next;
        }

        return true;










    }
};