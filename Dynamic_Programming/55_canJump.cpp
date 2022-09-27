#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool canJump(vector<int> &nums){
        int len = nums.size(), target = len - 1;

        for (int i = len - 2; i >= 0; i--){
            if (i + nums[i] >= target){
                target = i;
            }
        }
        

        if(target == 0)
            return 1;
        else
            return 0;
    }
};

int main(){
    vector<int> nums = {3,2,1,0,4};
    Solution T;
    cout << T.canJump(nums) << endl;
}