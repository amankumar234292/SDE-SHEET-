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

int recursion(int index, int n ,  int target, vector<int>v)
{
    if(index==0)
    {
        if(target==0 and v[index]==0)
        return 2;

        if(target==0 or target==v[index])
        return 1;

        else 
        return 0;
    }

    int notPick=recursion(index-1,n,target,v);
    int pick=0;

    if(target>=v[index])
    pick=recursion(index-1,n, target-v[index],v);

    return pick+notPick;
}

int topDown(int index,int target, vector<int>&v, vector<vector<int>>&dp)
{  
    if(index==0)
    {
        if(target==0 and v[index]==0)
        return 2;

        if(target==0 or target==v[index])
        return 1;

        else 
        return 0;
    }

    if(dp[index][target]!=-1)
    return dp[index][target];

    int notPick=topDown(index-1,target,v,dp);
    int pick=0;

    if(target>=v[index])
    pick=topDown(index-1, target-v[index],v,dp);

    return dp[index][target]=pick+notPick;
}


int bottomUp(vector<int>v,int  target)
{
    vector<vector<int>>dp(v.size()+1,vector<int>(target+1,0));
    dp[0][0]=1;

    for(int i=1;i<=v.size();i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(j==0)
            dp[i][j]=1;

            else 
            {
                int notPick=dp[i-1][j];
                int pick=0;
                if(j>=v[i-1])
                pick=dp[i-1][j-v[i-1]];

                dp[i][j]=pick+notPick;
            }
        }
    }

    for(auto i:dp)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }


    return dp[v.size()][target];

    // return 0;

}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.

    vector<vector<int>>dp(num.size(),vector<int>(tar+1,-1));
    int n=num.size();
    // return topDown(n-1, tar,num,dp);

    return bottomUp(num,tar);
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
        ll i,j,n,k;
        cin>>n>>k;

        vector<int>v(n);
        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<findWays(v,k)<<endl;
    }
    return 0;
}