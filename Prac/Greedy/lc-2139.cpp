class Solution {
    public:
        int minMoves(int target, int maxDoubles) {
            int count=0;
            while(target>1&&maxDoubles>0){
                if(target%2==0){
                    target/=2;
                    maxDoubles--;
                }
                else{
                    target--;
                }
                count++;
            }
            return count +(target-1);
        }
    };