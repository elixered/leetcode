class Solution {
public:
    
    int eval(int a, int b, char op){
        return op=='*'?a*b:op=='+'?a+b:a-b;
    }
    
    vector<int> diffWaysToCompute(string s) {
        int n = s.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!isdigit(s[i])){
                vector<int> ans1 = diffWaysToCompute(s.substr(0,i));
                vector<int> ans2 = diffWaysToCompute(s.substr(i+1));
                for(auto n1:ans1){
                    for(auto n2:ans2){
                        ans.push_back(eval(n1,n2,s[i]));
                    }
                }
            }
        }
        if(ans.empty())
            ans.push_back(stoi(s));
        return ans;
    }
};