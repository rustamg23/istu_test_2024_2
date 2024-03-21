#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "functions.h"

using namespace std;

int main() {
    vector<float> arr = {10.1221, -14.14243, 15.11111, -20.543312, 21.64345, -25.75453, 30.46764};
    Res output = checkAndTransform(arr);
    cout << output.key << output.key_index;
    printArray(output.result);
    return 0;
}

