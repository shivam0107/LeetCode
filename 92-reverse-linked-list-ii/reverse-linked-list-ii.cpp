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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        //time complexity -- O(N)
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* leftPre = dummy;
        ListNode* curr = head;

        for(int i =0;i <left-1; i++){
                leftPre = leftPre->next;
                curr = curr->next;
        }
      
        ListNode* subListHead = curr;
        ListNode* prevNode = NULL;
        ListNode* forward = NULL;

        for(int i = 0; i<right-left+1; i++){   

             forward = curr->next;
             curr->next = prevNode;
             prevNode = curr;
             curr = forward;
           
         }

        leftPre->next = prevNode;
        subListHead->next = curr;

         return dummy->next;


    }
};