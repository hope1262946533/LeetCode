#include "cstdio"

#include <vector>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> result = merge(nums1, nums2);
       printf("%d\n", result.size());
       int mid = (result.size() - 1) >> 1;
       if (result.size() % 2) {
       		return result[mid];
	   } else {
	   		return (result[mid] + result[mid + 1]) / 2.0;
	   } 
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> result;
    	int index1 = 0, index2 = 0;
    	while (index1 < nums1.size() && index2 < nums2.size()) {
    		if (nums1[index1] < nums2[index2]) {
    			result.push_back(nums1[index1]);
    			++ index1;
			} else {
				result.push_back(nums2[index2]);
				++ index2;
			}
		}
		while (index1 < nums1.size()) {
			result.push_back(nums1[index1]);
			++ index1;
		}
		while (index2 < nums2.size()) {
			result.push_back(nums2[index2]);
			++ index2;
		}
		return result;
	}
};

int main() {
	vector<int> nums1, nums2;
	nums1.push_back(1);
	nums1.push_back(3);

	nums2.push_back(2);	
	nums2.push_back(5);
	
	Solution solution;
	
	printf("%lf\n", solution.findMedianSortedArrays(nums1, nums2));
	return 0; 
} 
