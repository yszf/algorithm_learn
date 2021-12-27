#include <vector>
#include <iostream>
#include "Utils.h"

namespace Class01 {

	/*
		����һ����������arr������������X���ϵĵ�
		����һ������K���������ӵĳ���
		�����������ѹ�м����㣿
		��ʹ���ӱ�Ե����ס��Ҳ���ס
	*/

	class Code01_CordCoverMaxPoint {
	public:
		// L�����ӵĳ���
		static int MaxPoint1(std::vector<int> arr, int L) {
			int res = 0;
			for (size_t i = 0; i < arr.size(); ++i) {
				int nearest = NearestIndex(arr, i, arr[i] - L);
				res = Utils::Max(res, i - nearest + 1);
			}
			return res;
		}
		// R��������±꣬��Ϊ���ӵ�ĩβ
		// ���ֲ��Ҿ�value���������Ԫ���±�
		static int NearestIndex(std::vector<int> arr, int R, int value) {
			int L = 0;
			int index = R;
			while (L <= R) {
				int mid = L + ((R - L) >> 1);
				if (arr[mid] >= value) {
					index = mid;
					R = mid - 1;
				}
				else {
					L = mid + 1;
				}
			}
			return index;
		}
	};
}

//int main() {
//	std::vector<int> arr{ 1, 2, 4, 5, 6, 9, 10, 12, 17 };
//	int L = 4;
//
//	int ans = Class01::Code01_CordCoverMaxPoint::MaxPoint1(arr, 4);
//
//	std::cout << "res = " << ans << std::endl;
//
//	return 0;
//}


int main() {
	int len = 100;
	int max = 1000;
	int test_times = 10;
	std::cout << "���Կ�ʼ" << std::endl;
	Utils::SRandom();
	for (int i = 0; i < test_times; ++i) {
		int L = Utils::Random(max);
		std::vector<int> arr = Utils::GenerateArray(len, max);
		int ans1 = Class01::Code01_CordCoverMaxPoint::MaxPoint1(arr, L);
		std::cout << "ans1 = " << ans1 << std::endl;
	}

	return 0;
}