class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num_lists = lists.size();
        int step = 1;

        while (step < num_lists) {
            for (int i=0; i+step < num_lists; i += (step*2))
                lists[i] = mergeTwoLists(lists[i], lists[i+step]);
            step *= 2;
        }
        
        return num_lists > 0 ? lists[0] : nullptr;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sentinel = new ListNode();
        ListNode* curr = sentinel;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            
            curr = curr->next;
        }
        
        curr->next = list1 ? list1 : list2;
        
        return sentinel->next;
    }
};