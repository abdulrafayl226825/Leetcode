#include <bits/stdc++.h>
using namespace std;
string DecimalToBinaryString(int& a)
{
    string binary = "";
    while (a > 0)
    {
        int rem = a % 2;
        binary = to_string(rem) + binary;
        a = a / 2;
    }
    return binary;
}
int BinaryStringToDecimal(const string& binary)
{
    int decimal = 0;
    int power = 0;
    for (int i = binary.length() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            decimal += pow(2, power);
        }
        else if (binary[i] != '0')
        {
            throw invalid_argument("Invalid binary string");

        }
        power++;
    }
    return decimal;
}
int rangeBitwiseAnd(int left, int right) {
    if(left==right) return left;


    auto x=DecimalToBinaryString(left);
    auto y=DecimalToBinaryString(right);
    int low=x.length();
    int high=y.length();
    if(high!=low) return 0;
    string s(high,'0');
    int i=0;
    for(;i<=high;i++)
    {
        if(x[i]!=y[i])
            break;
        s[i]=x[i];
    }
    return BinaryStringToDecimal(s);
}int main()
{
  int low =16;
      cout<<rangeBitwiseAnd(5,7)<<endl;
}
