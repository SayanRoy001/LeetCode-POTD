class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=0;int j=0;
        int n=nums.size();
        int count=0;
        // while(i<n){
        //                 // count++;
        //     while(nums[i]!=0){
        //         i++;
        //         j=i;
        //         if(i>=n){
        //             return count;
        //         }
        //     }
        //     count++;//here cuz ik its gonne flip if nums[i]==0
        //     int k=3;

        //     while(k--){
        //         if(j>=n){//checking such that if j>=n 
        //                 //means the 3 flip is not possible so its wrong
        //             return -1;
        //         }
        //         if(nums[j]==0){
        //             nums[j]=1;
        //         }
        //         else{
        //             nums[j]=0;
        //         }
                
        //         j++;
        //     }
        // }

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
                if(i+1>=n||i+2>=n) return -1;
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
            }
        }
        return count;
    }
};