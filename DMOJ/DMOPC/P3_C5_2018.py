# Python3 program to find longest subarray 
# with sum of elements at-least k. 
  
# function to find the length of largest  
# subarray having sum atmost k. 
def atMostSum(arr, n, k): 
    _sum = 0
    cnt = 0
    maxcnt = 0
      
    for i in range(n): 
  
        # If adding current element doesn't 
        # Cross limit add it to current window 
        if ((_sum + arr[i]) < k): 
            _sum += arr[i] 
            cnt += 1
          
        # Else, remove first element of current 
        # window and add the current element 
        elif(sum != 0): 
            _sum = _sum - arr[i - cnt] + arr[i] 
          
        # keep track of max length. 
        maxcnt = max(cnt, maxcnt) 
  
    return maxcnt 
      
# Driver function 

  
# This code is contributed by "Abhishek Sharma 44"  
  
n, k = (int(x) for x in input().split())
arr = [int(x) for x in input().split()] 
n = len(arr) 
print(atMostSum(arr, n, k))