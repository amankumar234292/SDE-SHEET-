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

long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());

    // for(long long i=0;i<n;i++)
    // cout<<a[i]<<" ";
    // cout<<endl;

    long long ans=INT_MAX;

    for(long long second=m-1;second<n;second++)
    {
        // cout<<a[second]<<" "<<a[second-(m-1)]<<endl;
        ans=min(ans,a[second]-a[second-(m-1)]);
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
    // test()
    {
        ll i,j,n,m;
        cin>>n>>m;

        vector<long long>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        cout<<findMinDiff(v,n,m)<<endl;
    }
    return 0;
}