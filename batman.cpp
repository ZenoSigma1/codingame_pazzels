#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Чтение размеров здания
    int w, h;
    cin >> w >> h; cin.ignore();
    
    // Чтение максимального количества прыжков
    int n;
    cin >> n; cin.ignore();
    
    // Чтение начальной позиции Бэтмена
    int x0, y0;
    cin >> x0 >> y0; cin.ignore();

    // Инициализация границ поиска
    int x_min = 0, y_min = 0;
    int x_max = w - 1;
    int y_max = h - 1;

    // Игровой цикл
    while (1) {
        string bomb_dir;
        cin >> bomb_dir; cin.ignore();

        // Анализ направления бомбы и обновление границ поиска
        if (bomb_dir.find('U') != string::npos) {
            // Бомба выше - опускаем верхнюю границу
            y_max = y0 - 1;
        } else if (bomb_dir.find('D') != string::npos) {
            // Бомба ниже - поднимаем нижнюю границу
            y_min = y0 + 1;
        }

        if (bomb_dir.find('L') != string::npos) {
            // Бомба левее - сдвигаем правую границу
            x_max = x0 - 1;
        } else if (bomb_dir.find('R') != string::npos) {
            // Бомба правее - сдвигаем левую границу
            x_min = x0 + 1;
        }

        // Вычисление новой позиции как середины текущих границ
        x0 = (x_min + x_max) / 2;
        y0 = (y_min + y_max) / 2;

        // Вывод следующей позиции для прыжка
        cout << x0 << " " << y0 << endl;
    }
}
