class Solution {
public:
    string reformat(string s) {
        string a,b;
        for(auto c:s)
            if(isdigit(c))
                a.push_back(c);
            else b.push_back(c);
        string ans;
        if(abs((int)a.size() - (int)b.size()) > 1)
            return "";
        int i=0,j=0;
        if(a.size() < b.size())
            swap(a,b);
        while(i<a.size() && j<b.size()){
            ans.push_back(a[i++]);
            ans.push_back(b[j++]);
        }
        while(i<a.size())
        ans.push_back(a[i++]);
        return ans;
    }
};