#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function Declarations
void registerUser();
void loginUser();

int main()
{
    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << " LOGIN & REGISTRATION SYSTEM\n";
        cout << "=================================\n";

        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            loginUser();
            break;

        case 3:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}

// Function to register a new user
void registerUser()
{
    string enteredUsername, enteredPassword;
    string storedUsername, storedPassword;

    // Taking user input
    cout << "\nEnter Username : ";
    cin >> enteredUsername;

    cout << "Enter Password : ";
    cin >> enteredPassword;

    // Open file for reading
    ifstream readFile("users.txt");

    // Check if username already exists
    while (readFile >> storedUsername >> storedPassword)
    {
        if (enteredUsername == storedUsername)
        {
            cout << "\nUsername already exists!\n";
            readFile.close();
            return;
        }
    }

    readFile.close();

    // Open file in append mode
    ofstream writeFile("users.txt", ios::app);

    // Write username and password to the file
    writeFile << enteredUsername << " " << enteredPassword << endl;

    writeFile.close();

    cout << "\nRegistration Successful!\n";
}

// Function to login an existing user
void loginUser()
{
    string enteredUsername, enteredPassword;
    string storedUsername, storedPassword;

    // Taking user input
    cout << "\nEnter Username : ";
    cin >> enteredUsername;

    cout << "Enter Password : ";
    cin >> enteredPassword;

    // Open file for reading
    ifstream readFile("users.txt");

    // Check every username and password
    while (readFile >> storedUsername >> storedPassword)
    {
        if (enteredUsername == storedUsername &&
            enteredPassword == storedPassword)
        {
            cout << "\nLogin Successful!\n";
            cout << "Welcome, " << enteredUsername << "!\n";

            readFile.close();
            return;
        }
    }

    readFile.close();

    cout << "\nInvalid Username or Password!\n";
}