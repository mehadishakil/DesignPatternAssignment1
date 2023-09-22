// Virtual Kingdom with  ->   singleton design pattern

#include <iostream>
using namespace std;

// king class
class King
{

    // private variable and constructor
private:
    static King *instance;
    string nameOfKing;

    // Private constructor so that no objects can be created.
    King()
    {
        nameOfKing = "Salman Bin Abdul Aziz";
    }

    // public variable and function
public:
    static King *getInstance()
    {
        if (!instance)
            instance = new King;
        return instance;
    }

    string getName()
    {
        return nameOfKing;
    }

    void setName(string kName)
    {
        nameOfKing = kName;
    }
};

// Initialize pointer to zero so that it can be initialized in first call to getInstance
King *King::instance = 0;

// Display class to print some info
class Display
{

public:
    // dashboard function
    void Dashboard()
    {
        system("CLS");
        cout << "--------------------VIRTUAL KINGDOM--------------------\n\n";
        cout << "1. Who is the current king ?" << endl;
        cout << "2. Promote yourself to become a King " << endl;
        cout << "3. Exit" << endl;
        cout << "Choose your action: ";
    }
};

// main function
int main()
{

    // creating Display class object to display info by display class object
    Display *display = new Display();

    while (true)
    {

        display->Dashboard(); // calling Dashboard function
        int action;
        cin >> action;

        if (action == 1)
        {
            King *s = s->getInstance(); // getting instance of king class
            cout << "\n\n";
            cout << s->getName() << " is the current King of this Virtual Kingdom." << endl;
            cout << "\n\n";
            system("pause"); // system("pause"); -> to hold the screen
        }

        else if (action == 2)
        {
            King *s = s->getInstance();
            char ansDead, ansBattle, ansKing;
            string kName;

            // taking some input to check is he worthy to become a king or not
            cout << "\n\n\n\n";
            cout << "Is the previous king dead? (Y/N)\n";
            cin >> ansDead;

            cout << "Did he lose his kingdom to another king in battle? (Y/N)\n";
            cin >> ansBattle;

            cout << "Are you the king who defeated him? (Y/N)\n";
            cin >> ansKing;

            // convertting char input to uppercase
            ansDead = toupper(ansDead);
            ansBattle = toupper(ansBattle);
            ansKing = toupper(ansKing);

            if (ansDead == 'Y')
            {
                cout << "What is your name?\n";
                getline(cin >> ws, kName);

                cout << endl
                     << kName << " is the new King of this Virtual Kingdom.\n\n";
                s->setName(kName);
            }
            else if (ansDead == 'N' && ansBattle == 'Y' && ansKing == 'Y')
            {
                cout << "What is your name?\n";
                getline(cin >> ws, kName);

                cout << " \n"
                     << kName << " is the new King of this Virtual Kingdom.\n\n";
                s->setName(kName);
            }
            else if (ansDead == 'N' && ansBattle == 'N' && ansKing == 'N')
            {
                cout << " \n\n";
                cout << s->getName() << " is the current King of this Virtual Kingdom. \nNo one else will be able to be the king of this kingdom until he dies or lost his kingdom to another king in a war.\n\n";
            }
            else
            {
                cout << "Please press correct input.\n";
            }

            system("pause");
        }

        else if (action == 3)
            return 0;

        else
            cout << "Please, Enter a correct number for your action. ";
    }
}