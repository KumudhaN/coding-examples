https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1_ptr=0, n2_ptr=0;
        vector<int> merged_arr;
        while (n1_ptr < m && n2_ptr < n){
            //cout << "Inisde for ";
            while (n1_ptr < m && nums1[n1_ptr] !=0 && nums1[n1_ptr] <= nums2[n2_ptr]){
                //cout << "Inside first while ";
                n1_ptr++;
            }
            int n2_start = n2_ptr;
            while(n2_ptr < n && nums2[n2_ptr] !=0 &&  nums2[n2_ptr] < nums1[n1_ptr]){
                //cout << "Inside second while ";
                n2_ptr++;
            }
            for(int i=n1_ptr; i< n2_ptr - n2_start;i++){
                cout << "Swapping: " << nums1[i] << " " << nums2[n2_start+i] << std::endl;
                int tmp = nums1[i];
                nums1[i] = nums2[n2_start+i];
                nums2[n2_start+i] = tmp;
                n1_ptr++;
            }
        }
        if(n1_ptr == m+n){
            return;
        }
    }
};