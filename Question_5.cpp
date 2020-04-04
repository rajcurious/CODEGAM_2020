#include <bits/stdc++.h>

using namespace std;

int sqr[60][60], a, k, t;
bool r_safe[60][60], c_safe[60][60], flag;

void solver(int r, int c, int m) {
    if (r == a && c == a + 1 && m == k && !flag) {
        flag = true;
        cout << "Case #" << t << ": " << "POSSIBLE\n";
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= a; ++j) {
                cout << sqr[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    } else if (r > a) {
        return;
    } else if (c > a) {
        solver(r + 1, 1, m);
    }
    for (int i = 1; i <= a && !flag; ++i) {
        if (!r_safe[r][i] && !c_safe[c][i]) {
            r_safe[r][i] = c_safe[c][i] = true;
            if (r == c) {
                m += i;
            }
            sqr[r][c] = i;

            solver(r, c + 1, m);

            r_safe[r][i] = c_safe[c][i] = false;
            if (r == c) {
                m -= i;
            }
            sqr[r][c] = 0;
        }
    }
}

int main() {
    int T;
    scanf(" %d", &T);
    for (t = 1; t <= T; ++t) {
        scanf(" %d %d", &a, &k);
        solver(1, 1, 0);
        if (!flag) {
            cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
        }
        flag = false;
    }
    return 0;
}
