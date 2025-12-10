#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Кiлькiсть рядкiв: ";
    cin >> rows;
    cout << "Кiлькiсть стовпцiв: ";
    cin >> cols;
    int **a = new int*[rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];
    cout << "Введiть значення матрицi (" << rows * cols <<" чисел в межах [0;100]):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];
    }
    int soft = 0;
    int signal = 0;
    int obs = 0;
    int total = rows*cols;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int x = a[i][j];
            if (x <= 20) soft++;
            else if (x <= 60) signal++;
            else obs++;
        }
    }
    float softPct = (float) soft * 100 / total;
    float signalPct = (float) signal * 100 / total;
    float obsPct = (float) obs * 100 / total;
    cout << "\nВiдсоток м'якого грунту: " << softPct << "%\n";
    cout << "Вiдсоток нормального сигналу: " << signalPct << "%\n";
    cout << "Вiдсоток високих перешкод: " << obsPct << "%\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int x = a[i][j];
            if (x >= 21 && x <= 60)
            {
                int cnt = 0;
                if (i > 0 && a[i - 1][j] > 60) cnt++;
                if (i < rows - 1 && a[i + 1][j] > 60) cnt++;
                if (j > 0 && a[i][j - 1] > 60) cnt++;
                if (j < cols - 1 && a[i][j + 1] > 60) cnt++;
                if (cnt >= 2)
                {
                    a[i][j] = a[i][j] + 10;
                    if (a[i][j] > 100) a[i][j] = 100;
                }
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int x = a[i][j];
            if (x >= 0 && x <= 20)
            {
                bool hasbig = false;
                if (i > 0 && a[i - 1][j] > 60) hasbig = true;
                if (i < rows - 1 && a[i + 1][j] > 60) hasbig = true;
                if (j > 0 && a[i][j - 1] > 60) hasbig = true;
                if (j < cols - 1 && a[i][j + 1] > 60) hasbig = true;
                if (hasbig)
                {
                    a[i][j] = 21;
                }
            }
        }
    }
    int bestLen = 0;
    int bestRow = -1;
    int bestStartCol = -1;
    int bestEndCol = -1;

    for (int i = 0; i < rows; i++) {
        int curLen = 0;
        int curStart = 0;

        for (int j = 0; j < cols; j++) {
            if (a[i][j] <= 60) {
                if (curLen == 0) {
                    curStart = j;
                }
                curLen++;

                if (curLen > bestLen) {
                    bestLen = curLen;
                    bestRow = i;
                    bestStartCol = curStart;
                    bestEndCol = j;
                }
            } else
                curLen = 0;
        }
    }
    cout << "Матриця пiсля обробки:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    if (bestLen > 0) {
        cout << "\nНайдовший вiдрiзок, де всi значення <= 60:\n";
        cout << "Довжина: " << bestLen << "\n";
        cout << "Рядок: " << (bestRow + 1) << "\n";
        cout << "Початок: стовпець " << (bestStartCol + 1) << ", кiнець: стовпець " << (bestEndCol + 1) << "\n";
    } else
    {
        cout << "\nНемає жодного вiдрiзка, де всi значення <= 60.\n";
    }
    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;

        return 0;
    }