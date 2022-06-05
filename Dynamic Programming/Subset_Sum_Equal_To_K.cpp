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

void subsequence (int index, int n , vector<int>v,vector<int>output)
{
    if(index>=n)
    {
        for(auto i:output)
        cout<<i<<" ";
        cout<<endl;
        return;
    }
    output.push_back(v[index]);
    subsequence(index+1,n,v,output);

    output.pop_back();
    subsequence(index+1,n,v,output);

    return ;
}

bool recursion(int index, int n, int target, vector<int>v)
{
    if(target==0)
    return true;

    if(index==0) 
    {
        // cout<<sum<<endl;
        return (v[index]==target);
    }

    bool notTake=recursion(index-1, n , target, v);

    bool take=false;
 
    if(v[index]<=target)
    take=recursion(index+1,n, target-v[index], v);

    return take|notTake;
}

bool topDown(int index, int sum , int n, int target, vector<int>&v,vector<vector<int>>&dp)
{
    if(target==0)
    return true;

    if(index>=n) 
    {
        // cout<<sum<<endl;
        return dp[index][sum]=(target==sum);
    }

    if(dp[index][sum]!=-1)
    return dp[index][sum];

    bool notTake=topDown(index+1,sum, n , target, v,dp);

    bool take=false;

    if(v[index]<=target-sum)
    take=topDown(index+1, sum+v[index],n, target, v,dp);

    return dp[index][sum]=take|notTake;
}

bool bottomUp(vector<int>v, int k)
{
    vector<vector<int>>dp(v.size()+1,vector<int>(k+1,0));

    for(int i=0;i<=v.size();i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(i==0 and j==0)
            dp[i][j]=true;

            else if(i==0)
            dp[i][j]=false;

            else if(j==0)
            dp[i][j]=true;

            else 
            {
                if(j-v[i-1]>=0)
                dp[i][j]=dp[i-1][j]|dp[i-1][j-v[i-1]];

                else 
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[v.size()][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) 
{
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    // return topDown(0,0,n, k, arr,dp);
    

    return bottomUp(arr,k);
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

        // vector<int>output;

        // subsequence(0,n,v,output);

        cout<<subsetSumToK(n,k,v)<<endl;
        // cout<<endl;

    }
    return 0;
}