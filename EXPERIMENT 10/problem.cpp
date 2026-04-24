#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class FenwickTree {
private:
	vector<int> bit;
	int n;
public:
	explicit FenwickTree(int size) : bit(size + 1, 0), n(size) {}
	void update(int idx, int delta) {
		for (; idx <= n; idx += idx & -idx) {
			bit[idx] += delta;
		}
	}
	int query(int idx) const {
		int sum = 0;
		for (; idx > 0; idx -= idx & -idx) {
			sum += bit[idx];
		}
		return sum;
	}
};
vector<int> countSmaller(const vector<int>& nums) {
	int n = static_cast<int>(nums.size());
	vector<int> ans(n, 0);
	vector<int> sortedVals = nums;
	sort(sortedVals.begin(), sortedVals.end());
	sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
	FenwickTree ft(static_cast<int>(sortedVals.size()));
	for (int i = n - 1; i >= 0; --i) {
		int rank = static_cast<int>(lower_bound(sortedVals.begin(), sortedVals.end(), nums[i]) - sortedVals.begin()) + 1;
		ans[i] = ft.query(rank - 1);
		ft.update(rank, 1);
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}
	vector<int> result = countSmaller(nums);
	for (int i = 0; i < n; ++i) {
		cout << result[i] << (i + 1 == n ? '\n' : ' ');
	}
	return 0;
}
