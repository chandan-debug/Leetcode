class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged;

        if (m == 0 && n == 0) {
            // Both input vectors are empty, return 0 as the median or handle as needed.
            return 0.0;
        } else if (m == 0) {
            // If nums1 is empty, simply return the median of nums2.
            int mid = n / 2;
            if (n % 2 == 0) {
                return static_cast<double>(nums2[mid - 1] + nums2[mid]) / 2.0;
            } else {
                return static_cast<double>(nums2[mid]);
            }
        } else if (n == 0) {
            // If nums2 is empty, simply return the median of nums1.
            int mid = m / 2;
            if (m % 2 == 0) {
                return static_cast<double>(nums1[mid - 1] + nums1[mid]) / 2.0;
            } else {
                return static_cast<double>(nums1[mid]);
            }
        }

        for (int i = 0; i < m; ++i) {
            if (nums1[i] > nums2[0]) {
                // Swap elements if nums1[i] is greater than nums2[0]
                swap(nums1[i], nums2[0]);

                // Re-arrange nums2 to keep it sorted (assuming nums2 is already sorted)
                int j = 0;
                while (j < n - 1 && nums2[j] > nums2[j + 1]) {
                    swap(nums2[j], nums2[j + 1]);
                    ++j;
                }
            }
        }

        // Merge nums1 and sorted nums2
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());

        int totalSize = merged.size();
        int mid = totalSize / 2;
        if (totalSize % 2 == 0) {
            return static_cast<double>(merged[mid - 1] + merged[mid]) / 2.0;
        } else {
            return static_cast<double>(merged[mid]);
        }
    }
};
