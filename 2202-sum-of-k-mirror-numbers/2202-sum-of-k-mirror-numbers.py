class Solution:
    
    def kMirror(self, k: int, n: int) -> int:
        def converter(n,k):
            digits = []
            while n>0:
                digit = n%k
                digits.append(str(digit))
                n//=k
           
            return int(''.join(reversed(digits)))
        def generate_palindromes():
            length = 1
            while True:

                
            # for odd lengths 
                for i in range(10**(length-1),10**length):
                    s=str(i)
                    yield(int(s+s[-2::-1]))
            # for even lengths
                for i in range(10**(length-1),10**length):
                    s = str(i)
                    yield(int(s + s[::-1]))
                length+=1
        cnt = 0
        sums = 0
        for i in generate_palindromes():
            m = converter(i,k)  
            if str(m) == str(m)[::-1]:
                # print(i,m)
                sums+=i
                cnt+=1
            if cnt == n:
                break
        

        return sums
        