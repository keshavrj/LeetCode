class Solution:
    def maxProfit(self, arr: List[int]) -> int:
        if len(arr)==0:
            return 0
        
        buy_price= arr[0]
        profit= 0
        
        for i in range(1, len(arr)):
            if arr[i]<buy_price:
                buy_price= arr[i]
            if profit< arr[i]-buy_price:
                profit= arr[i]-buy_price
            
        return profit