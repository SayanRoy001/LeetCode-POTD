class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
           long long mini=*min_element(ranks.begin(),ranks.end());
           long long maxi=*max_element(ranks.begin(),ranks.end());
           long long carsSq=cars;
           carsSq*=carsSq;
           long long s=mini;long long e=(long long)(carsSq*maxi);
           long long ans=0;
            while(s<=e){
                long long mid=s+(e-s)/2;
                long long nC=0;
                for(auto it:ranks){
                    nC+=sqrt(mid/it);
                }
                if(nC>=cars){
                    e=mid-1;
                    ans=mid;
                }
                else{
                    s=mid+1;
                }
            }
            return ans;
        }
    };