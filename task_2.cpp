#include "task_2.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include "util.hpp"

namespace second
{
    /*
        2. Дана строка, содержащая английский текст. 
        Вывести в алфавитном порядке слова текста, содержащие не более 3-х согласных, 
        в остальных словах удалить гласные и продублировать согласные буквы.
    */

    // Уменьшить букву
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

    // Дублировать согласные
    std::string process_word(const std::string& word)
    {
        std::string result;
        for (char letter : word)
        {
            if (is_consonant(letter))
            {
                result.push_back(letter); // push_back добавляет один символ в конец строки
                result.push_back(letter);
            }
        }
        return result;
    }

    int task_2()
    {
        std::ifstream in("input2.txt");
        std::ofstream out("output2.txt");
        const size_t max_size = 10240;
        size_t current_size = 0;
        std::string output_content;

        if (!in.is_open())
        {
            std::cerr << "Could not open the file input2.txt!" << std::endl;
            return 1;
        }

        std::string line, word;
        while(std::getline(in, line))
        {
            std::istringstream stream(line); // для чтения строк
            while(stream >> word)
            {
                int consonant_count = 0;
                for (char letter : word)
                {
                    if(is_consonant(letter))
                        ++consonant_count;
                }      

                std::string processed_word;
                
                if (consonant_count <= 3) processed_word = word;
                else processed_word = process_word(word);                   

                if (current_size + processed_word.size() + 1 > max_size)
                    break; // +1 для пробела
                
                if (output_content.find(processed_word) == std::string::npos) {
                    output_content += processed_word + "\n";
                    current_size += processed_word.size() + 1; // +1 для новой строки
                }
                if (current_size > max_size)
                break;
            }
        }

        in.close();
        std::istringstream result_stream(output_content);
        std::ostringstream sorted_output; // для вывода строк
        std::string sorted_words[1024];
        int word_count = 0;

        while (std::getline(result_stream, word))
            sorted_words[word_count++] = word;       

        std::sort(sorted_words, sorted_words + word_count);
        
        for (int i = 0; i < word_count; ++i)
            sorted_output << sorted_words[i] << "\n";

        out << sorted_output.str();
        out.close();

        std::cout << "Task 2 completed succesfuly!" << std::endl;
        return 0;
    }
}