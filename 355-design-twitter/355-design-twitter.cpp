class Twitter {
public:
    
    unordered_map<int,vector<pair<int,int>>> mp;
    unordered_map<int,unordered_set<int>> flw;
    int id = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({id++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        flw[userId].insert(userId);
        set<pair<int,int>> st;
        for(auto it:flw[userId]){
            for(auto p:mp[it])
                st.insert(p);
        }
        for(auto itr=st.rbegin(); itr!=st.rend(); ++itr){
            ans.push_back(itr->second);
            if(ans.size()==10) break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        flw[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        flw[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */