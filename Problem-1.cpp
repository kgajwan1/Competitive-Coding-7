//)(nlogn) +O(n)

//Its messy since I had to sort + use a pq
class mycompare{
public:
    bool operator()(int a ,int b){
        return a>b;
    }
};
bool compareInterval(vector<int> i1, vector<int> i2){
	return (i1[0] < i2[0]);
}
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int maxConf = INT_MIN;
        int currConf = 0;
        //Start a loop from beginning to end and compare
        sort(intervals.begin(),intervals.end(), compareInterval);
        priority_queue<int,vector<int>,mycompare> pq;//max_heap
        for(auto interval : intervals){
            currConf++;
            pq.push(interval[1]);
            int top = pq.top();
            while(top <= interval[0] && !pq.empty()){
                pq.pop();
                top = pq.top();
                currConf--;
            }
            if(maxConf < currConf) maxConf = currConf;
        }
    return maxConf;
    }
};
