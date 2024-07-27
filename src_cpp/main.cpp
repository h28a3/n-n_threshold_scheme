#include"header.h"

int main(void) {
    int n, p;

    cout << "参加者数：";
    cin >> n;
    cout << "有限体のサイズ：";
    cin >> p;

    buf.resize(n);
    dfs(0,n,0,1);

    vector<vector<int>> pat(bufs.size());
    vector<vector<double>> dis;
    copy(bufs.begin(), bufs.end(), pat.begin());

    double pr = 1 / pow(n - 1, p);

    for (int s = 0;s < p;s++) {
        bufs = {};
        leakage = {};
        buf.resize(n-1);
        dfs(0, n-1, 0, p-1);

        vector<vector<int>> share(bufs.size());
        copy(bufs.begin(), bufs.end(), share.begin());

        for (int i = 0;i < share.size();i++) {
            int sum_share = accumulate(share[i].begin(), share[i].end(), 0);

            while (sum_share > s)
                sum_share -= p;

            share[i].push_back((s - sum_share) % p);

            mapping(share[i], n, p);
        }

        vector<double> counter = {};
        for (vector<int> i : pat)
            counter.push_back(pr * count(leakage.begin(), leakage.end(), i));

        dis.push_back(counter);
    }

    vector<vector<double>> ans = sd_vec(dis, n, p);
    for (int i = 0;i < ans.size();i++) {
        for (int j = 0;j < ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}