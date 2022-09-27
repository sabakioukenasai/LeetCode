#include<iostream>
#include<vector>
using namespace std;

class Solution{
public :
    int jump(vector<int> &nums){
        int steps = 0, start = 0, end = 0;
        while (end < nums.size()-1) {
            int max = end;
            for (int i = start; i <= end; i++) {
                if (nums[i]+i > max) {
                    max = nums[i]+i;
                } 
            }
            start = end+1;
            end = max;
            steps++;
        }
        return steps;
    }
};

int main(){
    vector<int> nums{2, 3, 1, 1, 4};
    Solution T;
    cout << T.jump(nums) << endl;

}