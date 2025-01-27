class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const vector<int>&a , const vector<int>&b)
        { return a[1] < b[1]; });
        int sc =0;
        priority_queue<int> pq;
        for(auto & i : courses)
        {
            auto dur = i[0] , end = i[1];
            if(dur + sc <= end)
            {
                    pq.push(dur);
                    sc+=dur;
            }
            else if(!pq.empty() && pq.top()>dur)
            {
                sc +=dur - pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};