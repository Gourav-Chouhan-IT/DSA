class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int timestamp = 0;

    Twitter() {
       
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back({timestamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int> result;

        // Max heap:
        // {timestamp, userId, index}
        priority_queue<tuple<int, int, int>> pq;

        // User's own tweets must also appear
        if (!tweets[userId].empty()) {
            int index = tweets[userId].size() - 1;

            pq.push({
                tweets[userId][index].first,
                userId,
                index
            });
        }

        // Add the newest tweet of every person userId follows
        for (int followeeId : following[userId]) {

            if (!tweets[followeeId].empty()) {

                int index = tweets[followeeId].size() - 1;

                pq.push({
                    tweets[followeeId][index].first,
                    followeeId,
                    index
                });
            }
        }

        // Get at most 10 newest tweets
        while (!pq.empty() && result.size() < 10) {

            auto [time, currentUser, index] = pq.top();
            pq.pop();

            // Add tweet ID to result
            result.push_back(
                tweets[currentUser][index].second
            );

            // Move to the next older tweet of same user
            if (index > 0) {

                index--;

                pq.push({
                    tweets[currentUser][index].first,
                    currentUser,
                    index
                });
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};