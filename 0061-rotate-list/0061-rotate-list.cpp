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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* t = head;
        if(head == NULL) return head;
        int length = 1;
        while(temp->next!=NULL) 
        {
            temp = temp->next;
            length++;
        }
        cout<<temp->val;
        // temp->next = t;
        k = k%length;
        if(k==0) return head;
        int x = length-k;

        ListNode* prev = NULL;
        ListNode* curr = head;
        for(int i = 1;i<=x;i++)
        {
            prev = curr;
            curr = curr->next;
        }
        ListNode* start = curr;
        prev->next = NULL;
        while(curr->next!=NULL)
        {
            curr = curr->next;
        }
        curr->next = head;
        return start;
    }
};