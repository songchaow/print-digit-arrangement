// increase.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>

constexpr auto MAX_VALUE = 20;
constexpr auto ARRAY_SIZE = 8;

/*
array数组中每个整型数的取值可以是0,1,...,max_value。
init用来指示，是否为第一次调用。（后续的调用，如果array数组就是上次的输出结果，就不用重新计算visited数组和increase_index）
*/
bool increase(int* ar, int arraysize, bool init = false)
{
	static bool visited[MAX_VALUE+1] = { false };
	static int increase_index = 0;
	bool completed = false;
	bool increased = false; // whether we have already increased one bit of array.
	// we don't need to increase when `init` is true.
	if (init)
	{
		// update `visited`.
		for (int i = 0; i <= MAX_VALUE; i++)
			visited[i] = false;
		increase_index = 0;
	}

	int candidate = 0;
	if (!increased && !init)
		candidate = ar[increase_index] + 1;
	else candidate = ar[increase_index];

	while (true)
	{
		if (candidate <= MAX_VALUE)
		{
			if (visited[candidate])
			{
				candidate++;
				continue;
			}
			else
			{
				// The candidate is OK
				if (!increased && !init)
					// we must also set previous value to false
					visited[ar[increase_index]] = false;
				ar[increase_index] = candidate;
				visited[candidate] = true;
				increased = true;
				if (increase_index < arraysize - 1)
				{
					increase_index++;
					candidate = ar[increase_index];
					continue;
				}
				else
					// we have found a suitable array state.
					return true;
			}
		}
		else
		{
			// if(!increased && !init) // always true, actually
			visited[ar[increase_index]] = false;
			ar[increase_index] = 0;
			increase_index--;
			if (increase_index < 0)
				return false;
			candidate = ar[increase_index] + 1;
		}


	}


}

//int main()
//{
//    std::cout << "Hello World!\n"; 
//	std::ofstream foutput("numbers.txt");
//	// construct initial array
//	int ar[ARRAY_SIZE] = { 0,1,2,3,4,5,6,7 };
//	increase(ar, ARRAY_SIZE, true);
//	for (int i = 0; i < 100000; i++)
//	{
//		for (int i = 0; i < ARRAY_SIZE; i++)
//		{
//			foutput << ar[i] << " ";
//		}
//		foutput << std::endl;
//		increase(ar, ARRAY_SIZE);
//	}
//
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
