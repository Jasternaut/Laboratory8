#include "util.hpp"
#include <string>

namespace util
{
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
}