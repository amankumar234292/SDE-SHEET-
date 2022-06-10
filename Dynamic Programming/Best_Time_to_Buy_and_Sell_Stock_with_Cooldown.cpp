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

int solve(int index, bool buy, vector<int>price, int n, vector<vector<int>>dp)
{
    if(index>=n)
    return 0;

    if(dp[index][buy]!=-1)
    return dp[index][buy];

    if(buy)
    {
        int ifBuy=-price[index]+solve(index+1, false, price, n,dp);
        int ifNotBuy=solve(index+1, true, price, n,dp);

        return dp[index][buy]=max(ifBuy, ifNotBuy);
    }

    else 
    {
        int ifSell=price[index]+solve(index+2, true, price, n, dp);
        int ifNotSell=0+solve(index+1, false, price, n, dp);

        return dp[index][buy]=max(ifSell, ifNotSell);
    }
}

int maxProfit(vector<int>& prices) 
{
    vector<vector<int>>dp(prices.size(), vector<int>(2,-1));
    return solve(0, true, prices, prices.size(),dp);
        
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

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<maxProfit(v)<<endl;
    }
    return 0;
}