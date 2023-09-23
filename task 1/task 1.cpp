/*при выполнении данной задачи вы должны сравнить библиотеки “string.h” или <cstring>(с) и
<string>(с++).
а) перед main() в комментариях ответьте на вопросы и напишите соответствия с – с++ для
следующих функций(причем соответствия необязательно будут в виде функций) :
	1) strlen - string::length
	2) strcpy - аналога нет, поэтому пишем (a = b)
	3) strcmp - аналога нет
	4) strcat - someString.append
	5) somestring[index] - someString.at(index)
	6) не имеет точного аналога (возможно использовать strcat)  - push_back
	7) не имеет аналога - pop_back

	функции могут не иметь точного аналога в библиотеке другого языка.почему ? – объясните главную
	разницу строк в с и с++.

	Строки в C - массив элементов char с null-байтом в окончании
	Строки в C++ - обЪект класса string с динамической памятью

	б) теперь напишите программу на с++, которая будет сортировать буквы в алфавитном порядке в
	веденной пользователем строке.причем программа должна удалять пробелы и пунктуационные
	знаки.
	nb: используйте только библиотеку <string>.
	*/

#include <iostream>
#include <string>

int main() {
    std::string input;

    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    // Удаляем пробелы и пунктуационные знаки
    std::string cleanedInput;
    for (char c : input) {
        if (!std::isspace(c) && !std::ispunct(c)) {
            cleanedInput += c;
        }
    }

    // Сортируем буквы в алфавитном порядке
    for (int i = 0; i < cleanedInput.length() - 1; i++) {
        for (int j = 0; j < cleanedInput.length() - i - 1; j++) {
            if (cleanedInput[j] > cleanedInput[j + 1]) {
                char temp = cleanedInput[j];
                cleanedInput[j] = cleanedInput[j + 1];
                cleanedInput[j + 1] = temp;
            }
        }
    }

    std::cout << "Результат: " << cleanedInput << std::endl;

    return 0;
}


	

