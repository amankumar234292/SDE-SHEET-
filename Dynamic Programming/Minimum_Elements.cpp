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

int recursion(int index,vector<int>&num, int x)
{
    if(index==0)
    {
        if(x%num[index]==0)
        return x/num[index];

        return 10e7;
    }

    int notPick=0+recursion(index-1, num, x);
    int pick=10e7;
    if(x>=num[index])
    pick=1+recursion(index, num, x-num[index]);

    return min(pick,notPick);
}


int topDown(int index,vector<int>&num, int x,vector<vector<int>>&dp)
{
    if(index==0)
    {
        if(x%num[index]==0)
        return x/num[index];

        return 10e7;
    }

    if(dp[index][x]!=-1)
    return dp[index][x];

    int notPick=0+topDown(index-1, num, x,dp);
    int pick=10e7;
    if(x>=num[index])
    pick=1+topDown(index, num, x-num[index],dp);

    return dp[index][x]=min(pick,notPick);
}


int bottomUp(vector<int>num, int sum)
{
    vector<int>dp(sum+1,10e7);

    dp[0]=0;

    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<num.size();j++)
        {
            if(num[j]<=i)
            dp[i]=min(dp[i],dp[i-num[j]]+1);
        }
    }

    // for(auto i:dp)
    // cout<<i<<" ";
    // cout<<endl;

    if(dp[sum]==10e7)
    return -1;
    return dp[sum];
}

int minimumElements(vector<int> &num, int x)
{
    // vector<vector<int>>dp(num.size(),vector<int>(x+1,-1));
    // int ans= topDown(num.size()-1,num, x,dp);
    // if(ans==10e7)
    // return -1;
    // return ans;


    return bottomUp(num,x);
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
        int x;
        cin>>x;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        

        cout<<minimumElements(v,x)<<endl;
    }
    return 0;
}
