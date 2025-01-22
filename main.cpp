#include <iostream>
#include "task_1.hpp"
#include "task_2.hpp"
#include "task_3.hpp"

/*
Лабораторная работа 8. 
В подзадаче 1 не более 2000 слов.
В подзадачах 2 и 3 считать, что размер текста не более 10 кБ.

1. Дан файл, содержащий английский текст. 
Найти в тексте N<=2000 самых длинных слов, в которых согласные буквы упорядочены по алфавиту. 
Записать найденные слова в текстовый файл в порядке невозрастания длины. 
Все найденные слова должны быть разными!
 
2. Дана строка, содержащая английский текст. 
Вывести в алфавитном порядке слова текста, содержащие не более 3-х согласных, 
в остальных словах удалить гласные и продублировать согласные буквы.
 
3. В текстовом файле input.txt записан английский текст. 
Найти в тексте слова, содержащие две одинаковые буквы подряд, 
записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы. 
Полученный текст записать в файл output.txt. 
Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.
*/

int main()
{
    std::cout << "Select number of the task: ";
    int task;
    std::cin >> task;

    switch (task)
    {
        case 1:
            if(first::task_1() == 0) return 0;
        break;

        case 2:
            if(second::task_2() == 0) return 0;
        break;

        case 3:
            if(third::task_3() == 0) return 0;
        break;
        
        default:
            std::cout << "Wrong number." << std::endl;
    }

    return 0;
}