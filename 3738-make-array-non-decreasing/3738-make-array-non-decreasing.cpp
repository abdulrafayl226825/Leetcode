class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int> st;
        for(auto & i : nums)
        {
            if(st.empty() || st.top()<=i)
                st.push(i);
            
        }
        return st.size();
    }
};