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
		// ��������
		static int MaxPoint0(std::vector<int> arr, int L) {
			int max = 0;
			for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
				int pre = i - 1;
				while (pre >= 0 && arr[i] - arr[pre] <= L) {
					pre--;
				}
				max = Utils::Max(max, i - pre);
			}
			return max;
		}

		// L�����ӵĳ���
		static int MaxPoint1(std::vector<int> arr, int L) {
			int res = 0;
			for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
				int nearest = NearestIndex(arr, i, arr[i] - L);
				res = Utils::Max(res, i - nearest + 1);
			}
			return res;
		}

		static int MaxPoint2(std::vector<int> arr, int L) {
			int left, right;
			left = right = 0;
			int N = static_cast<int>(arr.size());
			int max = 0;
			while (left < N) {
				while (right < N && arr[right] - arr[left] <= L) {
					right++;
				}
				max = Utils::Max(max, right - (left++));
			}
			return max;
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

int main01() {
	int len = 100;
	int max = 1000;
	int test_times = 10000;
	std::cout << "���Կ�ʼ" << std::endl;
	Utils::SRandom();
	for (int i = 0; i < test_times; ++i) {
		int L = Utils::Random(max);
		std::vector<int> arr = Utils::GenerateArray(len, max);
		int ans0 = Class01::Code01_CordCoverMaxPoint::MaxPoint0(arr, L);
		int ans1 = Class01::Code01_CordCoverMaxPoint::MaxPoint1(arr, L);
		int ans2 = Class01::Code01_CordCoverMaxPoint::MaxPoint2(arr, L);
		if (ans0 != ans1 || ans1 != ans2) {
			std::cout << "error!" << std::endl;
			break;
		}
	}
	std::cout << "����ͨ��" << std::endl;

	return 0;
}