#include <iostream>
using namespace std;

int main() {
    int surface_n;
    cin >> surface_n;
    for (int i = 0; i < surface_n; i++) {
        int land_x, land_y;
        cin >> land_x >> land_y;
    }

    while (true) {
        int x, y, h_speed, v_speed, fuel, rotate, power;
        cin >> x >> y >> h_speed >> v_speed >> fuel >> rotate >> power;

        // Целевая вертикальная скорость
        int target_vs = -30;
        
        // Расчет ошибки управления
        int error = v_speed - target_vs;
        
        // Регулировка мощности на основе ошибки
        if (error <= -10) {
            power = 4;  // Максимальная тяга для торможения
        } else if (error >= 10) {
            power = 0;  // Минимальная тяга для экономии топлива
        } else {
            power = 3;  // Средняя тяга для поддержания скорости
        }

        // Вывод управления: угол 0°, вычисленная мощность
        cout << "0 " << power << endl;
    }
}
