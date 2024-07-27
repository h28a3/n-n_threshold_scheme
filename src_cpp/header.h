#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

extern vector<int> buf;
extern vector<vector<int>> bufs;
extern vector<vector<int>> leakage;

void dfs(int i, const int size, const int begin, const int end);
double pow(int n, int p);
void mapping(vector<int> share, int n, int p);
double sd(vector<double> x, vector<double> y, int n);
vector<vector<double>> sd_vec(vector<vector<double>> x, int n, int p);