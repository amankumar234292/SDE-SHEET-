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


int recursion (int start_row,int start1_col, int start2_col, int row, int col , vector<vector<int>>grid)
{
    if(start1_col<0 or start1_col>=col or start2_col<0 or start2_col>=col)
    return -10e8;

    if(start_row==row-1)
    {
        if(start1_col==start2_col)
        return grid[start_row][start1_col];

        else 
        return grid[start_row][start1_col]+grid[start_row][start2_col];
    }

    int maxi=INT_MIN;
    for(int i=-1;i<=+1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if(start1_col==start2_col)
            {
                maxi=max(maxi, grid[start_row][start1_col]+recursion(start_row+1,start1_col+i, start2_col+j,row, col,grid));
            }

            else maxi=max(maxi, grid[start_row][start1_col]+grid[start_row][start2_col]+recursion(start_row+1, start1_col+i, start2_col+j, row, col, grid));
        }
    }

    return maxi;
}



int topDown (int start_row,int start1_col, int start2_col, int row, int col , vector<vector<int>>&grid, vector<vector<vector<int>>>&dp)
{
    if(start1_col<0 or start1_col>=col or start2_col<0 or start2_col>=col)
    return -10e8;

    if(start_row==row-1)
    {
        if(start1_col==start2_col)
        return grid[start_row][start1_col];

        else 
        return grid[start_row][start1_col]+grid[start_row][start2_col];
    }

    if(dp[start_row][start1_col][start2_col]!=-1)
    return dp[start_row][start1_col][start2_col];

    int maxi=-10e8;
    for(int i=-1;i<=+1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            int value=0;
            if(start1_col==start2_col)
            value=grid[start_row][start1_col];
            else 
            value=grid[start_row][start1_col]+grid[start_row][start2_col];
            
            value+=topDown(start_row+1, start1_col+i, start2_col+j, row, col, grid, dp);
            maxi=max(maxi, value);
        }
    }
    return dp[start_row][start1_col][start2_col]=maxi;
}


int bottomUp(vector<vector<int>>grid)
{
    vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),0)));

    for(int row=0;row<grid.size();row++)
    {
        for(int col1=0;col1<grid[0].size();col1++)
        {
            for(int col2=0;col2<grid[0].size();col2++)
            {
                if(row==0)
                {
                    if(col1==col2)
                    dp[row][col1][col2]=grid[row][col1];

                    else 
                    dp[row][col1][col2]=grid[row][col1]+grid[row][col2];
                }

                else 
                {
                    for(int j1=-1;j1<=1;j1++)
                    {
                        for(int j2=-1;j2<=1;j2++)
                        {
                            if(col1+j1>=0 and col1+j1<grid[0].size() and col2+j2>=0 and col2<grid[0].size())
                            dp[row][col1][col2]=1;
                        }
                    }

                }
            }
        }
    }
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r , vector<vector<int>>(c,vector<int>(c,-1)));

    return topDown(0,0,c-1,r,c,grid,dp);
    // return recursion(0,0,c-1,r,c,grid);
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
        int i,j,n,m;
        cin>>n>>m;

        vector<vector<int>>v(n,vector<int>(m));

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            cin>>v[i][j];
        }

        cout<<maximumChocolates(n,m,v)<<endl;
    }
    return 0;
}