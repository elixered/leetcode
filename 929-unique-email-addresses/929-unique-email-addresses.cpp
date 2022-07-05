class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto email:emails){
            string s;
            int i = 0;
            int n = email.size();
            bool plus = false;
            while(i<n && email[i]!='@'){
                if(!plus && email[i]!='.' && email[i]!='+')
                    s += email[i];
                else if(email[i]=='+')
                    plus = true;
                i++;
            }
            s += email.substr(i);
            st.insert(s);
        }
        return st.size();
    }
};