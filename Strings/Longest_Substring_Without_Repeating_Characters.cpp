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

int lengthOfLongestSubstring(string s) {

    if(s.length()==0)
    return 0;

    int left=0;
    int right=0;
    int len=s.length();
    int ans=1;
    map<char,int>mp;

    while(right<len){

        cout<<left<<" "<<right<<endl;
        mp[s[right]]++;

        if(mp[s[right]]==1){
            cout<<"YES"<<endl;
            ans=max(ans,right-left+1);
            right++;
        } else {
            
            if(s[left]==s[right]){
                
                mp[s[left]]--;
                left++;
            } else {
                while(true){
                    if(s[left]==s[right]){
                         mp[s[left]]--;
                        left++;
                        
                        break;
                    }

                    mp[s[left]]--;
                    left++;
                }
            }
            //  ans=max(ans,right-left+1);
            right++;
        }
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
        ll i,j,n;
        string s;
        cin>>s;

        cout<<lengthOfLongestSubstring(s)<<endl;
      
    }
    return 0;
}