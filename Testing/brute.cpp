#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <chrono>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
template<typename T>
using ordered_set = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
std::ostream& operator<<( std::ostream& dest, __int128_t value ) {std::ostream::sentry s( dest ); if ( s ) {__uint128_t tmp = value < 0 ? -value : value; char buffer[ 128 ]; char* d = std::end( buffer ); do {-- d; *d = "0123456789"[ tmp % 10 ]; tmp /= 10; } while ( tmp != 0 ); if ( value < 0 ) {-- d; *d = '-'; } int len = std::end( buffer ) - d; if ( dest.rdbuf()->sputn( d, len ) != len ) {dest.setstate( std::ios_base::badbit ); } } return dest; }
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define int long long int
const int mod = 1e9 + 7;
using lll = __int128;


signed main()
{
    // auto start = chrono::high_resolution_clock::now();
    fastio;
    
    int t = 1;
    // cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> even;
        vector<int> odd;
        for(int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            if(num % 2 == 0)
            {
                even.push_back(num);
            }
            else
            {
                odd.push_back(num);
            }
        }
        vector<int> arr;
        for(int i = 0; i < even.size(); i++)
        {
            arr.push_back(even[i]);
        }
        for(int i = 0; i < odd.size(); i++)
        {
            arr.push_back(odd[i]);
        }
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            for(int j = i + 1; j < arr.size(); j++)
            {
                if(__gcd(arr[i], 2 * arr[j]) > 1)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
 
 
    }
    // auto end = chrono::high_resolution_clock::now(); double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); time_taken *= 1e-9; cerr << "Time Taken by program is : " << fixed << time_taken << setprecision(9) << " sec" << endl; 
    return 0;   
}
