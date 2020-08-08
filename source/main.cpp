#include "stash.hpp"

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{   
    // Example with ints 
    Stash int_stash;
    int_stash.initialize(sizeof(int));

    for (int i = 0; i < 10; i++)
        int_stash.add(&i);

    for (int i = 0; i < int_stash.count(); i++)
        std::cout << "int_stash.fetch(" << i << ") = "
                  << *(int *)int_stash.fetch(i)
                  << std::endl;

    // Example with strings
    Stash string_stash;
    const int buf_size = 80;
    string_stash.initialize(sizeof(char) * buf_size);
    std::ifstream in("../source/main.cpp");
    std::string line;

    while(getline(in, line))
        string_stash.add(line.c_str());

    int k = 0;
    char *cp;

    while ((cp = (char *)string_stash.fetch(k++)) != 0)
        std::cout << "string_stash.fetch(" << k << ") = "
                  << cp << std::endl;

    int_stash.cleanup();
    string_stash.cleanup();

    return 0;
}
