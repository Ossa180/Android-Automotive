#include <iostream>

class Car
{
    private:
        std::string company;
        std::string model;
        int year;
    public:
        void setCompany(std::string c)
        {
            company = c;
        }
        void setModel(std::string m)
        {
            model = m;
        }
        void setYear(int y)
        {
            year = y;
        }
        std::string getCompany()
        {
            return company;
        }
        std::string getModel()
        {
            return model;
        }
        int getYear()
        {
            return year;
        }
};

int main()
{
    Car car1;
    car1.setCompany("Opel");
    car1.setModel("Astra");
    car1.setYear(2018);
    std::cout << "Car 1: " << car1.getCompany() << " " << car1.getModel() << " " << car1.getYear() << std::endl;

    return 0;
}