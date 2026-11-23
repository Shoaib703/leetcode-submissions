/*
 * Maximize Expression of Three Elements
 * Difficulty: Easy
 *
 * You are given an integer array nums.

Choose three elements a, b, and c from nums at distinct indices such that the value of the expression a + b - c is maximized.

Return an integer denoting the maximum possible value of this expression.

 
Example 1:


Input: nums = [1,4,2,5]

Output: 8

Explanation:

We can choose a = 4, b = 5, and c = 1. The expression value is 4 + 5 - 1 = 8, which is the maximum possible.


Example 2:


Input: nums = [-2,0,5,-2,4]

Output: 11

Explanation:

We can choose a = 5, b = 4, and c = -2. The expression value is 5 + 4 - (-2) = 11, which is the maximum possible.


 
Constraints:


	3 <= nums.length <= 100
	-100 <= nums[i] <= 100


 */

class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {

        int m1=INT_MIN,m2=INT_MIN,min1=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=m1){
                m2=max(m1,m2);
                m1=nums[i];
            }
            else if(nums[i]>=m2){
                m2=nums[i];
            }
            min1=min(nums[i],min1);
        }
        return m1+m2-min1;
    }
};