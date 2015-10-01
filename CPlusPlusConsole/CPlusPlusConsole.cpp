// CPlusPlusConsole.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void ModTest()
{
	int maxteam = 3;
	int teamindex = 0;
	for (int i = 0; i < 9; i++)
	{
		teamindex = (i + maxteam) % maxteam;
		std::cout << "i[" << i << "] : team[ " << teamindex << " ]" << std::endl;
	}
}

void selectminteamindextest()
{
	std::multimap<int, int> selectminteam;
	selectminteam.insert(std::make_pair(10, 0));
	selectminteam.insert(std::make_pair(12, 1));
	selectminteam.insert(std::make_pair(10, 2));
	std::cout << "headcount : " << (*selectminteam.begin()).first << ", teamindex : " << (*selectminteam.begin()).second << std::endl;
}

void test_nullptr()
{
	size_t nullptrsize = sizeof(nullptr);
	std::cout << typeid(nullptr).name() << std::endl;
	std::cout << typeid(nullptr).raw_name() << std::endl;
	std::cout << typeid(nullptr).hash_code() << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
//	ModTest();
//	selectminteamindextest();
	test_nullptr();
	::system("pause");
	return 0;
}