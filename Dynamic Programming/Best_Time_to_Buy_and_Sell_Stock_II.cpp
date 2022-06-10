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


long recursion(int index, bool buy, long *value, int n)
{
    if(index==n)
    return 0;

    if(buy==true)
    {
        long ifBuy=-value[index]+recursion(index+1, false, value, n);
        long ifNotBuy=0+recursion(index+1, true, value, n);
        return max(ifBuy,ifNotBuy );
    }
    
    else 
    {
        long ifSell=value[index]+recursion(index+1, true, value, n);
        long ifNotSell=0+recursion(index+1, false, value, n);
        return max(ifSell,ifNotSell);
    }
}

long topDown(int index, bool buy, long *value, int n, vector<vector<long>>dp)
{
    if(index==n)
    return 0;

    if(dp[index][buy]!=-1)
    return dp[index][buy];

    if(buy==true)
    {
        long ifBuy=-value[index]+topDown(index+1, false, value, n,dp);
        long ifNotBuy=0+topDown(index+1, true, value, n,dp);
        return dp[index][buy]=max(ifBuy,ifNotBuy );
    }
    
    else 
    {
        long ifSell=value[index]+topDown(index+1, true, value, n,dp);
        long ifNotSell=0+topDown(index+1, false, value, n,dp);
        return dp[index][buy]=max(ifSell,ifNotSell);
    }
} 


long bottomUp(long *value, int n)
{
    vector<vector<long>>dp(n, vector<long>(2,0));
    dp[0][0]=0;
    dp[0][1]=-value[0];

    for(int i=1;i<n;i++)
    {
        dp[i][0]=max(dp[i-1][0],value[i]+dp[i-1][1]);
        dp[i][1]=max(dp[i-1][1],-value[i]+dp[i-1][0]);
    }

    for(auto i:dp)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }

    return max(dp[n-1][0], dp[n-1][1]);
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    // vector<vector<long>>dp(n, vector<long>(2,-1));

    // return topDown(0, true, values, n,dp);

    return bottomUp(values , n);
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

        long v[n];

        for(i=0;i<n;i++)
        cin>>v[i];


        cout<<getMaximumProfit(v,n);
    }
    return 0;
}