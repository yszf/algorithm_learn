#pragma once

#include <algorithm>
#include <ctime>
#include <cassert>

namespace Utils {

	int Max(int a, int b) {
		return a > b ? a : b;
	}

	void SRandom() {
		srand((unsigned int)time(nullptr));
	}

	// ȡ�� [0, x)֮����������
	int Random(int n) {
		assert(n > 0);
		return rand() % n;
	}

	// ȡ�� [x, y]֮����������
	int Random(int left, int right) {
		assert(left > 0 && left < right);
		return (rand() % (right - left + 1)) + left;
	}

	template<typename T>
	T GetRandom(T min, T max) {
		static std::default_random_engine engine(static_cast<UINT32>(time(NULL)));
		if (min < max) {
			std::uniform_int_distribution<T> dis(min, max);
			return dis(engine);
		}
		else {
			std::uniform_int_distribution<T> dis(max, min);
			return dis(engine);
		}
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


