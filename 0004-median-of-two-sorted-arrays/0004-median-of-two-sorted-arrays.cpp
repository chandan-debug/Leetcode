class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nums3(n + m);
        int i = n - 1;
        int j = m - 1;
        int k = n + m - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] < nums2[j]) {
                nums3[k] = nums2[j];
                j--;
            } else {
                nums3[k] = nums1[i];
                i--;
            }
            k--;
        }
        while (i >= 0) {
            nums3[k] = nums1[i];
            i--;
            k--;
        }
        while (j >= 0) {
            nums3[k] = nums2[j];
            j--;
            k--;
        }

        int mid = (n + m) / 2;
        if ((n + m) % 2 == 0) {
            return (nums3[mid - 1] + nums3[mid]) / 2.0;
        } else {
            return nums3[mid];
        }
    }
};
