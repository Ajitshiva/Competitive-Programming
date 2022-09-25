#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define _FE_6(_CALL, x, ...) _CALL(x) _FE_5(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
  _NTH_ARG(__VA_ARGS__, _FE_6, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1)              \
  (MACRO, __VA_ARGS__)
#define watch(x) cerr << #x " = [ " << (x) << " ] ";
#define debug(...)                                                             \
  cerr << "[Line " << __LINE__ << ": ";                                        \
  FOR_EACH_MACRO(watch, __VA_ARGS__)                                           \
  cerr << "]" << endl
#else
#define debug(...)
#endif
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p) {return os << '{' << p.first << " => " << p.second << '}'; }
template <class T, class = decltype(begin(declval<T>())), class = enable_if_t < !is_same<T, string>::value >> ostream & operator<<(ostream &os, const T &c) {os << '['; for (auto it = begin(c); it != end(c); ++it) os << (it == begin(c) ? "" : ", ") << *it; return os << ']'; } void google(int i) {cout << "Case #" << i << ": " << '\n'; }
#define nitro ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#include <chrono>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int long long int 
const int mod = 1e9 + 7;
const int inf = 1e16;
const int LL = -1e5;
const int UL = 1e6 + 5;

class FenwickTree
{
    vector<vector<int>> bit;
    int n;
public:
    FenwickTree(int n)
    {
        bit.resize(n + 5, vector<int>(4, 0));
        this->n = n + 5;
    }

    array<int, 3> query(int idx)
    {       
        array<int, 3> res = {0, 0, 0};
        while(idx > 0)
        {
            for(int i = 1; i <= 3; i++) {
                res[i - 1] += bit[idx][i];
            }
            idx -= idx & (-idx);
        }
        return res;
    }

    void add(int idx, int val)
    {
        while(idx < n)
        {
            bit[idx][val] += 1;
            idx += idx & (-idx);
        }
    }

    void remove(int idx, int val)
    {
        while(idx < n)
        {
            bit[idx][val] -= 1;
            idx += idx & (-idx);
        }
    }
};



// void solution()
// {           
//   string s;
//   cin >> s;

//   int q;
//   cin >> q;
//   int n = s.size();
//   vector<vector<int>> count(n + 1, vector<int>(26, 0));
//   for(int i = 1; i <= n; i++) {
//     for(int j = 0; j < 26; j++) {
//         count[i][j] = count[i-1][j];
//     }
//     count[i][s[i-1]-'a']++;
//   }
//   int ans = 0;
//   while(q--) {
//     int s, e;
//     cin >> s >> e;
//     int len = e - s + 1;
//     if(len % 2 == 0) continue;
//     vector<int> subarray(26);
//     for(int j = 0; j < 26; j++) {
//         subarray[j] = count[e][j] - count[s-1][j];
//     }
//     // debug(temp);
//     int odd = 0;
//     int oddChar = -1;
//     for(int j = 0; j < 26; j++) {
//         if(subarray[j] & 1) {
//             odd++;
//             oddChar = j;
//         }
//     }
//     if(odd == 0 || odd > 1) continue;

//     vector<int> firstHalf(26), secondHalf(26);

//     int fs = s;
//     int fe = s + len / 2;
//     int ss = fe + 1;
//     int se = e;

//     for(int j = 0; j < 26; j++) {
//         firstHalf[j] = count[fe][j] - count[fs - 1][j];
//         secondHalf[j] = count[se][j] - count[ss - 1][j];
//     }

//     bool ok = true;
//     for(int j = 0; j < 26; j++) {
//         if(firstHalf[j] != secondHalf[j]) {
//             if(j != oddChar) {
//                 ok = false;
//             }
//         }
//     }
//     bool ok1 = true;
//     fe--;
//     ss = fe + 1;
//     for(int j = 0; j < 26; j++) {
//         firstHalf[j] = count[fe][j] - count[fs - 1][j];
//     }  
//     for(int j = 0; j < 26; j++) {
//         secondHalf[j] = count[se][j] - count[ss - 1][j];
//     }
//     for(int j = 0; j < 26; j++) {
//         if(firstHalf[j] != secondHalf[j]) {
//             if(j != oddChar) {
//                 ok1 = false;
//             }
//         }
//     }
//     if(ok || ok1) ans++;
//   }
//   cout << ans << '\n';

// }

void solution() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    FenwickTree ft(n);
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        ft.add(i, arr[i]);
    }
    int ans = 0;
    while(q--) {
        int i, val, z;
        cin >> i >> val >> z;

        ft.remove(i, arr[i]);
        arr[i] = val;
        ft.add(i, arr[i]);

        array<int, 3> left = ft.query(z);
        array<int, 3> full = ft.query(n);
        array<int, 3> right;
        for(int i = 0; i < 3; i++) {
            right[i] = full[i] - left[i];
        }
       
        int left_sum = left[0] + left[1] * 2 + left[2] * 3;
        int right_sum = right[0] + right[1] * 2 + right[2] * 3;
        int whole_sum = full[0] + full[1] * 2 + full[2] * 3;
        int half_sum = whole_sum / 2;
        debug(left, right, left_sum, right_sum, abs(left_sum - right_sum));
        if(whole_sum % 2 != 0) {
            ans += -1;
        }
        else if(left_sum == right_sum) {
            ans += 0;
        } else {
            if(left_sum > right_sum) {
                int diff = left_sum - right_sum;
                // debug(left);
                // debug(diff);

            } else {
                int diff = right_sum - left_sum;
                // debug(right);
                // debug(diff);
            }
        }
        cout << left[0] << ' ' << left[1] << ' ' << left[2] << '\n';        
    }

}


signed main()
{
    auto start = chrono::high_resolution_clock::now();
    nitro;
    int t = 1;
    cin >> t;
  
    for(int i = 1; i <= t; i++)
    {   
        cout << "Case #" << i << ": ";
        solution();
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cerr << "Time Taken by program is : " << fixed << time_taken << setprecision(9) << " sec" << endl;
    return 0;
}

        