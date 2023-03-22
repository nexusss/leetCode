class TweetCounts {
    unordered_map<string, multiset<int>> tweets;

    const int minute = 60;
    const int hour = minute * 60;
    const int day = hour * 24;

    void calc(const string &tweetName, vector<int> &result, multiset<int> &timesSet, int startTime, int endTime){

                    auto startIter = timesSet.lower_bound(startTime);
                    auto endIter = timesSet.upper_bound(endTime);
                    //cout << startTime << " " << endTime << endl;
                        result.push_back(std::distance(startIter, endIter));
                    

    }

public:
    TweetCounts(){

    }
    
    void recordTweet(string tweetName, int time) {
        tweets[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> result;
        auto timesFind = tweets.find(tweetName);
        if (timesFind == tweets.end()){
            return result;
        }

        if (freq == "minute"){
            for(int i = startTime ; i <= endTime ; i += minute){
                calc(tweetName, result, timesFind->second, i, min(endTime, i + minute - 1));
            }
        }
        else if (freq == "hour"){
            for(int i = startTime ; i <= endTime ; i += hour){
                calc(tweetName, result, timesFind->second, i, min(endTime, i + hour - 1));
            }

        }
        else if (freq == "day"){
            for(int i = startTime ; i <= endTime ; i += day){
                calc(tweetName, result, timesFind->second, i, min(endTime, i + day - 1));
            }
        }
        return result;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */