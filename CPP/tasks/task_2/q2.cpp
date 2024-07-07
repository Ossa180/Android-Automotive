#include <iostream>


class Calaculator
{
    private:
        double num1;
        double num2;
        char operation;
    public:
        void setNum1(double n1)
        {
            num1 = n1;
        }
        void setNum2(double n2)
        {
            num2 = n2;
        }
        void setOperation(char op)
        {
            operation = op;
        }
        double calculate()
        {
            switch (operation)
            {
                case '+':
                    return num1 + num2;
                case '-':
                    return num1 - num2;
                case '*':
                    return num1 * num2;
                case '/':
                    return num1 / num2;
                default:
                    return 0;
            }
        }

    
};

int main()
{
    Calaculator calc;
    calc.setNum1(10);
    calc.setNum2(5);
    calc.setOperation('+');
    std::cout << "Result: " << calc.calculate() << std::endl;

    return 0;
}