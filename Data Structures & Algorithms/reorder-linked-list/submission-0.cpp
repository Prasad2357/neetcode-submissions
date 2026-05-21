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
        if(head == nullptr || head->next == nullptr)
            return;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while(fast!= nullptr && fast->next !=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *list1 = head;      //head to mid
        ListNode *list2 = slow->next;  //mid to end
        slow->next = nullptr;

        //reversing the list2
        ListNode *prev = nullptr;
        ListNode *curr = list2;
        ListNode *next;

        while(curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        list2= prev;

        //merge both the lists
        while(list1!= nullptr && list2!= nullptr)
        {
            ListNode* after1 = list1->next;
            ListNode* after2 = list2->next;

            list1->next = list2;
            if(after1 == nullptr)
            {
                break;
            }

            list2->next = after1;

            list1 = after1;
            list2 = after2;
        } 
    }
    
};
