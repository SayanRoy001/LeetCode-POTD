class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size(), res=0;
        vector<int> pre(n), suff(n);
        pre[0]=nums[0];
        suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=min(pre[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            res=max(res,suff[i]-pre[i]);
        }
        if(res==0)return -1;
        return res;
    }
};