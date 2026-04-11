#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 1;

        while(fast < nums.size()){
            if(nums[slow] != nums[fast]){
                nums[slow+1] = nums[fast];
                slow++;
            }
            else{
                fast++;
            }
        }
        return slow+1;
    }
};