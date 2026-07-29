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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode end;
        ListNode* l3=&end;
        int i=0,c=0;
        while(l1 || l2 || c){

 //cause this can exceed the list pointer and return null in loop condiotion           
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;

            int sum = ( x + y +c );
            c=sum/10;

//naya listnode yesari banaunii hoo
            l3 -> next = new ListNode(sum%10);

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            l3 = l3->next;

        }
        if(l1) l3->next=l1;
        if(l2) l3->next=l2;

        return end.next;
    }
};