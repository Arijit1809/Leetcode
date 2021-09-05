class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans = new ListNode();
        ans->next = head;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur!=NULL && cur->next!=NULL){
            if(cur->val!=cur->next->val){
                prev = cur;
                cur=cur->next;
            }else{
                int rep = cur->val;
                while(cur->val==rep && cur->next!=NULL){
                    cur=cur->next;
                }
                if(cur->next==NULL && cur->val==rep){
                    cur=NULL;
                }
                if(ans->next->val == rep){
                    ans->next = cur;
                }else{
                    prev->next=cur;    
                }
            }
        }
        return ans->next;
    }
};