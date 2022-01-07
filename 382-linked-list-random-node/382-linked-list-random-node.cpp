class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res =-9;
        ListNode* node = head;
        int i = 1;
        while(node){
            int j = rand()%i;
            if(j==0)
                res = node->val;
            i++;
            node = node->next;
        }
        delete node;
        return res;
    }
};