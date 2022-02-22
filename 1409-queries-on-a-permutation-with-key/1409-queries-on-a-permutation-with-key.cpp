class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> result;
        vector<int>::iterator itr;
        vector<int> arr;
        int val;
        
        for(int i=0; i<m; i++)
        {
            arr.push_back(i+1);
        }
        
        for(int i=0; i<queries.size(); i++)
        {
            itr = find(arr.begin(), arr.end(), queries[i]);
            val = itr-arr.begin();
            result.push_back(val);
            arr.erase(itr);
            arr.insert(arr.begin(), queries[i]);
        }
        return result;
    }
};