#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
using namespace std;
/*
 * 355. Design Twitter
 * Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.


Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.*/

class Twitter {

    struct Tweets{
        size_t time;
        int tweet;
        explicit Tweets(size_t time, int tweet):time(time), tweet(tweet){}

        bool operator<(const Tweets& rhs) const
        {
            return time < rhs.time;
        }

    };

    unordered_map<int, vector<Tweets>> tweets;
    unordered_map<int, unordered_set<int>> followeed;
    size_t timeStamp = 0;

public:
    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timeStamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<Tweets> pq;

        auto &followeeIdArr = followeed[userId];

        for (auto tweet: tweets[userId]) {
            pq.emplace(tweet);
        }

        for(auto followeeId: followeeIdArr){
            for (auto tweet: tweets[followeeId]) {
                pq.emplace(tweet);
            }
        }

        vector<int> result;

        for(size_t i = 0; i < 10 and !pq.empty(); ++i){

            result.push_back(pq.top().tweet);
            pq.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        followeed[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followeed[followerId].erase(followeeId);
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
