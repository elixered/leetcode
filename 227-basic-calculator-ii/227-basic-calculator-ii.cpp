class Solution {
public:
    int calculate(string s) {
        vector<string> eq;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]==' ') continue;
            string temp;
            temp.push_back(s[i]);
            if(!isdigit(s[i]))
                eq.push_back(temp);
            else{
                while(i+1<n && isdigit(s[i+1])){
                temp.push_back(s[i+1]);
                i++;
                }
            eq.push_back(temp);
            }
        }
        int ans = 0;
        stack<string> st;
        vector<string> v = {"/","*"};
            for(auto c:eq){
                if(!st.empty() && (st.top()==v[0] or st.top()==v[1])){
                    string top = st.top();
                    st.pop();
                    int first = stoi(st.top());
                    st.pop();
                    int second = stoi(c);
                    string curr;
                    if(top==v[0])
                        curr = to_string(first/second);
                    else 
                        curr = to_string(first*second);
                    st.push(curr);
                }
                else st.push(c);
            }
            vector<string> temp;
            while(!st.empty())
            {
                temp.push_back(st.top());
                st.pop();
            }
            eq = temp;
            reverse(eq.begin(),eq.end());
        for(int i=0; i<eq.size(); i++){
            if(eq[i]=="+" or eq[i]=="-"){
                if(eq[i]=="+")
                    ans += stoi(eq[i+1]);
                else ans -= stoi(eq[i+1]);
                i++;
            }
        else ans += stoi(eq[i]);
        }
        return ans;
    }
};