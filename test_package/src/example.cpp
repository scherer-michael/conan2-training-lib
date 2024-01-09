#include "trainingLib.h"

#include <vector>
#include <string>

int main() {
    trainingLib();

    std::vector<std::string> vec;
    vec.push_back("test_package");

    trainingLib_print_vector(vec);
}
