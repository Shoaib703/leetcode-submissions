/*
 * Number of Sub-arrays With Odd Sum
 * Difficulty: Medium
 *
 * Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 
Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.


Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.


Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16


 
Constraints:


	1 <= arr.length <= 105
	1 <= arr[i] <= 100


 */

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        vector<pair<int,int>>mem(arr.size(),{0,0});
        if(arr[n-1]%2==0){
            mem[n-1].second=1;
        }
        else{
            mem[n-1].first=1;
            ans=1;
        }
        int mx=1e9+7;
        for(int i=n-2;i>=0;i--){
            ans%=mx;
            if(arr[i]%2==0){
                mem[i].second=1+mem[i+1].second;
                ans+=mem[i].first=mem[i+1].first;
                ans%=mx;
            }
            else{
               ans+=mem[i].first=1+mem[i+1].second;
               mem[i].second=mem[i+1].first;
               ans%=mx;
            }
        }
        return ans;
    }
};