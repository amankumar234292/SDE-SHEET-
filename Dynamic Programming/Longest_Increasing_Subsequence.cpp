#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll              long long int
#define endl            "\n"
#define MOD             1e9 + 7
#define test()          ll t; cin>>t; while(t--)
#define precision(x,y)  fixed<<setprecision(y)<<x
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
bool compare(ll a,ll b)
{
    return a<b;
}
 
int recursion(int index, int prev, int *arr, int n)
{
    if(index>=n)
    return 0;

    int notPick=0+recursion(index+1, prev, arr, n);

    int pick=0;
    if(prev==-1 or arr[prev]<arr[index])
    pick=1+recursion(index+1, index, arr, n);

    return max(pick, notPick);
}

int topDown(int index, int prev, int *arr, int n, vector<vector<int>>dp)
{
    if(index>=n)
    return 0;

    if(dp[index][prev+1]!=-1)
    return dp[index][prev+1];

    int notPick=0+topDown(index+1, prev, arr, n,dp);

    int pick=0;
    if(prev==-1 or arr[prev]<arr[index])
    pick=1+topDown(index+1, index, arr, n, dp);

    return dp[index][prev+1]= max(pick, notPick);
}

int bottomUp(int *arr, int n)
{
    vector<int>dp(n,0);
    int i,j;

    for(i=0;i<n;i++)
    {
        int maxi=0;
        for(j=0;j<=i;j++)
        {
            if(arr[i]>arr[j])
            maxi=max(maxi, dp[j]);
        }

        dp[i]=maxi+1;
    }


    return *max_element(dp.begin(),dp.end());
}


int findpos(vector<int>lis, int element)
{
    int first=0;
    int second=lis.size();
    int ans=0;

    while(first<=second)
    {
        int mid=first+(second-first)/2;

        if(lis[mid]==element)
        return mid;

        else if(lis[mid]>element)
        {
            ans=mid;
            second=mid-1;
        }

        else 
        first=mid+1;
    }

    return ans;
}


int binarySearchSolution(int *arr, int n)
{
    vector<int>lis;
    lis.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>lis.back())
        lis.push_back(arr[i]);

        else 
        {
            int pos=findpos(lis, arr[i]);
            lis[pos]=arr[i];
        }
    }

    for(auto i:lis)
    cout<<i<<" ";
    cout<<endl;

    return lis.size();
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n, vector<int>(n+1,-1));
    // return recursion(0, -1, arr, n);

    // return topDown(0, -1, arr, n, dp);

    return binarySearchSolution(arr,n);
}


int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    // test()
    {
        ll i,j,n;
        cin>>n;

        int arr[n];

        for(i=0;i<n;i++)
        cin>>arr[i];

        cout<<longestIncreasingSubsequence(arr, n);
    }
    return 0;
}