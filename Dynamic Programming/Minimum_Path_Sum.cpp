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


int recursion(int row, int col, vector<vector<int>>grid)
{
    if(row==0 and col==0)
    return grid[0][0];

    int down=INT_MAX, right=INT_MAX;

    if(row==0 and col>0)
    right=grid[row][col]+recursion(row,col-1,grid);

    else if(row>0 and col==0)
    down=grid[row][col]+recursion(row-1,col,grid);

    else 
    {
        right=grid[row][col]+recursion(row,col-1,grid);
        down=grid[row][col]+recursion(row-1,col,grid);
    }
    
    return min(right,down);
}


int topDown(int row, int col, vector<vector<int>>grid,vector<vector<int>>&dp)
{
    if(row==0 and col==0)
    return dp[0][0]=grid[0][0];

    if(dp[row][col]!=-1)
    return dp[row][col];

    int down=INT_MAX, right=INT_MAX;

    if(row==0 and col>0)
    right=grid[row][col]+topDown(row,col-1,grid,dp);

    else if(row>0 and col==0)
    down=grid[row][col]+topDown(row-1,col,grid,dp);

    else 
    {
        right=grid[row][col]+topDown(row,col-1,grid,dp);
        down=grid[row][col]+topDown(row-1,col,grid,dp);
    }
    
    return dp[row][col]=min(right,down);
}

int bottomUp(vector<vector<int>>grid)
{
    vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
    int i,j;

    for(i=0;i<grid.size();i++)
    {
        for(j=0;j<grid[0].size();j++)
        {
            if(i==0 and j==0)
            dp[0][0]=grid[0][0];

            else if(i==0 and j>0)
            dp[i][j]=grid[i][j]+dp[i][j-1];

            else if(i>0 and j==0)
            dp[i][j]=grid[i][j]+dp[i-1][j];

            else 
            dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }

    return dp[grid.size()-1][grid[0].size()-1];
}

int minSumPath(vector<vector<int>> &grid) 
{
    vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));

    return bottomUp(grid);
    // return topDown(grid.size()-1,grid[0].size()-1,grid,dp);
    // return recursion(grid.size()-1,grid[0].size()-1,grid);
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
        ll i,j,n,m;
        cin>>n>>m;

        vector<vector<int>>v(n,vector<int>(m,0));

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            cin>>v[i][j];
        }


        cout<<minSumPath(v)<<endl;;
    }
    return 0;
}