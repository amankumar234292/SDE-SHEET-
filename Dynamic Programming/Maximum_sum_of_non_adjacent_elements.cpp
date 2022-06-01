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


int topDown(int idx, vector<int>nums,vector<int>&dp)
{
    if(idx==0)
    return dp[0]=nums[idx];

    if(idx==1)
    return dp[1]=max(nums[idx],nums[idx-1]);

    if(dp[idx]!=-1)
    return dp[idx];

    int left=INT_MIN, right=INT_MIN;

    if(idx-2>=0)
    left=nums[idx]+topDown(idx-2,nums,dp);

    if(idx-1>=0)
    right=0+topDown(idx-1,nums,dp);

    return dp[idx]=max(left,right);
}


int bottomUp(vector<int>nums)
{
    vector<int>dp(nums.size(),0);

    dp[0]=nums[0];

    for(int i=1;i<nums.size();i++)
    {
        if(i==1)
        dp[i]=max(nums[i],nums[i-1]);

        else 
        dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
    }

    return dp[nums.size()-1];
}



int SpaceOptimizedBottomUp(vector<int>nums)
{
    vector<int>dp(nums.size(),0);

    int prev1=INT_MIN,prev2=INT_MIN,curr=INT_MIN;
    prev1=nums[0];

    if(nums.size()==1)
    return prev1;

    prev2=max(nums[0],nums[1]);

    if(nums.size()==2)
    return prev2;

    // curr=prev2;

    for(int i=2;i<nums.size();i++)
    {
        if(i==2)
        {
            curr=max(nums[i]+prev1,prev2);
        }

        else 
        {
            prev1=prev2;
            prev2=curr;

            curr=max(nums[i]+prev1,prev2);
        }
    }

    return curr;
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    vector<int>dp(nums.size(),-1);
    return SpaceOptimizedBottomUp(nums);
    
}

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    test()
    {
        int i,j,n;
        cin>>n;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<maximumNonAdjacentSum(v)<<endl;;
    }
    return 0;
}