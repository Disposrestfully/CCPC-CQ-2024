#include <bits/stdc++.h>
typedef std::vector<int> Poly;
constexpr int mod = 998244353, maxn = 1 << 22;
void inc (int &x, int y) {if ((x += y) >= mod) x -= mod;}
int plus (int x, int y) {return x + y >= mod ? x + y - mod : x + y;}
int power (int x, int y) {int z = 1; for (; y; y >>= 1, x = 1LL * x * x % mod) if (y & 1) z = 1LL * z * x % mod; return z;}
int n, t, w2[maxn], fct[maxn], inv[maxn], inf[maxn], a[maxn], pl[maxn], pr[maxn]; std::string s;
void init (void)
{
	fct[0] = inv[0] = inv[1] = inf[0] = 1;
	for (int i = 1; i < maxn; i++) fct[i] = 1LL * fct[i - 1] * i % mod;
	for (int i = 2; i < maxn; i++) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 1; i < maxn; i++) inf[i] = 1LL * inf[i - 1] * inv[i] % mod;
	*w2 = 1; w2[1 << 21] = 31;
	for (int i = 21; i; i--) w2[1 << (i - 1)] = 1LL * w2[1 << i] * w2[1 << i] % mod;
	for (int i = 1; i < maxn; i++) w2[i] = 1LL * w2[i & (i - 1)] * w2[i & -i] % mod;
}
void DIF (int *a)
{
	for (int i = t >> 1; i; i >>= 1)
		for (int *j = a, *o = w2; j < a + t; j += i << 1, o++)
			for (int *k = j, r; k < j + i; k++) r = 1LL * *o * k[i] % mod, k[i] = plus(*k, mod - r), *k = plus(*k, r);
}
void DIT (int *a)
{
	for (int i = 1; i < t; i <<= 1)
		for (int *j = a, *o = w2; j < a + t; j += i << 1, o++)
			for (int *k = j, r; k < j + i; k++) r = plus(*k, k[i]), k[i] = 1LL * *o * (*k - k[i] + mod) % mod, *k = r;
	std::reverse(a + 1, a + t);
	for (int *i = a, invt = mod - (mod - 1) / t; i < a + t; i++) *i = 1LL * *i * invt % mod;
}
Poly operator * (const Poly &a, const Poly &b)
{
	if (a.empty() or b.empty()) return {};
	static int A[maxn], B[maxn];
	for (t = 1; t < (int)a.size() + (int)b.size(); t <<= 1) ;
	for (int i = 0; i < t; i++) A[i] = i < (int)a.size() ? a[i] : 0, B[i] = i < (int)b.size() ? b[i] : 0;
	DIF(A); DIF(B);
	for (int i = 0; i < t; i++) A[i] = 1LL * A[i] * B[i] % mod;
	DIT(A);
	return Poly(A, A + (int)a.size() + (int)b.size() - 1);
}
Poly solve1 (int l, int r, Poly f) {
	if (l == r) {
		for (int i = f.size() - 1; ~i; i--) pl[l] = (1LL * pl[l] * l + f[i]) % mod;
		return {plus(mod - l, s[l] == 'L'), 1};
	}
	int m = (l + r) >> 1; auto g = solve1(l, m, f); return g * solve1(m + 1, r, f * g);
}
Poly solve2 (int l, int r, Poly f) {
	if (l == r) {
		for (int i = f.size() - 1; ~i; i--) pr[r] = (1LL * pr[r] * r + f[i]) % mod;
		return {plus(r, s[r] == 'R'), mod - 1};
	}
	int m = (l + r) >> 1; auto g = solve2(m + 1, r, f); return g * solve2(l, m, f * g);
}
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	std::cin >> n >> s; init();
	solve1(0, n - 1, {1}); solve2(0, n - 1, {1});
	for (int i = 0; i < n; i++) pl[i] = 1LL * (s[i] == 'L') * inf[i + 1] * pl[i] % mod, pr[i] = 1LL * (s[i] == 'R') * inf[n - i] * pr[i] % mod;
	for (int i = 0, p; i <= n; i++) {
		p = 1LL * (i == 0 ? 1 : pl[i - 1]) * (i == n ? 1 : pr[i]) % mod;
		if (i > 0) inc(a[i - 1], p);
		if (i < n) inc(a[i], p);
	}
	for (int i = 0; i < n; i++) std::cout << a[i] << " \n"[i == n - 1];
	return 0;
}