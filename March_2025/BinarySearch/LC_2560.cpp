#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool checkPossibleSubSequence(vector<int>&nums,int mid,int k){
        int count=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]<=mid){
                count++;
                if(count==k){
                    return true;
                }
                i+=2;
            }
            else{
                i++;
            }
        }
       return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
       int n=nums.size();
       int s=*min_element(nums.begin(),nums.end());
       int e=*max_element(nums.begin(),nums.end());
       int ans=-1;
       int mid=s+(e-s)/2;
       while(s<=e){
            if(checkPossibleSubSequence(nums,mid,k)){
                //if for a value mid, possible sequence
                // whose val<=mid  exists or not
                e=mid-1;
                ans=mid;
            }
            else {
                s=mid+1;
            }
            mid=s+(e-s)/2;
       }
       return ans;

    }
};