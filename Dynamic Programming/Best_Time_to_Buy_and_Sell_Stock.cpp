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

int maximumProfit(vector<int> &prices)
{
    int mini=prices[0];
    int ans=INT_MIN;

    for(int i=1;i<prices.size();i++)
    {
        mini=min(mini,prices[i]);
        ans=max(prices[i]-mini,ans);
    }

    return ans;
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

        vector<int>prices(n);

        for(i=0;i<n;i++)
        cin>>prices[i];

        cout<<maximumProfit(prices)<<endl;
      
    }
    return 0;
}