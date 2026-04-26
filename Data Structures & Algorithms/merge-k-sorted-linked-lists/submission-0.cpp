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
struct cmp
{
bool operator()(ListNode* a , ListNode* b){
    return a->val>b->val;
}
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*,vector<ListNode*>,cmp> qu;
        ListNode* head=new ListNode(0);

        ListNode* dummy=head;

        int len=lists.size();
        for(int i=0;i<len;i++)
        {
            if(lists[i])
                qu.push(lists[i]);
        }
        while(qu.size())
        {
            ListNode *node=qu.top();
            qu.pop();
            if(node->next)
                qu.push(node->next);
            dummy->next=node;
            dummy=dummy->next;
        }
    return head->next;    
    }
};
