#include<iostream>
#include<mutex>
#include<thread>
#include<vector>

using namespace std;

int counter = 0;
std::mutex mtx;

void func() {
	for(int i = 0; i < 10000; ++i) {
		mtx.lock();
		++counter;
		mtx.unlock();
	}
}

int main() {
	auto threads = std::vector<std::thread>(10);

	for(auto &v : threads) {
		v = std::thread(func);
	}	

	for(auto &th : threads) {
		th.join();
	}

	cout << counter << endl;

	return 0;
}
