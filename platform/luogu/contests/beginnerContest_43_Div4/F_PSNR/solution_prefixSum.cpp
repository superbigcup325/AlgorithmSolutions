#include <bits/stdc++.h>
using namespace std;
#define int long long

//prefix

signed main() {
    int h, w;
    cin >> h >> w;
    vector<vector<vector<int>>> I(3, vector<vector<int>>(h, vector<int>(w)));
    vector<vector<vector<int>>> K(3, vector<vector<int>>(h, vector<int>(w)));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> I[0][i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> I[1][i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> I[2][i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> K[0][i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> K[1][i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> K[2][i][j];
        }
    }

    vector<vector<vector<int>>> diff(3, vector<vector<int>>(h, vector<int>(w)));
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int d = I[k][i][j] - K[k][i][j];
                diff[k][i][j] = d * d;
            }
        }
    }

    vector<vector<vector<int>>> pref_sum(3, vector<vector<int>>(h+1, vector<int>(w+1, 0)));

    for (int k = 0; k < 3; k++) {
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                pref_sum[k][i][j] = diff[k][i-1][j-1]
                                  + pref_sum[k][i-1][j]
                                  + pref_sum[k][i][j-1]
                                  - pref_sum[k][i-1][j-1];
            }
        }
    }

    auto get_diff_sum = [&](int k, int x1, int y1, int x2, int y2) {
        return pref_sum[k][x2+1][y2+1] - pref_sum[k][x1][y2+1]
               - pref_sum[k][x2+1][y1] + pref_sum[k][x1][y1];
    };

    int min_h = (h + 1) / 2;
    int min_w = (w + 1) / 2;
    double min_M = 1e18;
    for (int x1 = 0; x1 < h; x1++) {
        for (int x2 = x1; x2 < h; x2++) {
            int height = x2 - x1 + 1;
            if (height < min_h) continue;

            for (int y1 = 0; y1 < w; y1++) {
                for (int y2 = y1; y2 < w; y2++) {
                    int width = y2 - y1 + 1;
                    if (width < min_w) continue;

                    int total_diff = 0;
                    for (int k = 0; k < 3; k++) {
                        total_diff += get_diff_sum(k, x1, y1, x2, y2);
                    }
                    double M = static_cast<double>(total_diff) / (3.0 * height * width);
                    if (M < min_M) {
                        min_M = M;
                    }
                }
            }
        }
    }
    double PSNR = 20.0 * log10(255 / sqrt(min_M));
    cout << fixed << setprecision(8) << PSNR << endl;
    return 0;
}