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


int recursion(int index, int n ,int sum, int target , vector<int>v)
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


    int notPick=recursion(index-1,n, sum, target, v);

    int pick=0;
    if(v[index]<=target)
    pick=recursion(index-1, n, sum, target-v[index],v);

    return pick+notPick;
}



int topDown(int index, int n ,int sum, int target , vector<int>v, vector<vector<int>>dp)
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

    int notPick=recursion(index-1,n, sum, target, v);

    int pick=0;
    if(v[index]<=target)
    pick=recursion(index-1, n, sum, target-v[index],v);

    return dp[index][target]=pick+notPick;
}

int targetSum(int n, int target, vector<int>& arr) 
{
    

    int sum=accumulate(arr.begin(),arr.end(),0);
    if((sum-target)%2==0)
    {
        vector<vector<int>>dp(n, vector<int>((sum-target)/2+1, -1));
        return topDown(n-1,n, sum, (sum-target)/2,arr, dp);
    }
    return 0;
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
        ll i,j,n,d;
        cin>>n>>d;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<targetSum(n, d, v)<<endl;
    }
    return 0;
}