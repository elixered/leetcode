class Solution {
public:
    string intToRoman(int num) {
        map<int,string,greater<int>> mp = {
            {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"}, {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"}, {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}};
            string ans;
            for(auto it:mp)
            {
                int x = num/it.first;
                for(int i=0; i<x; i++)
                    ans += it.second;
                num %= it.first;
            }
            return ans;
    }
};