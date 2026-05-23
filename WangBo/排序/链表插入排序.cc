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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode *dummy = new ListNode;
        dummy->next=head;
        ListNode* cur;
        ListNode* tmp=head;
        while(tmp&&tmp->next){
            cur=tmp->next;
            if(cur->val< tmp->val){
                tmp->next=cur->next;
                ListNode*pre = dummy;
                ListNode*nex = dummy->next;
                while(nex!=tmp->next){
                    if(cur->val<nex->val){
                        pre->next=cur;
                        cur->next=nex;
                        break;
                    }
                    pre=nex;
                    nex=nex->next;
                }
            }
            else{
                tmp=cur;
            }
        }
        return dummy->next; 
    }
};