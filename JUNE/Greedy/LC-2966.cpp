#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i+=3){
            int diff=nums[i+2]-nums[i];;
            if(diff>k) return {};
            ans.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        //  vector<int>temp;
        // for(int i=0;i<n;i++){
        //     if(temp.size()==3) {
        //         ans.push_back(temp);
        //         temp.pop_back();temp.pop_back();temp.pop_back();
        //     }
        //     temp.push_back(nums[i]);
        // }
        // ans.push_back(temp);
        return ans;
    }//1 1 3 3 4 5 7 8 9 
};