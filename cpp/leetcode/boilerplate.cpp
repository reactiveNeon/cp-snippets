#define DEBUG

template<typename S, typename T> void smax(S &a, const T &b) { if(a < b) a = b; }
template<typename S, typename T> void smin(S &a, const T &b) { if(a > b) a = b; }
template<typename S, typename T, typename F> void smax(S &a, const T &b, F f) { if(a < b) { a = b; f(); } }
template<typename S, typename T, typename F> void smin(S &a, const T &b, F f) { if(a > b) { a = b; f(); } }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for(const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename... T> ostream& operator<<(ostream &os, const tuple<T...>& tup) { os << '('; apply([&os](const T&... args) { string sep; ((os << sep << args, sep = ", "), ...); }, tup); return os << ')'; }
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#ifdef DEBUG
#define DBG(...) cout << '[' << (__LINE__ - 9) << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define DBG(...) ((void)0)
#endif
#define RANGE(x) (x).begin(), (x).end()
#define MP make_pair
#define MT make_tuple
#define PII pair<int, int>
using i8 = int8_t; using i16 = int16_t; using i32 = int32_t; using i64 = int64_t; using u8 = uint8_t; using u16 = uint16_t; using u32 = uint32_t; using u64 = uint64_t;
template<typename T> T clamp(T x, T lo, T hi) { return min(hi, max(lo, x)); }
auto fastio = [](){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
