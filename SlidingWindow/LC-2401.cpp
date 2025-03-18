#include <bits/stdc++.h>
using namespace std;
//if x^y==x+y then x&y=0 as x and y do not have any set bits in their positions
//8,5,2
//1000
//0101
//0010
//xoring 8,5 gives 1101 & then xoring with 2 gives 1111 that means all bits pos is 1
//so now xoring with any other number results 1
//so for each pair in the subarr, all xoring should return their sum, as it indicates,
//no change in the bits position
//so if we take the subarr of 3 elements, then we can check if the xoring of the 3 elements
//is equal to the sum of the 3 elements, then we can say that the subarr is good
//so we can check for all the subarrs of 3 elements and check if they are good or not

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n=nums.size();
            int i = 0;
            int j = 0;
            int LNS=0;
            int xorSum=0;
            int sum=0;
            int count=0;
            while(j<n){
                xorSum^=nums[j];
                sum+=nums[j];
                if(xorSum==sum){
                    count=j-i+1;
                    // cout<<i<<" "<<j<<" "<<count<<endl;
                    LNS=max(count,LNS);
                }
                else{
                    while(xorSum!=sum){
                        int a=nums[i];
                        xorSum^=a;
                        sum-=a;
                        i++;
                    }
                }
                j++;
            }
            
            return LNS;
        }
    };