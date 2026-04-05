#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        //if no element or 1 we cant store water
        if (n == 0 || n== 1) return 0;

        //if 2 element simple calculate
        if(n == 2) return min(height[0], height[1]);
        int maxi = 0;

        //Brute force
        // for(int i = 0 ; i < n ; i++){
        //    for(int j = i+1 ; j < n ; j++){

        //     //calculate wid and len
        //     int width = j - i;
        //     int length = min(height[i] , height[j]);

        //     //find area and return the max
        //     int area = length * width;
        //      maxi = max(maxi,area);
        //    }
        // }

        // more optimized solution
        int left = 0;
        int right = n-1;

        while(left < right){
            int w = right - left;

            int l = min(height[left] , height[right]);

            int area = l * w;

            maxi = max(maxi, area);

            if(height[left] > height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxi;
    }
};