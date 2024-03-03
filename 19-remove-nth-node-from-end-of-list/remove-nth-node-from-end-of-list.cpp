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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tail = head;
        int length = 0;

        while(tail != NULL){
            length++;
            tail = tail->next;
        }

        

        int removeNode = (length - n)+1;
    //    cout<<removeNode<<endl;
        if(removeNode == 1){
            head = head->next;
            return head;
        }


        tail = head;
        ListNode* temp = NULL;
        ListNode* nextNode = head->next;


        while(removeNode != 1 && nextNode != NULL){
            removeNode--;
            temp = tail;
            tail = tail->next;
            nextNode = nextNode->next;
        }
        temp->next = nextNode;

 

        return head;
    }
};