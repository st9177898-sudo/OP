#include <iostream>
#include <vector>
using namespace std;

class Airport {
private:
    string name;
    string code;
public:
    Airport(const string& n, const string& c) : name(n), code(c) {}
    string getName() const { return name; }
    string getCode() const { return code; }
    friend ostream& operator<<(ostream& os, const Airport& a) {
        os << a.name << " (" << a.code << ")";
        return os;
    }
};
class Route {
private:
    Airport dep;
    Airport arr;
    float distance;
public:
    Route(const Airport& dep, const Airport& arr, float dist) : dep(dep), arr(arr), distance(dist) {}
    void printRoute() const { cout << dep << " -> " << arr << ", " << distance << " km"<<endl; }
};
class Airplane {
private:
    string model;
    int capac;
    vector<Route*> routes;
public:
    Airplane(const string& m, int c) : model(m), capac(c) {}
    ~Airplane() { for (auto r : routes) delete r; }
    void addRoute(Route* r) { routes.push_back(r); }
    void printInfo() const {
        cout << "Літак " << model << ", місткість " << capac <<endl;
        for (auto r : routes) r->printRoute();
    }
};
int main() {
    Airport kyiv("Бориспіль", "KBP");
    Airport lax("Лос-Анджелес", "LAX");
    Airport sfo("Сан-Франциско", "SFO");

    Airplane plane1("Boeing 737", 180);
    Airplane plane2("Airbus A320", 160);

    plane1.addRoute(new Route(kyiv, lax, 3983));
    plane1.addRoute(new Route(lax, sfo, 543));
    plane2.addRoute(new Route(sfo, kyiv, 4130));

    plane1.printInfo();
    cout << endl;
    plane2.printInfo();
}