#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll              int
#define endl            "\n"
#define MOD             1e9 + 7
#define test()          ll t; cin>>t; while(t--)
#define precision(x,y)  fixed<<setprecision(y)<<x
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
bool compare(ll a,ll b)
{
    return a<b;
}

ll  ans=INT_MAX;

ll topDown(ll idx,ll k,vector<ll>height, vector<ll>&dp)
{
    if(idx<=0)
    return dp[0]=0;

    if(dp[idx]!=-1)
    return dp[idx];

   

    for(ll j=1;j<=k;j++)
    {
        if(idx-j>=0)
        {
            ll jump =topDown(idx-j,k,height,dp)+abs(height[idx]-height[idx-j]);
            ans=min(ans,jump);
        }
        
    }
    return dp[idx]=ans;
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
        ll i,j,n,k;
        cin>>n>>k;

        vector<ll>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        vector<ll>dp(n,-1);
        cout<<topDown(n-1,k,v,dp)<<endl;

        // for(auto i:dp)
        // cout<<i<<" ";
        // cout<<endl;
    }
    return 0;
}