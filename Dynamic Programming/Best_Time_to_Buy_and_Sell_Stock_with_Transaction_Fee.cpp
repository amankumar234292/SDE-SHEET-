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


int solve(int index, bool buy, vector<int>&price, int n, vector<vector<int>>&dp, int fee)
{
    if(index>=n)
    return 0;

    if(dp[index][buy]!=-1)
    return dp[index][buy];

    if(buy)
    {
        int ifBuy=-price[index]+solve(index+1, false, price, n,dp,fee);
        int ifNotBuy=solve(index+1, true, price, n,dp,fee);

        return dp[index][buy]=max(ifBuy, ifNotBuy);
    }

    else 
    {
        int ifSell=price[index]-fee+solve(index+1, true, price, n, dp,fee);
        int ifNotSell=0+solve(index+1, false, price, n, dp,fee);

        return dp[index][buy]=max(ifSell, ifNotSell);
    }
}


int maximumProfit(int n, int fee, vector<int> &prices) 
{
    vector<vector<int>>dp(n, vector<int>(2, -1));
    return solve(0, true, prices, n, dp, fee);
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
        ll i,j,n, fee;
        cin>>n>>fee;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<maximumProfit(n, fee, v)<<endl;
      
    }
    return 0;
}