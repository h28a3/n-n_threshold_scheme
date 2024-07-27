#include"header.h"

vector<int> buf;
vector<vector<int>> bufs;
vector<vector<int>> leakage;

double pow(int n, int p) {
    if (n == 0)
        return 1;
    else
        return p * pow(n - 1, p);
}

void dfs(int i, const int size, const int begin, const int end) {
    if (i == size)
        bufs.push_back(buf);
    else {
        for (int j = begin; j <= end; ++j) {
            buf[i] = j;
            dfs(i + 1, size, begin, end);
        }
    }
}

void mapping(vector<int> share, int n, int p) {
    vector<int> tmp = {};
    for (int i = 0;i < n;i++) {
        if (share[i] > p / 2)
            tmp.push_back(1);
        else
            tmp.push_back(0);
    }
    leakage.push_back(tmp);
}

double sd(vector<double> x, vector<double> y, int n) {
    double ans = 0;
    for (int i = 0;i < pow(n, 2); i++)
        ans += abs(x[i] - y[i]);
    return ans;
}

vector<vector<double>> sd_vec(vector<vector<double>> x, int n, int p) {
    vector<vector<double>> ans;
    for (int i = 0;i < p;i++) {
        vector<double> ans0 = {};
        for (int j = i + 1;j < p;j++)
            ans0.push_back(sd(x[i], x[j], n));
        ans.push_back(ans0);
    }
    return ans;
}