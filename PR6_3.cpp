#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int r;
    int c;
};
int main() {
    int rows, cols;
    cout << "Введiть кiлькiсть рядкiв i стовпцiв: ";
    cin >> rows >> cols;
    vector< vector<int> > a(rows, vector<int>(cols));
    cout << "Введiть матрицю висот (" << rows*cols << " чисел):\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];
    int threshSegment;
    cout << "Введiть порiг для вiдрiзка: ";
    cin >> threshSegment;
    int bestRow = -1, bestStartCol = -1, bestEndCol = -1, bestLen = 0;
    for (int i = 0; i < rows; i++) {
        for (int start = 0; start < cols; start++) {
            int mn = a[i][start];
            int mx = a[i][start];
            for (int end = start; end < cols; end++) {
                int v = a[i][end];
                if (v < mn) mn = v;
                if (v > mx) mx = v;
                if (mx - mn <= threshSegment) {
                    int len = end - start + 1;
                    if (len > bestLen) {
                        bestLen = len;
                        bestRow = i;
                        bestStartCol = start;
                        bestEndCol = end;
                    }
                }
            }
        }
    }
    cout << "\nНайкращий вiдрiзок:\n";
    cout << "Рядок: " << bestRow + 1 << "\n";
    cout << "Початок: " << bestStartCol + 1 << "\n";
    cout << "Кiнець: " << bestEndCol + 1 << "\n";
    cout << "Довжина: " << bestLen << "\n\n";
    vector<Cell> localMins;
    int dr8[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dc8[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int v = a[r][c];
            bool ok = true;
            for (int k = 0; k < 8; k++) {
                int nr = r + dr8[k];
                int nc = c + dc8[k];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (a[nr][nc] <= v) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                Cell t;
                t.r = r;
                t.c = c;
                localMins.push_back(t);
            }
        }
    }
    cout << "Локальнi мiнiмуми (r c):\n";
    for (int i = 0; i < (int)localMins.size(); i++)
        cout << localMins[i].r + 1 << " " << localMins[i].c + 1 << "\n";
    int sr, sc, tr, tc, heightLimit;
    cout << "\nВведiть координати старту (r c): ";
    cin >> sr >> sc;
    cout << "Введiть координати фiнiшу (r c): ";
    cin >> tr >> tc;
    cout << "Введiть максимально допустиму висоту для руху: ";
    cin >> heightLimit;
    sr--; sc--; tr--; tc--;
    if (sr < 0 || sr >= rows || sc < 0 || sc >= cols ||
        tr < 0 || tr >= rows || tc < 0 || tc >= cols ||
        a[sr][sc] > heightLimit || a[tr][tc] > heightLimit) {
        cout << "\nМаршрут неможливий.\n";
        return 0;
    }
    vector< vector<int> > dist(rows, vector<int>(cols, -1));
    vector< vector<Cell> > parent(rows, vector<Cell>(cols, {-1, -1}));
    queue<Cell> q;
    q.push({sr, sc});
    dist[sr][sc] = 0;
    int dr4[4] = {-1, 1, 0, 0};
    int dc4[4] = { 0, 0,-1, 1};
    while (!q.empty()) {
        Cell cur = q.front();
        q.pop();
        if (cur.r == tr && cur.c == tc) break;
        for (int k = 0; k < 4; k++) {
            int nr = cur.r + dr4[k];
            int nc = cur.c + dc4[k];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (dist[nr][nc] == -1 && a[nr][nc] <= heightLimit) {
                    dist[nr][nc] = dist[cur.r][cur.c] + 1;
                    parent[nr][nc] = {cur.r, cur.c};
                    q.push({nr, nc});
                }
            }
        }
    }
    if (dist[tr][tc] == -1) {
        cout << "\nМаршрут недосяжний.\n";
        return 0;
    }
    cout << "\nДовжина маршруту: " << dist[tr][tc] << "\n";
    cout << "Маршрут (r c):\n";
    vector<Cell> path;
    Cell cur = {tr, tc};
    while (!(cur.r == sr && cur.c == sc)) {
        path.push_back(cur);
        cur = parent[cur.r][cur.c];
    }
    path.push_back({sr, sc});
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i].r + 1 << " " << path[i].c + 1 << "\n";

    return 0;
}