class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        // stable_partition returns an iterator to the first element of the second group.
        
        auto it = stable_partition(logs.begin(), logs.end(), [](const string& str) {
            return isalpha(str.back());
        });
        
        sort(logs.begin(), it, [](const string& str1, const string& str2) {
            auto substr1 = string(str1.begin() + str1.find(' '), str1.end());
            auto substr2 = string(str2.begin() + str2.find(' '), str2.end());
            return (substr1 == substr2) ? str1 < str2 : substr1 < substr2;
        });
        
        return logs;
    }
};