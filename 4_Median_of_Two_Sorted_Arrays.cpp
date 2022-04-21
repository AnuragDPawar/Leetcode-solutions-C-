#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int n = nums1.size();
        double res;
        if(n%2==1) res = nums1[n/2];
        else{
            int idx = n/2;
            double sum = nums1[idx]+nums1[idx-1];
            res  = sum/2;
        }
        return res;
    }
};

int main()
{
    vector<int> nums1 {1,2};
    vector<int> nums2 {3,4};
    Solution sa;
    cout<<sa.findMedianSortedArrays(nums1,nums2);
    return 0;
}

/*
Algorithm
1. Append second array on first one.
2. Sort the first array.
3. Return the middle element if length is odd.
4. Return the average of the middle two elements.

Time complexity: O(nlogn)
Space complexity: O(n1+n2)
*/