#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0 ; 
        int right = n -1;
        int leftMax = 0;
        int rightMax = 0 ;
        int water = 0;

        // while( left < right){

        //     if(leftMax < rightMax){
        //         left++;
        //         leftMax = max(leftMax ,height[left]);
        //         water += leftMax - height[left];
        //     }

        //     else{
        //         right--;
        //         rightMax = max(rightMax ,height[right]);
        //         water += rightMax - height[right];
        //     }
        // }
        
        // return water;


        while(left < right){
            if(height[left] <= height[right]){
               if(leftMax > height[left]){
                 water += leftMax -height[left];
               } else{
                 leftMax = max(leftMax , height[left]);
               }
               left++;
            }
            
            else{
               if(rightMax > height[right]){
                water += rightMax - height[right];
               }
               else {
                rightMax = max(rightMax , height[right]);
               }
               right--;
            }
        }
        return water;
    }
};