class Solution {
public:
    typedef pair<int,int> ppi;
    string boldWords(vector<string>& words, string s) {
          vector<ppi> pos;
        for(const auto& w: words) {
            int c = w.length();
            for(int i = 0; (i = s.find(w,i)) != string::npos; ++i) {
                pos.emplace_back(i, i+c);
            }
        }
        int m = pos.size();
        sort(pos.begin(),pos.end());
        vector<ppi> merged;
        for(int i=0; i<m; i++){
            if(merged.empty() or merged.back().second < pos[i].first)
                merged.push_back(pos[i]);
            else{
                merged.back().second = max(merged.back().second,pos[i].second);
            }
        }
       for(auto it = merged.rbegin(); it != merged.rend(); ++it) {
            s.insert(it->second, "</b>"); s.insert(it->first, "<b>");
        }
        
        return s;
    }
};