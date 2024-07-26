#include <iostream>
#include <thread>

bool flag = true;
void beep(int timer)
{
    while (flag)
    {
        std::this_thread::sleep_for(std::chrono::seconds(timer));
        if (flag)
        {
            std::cout << "\a" << std::flush;
        }
    }
}

int main()
{
    std::cout << "Start: (Press Enter to stop)\n";
    int timer = 3;
    std::thread t1(beep, timer);
    std::cin.get(); // Wait for Enter key press
    flag = false;
    t1.join();
    return 0;
}