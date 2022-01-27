struct node{
    vector<node*> link;
    node()
    {
        link = vector<node*>(2,NULL);
    }
};

class Solution {
    node* root = new node();
    void insert(int n)
    {
        node *temp = root;
        for(int i=31; i>=0; i--)
        {
            int bit = ((1<<i)&n)==0?0:1;
            if(temp->link[bit]==NULL)
                temp->link[bit] = new node();
            temp = temp->link[bit];
        }
    }
    int findMax(int n)
    {
        node *temp = root;
        int maxi = 0;
        for(int i=31; i>=0; i--)
        {
            int bit = ((1<<i)&n)==0?0:1;
            if(temp->link[!bit]!=NULL)
            {
                maxi = maxi|(1<<i);
                temp = temp->link[!bit];
            }
            else
                temp = temp->link[bit];
        }
        return maxi;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        for(auto it:nums)
            insert(it);
        int ans = 0;
        for(auto it:nums)
            ans = max(ans,findMax(it));
        return ans;
    }
};