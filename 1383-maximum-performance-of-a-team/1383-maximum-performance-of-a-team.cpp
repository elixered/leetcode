struct comp
{
    bool operator()(pair<int,int>&p1,pair<int,int>&p2)
    {
        return p1.first>p2.first;
    }
};
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod=1e9+7;
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++)
            ans.push_back({efficiency[i],speed[i]});
        sort(ans.begin(),ans.end(),comp());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        long long int sum=0;
        long long int result=0;
        for(int i=0;i<n;i++)
        {   if(i>=k)
              {
                    sum-=pq.top();
                    pq.pop();
              }
             sum=sum+ans[i].second;
             result=max(result,sum*ans[i].first);
             pq.push(ans[i].second);
            
        }
        return result%mod;
    }
};