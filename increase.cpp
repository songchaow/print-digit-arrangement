// increase.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <fstream>
#include<stdio.h>
#include <cmath>
#include <vector>
#define jingzi 10 
constexpr auto MAX_VALUE = jingzi;
constexpr auto PLACE_HOLDER = -1;
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

	int candidate = 1;
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
			ar[increase_index] = 1;
			increase_index--;
			if (increase_index < 0)
				return false;
			candidate = ar[increase_index] + 1;
		}


	}


}


struct zhe {
	int a[jingzi];
};
zhe extra, sa, sb, ta, tb;
int d(int a, int b) {
	if (a > b)
		return(a - b);
	else
		return(b - a);
}

int DD(int* a, int* b) {
	int i, j = 0;
	for (i = 0; i < jingzi; i++)
	{
		if (d(a[i], b[i]) > j)
			j = d(a[i], b[i]);
	}
	return j;
}

void jiafa(zhe n) {
	int i;
	extra = n;
	extra.a[0]++;
	for (i = 0; i < jingzi; i++) {
		if (extra.a[i] >= jingzi) {
			extra.a[i + 1]++;
			extra.a[i] = extra.a[i] - jingzi;
		}
	}
}

int comp(zhe a, zhe b) {
	int i;
	for (i = jingzi - 1; i > -1; i--) {
		if (a.a[i] > b.a[i])return 1;
		if (a.a[i] < b.a[i])return -1;
	}
	return 0;
}

int same(zhe a) {
	int i, j;
	for (i = 0; i < jingzi - 1; i++)
		for (j = i + 1; j < jingzi; j++) {
			if (a.a[i] == a.a[j])
				return 0;
		}
	return 1;
}

// arr: array of r elements' positions, note that position values begin with 1.
int distance2array(int* arr, int r, std::vector<int> &selected_el)
{
	int min_abs = jingzi; // any big value
	// Part I of the array
	for (int row = 1; row <= jingzi; row++)
	{
		int max_abs = 0;
		for (int i = 0; i < r; i++)
		{
			int arr_value = (row + arr[i] - 1 - 1) % jingzi + 1;
			int curr_abs = std::abs(selected_el[i] - arr_value);
			if (curr_abs > max_abs)
				max_abs = curr_abs;
		}
		if (min_abs > max_abs)
			min_abs = max_abs;
	}
	// Part II of the array
	for (int row = 1; row <= jingzi; row++)
	{
		int max_abs = 0;
		for (int i = 0; i < r; i++)
		{
			int arr_value = (jingzi + row - 2 - arr[i] + 1) % jingzi + 1;
			int curr_abs = std::abs(selected_el[i] - arr_value);
			if (curr_abs > max_abs)
				max_abs = curr_abs;
		}
		if (min_abs > max_abs)
			min_abs = max_abs;
	}

	return min_abs;
}

int main()
{
	int D[2 * jingzi][jingzi];
	int i, j, l = 0, s, k = jingzi;
	l = jingzi - std::ceil(std::sqrt(jingzi + 3));
	int r = 2*jingzi - 2*l - 2;
	std::vector<int> selected_elements;
	for (int i = 1; i <= r / 2; i++)
	{
		selected_elements.push_back(i);
		selected_elements.push_back(jingzi - i + 1);
	}
	// initial positions for r elements. Only first 4 positions will be occupied
	int ar[20];
	// arrangement of total jingzi elements
	int ar_dist[20];
	for (int i = 0; i <= r - 1; i++)
		ar[i] = i + 1;
	increase(ar, r, true);
	//// construct ar_dist according to ar
	//for (int i = 0; i < jingzi; i++)
	//	ar_dist[i] = 0;
	//for (int i = 0; i < r; i++)
	//	ar_dist[ar[i]] = i;
	int max_distance = distance2array(ar,r,selected_elements);
	while (increase(ar, r, false))
	{
		int distance = distance2array(ar, r, selected_elements);
		if (max_distance < distance)
			max_distance = distance;
	}
	std::cout << "max distance: " << max_distance;


	return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
