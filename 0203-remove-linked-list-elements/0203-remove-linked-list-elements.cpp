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
    ListNode* removeElements(ListNode* head, int val) {
        rem(head,NULL,val);
        return head;
    }
    void rem(ListNode*& head,ListNode* prev,int val)
    {
        if(head == NULL) return;
        if(head->val == val)
        {
            if(prev == NULL) 
            {
                head = head->next;
                rem(head,NULL,val);
            }
            else
            {
                prev->next = head->next;
                rem(prev->next,prev,val);
            }
        }
        else rem(head->next,head,val);
    }
};