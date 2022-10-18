class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while(--n)
        {
            string curr = "";
            
            for(int i=0; i<res.size(); i++){
                int count = 1;
            while(i+1<res.size() && res[i]==res[i+1])
            {
                count++,i++;
            }
            curr += to_string(count)+res[i];
            }
            res = curr;
        }
        return res;
    }
};