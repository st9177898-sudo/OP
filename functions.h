#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
using namespace std;

struct Visitor {
    double weight;
    double workout;
    double energy;
};
void doExercise(Visitor &v, double intensity) {
    v.workout += intensity;
    v.energy -= intensity * 0.5;
    cout << "Ви виконали вправи з інтенсивністю " << intensity << endl;
}
void eat(Visitor &v, double calories) {
    v.energy += calories;
    v.weight += calories * 0.01;
    cout << "Ви поїли " << calories << " калорій" << endl;
}
void rest(Visitor &v, double hours) {
    v.energy += hours * 5;
    cout << "Ви відпочивали " << hours << " годин" << endl;
}
void showStatus(const Visitor &v) {
    cout << "Стан відвідувача:" << endl;
    cout << "Вага: " << v.weight << endl;
    cout << "Обсяг тренування: " << v.workout << endl;
    cout << "Енергія: " << v.energy << endl << endl;
}
#endif