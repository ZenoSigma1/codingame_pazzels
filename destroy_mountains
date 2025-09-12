#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // Бесконечный цикл игры
    while (1) {
        int max_height = -1; // Начнем с очень маленького числа 
        int target_index = 0; // По умолчанию стреляем в первую гору 

        // Читаем высоты всех 8 гор
        for (int i = 0; i < 8; i++) {
            int mountain_h; // Высота текущей горы 
            cin >> mountain_h; // Читаем высоту  
            cin.ignore(); // Очищаем буфер обмена


            //Ищем самую высокую гору
            if (mountain_h > max_height){
                max_height = mountain_h;
                target_index = i; // Запоминаем индекс этой горы 
            }

        }
         // Стреляем в самую высокую гору  
        cout << target_index << endl;
    }
}
