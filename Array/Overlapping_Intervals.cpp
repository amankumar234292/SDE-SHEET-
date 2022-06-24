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

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int i,j,k,n=intervals.size();
    vector<vector<int>>result;
    vector<int>temp=intervals[0];

    for(i=1;i<n;i++){
        if(temp[1]>=intervals[i][0])
        {
            temp[1]=max(temp[1],intervals[i][1]);
        }
        else 
        {
            result.push_back(temp);
            temp=intervals[i];
        }
    }

    result.push_back(temp);
    return result;
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
      
    }
    return 0;
}