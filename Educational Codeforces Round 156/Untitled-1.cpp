#include <iostream>
#include <iomanip>

int main() {
    double number = 3.14159265;

    // Set precision to 2 decimal places
    std::streamsize oldPrecision = std::cout.precision(5);

    // Print the double value
    std::cout << number << std::endl;

    // Restore the old precision
    // std::cout.precision(oldPrecision);

    return 0;
}
