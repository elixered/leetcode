typedef pair<int,int> pii;
class Solution {
    static bool cmp(pii p1,pii p2)
    {
        if(p1.second==p2.second)
            return p1.first<p2.first;//if age is same sort by score to order weaker peer before stronger peer
        return p1.second<p2.second;//sort by ages
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       vector<pii> psa;
        int n=scores.size(),i,j;
        for( i=0;i<n;i++)
        {
            psa.push_back({scores[i],ages[i]});
        }
        sort(psa.begin(),psa.end(),cmp);
        
         int lis[n]; 
   
   
    for (int i = 0; i < n; i++ )  
    { 
        lis[i] = psa[i].first; 
        for (int j = 0; j < i; j++ )   
            if ( (psa[i].first >= psa[j].first  )&&lis[i]<lis[j]+psa[i].first)  
                lis[i] = lis[j] + psa[i].first; 
      
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
    }
};