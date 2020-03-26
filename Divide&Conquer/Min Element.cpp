#include <bits/stdc++.h>
using namespace std;
int dAndC(int *arr, int s, int e)
{
    if(s==e) return arr[s];
    else
    {
        int mid = (s+e)/2;
        int left = dAndC(arr,s,mid);
        int right = dAndC(arr,mid+1,e);
        return min(left,right);
    }
}
int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << dAndC(arr,0,n-1) << endl;
    return 0;
}
