
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newRoot = (ListNode *)malloc(sizeof(ListNode));
        ListNode *current = newRoot;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                current = current->next;
                l1 = l1->next;
            } else {
                current->next = l2;
                current = current->next;
                l2 = l2->next;
            }
        }
        
        if (l1) {
            current->next = l1;
        } else {
            current->next = l2;
        }
        return newRoot->next;
    }
};
