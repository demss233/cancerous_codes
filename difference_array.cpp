struct diff_array {
	vector<int> a, h;
	diff_array(vector<int> v) {
		a.resize(sz(v) + 1, 0);
		h.resize(sz(v));
		for(int i = 0; i < sz(v); ++i) h[i] = v[i];
	}
	void update(int l, int r, int x) {
		a[l] += x;
		a[r + 1] -= x;
	}
	void merge() {
		for(int i = 1; i < sz(a) - 1; ++i) {
			a[i] += a[i - 1];
		}
		for(int i = 0; i < sz(h); ++i) {
			h[i] = a[i];
		}
	}
};
