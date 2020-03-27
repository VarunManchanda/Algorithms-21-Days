class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return dAndC(nums,0,nums.size()-1);
    }
    int dAndC(vector<int> &nums, int s, int e)
    {
        if(s==e) return nums[s];
        else
        {
            int mid = (s+e)/2;
            int left = dAndC(nums,s,mid);
            int right = dAndC(nums,mid+1,e);
            if(left==right) return left;
            int lCount = count(left,nums,s,e);
            int rCount = count(right,nums,s,e);
            return lCount > rCount ? left : right;
        }
    }
    int count(int key, vector<int> &nums, int i, int j)
    {
        int ans = 0;
        for(int l=i; l<=j; ++l)
        {
            if(nums[l]==key) ans+=1;
        }
        return ans;
    }
};
