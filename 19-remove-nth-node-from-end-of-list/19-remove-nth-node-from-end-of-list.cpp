class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode*prev=head;
        ListNode *temp=head;
        
        for(int i=0;i<n;i++)
        {
            temp=temp->next;
        }
        
        if(!temp)
        {
            head=head->next;
            return head;
        }
        
        while(temp->next!=NULL)
        {
            prev=prev->next;
            temp=temp->next;
        }
    
        ListNode *node = prev->next->next;
        prev->next=node;      
        
        return head;
        
    }
};