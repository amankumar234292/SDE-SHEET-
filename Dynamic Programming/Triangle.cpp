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

int recursion(int i,int j, int n, vector<vector<int>>triangle)
{

    if(i==n-1)
    return triangle[n-1][j];

    
    int down=triangle[i][j]+recursion(i+1,j,n,triangle);
    int diagonal=triangle[i][j]+recursion(i+1,j+1,n,triangle);

    return min(down,diagonal);
}

int topDown(int i,int j, int n, vector<vector<int>>triangle, vector<vector<int>>&dp)
{

    if(i==n-1)
    return dp[n-1][j]=triangle[n-1][j];

    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int down=triangle[i][j]+topDown(i+1,j,n,triangle,dp);
    int diagonal=triangle[i][j]+topDown(i+1,j+1,n,triangle,dp);

    return dp[i][j]=min(down,diagonal);
}


int bottomUp(vector<vector<int>>triangle)
{
    vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),INT_MAX));
    int i,j,n=triangle.size();

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=j)
            {
                if(i==0 and j==0)
                dp[i][j]=triangle[i][j];

                else 
                {
                    if(j-1<0)
                    dp[i][j]=triangle[i][j]+(dp[i-1][j]);

                    else 
                    dp[i][j]=triangle[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                    
                }
                
            }
        }
    }

    // for(auto i:dp)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    return *min_element(dp[n-1].begin(),dp[n-1].end());
}

int minimumPathSum(vector<vector<int>>& triangle, int n)
{
    vector<vector<int>>dp(n, vector<int>(n,-1));
    // return topDown(0,0,n,triangle,dp);
    // return recursion(0,0,n, triangle);

    return bottomUp(triangle);
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

        vector<vector<int>>v(n,vector<int>(n,INT_MAX));

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            if(i>=j)
            cin>>v[i][j];
        }

        cout<<minimumPathSum(v,n)<<endl;
    }
    return 0;
}