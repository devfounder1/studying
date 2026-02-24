#include <iostream>
#include <Eigen/Dense>
#include <iomanip>
#include <cmath>

using namespace std;
using namespace Eigen;

int main() {
    cout << "=== Проект: Умный оценщик домов (Linear Regression) ===" << endl << endl;

    // --- ЭТАП 1: ПОДГОТОВКА ДАННЫХ ---
    
    // Матрица признаков X: 5 домов, 2 признака (Площадь, Комнаты)
    MatrixXf X(5, 2);
    X << 50, 2,
         80, 3,
         100, 4,
         60, 2,
         90, 3;

    // Вектор целевых значений y: Цены (в миллионах)
    VectorXf y(5);
    y << 5, 8, 11, 6, 9;

    cout << "Исходные данные:" << endl;
    cout << "Площадь | Комнаты | Цена" << endl;
    for (int i = 0; i < X.rows(); ++i) {
        cout << setw(7) << X(i, 0) << " | " << setw(7) << X(i, 1) << " | " << y(i) << endl;
    }
    cout << endl;

    // --- ЭТАП 2: НОРМАЛИЗАЦИЯ (Важно!) ---
    // Признаки имеют разный масштаб (50-100 против 2-4). Без нормализации обучение будет плохим.
    
    cout << "--- Нормализация данных ---" << endl;
    
    // Нормализуем столбец 0 (Площадь)
    float mean_area = X.col(0).mean();
    float std_area = sqrt((X.col(0).array() - mean_area).square().sum() / X.rows());
    X.col(0) = (X.col(0).array() - mean_area) / std_area;

    // Нормализуем столбец 1 (Комнаты)
    float mean_rooms = X.col(1).mean();
    float std_rooms = sqrt((X.col(1).array() - mean_rooms).square().sum() / X.rows());
    X.col(1) = (X.col(1).array() - mean_rooms) / std_rooms;

    cout << "Данные нормализованы (среднее ~0, отклонение ~1)." << endl;
    cout << "Пример первых строк X после нормализации:\n" << X.topRows(2) << endl << endl;

    // --- ЭТАП 3: ОБУЧЕНИЕ МОДЕЛИ ---
    
    // Инициализируем веса случайными маленькими числами
    // w[0] - вес для площади, w[1] - вес для комнат
    Vector2f w; 
    w << 0.0, 0.0; 
    
    float b = 0.0; // Смещение (bias)
    float lr = 0.1; // Скорость обучения (побольше, т.к. данные нормализованы)
    int epochs = 1000;

    cout << "--- Процесс обучения ---" << endl;
    cout << fixed << setprecision(6);

    for (int i = 0; i < epochs; ++i) {
        // 1. Предсказание: y_pred = X * w + b
        // X (5x2) * w (2x1) = вектор (5x1)
        VectorXf y_pred = X * w + VectorXf::Constant(X.rows(), b);

        // 2. Ошибка
        VectorXf error = y_pred - y;

        // 3. Вычисление градиентов
        // Градиент для весов: (X_transpose * error) / N
        // Нам нужно учесть размер выборки, чтобы шаг был адекватным
        Vector2f grad_w = (X.transpose() * error) / X.rows();
        
        // Градиент для смещения: среднее ошибки
        float grad_b = error.mean();

        // 4. Обновление параметров (Шаг вниз)
        w = w - lr * grad_w;
        b = b - lr * grad_b;

        // Вывод прогресса каждые 200 шагов
        if (i % 200 == 0) {
            float mse = (error.array().square()).mean();
            cout << "Шаг " << i << ": w=[" << w(0) << ", " << w(1) << "], b=" << b << ", MSE=" << mse << endl;
        }
    }

    cout << "\nОбучение завершено!" << endl;
    cout << "Найденные параметры:" << endl;
    cout << "Вес площади (w1): " << w(0) << endl;
    cout << "Вес комнат (w2):  " << w(1) << endl;
    cout << "Смещение (b):     " << b << endl << endl;

    // --- ЭТАП 4: ПРОВЕРКА И ПРЕДСКАЗАНИЕ ---
    
    cout << "--- Проверка на обучающих данных ---" << endl;
    VectorXf final_pred = X * w + VectorXf::Constant(X.rows(), b);
    
    cout << "Дом | Реальная цена | Предсказанная | Разница" << endl;
    for (int i = 0; i < X.rows(); ++i) {
        cout << " " << i+1 << "  | " << setw(13) << y(i) << " | " << setw(13) << final_pred(i) << " | " << (y(i) - final_pred(i)) << endl;
    }

    // --- ЭТАП 5: ПРЕДСКАЗАНИЕ ДЛЯ НОВОГО ДОМА ---
    cout << "\n--- Предсказание для нового дома ---" << endl;
    cout << "Допустим, новый дом: Площадь 75 м², 3 комнаты." << endl;

    // Важно: Новый дом нужно нормализовать ТАКИМИ ЖЕ параметрами, как и обучающие!
    float new_area = 75.0;
    float new_rooms = 3.0;

    float norm_area = (new_area - mean_area) / std_area;
    float norm_rooms = (new_rooms - mean_rooms) / std_rooms;

    Vector2f new_x;
    new_x << norm_area, norm_rooms;

    float predicted_price = new_x.dot(w) + b;

    cout << "Нормализованные признаки: [" << norm_area << ", " << norm_rooms << "]" << endl;
    cout << ">>> ПРЕДСКАЗАННАЯ ЦЕНА: " << predicted_price << " млн руб." << endl;
    
    // Для справки: какая была бы цена по нашей скрытой формуле (0.1*площадь + 0.5*комнаты)
    float real_logic_price = 0.1 * new_area + 0.5 * new_rooms;
    cout << "(Для сравнения: по простой логике это было бы около " << real_logic_price << " млн)" << endl;

    cout << "\nНажми Enter...";
    cin.get();

    return 0;
}