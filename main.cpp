#include "string.h"
#include <iostream>

#include <string>

int main()
{
        String a, b;

        a = "hello ";
        b = "world";

        std::cout << "a = " << a << ", b = " << b << '\n';

        std::cout << "a + b = " << a + b << '\n';

        a.swap(b);

        std::cout << "After swap: a = " << a << ", b = " << b << '\n';

        a.append(b);

        std::cout << "After appending: a = " << a << ", b = " << b << '\n';

        int index = a.find_first_of('o');

        std::cout << "First index of 'o' in a is: " << index << '\n';

        return 0;
}

