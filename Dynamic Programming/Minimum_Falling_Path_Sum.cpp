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

int recursion(int i,int j,int n, vector<vector<int>>v)
{
    if(i==n-1)
    return v[i][j];


    int first=INT_MAX, second=INT_MAX, third=INT_MAX;

    if(j==0)
    {
        first=v[i][j]+recursion(i+1,j,n,v);
        second=v[i][j]+recursion(i+1,j+1,n,v);
    }

    else if(j==n-1)
    {
        first=v[i][j]+recursion(i+1,j,n,v);
        second=v[i][j]+recursion(i+1,j-1,n,v);
    }

    else 
    {
        first=v[i][j]+recursion(i+1,j,n,v);
        second=v[i][j]+recursion(i+1,j-1,n,v);
        third=v[i][j]+recursion(i+1,j+1,n,v);
    }

    return min({first, second, third});
}


int topDown(int i,int j,int n, vector<vector<int>>v, vector<vector<int>>&dp)
{
    if(i==n-1)
    return v[i][j];

    if(dp[i][j]!=-1)
    return dp[i][j];


    int first=10e9, second=10e9, third=10e9;

    if(j==0)
    {
        first=v[i][j]+topDown(i+1,j,n,v,dp);
        second=v[i][j]+topDown(i+1,j+1,n,v,dp);
    }

    else if(j==n-1)
    {
        first=v[i][j]+topDown(i+1,j,n,v,dp);
        second=v[i][j]+topDown(i+1,j-1,n,v,dp);
    }

    else 
    {
        first=v[i][j]+topDown(i+1,j,n,v,dp);
        second=v[i][j]+topDown(i+1,j-1,n,v,dp);
        third=v[i][j]+topDown(i+1,j+1,n,v,dp);
    }

    return dp[i][j]=min({first, second, third});
}


int bottomUp(vector<vector<int>>v)
{
    vector<vector<int>>dp(v.size(),vector<int>(v.size(),0));

    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(i==0)
            dp[i][j]=v[i][j];

            else 
            {
                if(j==0)
                dp[i][j]=v[i][j]+min(dp[i-1][j],dp[i-1][j+1]);

                else if(j==v.size()-1)
                dp[i][j]=v[i][j]+min(dp[i-1][j],dp[i-1][j-1]);

                else 
                dp[i][j]=v[i][j]+min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
            }
        }
    }

    return *min_element(dp[v.size()-1].begin(),dp[v.size()-1].end());
}

int minFallingPathSum(vector<vector<int>> &vec, int n) 
{
    int mini=INT_MAX;
    // for(int j=0;j<n;j++)
    // mini=min(mini,recursion(0,j,n,vec));

    // return mini;


    // vector<vector<int>>dp(n,vector<int>(n,-1));

    // for(int j=0;j<n;j++)
    // {
    //     mini=min(mini, topDown(0,j,n,vec,dp));


    //     // for(auto i:dp)
    //     // {
    //     //     for(auto j:i)
    //     //     cout<<j<<" ";
    //     //     cout<<endl;
    //     // }
    //     // cout<<endl;
    // }

    // return mini;


    return bottomUp(vec);
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

        vector<vector<int>>v(n,vector<int>(n,0));
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            cin>>v[i][j];
        }
        cout<<minFallingPathSum(v, n)<<endl;
    }
    return 0;
}