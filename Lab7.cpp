#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    Visitor v;
    cout << "Введіть робочу вагу: ";
    cin >> v.weight;
    cout << "Введіть початковий обсяг тренування: ";
    cin >> v.workout;
    cout << "Введіть початкову енергію: ";
    cin >> v.energy;
    cout << endl;
    doExercise(v, 10);
    eat(v, 500);
    rest(v, 2);
    showStatus(v);

    return 0;
}