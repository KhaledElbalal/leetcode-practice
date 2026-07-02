class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m; i < m + n; i++) {
            nums1[i] = nums2[i-m];
        }
        for(int i = 0; i < m + n; i++) {
            int minPos = i;
            for(int j = i + 1; j < m + n; j++) {
                if(nums1[j] < nums1[minPos]) minPos = j;
            }
            swap(nums1[i], nums1[minPos]);
        }
    }
};