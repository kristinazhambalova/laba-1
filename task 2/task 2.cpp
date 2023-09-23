//А) Перед main() в комментариях ответьте на вопросы и напишите соответствия С – С++ для
//следующих операций :
//1) int* ptr = (int*)malloc(sizeof(int)) - int* ptr = new int
//2) int* ptrArr = (int*)malloc(sizeof(int) * N) - int* ptrArr = new int[N]
//3) free(ptr) - delete ptr
//4) free(ptrArr) - delete[] ptrArr
//В С++ необходимо ли освобождать динамическую память ? 
// Да, оператором delete.
//Можно ли освободить одну и ту же выделенную память дважды ? 
// Нет, это приводит к недокументированному поведению.
//А можно ли освободить невыделенную память ? 
// Нет.
// 
// 
// 
//Б) Треугольник Фибоначчи.У некоторых это задание было на программировании по С.Теперь
//требуется адаптировать эту программу(или написать заново) на С++ с определенными
//требованиями(NB) :
//	-именно пользователь должен решать(посредством ввода в командную строку) сколько строк у
//	пирамиды должно быть;
//-перемещаться по массиву(-ам) необходимо только через указательную арифметику – Pointer
//Arithmetic[arr[i][j] - > *(*(arr + i) + j)];
//-использовать только динамическое выделение памяти

#include <iostream>

int** createFibonacciTriangle(int rows) {
    int** triangle = new int* [rows];

    for (int i = 0; i < rows; i++) {
        triangle[i] = new int[i + 1];
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            *(triangle[i] + j) = *(triangle[i - 1] + j - 1) + *(triangle[i - 1] + j);
        }
    }

    return triangle;
}

void printFibonacciTriangle(int** triangle, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << *(*(triangle + i) + j) << " ";
        }
        std::cout << std::endl;
    }
}

void deleteFibonacciTriangle(int** triangle, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;
}

int main() {
    int rows;

    std::cout << "Введите количество строк: ";
    std::cin >> rows;

    // Создание треугольника Фибоначчи
    int** fibonacciTriangle = createFibonacciTriangle(rows);

    // Вывод треугольника Фибоначчи
    printFibonacciTriangle(fibonacciTriangle, rows);

    // Освобождение памяти
    deleteFibonacciTriangle(fibonacciTriangle, rows);

    return 0;
}