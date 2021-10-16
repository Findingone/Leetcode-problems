class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpLength = nums.at(0);
        while(jumpLength!=0){
            nums.erase(nums.begin());
            if(nums.size()==0){
                return true;
            }
            jumpLength--;
            jumpLength = nums.at(0)>jumpLength?nums.at(0):jumpLength;
        }
        if(nums.size()==1){
                return true;
        }
        return false;
    }
};
