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

int longSubarrWthSumDivByK(int arr[], int n, int k){

    vector<int>prefix(n,0);
    map<int,vector<int>>mp;
    prefix[0]=arr[0];
    mp[((prefix[0]%k)+k)%k].push_back(0);

    for(int i=1;i<n;i++){
        prefix[i]=arr[i]+prefix[i-1];
        mp[((prefix[i]%k)+k)%k].push_back(i);
    }

    for(auto i:prefix)
    cout<<i<<" ";
    cout<<endl;

    for(auto i:mp)
    {
        cout<<i.first<<": ";
        for(auto j:i.second)
        cout<<j<<" ";
        cout<<endl;
    }

    int ans=INT_MIN;

    for(auto i:mp)
    {
        if(i.first==0)
        ans=max(ans, mp[0].back()+1);

        else 
        ans=max(ans, mp[i.first].back()-mp[i.first].front());
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
        ll i,j,n,k;
        cin>>n>>k;

        int arr[n];

        for(i=0;i<n;i++)
        cin>>arr[i];

        cout<<longSubarrWthSumDivByK(arr,n,k)<<endl;
      
    }
    return 0;
}