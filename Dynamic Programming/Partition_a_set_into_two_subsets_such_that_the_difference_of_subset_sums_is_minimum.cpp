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


// int recursion(int index, int sum, int total, int n , vector<int>v)
// {
//     if(index==n-1)
//     {
//         cout<<sum<<endl;
//         return v[n-1];
//     }

//     sum+=v[index];
//     int first=recursion(index+1, sum, total, n , v);
//     sum-=v[index];
//     int second=recursion(index+1, sum, total, n, v);

//     return min(total-first, total-second);
// }

int recursion(int index, int sum, int total, int n , vector<int>v)
{
    if(index==n-1)
    {
        // cout<<sum<<endl;
        return abs(total-sum-sum);
    }

    int notPick=recursion(index+1,sum,total,n, v);
    int pick=recursion(index+1,sum+v[index], total, n, v );

    return min(notPick, pick);
}


int bottomUp(vector<int>v, int k)
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

    int mini=INT_MAX;
    // cout<<k<<endl;

    for(int i=0;i<=k;i++)
    {
        if(dp[v.size()][i]==1)
        {
            // cout<<i<<" "<<endl;
            mini=min(mini, abs(k-i-i));
        }
    }

    return mini;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int total=accumulate(arr.begin(),arr.end(),0);

    return recursion(0,0,total, n, arr);

	// return bottomUp(arr,total);
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

        cout<<minSubsetSumDifference(v,n)<<endl;
    }
    return 0;
}