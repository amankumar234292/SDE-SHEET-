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

  vector<int> nextPermutation(int N, vector<int> arr){
        int idx1=-1,idx2=0;
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                idx1=i;
                break;
            }
        }
        
        // cout<<idx1<<endl;
        
        if(idx1==-1)
        {
            reverse(arr.begin(),arr.end());
            return arr;
        }
        
        for(int i=N-1;i>=0;i--)
        {
            if(arr[i]>arr[idx1])
            {
                idx2=i;
                break;
            }
        }
        
        swap(arr[idx1],arr[idx2]);
        
        // cout<<idx1<<" "<<idx2<<endl;
        
        int first=idx1+1;
        int last=N-1;
        
        // cout<<first<<" "<<last<<endl;
        
        while(first<last)
        {
            swap(arr[first],arr[last]);
            first++;
            last--;
        }
        
        return arr;
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