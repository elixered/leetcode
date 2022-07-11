class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        int i=findNext(team,-1,1), j=findNext(team,-1,0), cat=0;
        
        while( i<team.size()&&j<team.size() ){
            if(j<i-dist){
                j=findNext(team,j,0);
            }else if(i+dist<j){
                i=findNext(team,i,1);
            }else{
                cat++;
                i=findNext(team,i,1);
                j=findNext(team,j,0);
            }
        }
        
        return cat;
    }
    
private:
    int findNext( vector<int>& team, int i, int t ){
        i++;
        while( i<team.size()&&team[i]!=t)   i++;
        return i;
    }
};