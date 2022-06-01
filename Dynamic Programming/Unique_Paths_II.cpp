#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll              long long int
#define endl            "\n"
#define MOD             1000000007
#define test()          ll t; cin>>t; while(t--)
#define precision(x,y)  fixed<<setprecision(y)<<x
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
bool compare(ll a,ll b)
{
    return a<b;
}


int recursion(int n, int m, vector<vector<int>>v)
{
    if(n==0 and m==0)
    {
        if(v[n][m]==-1)
        return 0;

        return 1;
    }

    if(v[n][m]==-1)
    return 0;

    if(n<0 or m<0)
    return 0;

    int right=0,down=0;

    if(n==0 and m>0)
    right=recursion(n,m-1,v);

    else if(n>0 and m==0)
    down=recursion(n-1,m,v);

    else {
        right=recursion(n,m-1,v);
        down=recursion(n-1,m,v);
    }
    return right+down;
}


int topDown(int n, int m, vector<vector<int>>v, vector<vector<int>>&dp)
{

    
    if(n==0 and m==0)
    {
        if(v[n][m]==-1)
        return dp[n][m]=0;

        return dp[n][m]=1;
    }

    if(v[n][m]==-1)
    return dp[n][m]=0;
    

    if(dp[n][m]!=-1)
    return dp[n][m];

    int right=0,down=0;

    if(n==0 and m>0)
    right=topDown(n,m-1,v,dp);

    else if(n>0 and m==0)
    down=topDown(n-1,m,v,dp);

    else {
        right=topDown(n,m-1,v,dp);
        down=topDown(n-1,m,v,dp);
    }
    return dp[n][m]=(right+down)%MOD;

}


int buttomUp(int n, int m , vector<vector<int>>v)
{
    vector<vector<int>>dp(n,vector<int>(m,0));
    int i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(v[i][j]==-1)
            dp[i][j]=0;

            else if(i==0 and j==0)
            dp[i][j]=1;

            else if(i==0 and j>0)
            dp[i][j]=dp[i][j-1];

            else if(i>0 and j==0)
            dp[i][j]=dp[i-1][j];

            else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }


    return dp[n-1][m-1];
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>>dp(n,vector<int>(m,-1));
    // return topDown(n-1,m-1,mat,dp);

    return buttomUp(n,m,mat);
    // return recursion(n-1,m-1,mat);
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

        cout<<mazeObstacles(n,m,v)<<endl;
    }
    return 0;
}