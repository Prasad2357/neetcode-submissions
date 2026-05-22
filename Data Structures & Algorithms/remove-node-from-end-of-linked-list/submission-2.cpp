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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = 0;

        ListNode *temp = head;
        while(temp != nullptr)
        {
            length++;
            temp = temp->next;
        }

        if(length == 1)
        {   
            return nullptr;
        }
        int delete_index = length -n+1;

        if(delete_index == 1)
        {   
            head = head->next;
            return head;
        }

        length = 1;
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while(delete_index != length)
        {
            length++;
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        

        return head;
    
        
    }
};
