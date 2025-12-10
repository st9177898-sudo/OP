#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3;
    cout << "n1 (палети з цеглою): " << endl;
    cin >> n1;
    cout << "n2 (сервернi юнiти): " << endl;
    cin >> n2;
    cout << "n3 (бронеплити): " << endl;
    cin >> n3;
    int n = n1+n2+n3;
    int *a = new int[n];
    cout << "Введiть " << n << " значень (-50-100): " << endl;
    int *p = a;
    while (p < a + n)
    {
        cin >> *p;
        p++;
    }
    cout << "\nПочатковий масив: \n";
    cout << "Будмайданчик: ";
    p = a;
    for (int i = 0; i < n1; i++, p++)
        cout << *p << " "<<endl;
    cout << "\nСерверна зона: ";
    for (int i = 0; i < n2; i++, p++)
        cout << *p << " "<<endl;
    cout << "\nБронеплити: ";
    for (int i = 0; i < n3; i++, p++)
        cout << *p << " "<<endl;
    cout << "\n\n";
    int *start1 = a;
    int *end1 = a + n1;
    int *start2 = a + n1;
    int *end2 = a + n1 + n2;
    int *start3 = a + n1 + n2;
    int *end3 = a + n;
    int *q;
    for (q = start1; q < end1; q++)
        if (*q < 0) *q = 0;
    for (q = start2; q < end2; q++)
        if (*q < 0) *q = 0;
    for (q = start3; q < end3; q++)
        if (*q < 0) *q = 0;
    int min1 = *start1, max1 = *start1;
    int sum1 = 0;
    for (q = start1; q < end1; q++)
    {
        if (*q < min1) min1 = *q;
        if (*q > max1) max1 = *q;
        sum1 += *q;
    }
    float avg1 = (float)sum1 / n1;

    int min2 = *start2, max2 = *start2;
    int sum2 = 0;
    for (q = start2; q < end2; q++)
    {
        if (*q < min2) min2 = *q;
        if (*q > max2) max2 = *q;
        sum2 += *q;
    }
    float avg2 = (float)sum2 / n2;

    int min3 = *start3, max3 = *start3;
    int sum3 = 0;
    for (q = start3; q < end3; q++)
    {
        if (*q < min3) min3 = *q;
        if (*q > max3) max3 = *q;
        sum3 += *q;
    }
    float avg3 = (float)sum3 / n3;
    cout << "Пiдсумки по сегментах: \n";
    cout << "Будмайданчик: min = " << min1 << ", max = " << max1 << ", avg = " << avg1 << "\n";
    cout << "Серверна зона: min = " << min2 << ", max = " << max2 << ", avg = " << avg2 << "\n";
    cout << "Бронеплити: min = " << min3 << ", max = " << max3 << ", avg = " << avg3 << "\n\n";
    int *L, *R, tmp;
    L = start1;
    R = end1 - 1;
    while (L < R)
    {
        while (L < R && *L == 0) L++;
        while (L < R && *R > 0) R--;
        if (L < R)
        {
            tmp = *L;
            *L = *R;
            *R = tmp;
        }
    }
    L = start2;
    R = end2 - 1;
    while (L < R)
    {
        while (L < R && *L == 0) L++;
        while (L < R && *R > 0) R--;
        if (L < R)
        {
            tmp = *L;
            *L = *R;
            *R = tmp;
        }
    }
    L = start3;
    R = end3 - 1;
    while (L < R)
    {
        while (L < R && *L == 0) L++;
        while (L < R && *R > 0) R--;
        if (L < R)
        {
            tmp = *L;
            *L = *R;
            *R = tmp;
        }
    }
    int above = 0;
    for (q = start3; q < end3; q++)
        if (*q > avg3) above++;
    cout << "Кiлькiсть бронеплит бiльше середнього: " << above << "\n";
    float load = avg1 * avg2 * above;
    cout << "Узагальнений показник навантаження: " << load << "\n\n";
    cout << "Пiдсумковий масив:\n";
    cout << "Будмайданчик: ";
    p = start1;
    for (int i = 0; i < n1; i++, p++)
        cout << *p << " ";

    cout << "\nСерверна зона: ";
    for (int i = 0; i < n2; i++, p++)
        cout << *p << " ";

    cout << "\nБронепластини: ";
    for (int i = 0; i < n3; i++, p++)
        cout << *p << " ";
    cout << "\n";
    delete [] a;

    return 0;
}