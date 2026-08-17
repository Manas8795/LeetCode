/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> m;
        ListNode* temp = head;
        // int x = 1;
        // if(head == NULL) return temp;
        
        while(temp!=NULL)
        {
            if(m.count(temp)>0) return temp;
            m[temp] = 1;
            temp = temp->next;
        }
        return temp;
    }
};