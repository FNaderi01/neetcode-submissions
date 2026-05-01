class Twitter {
    int timestamp;
    

    struct User {
        unordered_set<int> follower;
        unordered_set<int> following;
        map<int, pair<int, int>, greater<int>> feed; // {timestamp, {tweetId, userId}}
        vector<pair<int, int>> posts;
        int id;

        User(int id) {
            this->id = id;
            follower.insert(id);
            following.insert(id);
        }

        void propagate(int tweetId, int time, unordered_map<int, User*>& users) {
            for(int f : follower) {
                users[f]->feed[time] = {tweetId, id};
            }
        }
    };

    unordered_map<int, User*> users;
public:
    Twitter() {
        timestamp = 0;
    }
    void checkExists(int userId) {
        if(users.find(userId) == users.end()) {
            users[userId] = new User(userId);
        }

        return;
    }
    void postTweet(int userId, int tweetId) {
        checkExists(userId);
        users[userId]->posts.push_back({timestamp, tweetId});
        users[userId]->propagate(tweetId, timestamp, users);
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        checkExists(userId);
        vector<int> ans;
        auto feed = users[userId]->feed;
        vector<int> toRemove;
        for(auto cur : feed) {
            int uId = cur.second.second;
            if(users[userId]->following.find(uId) != users[userId]->following.end()) {
                ans.push_back(cur.second.first);
            } else {
                toRemove.push_back(cur.first);
            }

            if(ans.size() == 10) {
                break;
            }
        }

        for(int t : toRemove) {
            users[userId]->feed.erase(t);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }

        checkExists(followerId);
        checkExists(followeeId);

        users[followerId]->following.insert(followeeId);
        users[followeeId]->follower.insert(followerId);

        int count = 0;
        for(auto post : users[followeeId]->posts) {
            users[followerId]->feed[post.first] = {post.second, followeeId};
            if(count >= 10) {
                break;
            }
            count++;
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        users[followerId]->following.erase(followeeId);
        users[followeeId]->follower.erase(followerId);
    }
};
