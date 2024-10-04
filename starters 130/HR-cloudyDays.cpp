#include<bits/stdc++.h>
using namespace std;

int findIndexRight(int n, vector<pair<long,long>> v, int val) {
	int s = 0, e = n-1;
	while(e-s > 1) {
		int m = (s+e)/2;
		if(v[m].first <= val) s = m;
		else e = m;
	}
	return s;
}

int findIndexLeft(int n, vector<pair<long, long>> v, int val) {
	int s = 0, e = n-1;
	while(e-s > 1) {
		int m = (s+e)/2;
		if(v[m].first >= val) e = m;
		else s = m;
	}
	return e;
}

long solve(vector<long> p, vector<long> x, vector<long> y, vector<long> r) {
	int n = x.size(), m = y.size();
	vector<pair<long, long>> towns, clouds;
	for(int i = 0; i < n; i++) {
		towns.push_back({x[i], p[i]});
	}
	sort(towns.begin(), towns.end());
	for(int i = 0; i < m; i++) {
		clouds.push_back({y[i], r[i]});
	}
	sort(clouds.begin(), clouds.end());
	vector<int> cc(n+1, 0);
	vector<pair<int, int>> reach;
	for(int i = 0; i < m; i++) {
		int cp = clouds[i].first, cr = clouds[i].second;
		int l = cp-cr, rt = cp+cr;
		if(l < towns[0].first) {
			if(rt < towns[0].first) {
				reach.push_back({-1, -1});
			} else {
				cc[0]++;
				if(rt >= towns[n-1].first) {
					cc[n]--;
					reach.push_back({0, n-1});
				} else {
					int indRight = findIndexRight(n, towns, rt);
					cc[indRight+1]--;
					reach.push_back({0, indRight});
				}
			}
		} else {
			int indLeft = findIndexLeft(n, towns, l);
			cc[indLeft]++;
			if(rt >= towns[n-1].first) {
					cc[n]--;
					reach.push_back({indLeft, n-1});
				} else {
					int indRight = findIndexRight(n, towns, rt);
					cc[indRight+1]--;
					reach.push_back({indLeft, indRight});
				}
		}
	}
	long safPop = 0;
	for(int i = 0; i < n; i++) {
		if(i > 0) cc[i] += cc[i-1];
		if(cc[i] == 0) safPop += towns[i].second;
	}
	vector<long> possSafPop(n+1, 0);
	for(int i = 0; i <= n; i++) {
		if(cc[i] == 1) possSafPop[i] = towns[i].second;
		if(i > 0) possSafPop[i] += possSafPop[i-1];
	}
	long maxSafPop = -1, tmpSafPop = 0;
	for(int i = 0; i < m; i++) {
		int l = reach[i].first;
		int rt = reach[i].second;
		if(l == -1) continue;
		tmpSafPop = possSafPop[rt];
		if(l > 0) tmpSafPop-=possSafPop[l-1];
		maxSafPop = max(maxSafPop, safPop+tmpSafPop);
	}
	return maxSafPop;
}

int main() {
	vector<long> p = {1, 2, 3, 4, 5};
	vector<long> x = {2, 5, 10, 20, 30};
	vector<long> y = {2, 5, 28, 20};
	vector<long> r = {5, 5, 5, 10};
	cout << solve(p, x, y, r);
	return 0;
}




























