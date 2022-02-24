#include <bits/stdc++.h>
using namespace std;
 
 class Solutions{
     public:
     int findMajorrity(vector<int> nums)
     {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++; //storing frequency of each element in the map
        }
        int res;
        for(auto x: m)
        {   
            int temp=x.second;
            if(temp>(nums.size())/2) res=x.first; //checking if number has appeared more than n/2 times
        }
        return res;
     }
 };

 int main()
 {
     Solutions sa;
     vector<int> nums {2,3,4,5,2,2,3,2,2};
     cout<<sa.findMajorrity(nums);
     return 0;
 }

 //time complexity: O(n) 
 //space complexity: O(n) as we used hashmap of size n