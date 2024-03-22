#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <utility>
#include <lib/lr1.h>
#include <string>


int main() {
    std::vector<float> arr = read_file("./data/path10r156.txt");
    Res output = checkAndTransform(arr);
    std::cout << "key: " << output.key << std::endl;
    std::cout << "key ind: " << output.key_index<< std::endl;
    write_file(output.result, "./data/path10r156res.txt" );
    return 0;
}