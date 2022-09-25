#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int
const int mod = 1e9 + 7;
const int N = 2e5 + 5;


signed main()
{
    auto start = chrono::high_resolution_clock::now();
    fastio;
    int t;
    cin >> t;
    while(t--)
    {

    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cerr << "Time Taken by program is : " << fixed << time_taken << setprecision(9) << " sec" << endl;
    return 0;
}

