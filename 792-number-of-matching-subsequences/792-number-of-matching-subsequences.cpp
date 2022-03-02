class Solution {
public:
        
    int numMatchingSubseq(string s, vector<string>& words) {
        
        // stores positions of each character in 2D vector
        vector<vector<int>>char_positions(26,vector<int>());
        
        int l = s.length();
        for(int i=0;i<l;i++)
        {
            char_positions[s[i]-'a'].push_back(i);
        }
        
        // count the valid subsequences
        int count = 0;
        int wordsl = words.size();
        
        // loop through all the given words
        for(int i=0;i<wordsl;i++)
        {
            int wl = words[i].length();
            bool flag = true;
            
            // if the first character's vector of a word is empty then subsequence does not exists
            if(!char_positions[words[i][0]-'a'].empty())
            {
                // index of first character of a word in string S
                int prevIndex = char_positions[words[i][0]-'a'][0];
                for(int j=1;j<wl;j++)
                {
                    // if the jth character's vector of a word is empty then subsequence does not exists
                    if(char_positions[words[i][j]-'a'].empty())
                    {
                        flag = false;
                        break;
                    }
                    
                    // find the index of the position in character vector where position is greater than prevIndex
                    int index = lower_bound(char_positions[words[i][j] - 'a'].begin(), char_positions[words[i][j] - 'a'].end(),prevIndex+1) - char_positions[words[i][j] - 'a'].begin();

                    // no position greater than prevIndex exists in vector of current character 
                    if(index == char_positions[words[i][j] - 'a'].size())
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        // position greater than prevIndex exists in vector of current character and so update the prevIndex with found position
                        prevIndex = char_positions[words[i][j] - 'a'][index];
                    }
                }

                // update valid subsequences 
                if(flag) count++;           
            }
        }
        
        return count;
    }
};