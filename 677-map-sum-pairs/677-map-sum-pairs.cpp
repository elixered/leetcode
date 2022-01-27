struct node{
    int val;
    vector<node*> children;
    node()
    {
        val = 0;
        children = vector<node*>(26,NULL);
    }
};

class MapSum {
public:
    node *root;
    MapSum() {
        root = new node();
    }
    
    void insert(string key, int val) {
        node* temp = root;
        for(auto ch:key)
        {
            int idx = ch-'a';
            if(temp->children[idx]==NULL)
                temp->children[idx] = new node();
            temp = temp->children[idx];
        }
        temp->val = val;
    }
    
    int sum(string key) {
        int ans = 0;
        node* temp = root;
        for(auto ch:key)
        {
            int idx = ch-'a';
            if(temp->children[idx]==NULL)
                return 0;
            temp = temp->children[idx];
        }
        ans = getSum(temp);
        return ans;
    }
    int getSum(node* temp)
    {
        if(temp==NULL) return 0;
        int curr = temp->val;
        for(int i=0; i<26; i++)
        {
                curr += getSum(temp->children[i]);
        }
        return curr;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */