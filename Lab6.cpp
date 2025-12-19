#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> low;
    multiset<int> high;
    cout << "Вводьте числа по одному:" << endl;
    int x;
    while (cin >> x) {
        if (low.empty() || x <= *low.rbegin())
            low.insert(x);
        else
            high.insert(x);
        if (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            auto it = low.end();
            --it;
            low.erase(it);
        }
        else if (high.size() > low.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
        double median;
        if (low.size() == high.size())
            median = (*low.rbegin() + *high.begin()) / 2.0;
        else
            median = *low.rbegin();
        cout << "Поточна медіана: " << median << endl;
    }

    return 0;
}