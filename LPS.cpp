#include <iostream>
using namespace std;
int longestPalindromeSubseq(string s) {
      int  n=s.length();
        int count=0;
        int Max=0;
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0&& r<n)
            {
            if(s[l]==s[r])
             {   count++;
                l--,r++;
             }
            else{
                int x=l,y=r;
                while(x>=0 && y<n)
                {
                    if(s[x]==s[y])
                        {
                            x--;count++;
                        }
                        y++;
                }
                x=l,y=r;
                int count2=count;
                while(x>=0 && y<n)
                {
                    if(s[x]==s[y])
                    {
                        y++;count2++;
                    }
                    x--;
                }
                count=max(count2,count);
                }
                Max=max(count,Max);
            }
        }
    return Max;
    }
int main()
{
  int arr[10];
  arr[0]=3;
 cout<<arr[0]; 
  cout<<longestPalindromeSubseq("bbbab")<<endl;
}
