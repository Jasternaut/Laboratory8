#include "task_1.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>
#include "util.hpp"

namespace first
{
    /*
        1. Дан файл, содержащий английский текст. 
        Найти в тексте N<=2000 самых длинных слов, в которых согласные буквы упорядочены по алфавиту. 
        Записать найденные слова в текстовый файл в порядке невозрастания длины. 
        Все найденные слова должны быть разными!
    */

    const int N_Max = 2000;

    // Считать данные
    bool read(int& cnt, std::string words[N_Max])
    {
        std::ifstream in("input.txt");

        if (!in.is_open())
        {
            std::cerr << "\"input.txt\" isn't opened!" << std::endl;
            return false;
        }

        cnt = 0;
         
        while (!in.eof() && cnt < N_Max) 
        {
            in >> words[cnt];
            cnt++;
        }

        return true;
    }

    void write_console(int cnt, std::string words[N_Max])
    {
        for (int i = 0; i < cnt; i++)
        {
            std::cout << "<" << words[i] << ">" << std::endl;
        }
        std::cout << "Writing complete. Count = " << cnt << std::endl;
    }

    void write(int cnt, std::string words[N_Max])
    {   
        std::ofstream out("output.txt");
        for (int i = 0; i < cnt; ++i) 
        {
            out << words[i] << std::endl;
        }
        out.close();
    }

    // уменьшить букву
    char to_lower(char c)
    {
        if ('A' <= c && c <= 'Z')
            c += 32;
        return c;
    }
    
    // Является ли буква согласной 
    bool is_consonant(char c) 
    { 
        std::string consonants = "bcdfghjklmnpqrstvwxyz"; 
        return consonants.find(to_lower(c)) != std::string::npos; 
    }

    // Очистить слова от лишних знаков
    void clear_words(int cnt, std::string words[N_Max])
    {
        for(int i=0; i<cnt; i++)
            for(int j=0; j<words[i].length(); j++)
            {
                if(!isalpha(words[i][j]))
                {
                    words[i].erase(j, 1);
                    j--;
                }
            }
    }

    // Вспомогательная функция для проверки, упорядочены ли согласные по алфавиту
    bool are_consonants_alphabeted(std::string word)
    {
        char previous = '\0';

        for (char c : word)
        {
            char lower_c = to_lower(c);
            if(is_consonant(lower_c))
            {
                if(previous != '\0' && lower_c < previous)
                {
                    return false;
                }
                previous = lower_c;
            }
        }
        return true;
    }

    // Очищение списка от слов, в которых согласные не упорядочены по алфавиту
    void filter_alphabeted_words(int cnt, std::string words[N_Max], std::string sorted_words[N_Max], int& count)
    {
        count = 0;
        for (int i = 0; i<cnt; i++)
        {
            if (are_consonants_alphabeted(words[i]))
            {
                sorted_words[count] = words[i];
                count++;
            }
        }
    }

    // Функция для удаления дубликатов 
    // Внешний цикл: проходит по каждому элементу массива.
    // Внутренний цикл: сравнивает текущий элемент с последующими элементами.
    void remove_duplicates(std::string words[N_Max], int& cnt) 
    { 
        for (int i = 0; i < cnt; i++) 
        { 
            for (int j = i + 1; j < cnt; j++) 
            { 
                if (words[i] == words[j]) 
                { 
                    // Сдвигаем элементы влево, чтобы удалить дубликат 
                    for (int k = j; k < cnt - 1; k++) 
                    { 
                        words[k] = words[k + 1]; 
                    } 
                    cnt--; // Уменьшаем количество элементов 
                    j--; // Проверяем на новом месте 
                } 
            } 
        } 
    }

    // Функция для сортировки слов по убыванию их длины 
    void sort_by_length(std::string words[N_Max], int cnt) 
    { 
        for (int i = 0; i < cnt - 1; ++i) 
        { 
            for (int j = 0; j < cnt - i - 1; ++j) 
            { 
                if (words[j].length() < words[j + 1].length()) 
                { 
                    std::swap(words[j], words[j + 1]); 
                } 
            } 
        } 
    }

    // Главная часть кода первого пункта
    int task_1()
    {
        int cnt;
        int count;
        std::string words[N_Max];
        std::string sorted_words[N_Max];

        if (!read(cnt, words))
        {
            return -1;
        }
        
        clear_words(cnt, words);
        filter_alphabeted_words(cnt, words, sorted_words, count);
        remove_duplicates(sorted_words, count);
        sort_by_length(sorted_words, count);

        write_console(count, sorted_words);
        write(count, sorted_words);

        std::cout << "Task 1 completed succesfuly!";  
        return 0;
    }
}