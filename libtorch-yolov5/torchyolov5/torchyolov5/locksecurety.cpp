#include <iostream>
#include <mutex>
#include <thread> 
using namespace std;


int g_i = 0;
std::mutex g_i_mutex;  // protects g_i   
void safe_increment()
{
   // std::lock_guard<std::mutex> lock(g_i_mutex);
    for (int i=0;i<30;++i)
    {
    ++g_i;
    printf("g_i =%d \n", g_i);
    } 
   
    // g_i_mutex is automatically released when lock     
    // goes out of scope 
}

int main_lock()
{
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);
    t1.join();
    t2.join();
    system("pause");
    return 0;
}
