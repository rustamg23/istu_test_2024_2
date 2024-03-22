#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <sstream>
#include <utility>
#include <lib/lr1.h>

std::vector<float> read_file(std::string path) {
    std::vector<float> res;
    std::ifstream file_in(path);
    if (!file_in){

    }
    float number;
    while (file_in >> number) {
        res.push_back(number);
    }
    file_in.close();
    return res;
}

void write_file(std::vector<float> data, std::string path) {
    // Открываем файл для записи
    std::ofstream file_out(path);

    // Если не удалось открыть файл, выводим сообщение об ошибке
    if (!file_out) {
        std::cerr << "Unable to open file: " << path << std::endl;
        return;
    }

    // Стираем содержимое файла
    file_out.clear();

    // Записываем данные из вектора в файл, каждое значение на отдельной строке
    for (float value : data) {
        file_out << value << std::endl;
    }

    // Закрываем файл
    file_out.close();
}


int main() {
    std::vector<float> arr = read_file("./data/path10r156.txt");
    Res output = checkAndTransform(arr);
    std::cout << "key: " << output.key << std::endl;
    std::cout << "key ind: " << output.key_index<< std::endl;
    write_file(output.result, "./data/path10r156res.txt" );
    return 0;
}