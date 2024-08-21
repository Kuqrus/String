#include "Utils.h"

void CreateAndFill(std::vector<String>& v)
{
    std::vector<const char*> str = { "Lorem", "ipsum", "dolor", "sit",
                                    "Amet", "consectetur", "adipiscing", "elit",
                                    "Maecenas", "Et", "felis", "at",
                                    "mi", "tempus", "sodales"};

    for (const auto& s : str)
    {
        v.push_back(String(s));
    }
}

int main()
{
    /*
    std::vector<String> Strings;

    CreateAndFill(Strings);

    Utils::PrintVector(Strings);
    std::cout << std::endl;

    std::sort(Strings.begin(), Strings.end(),
        [&](const String& lhs, const String& rhs)
        {
            return Utils::ReverseSort(lhs, rhs);
        }
    );

    Utils::PrintVector(Strings);
    std::cout << std::endl;
    */

    char c;
    //std::isalpha(c);

    String s(c);

    s += "121233";

    std::cout << s << std::endl;
}