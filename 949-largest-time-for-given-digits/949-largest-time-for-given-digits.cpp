class Solution {
public:
    string ans = "";
    
    bool valid(string s){
        int hour = stoi(s.substr(0,2));
        int minutes = stoi(s.substr(2));
        return hour<24 && minutes<60;
    }
    
    int time(string s){
        int hour = stoi(s.substr(0,2));
        int minutes = stoi(s.substr(2));
        return hour*60+minutes;
    }
    
    void dfs(int idx, string& s){
        if(idx == s.size()){
            if(valid(s) && (ans == "" or time(s) > time(ans)))
                ans = s;
            return;
        }
        for(int i=idx; i<s.size(); ++i){
            swap(s[i],s[idx]);
            dfs(idx+1,s);
            swap(s[i],s[idx]);
        }
    }
    
    string largestTimeFromDigits(vector<int>& arr) {
        string s;
        for(auto it:arr)
            s += to_string(it);
        dfs(0,s);
        if(ans=="") return ans;
        return ans.substr(0,2)+":"+ans.substr(2);
    }
};