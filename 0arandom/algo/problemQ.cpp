#include <bits/stdc++.h>
using namespace std;

// Union-Find structure that also stores for each component the list of cell indices
// that haven't yet been updated with an answer.
struct UnFo {
    vector<int> parn;
    vector<int> cpsz;
    vector<vector<int>> pend; // pend[i]: list of indices in component i (only valid at root)

    UnFo(int size) {
        parn.resize(size);
        cpsz.resize(size, 1);
        pend.resize(size);
        for (int i = 0; i < size; i++){
            parn[i] = i;
            pend[i].push_back(i);
        }
    }

    int find(int node) {
        return parn[node] == node ? node : parn[node] = find(parn[node]);
    }

    // Merge the sets containing a and b and update the answer for pending cells 
    // if the new component size reaches at least (lim+1).
    void merge(int a, int b, int wt, vector<int>& ans, int lim) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        // Union by size: let 'a' be the larger component.
        if (cpsz[a] < cpsz[b]) swap(a, b);

        parn[b] = a;
        cpsz[a] += cpsz[b];

        // Merge the pending lists: add all pending from component b into component a.
        for (int idx : pend[b]) {
            pend[a].push_back(idx);
        }
        pend[b].clear();

        // If the new component size is large enough and there are still cells waiting,
        // update their answer to the current edge weight.
        if (cpsz[a] >= lim + 1 && !pend[a].empty()) {
            for (int idx : pend[a]) {
                ans[idx] = wt;
            }
            pend[a].clear();
        }
    }
};

// Structure for edges between grid cells.
struct Edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int row, col, lim;
    cin >> row >> col >> lim;
    int totl = row * col;
    vector<vector<int>> alti(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> alti[i][j];
        }
    }

    // Special case: If lim==0, no moves are required.
    if (lim == 0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << 0 << " ";
            }
            cout << "\n";
        }
        return 0;
    }

    // Helper lambda to convert 2D coordinates to a 1D index.
    auto indx = [&](int i, int j) {
        return i * col + j;
    };

    // Build the list of valid edges (only right and down neighbors to avoid duplicates).
    vector<Edge> edgs;
    edgs.reserve(row * col * 2);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i + 1 < row) {
                int diff = abs(alti[i][j] - alti[i + 1][j]);
                edgs.push_back({ indx(i, j), indx(i + 1, j), diff });
            }
            if (j + 1 < col) {
                int diff = abs(alti[i][j] - alti[i][j + 1]);
                edgs.push_back({ indx(i, j), indx(i, j + 1), diff });
            }
        }
    }
    sort(edgs.begin(), edgs.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    // Initialize answer array (for each cell, the minimum capability required)
    vector<int> ans(totl, -1);
    UnFo uf(totl);

    // Process edges in increasing order.
    for (auto &e : edgs) {
        uf.merge(e.u, e.v, e.w, ans, lim);
    }

    // Output the result in grid format.
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << ans[indx(i, j)] << " ";
        }
        cout << "\n";
    }
    return 0;
}
