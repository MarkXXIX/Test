#include <iostream>
#include <cmath>

using namespace std;

/* Выводит на консоль 2х мерный массив произвольного типа*/
template <typename T>
void out(T* arr, int COLS, int ROWS){
    for (int i = 0; i < COLS; ++i){
        for (int j = 0; j < ROWS; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
/* Считывает с консоли 2х мерный массив произвольного типа*/
template <typename T>
void in(T* arr, int COLS, int ROWS){
    for (int i = 0; i < COLS; ++i)
        for (int j = 0; j < ROWS; ++j){
            cout << "Введите число с индексом [" << i << "," << j << "] = ";
            cin >> arr[i][j]/* << " "*/;
        }
}


/* Превращает все отрицательные элементы в положительные*/
template <typename T>
void ConvertP(T* arr, int COLS, int ROWS){
    for (int i = 0; i < COLS; ++i)
        for (int j = 0; j < ROWS; ++j)
            if (arr[i][j] < 0)
                arr[i][j] = abs(arr[i][j]);
}

/* Превращает все положительные элементы в отрицательные*/
template <typename T>
void ConvertM(T* arr, int COLS, int ROWS) {
    for (int i = 0; i < COLS; ++i)
        for (int j = 0; j < ROWS; ++j)
            if (arr[i][j] > 0)
                arr[i][j] = arr[i][j] *= -1;
}

/* Находит среднее арифметическое отрицательных элементов*/
template <typename T>
void Arif(T* arr, int COLS, int ROWS) {
    int counter = 0; float result = 0;
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            if (arr[i][j] < 0) {
                counter++; result += arr[i][j];
            }
        }
    }
    cout << endl << "Среднее арифметическое отрицательных: " << result / counter << endl << endl;
}


/* Заменяет на 0 все числа, в указанном промежутке*/
template <typename T>
void Change(T* arr, int COLS, int ROWS) {
    cout << "Заменить числа в промежутке arr[x1;y1] до arr[x2;y2]\n";
    int x1, x2, y1, y2;
    cout << "x1 = "; cin >> x1;
    cout << "y1 = "; cin >> y1;
    cout << "x2 = "; cin >> x2;
    cout << "y2 = "; cin >> y2;
    int st = x1 * ROWS + y1; // вычисление начальной точки
    int en = x2 * ROWS + y2; // вычисление конечной точки
    int total = COLS * ROWS; // всего элементов в массиве

    int counter = 0;
    //cout << st << ' ' << en << ' ' << total << endl;
    for (int i = 0; i <= COLS-1; i++) {
        for (int j = 0; j <= ROWS-1; j++) {
            counter++; 
            if (counter > st && counter <= en) arr[i][j] = 0;
        }
    }
}

int main(){
    setlocale(LC_ALL, "russian");
    // для простоты используем массив 2х3,
    const int COLS = 2;
    const int ROWS = 3;
    int arr[COLS][ROWS] = { -1, -2, 3,
                             4, 5, 6 };

    //in(arr, COLS, ROWS);  // Заполнение с клавы

    out(arr, COLS, ROWS); // Вывод массива

    //ConvertP(arr, COLS, ROWS); // Замена отрицательных на положительные
    //ConvertM(arr, COLS, ROWS); // Замена положительных на отрицательные
    //Arif(arr, COLS, ROWS); // Ср арифметическое отрицательных числ
    Change(arr, COLS, ROWS); //замена на 0 на промежутке

    cout << "После изменений: ";
    out(arr, COLS, ROWS);  // снова выводим
    system("pause");
}