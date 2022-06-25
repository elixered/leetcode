/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordList, Master& master) {
        for(int i=0; i<10; i++){
            string s = wordList[rand() % wordList.size()];
            int x = master.guess(s);
            vector<string> temp;
            for(int i=0; i<wordList.size(); i++){
                string t = wordList[i];
                int diff = 0;
                for(int i=0; i<6; i++)
                    if(s[i]==t[i]) diff++;
                if(diff == x)
                    temp.push_back(wordList[i]);
            }
            wordList = temp;
        }
    }
};