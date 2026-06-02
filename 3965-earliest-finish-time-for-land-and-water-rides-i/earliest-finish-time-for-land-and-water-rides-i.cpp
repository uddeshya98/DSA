class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int landFinish = landStartTime[i] + landDuration[i];
                int finishTime1 = max(waterStartTime[j], landFinish) + waterDuration[j];
                
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int finishTime2 = max(landStartTime[i], waterFinish) + landDuration[i];
                
                minFinishTime = min({minFinishTime, finishTime1, finishTime2});
            }
        }
        
        return minFinishTime;
    }
};