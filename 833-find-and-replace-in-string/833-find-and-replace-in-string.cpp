class Solution {
public:
    
    struct node{
        int idx;
        string target;
        string source;
        node(int a, string b, string c){
            idx = a;
            target = b;
            source = c;
        }
    };
    
    bool match(string& s, int start, string source){
        for(int i=0; i<source.size(); ++i){
            if(i+start >= s.size() || s[i+start]!=source[i])
                return false;
        }
        return true;
    }
    
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<node> vec;
        int n = indices.size();
        int m = s.size();
        for(int i=0; i<n; ++i){
            if(match(s,indices[i],sources[i]))
                vec.push_back(node(indices[i],targets[i], sources[i]));
        }
        auto cmp = [](node& a, node& b){
            return a.idx < b.idx;
        };
        sort(begin(vec),end(vec),cmp);
        string ans;
        int index = 0;
        for(auto v:vec){
            while(index < v.idx)
                ans += s[index++];
            ans += v.target;
            index += v.source.size();
        }
        while(index < s.size())
            ans += s[index++];
        return ans;
    }
};