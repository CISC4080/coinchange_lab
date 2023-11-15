# coinchange_lab

In this lab, we solve different versions of the CoinChange problems, making use of recursive methods. You can work in a group of up to 3 students. 

## Preparation: 
     Download the following starter code: coin_change.cpp

## Requirements:

1. Implement the following function that returns a vector of vectors of Item, each of which is a subset of elements chosen from the given vector a[first…last]:
   ```
 /* if a is {1,2,3}, first=0, last=2, the function shall returns a vector of the following vectors:
   {}, {1}, {2}, {3}, {1,2},{1,3}, {2,3},{1,2,3}, all subsets of a[0…2].
   Precondition: last-first+1>=1, i.e., there is at least one element in the a[first…last]
   Note 1)if the length of a[first…last] is n, then the function should return a vector of 2n vectors
     2) The order of these subsets does not need to match what’s listed here… 
*/
vector<vector<int>> subsets (const vector<int> & a, int first, int last)
```
Note: Please refer to the examples in the slides… 

2. Implement the following function by using subsets() developed in step 1.
```
     /* Check if given value given be expressed by K or less coins chosen from the given set of coins  
         @param coins: all coins we can choose from 
         @param first, last: specify the range of coins to choose from, i.e., coins[first…last]
         @param value: the value to express
          @param K: the maximum # of coins to use    
          @precondition: all coins have positive values
           @postcondition: return true of false depending on the checking result  */
        bool CoinChangeK (const vector<int> & coins, int first, int last, int value, int K)
  ```    
Hint:  call subsets( ) function to return all possible subsets, and then go through them to see if any subsets with size <=K as a sum equal to value or not.


3. Implement an unlimited coin change problem, where each coin can be used for an unlimited number of times. 
```
      /* Check if given value given be expressed by coins chosen from the given set of coins  
         @param coins: all coins we can choose from 
          @param value: the value to express
           @precondition: all coins have positive values
           @postcondition: return true or false depending on the checking result, if return true, bestSolution is set to include the solution that uses minimum number of coins */
         bool UnlimitedCoinChange(const vector<int> & coins, int value，vector<int> & bestSolution)
```

Implement this function recursively, based upon the logic learnt in class (i.e., use decision tree to guide your design of the recursive algorithm). 


## Deadlines and Submission

Email the instructor about your team by Wednesday April 6th.
For the unlimited coin change problem, draw the decision tree for the following input:
coins={2,5,3,10}, value=15

by Friday April 8th. 
  Note: 1) The decision can be “Which coin to use next?”
            2) Or the decision can be “How many 10 to use?”, then “How many 3 to use?”, … lastly “How many 2 to use?”

By Tuesday April 12th, midnight, submit coinchange.cpp file to  autograder site:

https://storm.cis.fordham.edu:8443/web/project/460



