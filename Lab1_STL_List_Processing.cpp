#include <iostream>
#include <list>
#include <cmath>   
using namespace std;

int main() {
    // 1) Ввід n
    int n;
    cout << "Enter n: ";
    cin >> n;

    // 2) Ввід елементів у list
    list<double> L;
    cout << "Enter " << n << " real numbers:\n";

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        L.push_back(x);
    }

    // 3) Перевірка: чи є хоча б один елемент < -3
    bool hasLessThanMinus3 = false;
    for (double x : L) {
        if (x < -3.0) {
            hasLessThanMinus3 = true;
            break;
        }
    }

    // 4) Обробка списку за умовою
    if (hasLessThanMinus3) {
        // якщо є елемент < -3: замінити всі від'ємні на квадрати
        for (double& x : L) {
            if (x < 0.0) {
                x = x * x; // квадрат
            }
        }
    }
    else {
        // інакше: помножити всі елементи на 0.1
        for (double& x : L) {
            x = x * 0.1;
        }
    }

    // 5) Вивід у зворотному порядку
    cout << "Result (reverse order): ";
    for (auto it = L.rbegin(); it != L.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}