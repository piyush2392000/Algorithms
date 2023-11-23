#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to check if it's possible to divide the network into k regions
bool canDivide(vector<int>& g_weight, int n, int k, int max_latency) {
    int regions = 1;
    int current_latency = 0;

    for (int i = 0; i < n; i++) {
        if (g_weight[i] > max_latency) {
            return false;
        }

        if (current_latency + g_weight[i] <= max_latency) {
            current_latency += g_weight[i];
        } else {
            regions++;
            current_latency = g_weight[i];
        }
    }

    return regions <= k;
}

// Function to find the minimum possible value of the maximum max-latency
int minimizeMaxLatency(int g_nodes, int m, int k, vector<int>& g_from, vector<int>& g_to, vector<int>& g_weight) {
    int left = *max_element(g_weight.begin(), g_weight.end());
    int right = accumulate(g_weight.begin(), g_weight.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canDivide(g_weight, m, k, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int g_nodes = 3;
    int m = 3;
    int k = 2;
    vector<int> g_from = {1, 2, 3};
    vector<int> g_to = {2, 3, 1};
    vector<int> g_weight = {4, 5, 3};

    int result = minimizeMaxLatency(g_nodes, m, k, g_from, g_to, g_weight);
    cout << "Minimum possible value of the maximum max-latency: " << result << endl;

    return 0;
}