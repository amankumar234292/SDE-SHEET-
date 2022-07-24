// // // // // #include <bits/stdc++.h>
// // // // // #include<ext/pb_ds/assoc_container.hpp>
// // // // // #include<ext/pb_ds/tree_policy.hpp>
// // // // // using namespace std;
// // // // // using namespace __gnu_pbds;
// // // // // #define ll              long long int
// // // // // #define endl            "\n"
// // // // // #define MOD             1e9 + 7
// // // // // #define test()          ll t; cin>>t; while(t--)
// // // // // #define precision(x,y)  fixed<<setprecision(y)<<x
// // // // // #define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
// // // // // bool compare(ll a,ll b)
// // // // // {
// // // // //     return a<b;
// // // // // }

// // // // // int characterReplacement(string s, int k) {
// // // // //     int i,j,n=s.length();
// // // // //     int maxFreq=INT_MIN;

// // // // //     map<char,int>mp;
// // // // //     int start=0;
// // // // //     int ans=0;

// // // // //     for(int end=0;end<n;end++){
// // // // //         mp[s[end]]++;
// // // // //         maxFreq=max(maxFreq,mp[s[end]]);

// // // // //         if(end-start+1-maxFreq>k){

// // // // //             while(end-start+1-max)
// // // // //             mp[s[start]]--;
// // // // //             start++;
// // // // //             if(end-start+1-maxFreq)
// // // // //         }
// // // // //     }     
// // // // // }

// // // // // int main ()
// // // // // {
// // // // // #ifndef ONLINE_JUDGE
// // // // //     freopen("input.txt","r",stdin);
// // // // //     freopen("output.txt","w",stdout);
// // // // // #endif
// // // // //     ios_base::sync_with_stdio(false);
// // // // //     cin.tie(NULL);  
// // // // //     // test()
// // // // //     {
// // // // //         ll i,j,n;
// // // // //     }
// // // // //     return 0;
// // // // // }



// // // // #include <bits/stdc++.h>

// // // // using namespace std;


// // // // int main ()
// // // // {
 
// // // //     string s;
// // // //     cin>>s;

// // // //     int n=s.length(),i,j;
// // // //     string ans="";

// // // //     for(i=0;i<n;i++)
// // // //     {
// // // //         if(i==0 and s[i]!='/')
// // // //         {
// // // //             ans+='/';
// // // //             ans+=s[i];
// // // //         }

// // // //         else if(s[i]=='/' and s[i+1]=='/')
// // // //         {
// // // //             ans+='/';
// // // //             i++;
// // // //         }

// // // //         else if(s[i]=='/' and s[i+1]=='.' and s[i+1]=='.')
// // // //         {
// // // //             while(true)
// // // //             {
// // // //                 if(ans.back()=='/')
// // // //                 {
// // // //                     ans.pop_back();
// // // //                     break;
// // // //                 }

// // // //                 else 
// // // //                 ans.pop_back();
// // // //                 i+=2;
// // // //             }
// // // //         }

// // // //         else 
// // // //         ans+=s[i];
// // // //     }

// // // //     cout<<ans<<endl;
// // // //     return 0;
// // // // }


// // #include <bits/stdc++.h>
// // #include<ext/pb_ds/assoc_container.hpp>
// // #include<ext/pb_ds/tree_policy.hpp>
// // using namespace std;
// // using namespace __gnu_pbds;
// // #define ll              long long int
// // #define endl            "\n"
// // #define MOD             1e9 + 7
// // #define test()          ll t; cin>>t; while(t--)
// // #define precision(x,y)  fixed<<setprecision(y)<<x
// // #define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
// // bool compare(pair<string,string> a,pair<string,string> b)
// // {
// //     return a.second<b.second;
// // }

 
// // string print24(string str)
// // {
// //     // Get hours
// //     int h1 = (int)str[1] - '0';
// //     int h2 = (int)str[0] - '0';
// //     int hh = (h2 * 10 + h1 % 10);
// //     string ans;
 
// //     // If time is in "AM"
// //     if (str[5] == 'A')
// //     {
// //         if (hh == 12)
// //         {
// //             ans+="00";
// //             for (int i=2; i <= 4; i++)
// //                 ans.push_back(str[i]);
// //         }
// //         else
// //         {
// //             for (int i=0; i <= 4; i++)
// //                 ans.push_back(str[i]);
// //         }
// //     }
 
// //     // If time is in "PM"
// //     else
// //     {
// //         if (hh == 12)
// //         {
// //             ans.push_back('1');
// //             ans.push_back('2');
// //             for (int i=2; i <= 4; i++)
// //                 ans.push_back(str[i]);
// //         }
// //         else
// //         {
// //             hh = hh + 12;
// //             ans+=(to_string(hh));
// //             for (int i=2; i <= 4; i++)
// //                 ans.push_back(str[i]);
// //         }
// //     }

// //     return ans;
// // }


// // int main ()
// // {
// // #ifndef ONLINE_JUDGE
// //     freopen("input.txt","r",stdin);
// //     freopen("output.txt","w",stdout);
// // #endif
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(NULL);  
// //     // test()
// //     {
// //         string s;
// //         // cin>>s;

// //         vector<pair<string,string>>time;

// //         ll i,j,n;
// //         cin>>n;


// //         for(i=0;i<n;i++)
// //         {
// //             string t;
// //             cin>>t;
// //             // cout<<t<<endl;

// //             string start="",end="";

// //             for(j=0;j<7;j++)
// //             start+=t[j];

// //             for(j=8;j<t.size();j++)
// //             end+=t[j];

// //             time.push_back({print24(start),print24(end)});
// //         }


// //         sort(time.begin(),time.end(),compare);


// //         // for(auto i:time)
// //         // cout<<i.first<<" "<<i.second<<endl;


// //         string ans="00:00";
        

// //         for(i=1;i<time.size();i++)
// //         {
// //             string diff;
// //             int hh1=(time[i].first[0]-'0')*10+(time[i].first[1]-'0');
// //             int hh2=(time[i-1].second[0]-'0')*10+(time[i-1].second[1]-'0');

// //             int hh=hh1-hh2;
// //             int mm1=(time[i].first[3]-'0')*10+(time[i].first[4]-'0');
// //             int mm2=(time[i-1].second[3]-'0')*10+(time[i-1].second[4]-'0');

// //             if(mm1<mm2){
// //                 hh--;
// //                 int mm=60-mm2+mm1;
// //                 if(hh>=0 and hh<=9)
// //                 {
// //                     diff+='0';
// //                     diff+=to_string(hh);
// //                 }

// //                 else 
// //                 diff+=to_string(hh);

// //                 diff+=":";

// //                 if(mm>=0 and mm<=9)
// //                 {
// //                     diff+='0';
// //                     diff+=to_string(mm);
// //                 }
// //                 else 
// //                 diff+=to_string(mm);
// //             }

// //             else 
// //             {
// //                 if(hh>=0 and hh<=9)
// //                 {
// //                     diff+='0';
// //                     diff+=to_string(hh);
// //                 }

// //                 else 
// //                 diff+=to_string(hh);

// //                 int mm=mm1-mm2;

// //                 diff+=":";

// //                 if(mm>=0 and mm<=9)
// //                 {
// //                     diff+='0';
// //                     diff+=to_string(mm);
// //                 }
// //                 else 
// //                 diff+=to_string(mm);

// //             }

// //             ans=max(ans,diff);
// //         }

// //         cout<<ans<<endl;
// //     }
// //     return 0;
// // }




// #include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define ll              long long int
// #define endl            "\n"
// #define MOD             1e9 + 7
// #define test()          ll t; cin>>t; while(t--)
// #define precision(x,y)  fixed<<setprecision(y)<<x
// #define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
// bool compare(ll a,ll b)
// {
//     return a<b;
// }

// int main ()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);  
//     // test()
//     {
//         int i,j,n,k;
//         cin>>n;

//         vector<int>nums(n,0);

//         for(i=0;i<n;i++)
//         cin>>nums[i];
//         // for(auto i:nums)
//         // cout<<i<<" ";

//         int ans=INT_MAX;

//         for (i=0;i<nums.size(); i++) 
//         {
//         for (j=i+1;j<nums.size();j++) 
//         {
//             for (k=j+1;k<nums.size();k++) 
//             {
//                 if (nums[i]<nums[j] && nums[k]>nums[j])
//                 {
//                     ans=min(ans,nums[k]-nums[i]);
//                 }
//             }
//         }
//     }
    
//     if(ans==INT_MAX)
//     cout<<-1<<endl;

//     else 
//     cout<<ans<<endl;
//     }
//     return 0;
// }

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
        int i,j,n;
        string s;
        getline(cin,s);

        // cout<<s<<endl;
        int cnt=0;

        for(i=s.length()-1;i>=0;i--)
        {
            if(s[i]==' ')
            break;

            cnt++;
        }

        cout<<cnt<<endl;
    }
    return 0;
}