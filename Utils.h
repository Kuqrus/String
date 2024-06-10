#pragma once
#include "inc.h"


namespace Utils 
{
    void PrintVector(const std::vector<String>& v)
    {
        for (const String& s : v)
        {
            std::cout << s << " ";
        }
    }

    bool ReverseSort(const String& lhs, const String& rhs)
    {
        for (size_t i = 0; i < std::min(lhs.GetSize(), rhs.GetSize()); i++)
        {
            if (std::tolower(lhs.GetString()[i]) == std::tolower(rhs.GetString()[i])) {
                continue;
            }
            return std::tolower(lhs.GetString()[i]) > std::tolower(rhs.GetString()[i]);
        }
        return false;
    }
}
