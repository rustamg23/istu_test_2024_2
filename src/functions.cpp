#include "functions.h"
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

Res checkAndTransform(vector<float>& array) {
    Res output;
    
    if (array.size() > 1024) {
        output.errors.push_back("!!! The maximum length of the array has been exceeded !!!");
    } else if (array.size() == 0) {
        output.errors.push_back("!!! Array is empty !!!");
    } else {
        output.result = array;
        for (int i = 0; i < array.size(); i++) {
            if (abs(array[i]) < output.max){
                output.errors.push_back("!!! Stack Overflow !!!");
            } else {
                int product = calculateDigitsProduct(static_cast<int>(array[i]));
                if (product > static_cast<int>(array[i])) {
                    output.key = array[i];
                    output.key_index = i;
                    cout << "The product of the digits of the first number is greater than or equal to the number itself: " << array[i] << ". Index: " << i << endl;
                    // Transform array if condition is met
                    for (float& num : array) {
                        num = (num > 0) ? num * num : num;
                    }
                    output.result = array;
                }
            }
        }
        return output;
    }
}

void printArray(const vector<float>& arr) {
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;
}