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


long recursion(int index, int value, int *coins)
{
    // if(value==coins[index])
    // return 1;

    if(index==0)
    {
        if(value%coins[index]==0)
        return 1;

        return 0;
    }

    long notPick=recursion(index-1, value, coins);

    long pick=0;

    if(coins[index]<=value)
    pick=recursion(index, value-coins[index], coins);

    return pick+notPick;
}


long topDown(int index, int value, int *coins, vector<vector<int>>dp)
{
    // if(value==coins[index])
    // return 1;

    if(index==0)
    {
        if(value%coins[index]==0)
        return 1;

        return 0;
    }

    if(dp[index][value]!=-1)
    return dp[index][value];


    long notPick=topDown(index-1, value, coins,dp);

    long pick=0;

    if(coins[index]<=value)
    pick=topDown(index, value-coins[index], coins,dp);

    return dp[index][value]=pick+notPick;
}

long bottomUp(int *coins, int value , int n )
{
    vector<vector<long>>dp(n, vector<long>(value+1,0));

    for(int j=0;j<=value;j++)
    {
        dp[0][j]=(j%coins[0]==0);
    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=value;j++)
        {
           
            {
                long notPick=dp[i-1][j];
                long pick=0LL;
                if(coins[i]<=j) pick=dp[i][j-coins[i]];

                dp[i][j]=pick+notPick;
            }
        }
    }


    // for(auto i:dp)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }

    return dp[n-1][value];
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    // vector<vector<int>>dp(n, vector<int>(value+1, -1));

    return bottomUp(denominations, value, n);
    // return topDown(n-1, value, denominations, dp);
    // return recursion(n-1, value, denominations);
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

        int value;
        cin>>value;


        cout<<countWaysToMakeChange(arr, n, value);

    }
    return 0;
}