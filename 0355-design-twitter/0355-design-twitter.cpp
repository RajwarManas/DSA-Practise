class Twitter {
    int timer=0;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
    struct Node {
        int time;
        int tweetId;
        int user;
        int idx;
    };
    struct cmp {
        bool operator()(const Node& a, const Node& b) {
        return a.time < b.time;
        }
    };
public:
    Twitter() {
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++,tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<Node,vector<Node>,cmp> pq;
        following[userId].insert(userId);
        for(int user:following[userId]) {
            if(tweets[user].empty()) continue;
            int idx=tweets[user].size()-1;
            auto [time,id]=tweets[user][idx];
            pq.push({time,id,user,idx});
        }
        vector<int> res;
        while(!pq.empty()&&res.size()<10) {
            auto cur=pq.top();
            pq.pop();
            res.push_back(cur.tweetId);
            int nextIdx=cur.idx-1;
            if(nextIdx>=0) {
                auto [t,id]=tweets[cur.user][nextIdx];
                pq.push({t,id,cur.user,nextIdx});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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