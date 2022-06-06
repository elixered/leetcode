class Solution {
public:
    bool isValidSerialization(string p) {
        if(p=="#") return true;
        p += ",";
        stringstream s(p);
        string curr;
        getline(s,curr,',');
        if(curr=="#") return false;
        int cap = 2;
        while(getline(s,curr,','))
        {
            if(cap==0) return false;
            if(curr=="#")
                cap--;
            else cap++;
            if(cap<0) return false;
        }
        return cap==0;
    }
};