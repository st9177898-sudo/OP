#include <iostream>
using namespace std;
/*90-100 = A
 *80-89  = B
 *70-79  = C
 *60-69  = D
 *50-59  = E
 *30-49  = FX
 *1-29   = F
 */
int main() {
    unsigned short grade, sum;
    string result;
    cout << "Введiь оцiнку: ";
    cin >> grade;
    sum = grade / 10;
    switch (sum)
    {
    case 10: result = 'A'; break;
    case 9: result = 'A'; break;
    case 8: result = 'B'; break;
    case 7: result = 'C'; break;
    case 6: result = 'D'; break;
    case 5: result = "E"; break;
    case 4: result = "FX" ;break;
    case 3: result = "FX"; break;
    case 2: result = 'F'; break;
    default: result = 'F'; break;
    }
    cout << result<< endl;
    return 0;
}