class Solution {
public:
    int tribonacci(int n) {
        int first=0,second=1,third=1;
        int ans;
        if(n==0) return first;
        if(n==1|| n==2) return second;
        for(int i=3;i<=n;i++)
            {
            ans=first+second+third;
            first=second;
            second=third;
            third=ans;
            
        }
        return ans;
       
    }
};