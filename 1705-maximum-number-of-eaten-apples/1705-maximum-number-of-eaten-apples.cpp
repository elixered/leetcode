class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int m = 0, c = 0;
        int day = 0;
        for(int i=0; i<days.size(); ++i){
            day = i;
            if(apples[i])
                pq.push({i+days[i],apples[i]});
            m = max(m,i+days[i]);
            while(!pq.empty() && pq.top().first <= day)
                pq.pop();
            if(pq.empty()) continue;
            auto [deadline,num] = pq.top();
            pq.pop();
            num--;
            c++;
            if(num>0)
                pq.push({deadline,num});
        }
        day++;
        while(day<=m){
            while(!pq.empty() && pq.top().first <= day)
                pq.pop();
            if(pq.empty()) break;
            auto [deadline,num] = pq.top();
            pq.pop();
            num--;
            c++;
            if(num>0)
                pq.push({deadline,num});
            day++;
        }
        return c;
    }
};