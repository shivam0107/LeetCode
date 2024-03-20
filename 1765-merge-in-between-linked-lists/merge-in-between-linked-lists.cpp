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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* dummy = new ListNode(0);

        dummy->next = list1;

        ListNode* prev1 = dummy;
        ListNode* prev2 = dummy->next;

        while(a != 0){
            prev1 = prev1->next;
            a--;
        }

         while(b != 0){
            prev2 = prev2->next;
            b--;
        }

        ListNode* tail = list2;

        while(tail->next != NULL){
            tail = tail->next;
        }

        prev1->next = list2;
        tail->next = prev2->next;

        return dummy->next;



    }
};