#include <bits/stdc++.h>
#include <vector>

int solve(std::vector<int>& ants, int n) {
    std::vector<int> days(n, 0); // Days required for each ant to be removed
    std::queue<int> q;

    // Find initial ants that will be eaten
    for (int i = 0; i < n - 1; i++) {
        if (ants[i] < ants[i + 1]) {
            q.push(i + 1); // Store the index of the weaker ant
            days[i + 1] = 1; // First night for this ant
        }
    }

    int maxDays = 0;

    // BFS-like processing
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        maxDays = std::max(maxDays, days[idx]); // Track max nights

        if (idx + 1 < n && ants[idx] < ants[idx + 1] && days[idx + 1] == 0) {
            q.push(idx + 1);
            days[idx + 1] = days[idx] + 1;
        }
    }

    return maxDays;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ants(n);

    for (int i = 0; i < n; i++) {
        std::cin >> ants[i];
    }

    std::cout << solve(ants, n);
    return 0;
}
