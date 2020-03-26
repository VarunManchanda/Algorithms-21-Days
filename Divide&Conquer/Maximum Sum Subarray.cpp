#include <bits/stdc++.h>
using namespace std;
int crossSum(int *nums, int left, int mid, int right)
    {
        int maxleftsum = INT_MIN;
        int sum = 0;
        for(int i=mid; i>=left; i--)
        {
            sum += nums[i];
            maxleftsum = max(maxleftsum, sum);
        }
        int maxrightsum = INT_MIN;
        sum = 0;
        for(int i=mid+1; i<=right; i++)
        {
            sum += nums[i];
            maxrightsum = max(maxrightsum, sum);
        }
        return maxleftsum+maxrightsum;
    }
int dAndC(int *nums, int s, int e)
{
    if(s==e) return nums[s];
        int mid = (s+e)/2;
        int left = dAndC(nums,s,mid);
        int right = dAndC(nums,mid+1,e);
        int sum = crossSum(nums,s,mid,e);
        return max(sum,max(left,right));
}
int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << dAndC(arr,0,n-1) << endl;
    return 0;
}

