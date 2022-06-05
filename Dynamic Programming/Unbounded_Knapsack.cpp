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

int recursion(int index, int maxWeight,vector<int>profit, vector<int>weight)
{
    if(maxWeight==0)
    return 0;

    if(index==0)
    {
        if(maxWeight>=weight[index])
        {
            return (maxWeight/weight[index])*profit[index];
        }

        return 0;
    }


    int notPick=0+recursion(index-1,maxWeight,profit,weight);
    int pick=0;
    if(weight[index]<=maxWeight)
    pick=profit[index]+recursion(index,maxWeight-weight[index],profit,weight);

    return max(pick,notPick);
}


int topDown(int index, int maxWeight,vector<int>profit, vector<int>weight,vector<vector<int>>dp)
{
    if(maxWeight==0)
    return 0;

    if(index==0)
    {
        if(maxWeight>=weight[index])
        {
            return (maxWeight/weight[index])*profit[index];
        }

        return 0;
    }

    if(dp[index][maxWeight]!=-1)
    return dp[index][maxWeight];

    int notPick=0+topDown(index-1,maxWeight,profit,weight,dp);
    int pick=0;
    if(weight[index]<=maxWeight)
    pick=profit[index]+topDown(index,maxWeight-weight[index],profit,weight,dp);

    return dp[index][maxWeight]=max(pick,notPick);
}


int BottomUp(int n, int maxWeight,vector<int>&profit, vector<int>&weight)
{
    vector<vector<int>>dp(n, vector<int>(maxWeight+1,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            if(i==0)
            {
                dp[i][j]=((int)(j/weight[0]))*profit[0];
            }

            else 
            {
                int notPick=0+dp[i-1][j];
                int pick=INT_MIN;
                if(weight[i]<=j)
                pick=profit[i]+dp[i][j-weight[i]];

                dp[i][j]=max(pick, notPick);
            }
        }
    }


    return dp[n-1][maxWeight];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n, vector<int>(w+1, -1));

    // return topDown(n-1, w, profit, weight,dp);
    return BottomUp(n,w, profit,weight);
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
        ll i,j,n,maxWeight;
        cin>>n>>maxWeight;

        vector<int>w(n), v(n);
        for(i=0;i<n;i++)
        cin>>v[i];

        for(i=0;i<n;i++)
        cin>>w[i];

        

        cout<<unboundedKnapsack(n,maxWeight, v, w)<<endl;
    }
    return 0;
}