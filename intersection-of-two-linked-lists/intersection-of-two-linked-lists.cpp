/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        unordered_map<ListNode *, int> mp;

        ListNode *a = headA;
        ListNode *b = headB;

        while (a || b)
        {
            if (a)
            {
                if (mp[a] > 0)
                    return a;
                mp[a]++;
                a=a->next;
            }
            if (b)
            {
                if (mp[b] > 0)
                    return b;
                mp[b]++;
                b=b->next;
            }
        }
        return NULL;
    }
};