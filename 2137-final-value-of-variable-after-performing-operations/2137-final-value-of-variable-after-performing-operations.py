class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        cnt=0
        for i in operations:
            if i[0]=='+' or i[-1]=='+':
                cnt+=1
            else:
                cnt-=1
        return cnt