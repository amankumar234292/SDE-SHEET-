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


int recursion(int index, bool buy, int noOfTransactions, vector<int>&prices, int n)
{
    if(noOfTransactions==0)
    return 0;

    if(index==n)
    return 0;

    if(buy)
    {
        int ifBuy=-prices[index]+recursion(index+1, false, noOfTransactions, prices, n);
        int ifNotBuy=0+recursion(index+1, true, noOfTransactions, prices, n);

        return max(ifNotBuy, ifBuy);
    }

    else
    {
        int ifSell=prices[index]+recursion(index+1, true, noOfTransactions-1, prices, n);
        int ifNotSell=0+recursion(index+1, false, noOfTransactions, prices, n);

        return max(ifSell, ifNotSell);
    }
}



int topDown(int index, bool buy, int noOfTransactions, vector<int>&prices, int n,vector<vector<vector<int>>>&dp)
{
    if(noOfTransactions==0)
    return 0;

    if(index==n)
    return 0;

    if(dp[index][buy][noOfTransactions]!=-1)
    return dp[index][buy][noOfTransactions];

    if(buy)
    {
        int ifBuy=-prices[index]+topDown(index+1, false, noOfTransactions, prices, n,dp);
        int ifNotBuy=0+topDown(index+1, true, noOfTransactions, prices, n,dp);

        return dp[index][buy][noOfTransactions]=max(ifNotBuy, ifBuy);
    }

    else
    {
        int ifSell=prices[index]+topDown(index+1, true, noOfTransactions-1, prices, n,dp);
        int ifNotSell=0+topDown(index+1, false, noOfTransactions, prices, n,dp);

        return dp[index][buy][noOfTransactions]=max(ifSell, ifNotSell);
    }
}

int bottomUp(vector<int>prices, int n)
{
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

    int i,j,k;
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<3;k++)
            {
                
                // else 
                {
                    if(j==1)
                    {
                        dp[i][j][k]=max(dp[i+1][1][k],-prices[i]+dp[i+1][0][k]);
                    }

                    else 
                    {
                        dp[i][j][k]=max(dp[i+1][0][k],prices[i]+dp[i+1][1][k-1]);
                    }
                }
            }
        }
    }

    return dp[0][1][2];
}


int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
    // return recursion(0,true, 2, prices, n);

    // return topDown(0, true, 2, prices, n,dp);
    return bottomUp(prices,n);
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
        ll i,j,n;
        cin>>n;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<maxProfit(v,n)<<endl;
      
    }
    return 0;
}