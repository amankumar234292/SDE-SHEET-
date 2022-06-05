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

int recursion(int index, int target, vector<int>price)
{
    if(target==0)
    return 0;

    if(index==0)
    {
         return target*price[index];

    }

    int notPick=recursion(index-1, target, price);

    int pick=INT_MIN;
    if(index+1<=target)
    pick=price[index]+recursion(index, target-(index+1), price);

    return max(pick, notPick);
}

int topDown(int index, int target, vector<int>price, vector<vector<int>>dp)
{
    if(target==0)
    return 0;

    if(index==0)
    return target*price[index];

    if(dp[index][target]!=-1)
    return dp[index][target];

    int notPick=topDown(index-1, target, price,dp);

    int pick=INT_MIN;
    if(index+1<=target)
    pick=price[index]+topDown(index, target-(index+1), price,dp);

    return dp[index][target]=max(pick, notPick);
}


int bottomUp(vector<int>price)
{
    int n=price.size(),i,j;
    vector<vector<int>>dp(n, vector<int>(n+1, 0));

    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0)
            {
                dp[0][j]=j*price[0];
            }

            else 
            {
                int notPick=dp[i-1][j];
                int pick=INT_MIN;
                if(j>=i+1)
                pick=price[i]+dp[i][j-(i+1)];

                dp[i][j]=max(pick, notPick);
            }
        }
    }

    // for(auto i:dp)
    // {
    //     for(auto j:i)
    //     cout<<j<<" ";
    //     cout<<endl;
    // }

    return dp[n-1][n];
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>>dp(n, vector<int>(n+1, -1));
    //  return topDown(n-1, n, price,dp);''

     return bottomUp(price);
    // return recursion(n-1, n, price);
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

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<cutRod(v,n)<<endl;
    }
    return 0;
}