#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <utility>
#include <lib/lr1.h>
#include <string>


int main() {
    std::vector<float> arr = {12, 23, 45, -2222};
    Res output = checkAndTransform(arr);
    std::cout << "key: " << output.key << std::endl;
    std::cout << "key ind: " << output.key_index<< std::endl;
    return 0;
}