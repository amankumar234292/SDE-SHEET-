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

int maxArea(vector<int>& height) 
{
   int i,j,n=height.size(), ans=INT_MIN;
   int first=0;
   int second=n-1;

   while(first<=second)
   {
        ans=max(ans,abs(second-first)*min(height[first],height[second]));
        if(first+1<n and second-1>=0 and abs(second-1-first)*min(height[first],height[second-1])>abs(second-first-1)*min(height[first+1],height[second] ))
        {
            second--;
        }

        else 
        first++;
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
        {
            cin>>v[i];
        }

        cout<<maxArea(v)<<endl;
    }
    return 0;
}