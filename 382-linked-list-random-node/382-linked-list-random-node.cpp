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
    ListNode* head;
    int sz;
    Solution(ListNode* head) {
        this->head = head;
        ListNode* temp = head;
        int count = 0;
        while(temp)
        {
            temp = temp->next;
            count++;
        }
        sz = count;
    }
    
    int getRandom() {
        int n = rand()%sz;
        ListNode* temp = head;
        while(n>0)
        {
            n--;
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */