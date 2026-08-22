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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        int length = 0;
        while(temp !=0)
        {
            length++;
            temp = temp->next;
        }
        x(head,length);
        cout<<length;
    }
    void x(ListNode* temp,int length)
    {
        if(length <= 2) return;
        if(temp == NULL || temp->next == NULL ) return;
        ListNode* last = temp;
        ListNode* prev = NULL;
        int count = 0;
        while(count != length-1)
        {
            prev = last;
            last = last->next;
            
            count++;
        }
        prev->next = NULL;
        last->next = temp->next;
        temp->next = last;
        x(last->next,length-2);
    }
};