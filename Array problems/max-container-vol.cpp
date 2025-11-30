// https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    int maxArea(vector<int>& height) {

        // area = min(h(i), h(j)) * (index(j)-index(i))
        int len = height.size();
        int max_area = 0;

        // O(n2)
        // for(int i=0;i<len;i++){
        //     for(int j=i;j<len;j++){
        //         int area = min(height[i], height[j]) * (j-i);
        //         if(area > max_area)
        //             max_area = area;
        //     }
        // }

        int left_ptr = 0;
        int right_ptr = len-1;
        while(left_ptr < right_ptr){
            int area = min(height[left_ptr], height[right_ptr]) * (right_ptr-left_ptr);
            if(area > max_area) max_area = area;
            if(height[left_ptr] <height[right_ptr]) left_ptr++;
            else right_ptr--;
        }
        return max_area;
    }
};