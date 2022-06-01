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

int solve(int row,int col)
{
   if(row==0 and col==0)
   return 1;

   int right=0, down=0;

   if(row==0 and col>0)
   right=solve(row,col-1);

   else if(row>0 and col==0)
   down=solve(row-1,col);

   else 
   {
       right=solve(row,col-1);
       down=solve(row-1,col);
   }

   return right+down;
}



int topDown(vector<vector<int>>&dp,int row,int col)
{
   if(row==0 and col==0)
   return 1;

   if(dp[row][col]!=-1)
   return dp[row][col];


   int right=0, down=0;

   if(row==0 and col>0)
   right=topDown(dp,row,col-1);

   else if(row>0 and col==0)
   down=topDown(dp,row-1,col);

   else 
   {
       right=topDown(dp,row,col-1);
       down=topDown(dp,row-1,col);
   }

   return dp[row][col]=right+down;
}


int uniquePaths(int m, int n) 
{
    vector<vector<int>>dp(m,vector<int>(n,-1));

    return topDown(dp,m-1,n-1);
    return solve(m-1,n-1);
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
        cin>>m>>n;

        cout<<uniquePaths(m,n);
    }
    return 0;
}