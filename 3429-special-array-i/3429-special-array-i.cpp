class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++)
            {
                auto y = __builtin_popcount(nums[i+1]);
                auto x = __builtin_popcount(nums[i]);
                if( (nums[i]&1) == (nums[i+1]&1)  )
                return false;
            }
            return true;

    }
};