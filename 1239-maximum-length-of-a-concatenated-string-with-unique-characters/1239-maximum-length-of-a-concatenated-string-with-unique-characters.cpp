class Solution {
public:
    int n;
    int ans=0;
    
    void backtrack(int ind, string curr, vector<string>& arr){
        if(ind==n){
            int v=curr.size();
            cout<<curr<<" ";
            ans=max(ans, v);
            return;
        }
        int v=arr[ind].size();
        unordered_map<char, int> m;
        for(auto &x: curr){
            m[x]++;
        }
        bool f=true; //check if we can add this string to curr
        for(auto &x: arr[ind]){
            if(m.count(x))
            {
                f=false;
                break;
            }
            m[x]++;
        }
        if(f){ //since we can add it, now we have two options - to add it or to not add it
            curr+=arr[ind];
            backtrack(ind+1, curr, arr);
            curr=curr.substr(0, curr.size()-v);
            backtrack(ind+1, curr, arr);
        }
        else{ //we can't add it
            backtrack(ind+1, curr, arr);
        }
    }
    
    int maxLength(vector<string>& arr) {
        n=arr.size();
        string curr="";
        backtrack(0, curr, arr);
        return ans;
    }
};