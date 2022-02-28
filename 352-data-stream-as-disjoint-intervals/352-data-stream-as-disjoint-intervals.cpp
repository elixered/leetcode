class SummaryRanges {
public:
    set<int> set;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        set.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto it=set.begin(); it!=set.end(); it++)
        {
            vector<int> temp;
            temp.push_back(*it);
            auto it2 = it;
            while(it2!=prev(set.end()) && *it2+1 == *(next(it2))) 
                it2++;
            temp.push_back(*it2);
            ans.push_back(temp);
            it = it2;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */