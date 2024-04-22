#include <memory>
#include <locale>
#include "sum.cpp"
#include "subtraction.cpp"
#include "multiplication.cpp"
#include "division.cpp"

int main()
{
    std::shared_ptr<sum> _sum = std::make_shared<sum>();
    std::shared_ptr<subtraction> _subtraction = std::make_shared<subtraction>();
    std::shared_ptr<multiplication> _multiplication = std::make_shared<multiplication>();
    std::shared_ptr<division> _division = std::make_shared<division>();
    float number1, number2, result;
    std::string operation, yes_no;
    bool calculator_on_off{true};

    while (calculator_on_off == true)
    {
        int menu;
        bool valid_operation{false};
        yes_no = "";
        std::cout << "***** Calculator *****" << std::endl;

        std::cout << "Insert the first number:\n";
        std::cin >> number1;

        while (valid_operation == false)
        {
            std::cout << "Insert the operation that you want to do(Example-> + ; - ; x ; /):\n";
            std::cin >> operation;
            if (operation == "+" || operation == "-" || operation == "x" || operation == "/")
            {
                valid_operation = true;
            }
        }

        std::cout << "Insert the second number:\n";
        std::cin >> number2;
        if (operation == "+")
        {
            result = _sum->sum_numbers(number1, number2);
        }
        else if (operation == "-")
        {
            result = _subtraction->subtraction_numbers(number1, number2);
        }
        else if (operation == "x")
        {
            result = _multiplication->multiplication_numbers(number1, number2);
        }
        else if (operation == "/")
        {
            result = _division->division_numbers(number1, number2);
        }

        std::cout << "\nResult-> " << result << "\n"
                  << std::endl;

        while (yes_no != "yes" && yes_no != "no")
        {
            std::cout << "Do you want to do a new operation?\nType yes or no: ";
            std::cin >> yes_no;
            if (yes_no != "yes" && yes_no != "no")
            {
                std::cout << "Please write a valid anwser!";
            }
            else if (yes_no == "no")
            {
                calculator_on_off = false;
            }
        }

        system("cls");
    }

    return 0;
}