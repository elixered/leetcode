class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		int mini = INT_MAX;
		priority_queue<int> pq;

		for (auto n : nums) {
			n = n%2==0?n:2*n;
			mini = min(mini, n);
			pq.push(n);
		}

		int res = INT_MAX;

		while (pq.top()%2==0) {
			int n = pq.top();
			pq.pop();

			res = min(res, n - mini);

			if (n % 2 == 1) {
				break;
			}

			mini = min(mini, n / 2);
			pq.push(n / 2);
		}

		return min(res,pq.top()-mini);
	}
};