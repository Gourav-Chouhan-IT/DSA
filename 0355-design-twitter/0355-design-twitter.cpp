#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <tuple>

using namespace std;

class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int timestamp = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back({timestamp, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        vector<tuple<int, int, int>> initialCandidates;

        // 1. Collect most recent tweet for self and followees: O(F)
        if (!tweets[userId].empty()) {
            int index = tweets[userId].size() - 1;
            initialCandidates.push_back({tweets[userId][index].first, userId, index});
        }

        for (int followeeId : following[userId]) {
            if (!tweets[followeeId].empty()) {
                int index = tweets[followeeId].size() - 1;
                initialCandidates.push_back({tweets[followeeId][index].first, followeeId, index});
            }
        }

        // 2. Linear-time Heapify: O(F) via iterator range constructor
        priority_queue<tuple<int, int, int>> pq(initialCandidates.begin(), initialCandidates.end());

        // 3. Extract top K (K=10) tweets: O(K log F)
        while (!pq.empty() && result.size() < 10) {
            auto [time, currentUser, index] = pq.top();
            pq.pop();

            result.push_back(tweets[currentUser][index].second);

            if (index > 0) {
                index--;
                pq.push({tweets[currentUser][index].first, currentUser, index});
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