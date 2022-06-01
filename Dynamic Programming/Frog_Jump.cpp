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


int topDown(int idx,vector<int>&height,vector<int>&dp)
{
    if(idx==0)
    {
        dp[0]=0;
        return dp[0];
    }

    if(dp[idx]!=-1)
    return dp[idx];

    int left=topDown(idx-1,height,dp)+abs(height[idx]-height[idx-1]);

    int right=INT_MAX;
    if(idx>1)
    right=topDown(idx-2,height,dp)+abs(height[idx]-height[idx-2]);
    

    return dp[idx]=min(left,right);
}


int bottomUp(vector<int>height,vector<int>dp)
{
    ll i,n=height.size();
    dp[0]=0;
    dp[1]=abs(height[1]-height[0]);

    for(i=2;i<n;i++)
    {
        dp[i]=min(dp[i-1]+abs(height[i]-height[i-1]),dp[i-2]+abs(height[i]-height[i-2]));
    }

    return dp[n-1];

}

int frogJump(int n, vector<int>&height)
{
    vector<int>dp(n,-1);
    return topDown(n-1,height,dp);

    // return bottomUp(height,dp);
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
        int i,j,n;
        cin>>n;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<frogJump(n,v)<<endl;
    }
    return 0;
}