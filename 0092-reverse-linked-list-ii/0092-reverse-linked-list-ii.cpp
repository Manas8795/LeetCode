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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* t1 = dummy;
        ListNode* r = head;
        int x = 1;
        while(x!=left)
        {
            t1 = t1->next;
            x++;
        }
        ListNode* l = t1->next;
        // t1->next = NULL;
        x = 1;
        while(x!=right)
        {
            r = r->next;
            x++;
        }
        ListNode* t2 = r->next;
        r->next = NULL;
        ListNode* temp = l;
        ListNode* prev = NULL;
        
        while(temp!=NULL)
        {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        t1->next = prev;
        l->next = t2;
        return dummy->next;
    }
};