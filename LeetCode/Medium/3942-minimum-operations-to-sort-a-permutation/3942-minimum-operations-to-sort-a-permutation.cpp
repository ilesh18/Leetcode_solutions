class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int idx0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx0 = i;
                break;
            }
        }
        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx0 + i) % n] != i) {
                is_inc = false;
                break;
            }
        }
        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(idx0 - i + n) % n] != i) {
                is_dec = false;
                break;
            }
        }
        if (!is_inc && !is_dec) {
            return -1;
        }
        std::vector<int> dist(2 * n, -1);
        std::queue<int> q;
        
        dist[0 * n + 0] = 0;
        q.push(0 * n + 0);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            int ori = u / n;
            int k = u % n;
            int d = dist[u];
            int p1, p2;
            if (ori == 0) {
                p1 = 0 * n + (k + 1) % n;    
                p2 = 1 * n + (n - 1 - k);   
            } else {
                p1 = 1 * n + (k + 1) % n;   
                p2 = 0 * n + (n - 1 - k);   
            }
            
            if (dist[p1] == -1) {
                dist[p1] = d + 1;
                q.push(p1);
            }
            if (dist[p2] == -1) {
                dist[p2] = d + 1;
                q.push(p2);
            }
        }
        int ans = 1e9;
        if (is_inc && dist[0 * n + idx0] != -1) {
            ans = std::min(ans, dist[0 * n + idx0]);
        }
        if (is_dec && dist[1 * n + idx0] != -1) {
            ans = std::min(ans, dist[1 * n + idx0]);
        }
        
        return (ans == 1e9) ? -1 : ans;
    }
};