class Solution {

    struct node{
        node *next[2];
        int storeVal;
        node(){
            next[0] = NULL, next[1] = NULL, storeVal = 0;
        }
    };
    void insert(node *root, int val)
    {
        for(int i=31;i>=0;i--)
        {
            bool res= (val & (1 << i));
            if(root->next[res] == NULL) 
               root->next[res]=new node();
            root=root->next[res];
        }
        root->storeVal = val;
    }
    int search(node *root, int val)
    {
        for(int i = 31; i >= 0; i--)
        {
            bool res = (val & (1 << i));
            if(root->next[1 - res] != NULL)
                root = root->next[1 - res];
            else
                root=root->next[res];
        }
       return (root->storeVal ^ val); 
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
          int n = nums.size();
          // To get the correct order after sorting
          for(int i = 0; i < queries.size() ; i++)
              queries[i].push_back(i);
          // Sort the queries according to accending mi values     
          sort(queries.begin(),queries.end(), [](auto &a, auto &b){ return a[1] < b[1];});
          sort(nums.begin(), nums.end());
          int index = 0;
          node * root = new node();
          
          vector<int>res(queries.size(),-1);
          for(auto q : queries)
          {
              //keep inserting all the values which are lesser than mi in the trie
              while(index < n && nums[index] <= q[1])
              {
                  insert(root, nums[index]);
                  index ++;
              }
              // if any value inserted then we are now in a state of taking xor with atleast any number which satifies the limit                  condition
              if(index)
                res[q[2]] =  search(root, q[0]); 
          }
        return res;
    }
};