#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

int main() {
    int choice, a, b;

    do {
        cout << "\nCalculator Menu\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        switch (choice) {
            case 1:
                cout << "Result = " << add(a, b) << endl;
                break;

            case 2:
                cout << "Result = " << subtract(a, b) << endl;
                break;

            case 3:
                cout << "Result = " << multiply(a, b) << endl;
                break;

            case 4:
                if (b != 0)
                    cout << "Result = " << divide(a, b) << endl;
                else
                    cout << "Division by zero is not possible." << endl;
                break;

            case 5:
                cout << "Exiting Calculator..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}