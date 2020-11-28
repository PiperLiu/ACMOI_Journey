#include <string>
#include <iostream>
#include <typeinfo>

int main(int argc, char const *argv[])
{
    std::string s = "abc";
    std::cout << typeid(s).name() << std::endl;
    std::cout << typeid(s[0]).name() << std::endl;
    std::cout << typeid(s.substr(0, 1)).name() << std::endl;
    return 0;
}
