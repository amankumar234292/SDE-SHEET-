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

int trap(vector<int>& v) 
{
    int i,j,n=v.size();
    vector<int>front(v.size()), rear(v.size());
        
    int maxi=INT_MIN;
    for(i=0;i<n;i++)
    {
        maxi=max(maxi, v[i]);
        front[i]=maxi;
    }
        
    maxi=INT_MIN;
    for(i=n-1;i>=0;i--)
    {
        maxi=max(maxi, v[i]);
        rear[i]=maxi;
    }
    int ans=0;
    for(i=0;i<n;i++)
    {
        ans+=min(front[i],rear[i])-v[i];
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

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<trap(v)<<endl;
      
    }
    return 0;
}