#include <bits/stdc++.h>
using namespace std;
int rangeBitwiseAnd(int left, int right) {


        if(left == 0 || right == 0 )
            return 0;

        if (left == right)
            return left;
            
        int powL = log2(right);
        int powH = log2(left);
        
        if (powL != powH)
            return 0;

        long long int i = pow(2,powL);
        int sum = 0;

        while(sum + i <= left && sum + i <= right || sum + i > left && sum + i > right)
        {
            if (sum + i <= left)
                sum += i;
            i/= 2;
        }

        return sum;
    }

int main()
{
  int low =16;
      cout<<rangeBitwiseAnd(5,7)<<endl;
}
