#pragma once

#include <vector>
#include <limits>
#include <cmath>

struct Res
{
	float key;
    int key_index;
	std::vector<float> result;
	float max = sqrt(std::numeric_limits<float>::max());
	std::vector<std::string> errors;
};
// Объявление функций для тестирования
int calculateDigitsProduct(int num);
Res checkAndTransform(std::vector<float>& array);

