class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even_digits =0;
        auto n = nums.size();
        for(int i=0;i<n;i++)
        {
            int cnt =0;
            while(nums[i]>0)
            {
                cnt++;
                nums[i]/=10;
            }
            if(!(cnt&1)) even_digits++;
        }   
        return even_digits;
    }
};