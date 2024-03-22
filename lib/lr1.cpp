#include "lr1.h"
#include <iostream>
#include <cmath>
#include <limits>
using std::vector;

using namespace std;

int calculateDigitsProduct(int num) {
    num = abs(num);
    int product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

Res checkAndTransform(std::vector<float>& array) {
    Res output;
    output.key = 1;
    output.key_index = -1;
    output.max = sqrt(std::numeric_limits<float>::max());
    if (array.size() > 1024) {
        std::cout<<array.size();
        output.errors.push_back("oversize");
        return output;
    } else if (array.size() == 0) {
        output.errors.push_back("empty");
        return output;
    } else {
        output.result = array;
        for (int i = 0; i < array.size(); i++) {
            if (abs(array[i]) > output.max){
                output.errors.push_back("overflow");
                return output;
            } else {
                int product = calculateDigitsProduct(static_cast<int>(array[i]));
                std::cout << product << static_cast<int>(array[i]);
                if (product > static_cast<int>(array[i])) {
                    output.key = array[i];
                    output.key_index = i;
                    cout << "The product of the digits of the first number is greater than or equal to the number itself: " << array[i] << ". Index: " << i << endl;
                    // Transform array if condition is met
                    for (float& num : array) {
                        num = (num > 0) ? num * num : num;
                    }
                    output.result = array;
                    return output;
                }
            }
        }
        return output;
    }
}
