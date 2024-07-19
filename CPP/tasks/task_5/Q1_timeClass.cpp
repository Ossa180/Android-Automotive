#include <iostream>

class time_c
{
private:
    int hours, minutes, seconds;

public:
    time_c() : hours{}, minutes{}, seconds{} {}
    time_c(int h, int m, int s) : hours{h}, minutes{m}, seconds{s} {}
    void display() const
    {
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
    void add_time_c(const time_c &t1, const time_c &t2)
    {
        seconds = t1.seconds + t2.seconds;
        minutes = t1.minutes + t2.minutes + seconds / 60;
        hours = t1.hours + t2.hours + minutes / 60;
        seconds %= 60;
        minutes %= 60;
    }
};

int main()
{
    time_c t1{2, 45, 30};
    time_c t2{3, 30, 50};
    time_c t3;

    t3.add_time_c(t1, t2);
    t1.display();
    t2.display();
    t3.display();

    return 0;
}