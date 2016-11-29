#include <iostream>
#include <thread>
#include <mutex>
#include <cstring>

std::mutex mu;

void printMessage(std::string msg, int id)
{
	mu.lock();
	std::cout << msg << id << std::endl;
	mu.unlock();
}

void func_1(void)
{
	for (int i = 0; i > -1000; i--)
	{
		printMessage("from t1 ", i);
	}
}

int main()
{	
	std::thread t1(func_1);
	
	for (int i = 0; i < 1000; i++){
		printMessage("from main ", i);
	}
	
	t1.join();

	return 0;
}
