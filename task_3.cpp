#include <iostream>
#include "task_3.hpp"
#include <fstream>
#include <sstream>

namespace third
{
    /*
        3. В текстовом файле input.txt записан английский текст. 
        Найти в тексте слова, содержащие две одинаковые буквы подряд, 
        записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы. 
        Полученный текст записать в файл output.txt. 
        Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.
    */

    std::string process_word(const std::string& word)
    {
        std::string result = word;
        bool found = false;
        std::string duplicates;
        for (size_t i = 1; i < word.length(); ++i)
        {
            if (word[i] == word[i-1])
            {
                found = true;
                duplicates += word[i];
            }
        }
        if (found)
        {
            for (char& letter : result)
            {
                letter = std::toupper(letter);
            }
            result += " (" + duplicates + ")";
        }
        return result;
    }

    int task_3()
    {
        std::ifstream in("input3.txt");
        std::ofstream out("output3.txt");

        if (!in.is_open())
        {
            std::cerr << "Could not open the input3.txt!" << std::endl;
            return 1;
        }

        std::string line;
        std::ostringstream output_buffer;

        while(std::getline(in, line))
        {
            std::istringstream stream(line);
            std::string word;
            bool first_word = true;
            while (stream >> word)
            {
                std::string processed_word = process_word(word);
                if (!first_word) output_buffer << " ";
                output_buffer << processed_word;
                first_word = false;
            }
            output_buffer << "\n";
        }

        in.close();
        out << output_buffer.str();
        out.close();

        std::cout << "done.";
        return 0;
    }
}