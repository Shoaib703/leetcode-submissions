/*
 * Climbing Stairs II
 * Difficulty: Medium
 *
 * You are climbing a staircase with n + 1 steps, numbered from 0 to n.

You are also given a 1-indexed integer array costs of length n, where costs[i] is the cost of step i.

From step i, you can jump only to step i + 1, i + 2, or i + 3. The cost of jumping from step i to step j is defined as: costs[j] + (j - i)2

You start from step 0 with cost = 0.

Return the minimum total cost to reach step n.

 
Example 1:


Input: n = 4, costs = [1,2,3,4]

Output: 13

Explanation:

One optimal path is 0 → 1 → 2 → 4


	
		
			Jump
			Cost Calculation
			Cost
		
	
	
		
			0 → 1
			costs[1] + (1 - 0)2 = 1 + 1
			2
		
		
			1 → 2
			costs[2] + (2 - 1)2 = 2 + 1
			3
		
		
			2 → 4
			costs[4] + (4 - 2)2 = 4 + 4
			8
		
	


Thus, the minimum total cost is 2 + 3 + 8 = 13


Example 2:


Input: n = 4, costs = [5,1,6,2]

Output: 11

Explanation:

One optimal path is 0 → 2 → 4


	
		
			Jump
			Cost Calculation
			Cost
		
	
	
		
			0 → 2
			costs[2] + (2 - 0)2 = 1 + 4
			5
		
		
			2 → 4
			costs[4] + (4 - 2)2 = 2 + 4
			6
		
	


Thus, the minimum total cost is 5 + 6 = 11


Example 3:


Input: n = 3, costs = [9,8,3]

Output: 12

Explanation:

The optimal path is 0 → 3 with total cost = costs[3] + (3 - 0)2 = 3 + 9 = 12


 
Constraints:


	1 <= n == costs.length <= 105​​​​​​​
	1 <= costs[i] <= 104


 */

class Solution {
public:
    int solve(int &n,vector<int>&costs,vector<int>&dp,int i){
        if(i>n)return 1e9+7;
        if(i==n)return costs[n-1];
        if(dp[i]!=0)return dp[i];

        int a=1+solve(n,costs,dp,i+1);
        int b=4+solve(n,costs,dp,i+2);
        int c=min(a,b);
        dp[i]=costs[i-1]+min(c,9+solve(n,costs,dp,i+3));
        return dp[i];
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,0);
        dp[0]=min(1+solve(n,costs,dp,1),4+solve(n,costs,dp,2));
        dp[0]=min(dp[0],9+solve(n,costs,dp,3));
        return dp[0];
    }
};