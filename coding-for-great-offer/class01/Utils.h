#pragma once

#include <algorithm>
#include <ctime>

namespace Utils {

	int Max(int a, int b) {
		return a > b ? a : b;
	}

	// ȡ�� [0, x)֮����������
	int Random(int x) {
		srand((unsigned int)time(nullptr));
		return rand() % x;
	}

	// ȡ�� [x, y]֮����������
	int Random(int x, int y) {
		srand((unsigned int)time(nullptr));
		return (rand() % (y - x + 1)) + x;
	}

	std::vector<int> GenerateArray(int len, int max) {
		std::vector<int> arr;
		for (int i = 0; i < len; ++i) {
			arr.push_back(Random(max));
		}
		std::sort(arr.begin(), arr.end());
		return arr;
	} 
}


