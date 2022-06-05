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


int recursion(int index,int maxweight, vector<int>weight,vector<int>value)
{
    if(index==0)
    {
        if(weight[index]<=maxweight)
        return value[index];

        return 0; 
    }

    int notPick=recursion(index-1,maxweight,weight,value);

    int pick=0;
    if(maxweight>=weight[index])
    pick=recursion(index-1,maxweight-weight[index],weight, value);

    return max(pick, notPick);
}

int topDown(int index,int maxweight,  vector<int>&weight,vector<int>&value,vector<vector<int>>&dp)
{
    // if(maxweight==0)
    // return currValue;

    if(index==0)
    {
        if(weight[index]<=maxweight)
        return value[index];

        return 0; 
    }

    if(dp[index][maxweight]!=-1)
    return dp[index][maxweight];


    int notPick=0+topDown(index-1,maxweight,weight,value,dp);

    int pick=INT_MIN;
    if(maxweight>=weight[index])
    pick=value[index]+topDown(index-1,maxweight-weight[index],weight, value,dp);

    return dp[index][maxweight]=max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
    // return recursion(n-1,0, maxWeight, n, weight, value);

    return topDown(n-1, maxWeight, weight, value,dp);
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
        ll i,j,n, maxWeight;
        cin>>n;

        vector<int>weight(n), value(n);
        for(i=0;i<n;i++)
        cin>>weight[i];

        for(i=0;i<n;i++)
        cin>>value[i];

        cin>>maxWeight;

        cout<<knapsack(weight,value,n,maxWeight)<<endl;
    }
    return 0;
}