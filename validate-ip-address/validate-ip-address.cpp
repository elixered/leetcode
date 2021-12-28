class Solution {
public:
    string checkipv4(string queryIP)
    {
        if(count(queryIP.begin(),queryIP.end(),'.')!=3)
            return "Neither";
        stringstream ss(queryIP);
        string s1;
        int count = 4;
        while(count--)
        {
            getline(ss,s1,'.');
            if(s1.size()==0 or s1.size()>3)
                return "Neither";
            else if(s1[0]=='0' && s1.size()!=1)
                return "Neither";
            for(auto c:s1)
                if(c>'9' or c<'0')
                    return "Neither";
            if(s1<"0" or s1 >"255")
                return "Neither";
                
        }
        return "IPv4";
    }
    string checkipv6(string queryIP)
    {
        if(count(queryIP.begin(),queryIP.end(),':')!=7)
            return "Neither";
        stringstream ss(queryIP);
        string s1;
        int count = 8;
        while(count--)
        {
            getline(ss,s1,':');
            if(s1.size()==0 or s1.size()>4)
                return "Neither";
            for(auto c:s1)
                if(!((c>='0' && c<='9') or (c>='a' && c<='f') or (c>='A' && c<='F')))
                    return "Neither";
                
        }
        return "IPv6";
    }
    string validIPAddress(string queryIP) {
        int n = queryIP.size();
        for(auto c:queryIP)
        {
            if(c=='.')
                return checkipv4(queryIP);
            else if(c==':')
                return checkipv6(queryIP);
        }
        return "Neither";
    }
};