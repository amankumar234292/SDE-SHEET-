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
 
// bool compare(ll a,ll b)
// {
//     return a<b;
// }


int recursionSolution(int idx, int last , vector<vector<int>>points)
{
    if(idx==0)
    {
        int maxi=INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(last!=i)
            maxi=max(maxi,points[0][i]);
        }

        return maxi;
    }

    int maxi=INT_MIN;
    for(int i=0;i<3;i++)
    {
        if(last!=i)
        {
            maxi=max(maxi,points[idx][i]+recursionSolution(idx-1,i,points));
        }
    }

    return maxi;
}


int topDownSolution(int idx, int last , vector<vector<int>>&points, vector<vector<int>>&dp)
{
    if(idx==0)
    {
        int maxi=INT_MIN;
        int pos;

        for(int i=0;i<3;i++)
        {
            if(last!=i)
            {
                maxi=max(maxi,points[0][i]);

            } 
        }

        return dp[0][last]=maxi;
    }

    if(dp[idx][last]!=-1)
    return dp[idx][last];

    int maxi=INT_MIN;
    for(int i=0;i<3;i++)
    {
        if(last!=i)
        {
            maxi=max(maxi,points[idx][i]+topDownSolution(idx-1,i,points,dp));
        }
    }

    return dp[idx][last]=maxi;
}

int bottomUpSolution(int n, vector<vector<int>>points)
{
    vector<vector<int>>dp(n,vector<int>(3,0));

    dp[0][0]=points[0][0],dp[0][1]=points[0][1], dp[0][2]=points[0][2];

    for(int i=1;i<n;i++)
    {
        dp[i][0]=points[i][0]+max(dp[i-1][1],dp[i-1][2]);
        dp[i][1]=points[i][1]+max(dp[i-1][0],dp[i-1][2]);
        dp[i][2]=points[i][2]+max(dp[i-1][0],dp[i-1][1]);
    }

    return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}



int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(3,-1));
    // return topDownSolution(n-1,0,points,dp);
    // return recursionSolution(n-1,0,points);

    return bottomUpSolution(n,points);
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(3,-1));
    // return topDownSolution(n-1,0,points,dp);
    // return recursionSolution(n-1,0,points);

    return bottomUpSolution(n,points);
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

        vector<vector<int>>v(n,vector<int>(3,0));

        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                cin>>v[i][j];
            }
        }

        string s;
        s.substr

        cout<<ninjaTraining(n,v)<<endl;
    }
    return 0;
}