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

vector<vector<int>> threeSum(vector<int>& nums) 
{
    sort(nums.begin(),nums.end());
    for(auto i:nums)
    cout<<i<<" ";
    cout<<endl;
    set<vector<int>>st;
    int i,j,k,n=nums.size();
    vector<vector<int>>ans;

    for(i=0;i<n-1;i++)
    {
        int sum=-nums[i];
        int first=i+1;
        int second=n-1;
        while(first<second)
        {
            if(nums[first]+nums[second]==sum)
            {
                st.insert({nums[i],nums[first], nums[second]});
                first++;
                second--;
            }

            else if(nums[first]+nums[second]<sum)
            first++;

            else 
            second--;
        }
    }

    for(auto i:st)
    ans.push_back(i);

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

        for(auto i:threeSum(v))
        {
            for(auto j:i)
            cout<<j<<" ";
            cout<<endl;
        }
    }
    return 0;
}