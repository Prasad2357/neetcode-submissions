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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode * resHead = new ListNode;
        ListNode * temp;
        ListNode * l1 = list1;
        ListNode * l2 = list2;

        if(list1==nullptr && list2==nullptr)
        {
            return list1;
        }
        else if(list1== nullptr)
        {
            return list2;
        }

        else if (list2== nullptr)
        {
            return list1;
        }

        if(l1->val <= l2->val)
        {   
            resHead = l1;
            temp = resHead;
            l1 = l1->next;
        }
        else
        {
            resHead = l2;
            temp = resHead;
            l2 = l2->next;
        }

        while(l1!= nullptr && l2!= nullptr)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;

            }
        }

        if(l1 == nullptr && l2!=nullptr )
        {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;

        }

        else if (l2 == nullptr && l1!=nullptr)
        {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;   
        }

        return resHead;
        
    }
};
