class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i = 0, j = tokens.size()-1;
        int score = 0;
        int ans = 0;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                power -= tokens[i++];
                score ++;
            }
            else if(score>0)
            {
                ans = max(score,ans);
                score--;
                power += tokens[j--];
            }
            else return max(ans,score);
        }
        return max(ans,score);
    }
};