int mat[26][26];

bool comp_(char a, char b, int i){
    if(i==26){
        return a<b;
    }
    if(mat[a-'A'][i]>mat[b-'A'][i]){
        return true;
    }
    if(mat[a-'A'][i]<mat[b-'A'][i]){
        return false;
    }
    return comp_(a,b,i+1);
        
}

bool comp(char a, char b){
    return comp_(a,b,0);
}

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes[0].length();
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++)
                mat[i][j]=0;
        }
        for(auto vote:votes){
            for(int i=0;i<vote.size();i++){
                mat[vote[i]-'A'][i]++;
            }
        }
        
        sort(votes[0].begin(),votes[0].end(),comp);
      
        return votes[0];
    }
};