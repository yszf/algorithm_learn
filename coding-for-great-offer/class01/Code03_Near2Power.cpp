#include <cassert>
#include <iostream>

namespace class01 {

	/*
		题目：
		给定一个非负整数num，
		如何不用循环语句，
		返回>=num，并且离num最近的2的某次方
	*/

	/*
		解题思路：
		从最高位的1开始我不用管后面有几个1, 只要它最高的这个1跑完这一系列代码之后，后面全是1。
		效果就是从最高位的1开始后面全是1 , 哪怕你拥有最少数量的1, 你最高的只有一个1，跑完之后也会都弄满
		为啥-1, 如果n正好是2的某次方, 比如n=16,
		兼顾n正好是2的某次方
		如果N不是2的某次方这么搞正好够到自己最近的2的某次方，
		如果N正好是2的某次方方这么弄，正好够到自己。

		整形就32位, 所以只用做到16, 如果是long类型就再多一步
	*/

	class Code03_Near2Power {
	public:
		static int Process(int num) {
			assert(num >= 0);
			int n = num - 1;
			n |= n >> 1;
			n |= n >> 2;
			n |= n >> 4;
			n |= n >> 8;
			n |= n >> 16;
			return n < 0 ? 1 : n + 1;
		}
	};
}

int main() {
	int ans = class01::Code03_Near2Power::Process(120);
	std::cout << "ans = " << ans << std::endl;

	return 0;
}