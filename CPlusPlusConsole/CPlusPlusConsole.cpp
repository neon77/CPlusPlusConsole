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

struct a1{};
struct a2{};
struct a3{};
struct a4{};

template<class X> struct baseC{
	baseC(int a) { printf("baseC primary ctor: %d\n", a); }
};
template<> struct baseC<a1>{
	baseC(int a) { printf("baseC a1 ctor: %d\n", a); }
};
template<> struct baseC<a2>{
	baseC(int a) { printf("baseC a2 ctor: %d\n", a); }
};
template<> struct baseC<a3>{
	baseC(int a) { printf("baseC a3 ctor: %d\n", a); }
};
template<> struct baseC<a4>{
	baseC(int a) { printf("baseC a4 ctor: %d\n", a); }
};

template<class...A> struct container : public baseC<A>...{
	container() : baseC<A>(12)...{
		printf("container ctor\n");
	}
};

void test_variadic_template_member_initializer_list()
{
	container<a1, a2, a3, a4> test;
}

void print(std::forward_list<int>& flist)
{
	for (auto value : flist)
	{
		std::cout << value << std::endl;
	}

	std::cout << std::endl;
}

void test_foward_list_07()
{
	std::cout << "flist1" << std::endl;
	std::forward_list< int > flist1;
	flist1.push_front(5);
	flist1.push_front(7);
	flist1.push_front(6);
	print(flist1);

	std::cout << "flist2" << std::endl;
	std::forward_list< int > flist2;
	flist2.push_front(3);
	flist2.push_front(2);
	flist2.push_front(8);
	print(flist2);

	std::cout << "flist1.splice_after(flist1.begin(), flist2 )" << std::endl;
	flist1.splice_after(flist1.begin(), flist2);
	print(flist1);


	std::cout << "flist3" << std::endl;
	std::forward_list< int > flist3;
	flist3.push_front(15);
	flist3.push_front(17);
	flist3.push_front(16);
	print(flist3);

	std::cout << "flist4" << std::endl;
	std::forward_list< int > flist4;
	flist4.push_front(13);
	flist4.push_front(12);
	flist4.push_front(18);
	print(flist4);

	std::cout << "flist3.splice_after(flist3.begin(), flist4, flist4.begin() )" << std::endl;
	flist3.splice_after(flist3.begin(), flist4, flist4.begin());
	print(flist3);


	std::cout << "flist5" << std::endl;
	std::forward_list< int > flist5;
	flist5.push_front(25);
	flist5.push_front(27);
	flist5.push_front(26);
	print(flist5);

	std::cout << "flist6" << std::endl;
	std::forward_list< int > flist6;
	flist6.push_front(23);
	flist6.push_front(22);
	flist6.push_front(28);
	print(flist6);

	std::cout << "flist5.splice_after(flist5.begin(), flist6, flist6.begin(), flist6.end() )" << std::endl;
	flist5.splice_after(flist5.begin(), flist6, flist6.begin(), flist6.end());
	print(flist5);
}

//------------------------------------------------------------------------------
/**
	output : 0 1 0 1 0 1 0 1 0 1
	i 값에 따라 처음이 false, true 반복
*/
void test_bitwise()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::setw(2);
		std::cout << std::to_string(i & 1);
	}
	std::cout << std::endl;
}

void test_typeinfo()
{
	std::cout << typeid(int).name() << std::endl;
	std::cout << typeid(int).raw_name() << std::endl;
	std::cout << sizeof(typeid(int).hash_code()) << std::endl;
}

void test_c_array()
{
	int a[3] = { 0, 1, 2 };
	int* b = new int(3);
	b[0] = 3;
	*(b + 1) = 4;
//	b[1] = 4;
	b[2] = 5;
}

void test_unordered_map_erase()
{
	std::unordered_map<int, std::string> c = { { 1, "one" }, { 2, "two" }, { 3, "three" },
	{ 4, "four" }, { 5, "five" }, { 6, "six" } };
	// erase all odd numbers from c
	for (auto it = c.begin(); it != c.end();)
		if (it->first % 2 == 1)
			it = c.erase(it);
		else
			++it;
	for (auto& p : c)
		std::cout << p.second << ' ';
}

void test_type_index()
{
	struct A {
		virtual ~A() {}
	};

	struct B : A {};
	struct C : A {};

	std::unordered_map<std::type_index, std::string> type_names;

	auto& intypeinfo = typeid(int);
	std::string inttypename = intypeinfo.name();
	type_names[std::type_index(typeid(int))] = "int";
	type_names[std::type_index(typeid(double))] = "double";
	type_names[std::type_index(typeid(A))] = "A";
	type_names[std::type_index(typeid(B))] = "B";
	type_names[std::type_index(typeid(C))] = "C";

	int i = 0;
	double d = 0;
	A a;

	// note that we're storing pointer to type A
	std::unique_ptr<A> b(new B);
	std::unique_ptr<A> c(new C);

	std::cout << "i is " << type_names[std::type_index(typeid(i))] << '\n';
	std::cout << "d is " << type_names[std::type_index(typeid(d))] << '\n';
	std::cout << "a is " << type_names[std::type_index(typeid(a))] << '\n';
	std::cout << "b is " << type_names[std::type_index(typeid(*b))] << '\n';
	std::cout << "c is " << type_names[std::type_index(typeid(*c))] << '\n';
}

/*
int _tmain(int argc, _TCHAR* argv[])
{
//	ModTest();
//	selectminteamindextest();
//	test_nullptr();
//	test_variadic_template_member_initializer_list();
//	test_foward_list_07();
//	test_bitwise();
//	test_typeinfo();
//	test_c_array();
//	test_unordered_map_erase();
	test_type_index();
	::system("pause");
	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
	// Wait until main() sends data
	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk, []{return ready; });

	// after the wait, we own the lock.
	std::cout << "Worker thread is processing data\n";
	data += " after processing";

	// Send data back to main()
	processed = true;
	std::cout << "Worker thread signals data processing completed\n";

	// Manual unlocking is done before notifying, to avoid waking up
	// the waiting thread only to block again (see notify_one for details)
	lk.unlock();
	cv.notify_one();
}

int main()
{
	std::thread worker(worker_thread);

	data = "Example data";
	// send data to the worker thread
	{
		std::lock_guard<std::mutex> lk(m);
		ready = true;
		std::cout << "main() signals data ready for processing\n";
	}
	cv.notify_one();

	// wait for the worker
	{
		std::unique_lock<std::mutex> lk(m);
		cv.wait(lk, []{return processed; });
	}
	std::cout << "Back in main(), data = " << data << '\n';

	worker.join();

	system("pause");
}
*/

#include <string>
#include <iostream>

class Actor {
public:
	Actor(const char* name) : slapped_(false), name_(name) {}
	virtual ~Actor() {}
	virtual void update() = 0;
	void reset() { slapped_ = false; }
	void slap() {
		slapped_ = true;
	}
	bool wasSlapped() { return slapped_; }
	const std::string& name() const { return name_; }

private:
	bool slapped_;
	std::string name_;
};

class Stage {
public:
	void add(Actor* actor, int index) {
		actors_[index] = actor;
	}
	void update() {
		for (int i = 0; i < NUM_ACTORS; ++i) {
			std::cout << "Stage updates actor " << i << " (" << actors_[i]->name() << ")\r\n";
			actors_[i]->update();
			actors_[i]->reset();
		}
		std::cout << "Stage updates ends\r\n";
	}

private:
	static const int NUM_ACTORS = 3;
	Actor* actors_[NUM_ACTORS];
};

class Comedian : public Actor {
public:
	Comedian(const char* name) : Actor(name) {}
	void face(Actor* actor) { facing_ = actor; }
	virtual void update() {
		if (wasSlapped()) {
			std::cout << "  " << name() << " was slapped, so he slaps " << facing_->name() << std::endl;
			facing_->slap();
		}
		else {
			std::cout << "  " << name() << " was not slapped, so he does nothing\r\n";
		}
	}
private:
	Actor* facing_;
};

/*
int _tmain(int argc, _TCHAR* argv[]) {
	Stage stage;
	Comedian* harry = new Comedian("Harry");
	Comedian* baldy = new Comedian("Baldy");
	Comedian* chump = new Comedian("Chump");

	harry->face(baldy);
	baldy->face(chump);
	chump->face(harry);

	stage.add(harry, 2);
	stage.add(baldy, 1);
	stage.add(chump, 0);

	harry->slap();
	stage.update();
	stage.update();
	stage.update();
	stage.update();
	stage.update();

	int temp = 0;
	std::cin >> temp;

	return 0;
}
*/

//------------------------------------------------------------------------------
/**
	* 2017-06-16 : sbyang
	bit shift 연산이 data type을 넘어가는 경우 처리 확인
	이전에 C 책에서 본 내용인데 기억이 안나서 확인
*/
void BitShiftMaxLimitTest(int shiftstart, int shiftmax)
{
	uint64_t affinitymask = 1;
	for (int i = shiftstart; i < shiftmax; i++)
	{
		affinitymask = 1i64 << i;
		std::cout << std::setw(2) << i << ' ' << std::setw(21) << affinitymask;
		bool newline = (0 < i) && 0 == ((i + 1) % 5);
		if (true == newline)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << "  ";
		}
	}
	std::cout << "\n\n";
}

int _tmain(int argc, _TCHAR* argv[]) {

	BitShiftMaxLimitTest(0 , 64);

	BitShiftMaxLimitTest(64, 68);

	system("pause");

	return 0;
}
/* output
0                     1   1                     2   2                     4   3                     8   4                    16
5                    32   6                    64   7                   128   8                   256   9                   512
10                  1024  11                  2048  12                  4096  13                  8192  14                 16384
15                 32768  16                 65536  17                131072  18                262144  19                524288
20               1048576  21               2097152  22               4194304  23               8388608  24              16777216
25              33554432  26              67108864  27             134217728  28             268435456  29             536870912
30            1073741824  31            2147483648  32            4294967296  33            8589934592  34           17179869184
35           34359738368  36           68719476736  37          137438953472  38          274877906944  39          549755813888
40         1099511627776  41         2199023255552  42         4398046511104  43         8796093022208  44        17592186044416
45        35184372088832  46        70368744177664  47       140737488355328  48       281474976710656  49       562949953421312
50      1125899906842624  51      2251799813685248  52      4503599627370496  53      9007199254740992  54     18014398509481984
55     36028797018963968  56     72057594037927936  57    144115188075855872  58    288230376151711744  59    576460752303423488
60   1152921504606846976  61   2305843009213693952  62   4611686018427387904  63   9223372036854775808

64                     1  65                     2  66                     4  67                     8
*/