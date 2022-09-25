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

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    return os << '{' << p.first << " => " << p.second << '}';
}
template < class T, class = decltype(begin(declval<T>())), class = enable_if_t < !is_same<T, string>::value >> ostream & operator<<(ostream &os, const T &c)
{
    os << '[';
    for (auto it = begin(c); it != end(c); ++it) os << (it == begin(c) ? "" : ", ") << *it;
    return os << ']';
}