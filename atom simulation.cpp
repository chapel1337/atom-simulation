#include <iostream>
#include <string>
#include <windows.h>

using std::cout; using std::cin; using std::string; using std::system;

// written by chapel1337
// made on 10/14/2022
// i'm not really proud nor disappointed in this, not entirely sure why i decided to make this
// instead of reading learncpp.com (which i will do right after this)
// somewhat mediocre program /shrug

int atomicNumber{ 1 };
int atomicMass{ 1 };
// bool status{ true }; // true = stable, false = unstable

// preset is a hydrogen atom
int neutrons{ 0 };
int protons{ 1 };
int electrons{ 1 };

// first 20, i am not writing every known element
string listOfElements[]{ "hydrogen", "helium", "lithium", "beryllium", "boron", "carbon", "nitrogen", "oxygen", "flourine", "neon", "sodium", "magnesium", "aluminum", "silicon", "phosphorus", "sulfur", "chlorine", "argon", "potassium", "calcium"};

// ------- \\

void returnTo(string returnFunction);

void clear()
{
    system("cls");
}

void sleep(auto time)
{
    Sleep(1000 * time);
}

void title(string title)
{
    std::system(("title " + title).c_str());
}

void quit()
{
    clear();
    title("atom simulation - quit");

    for (int i{ 3 }; i >= 1; i--)
    {
        cout << "okay, exiting in " << i;

        sleep(1);
        clear();
    }

    exit(1);
}

void invalidInput(string message, string returnFunction)
{
    clear();
    title("atom simulation - invalid input");

    cout << message;

    sleep(2);
    returnTo(returnFunction);
}

void displayInformation()
{
    clear();

    // silly
    if (atomicMass < 0)
    {
        atomicMass = 0;
    }
    else if (protons < 0)
    {
        protons = 0;
    }
    else if (neutrons < 0)
    {
        neutrons = 0;
    }
    else if (electrons < 0)
    {
        electrons = 0;
    }
    else if (electrons < 0)
    {
        electrons = 0;
    }

    atomicMass = protons + neutrons;

    cout << "atomic mass: " << atomicMass << '\n';

    cout << "element: ";
    if (protons == 0) cout << "unknown\n";
    else cout << listOfElements[protons - 1] << '\n';

    cout << "atomic number: " << protons << '\n';

    // cout << "status: ";
    // (status) ? cout << "stable\n" : cout << "unstable\n"; // spooky ternary (it's october, so i had to use it)

    cout << '\n';
}

// ------- \\

void decayMenu()
{
    title("atom simulation - radioactive decay menu");
    displayInformation();

    char response{};

    cout << "1. alpha decay\n";
    cout << "2. beta decay\n";
    cout << "3. gamma decay\n";
    cout << "4. back\n";

    cin >> response;

    switch (response)
    {
    case '1':
        protons -= 2;
        neutrons -= 2;
        break;

    case '2':
        protons++;
        neutrons++;
        break;

    case '3':
        // :coffin:
        break;

    case '4':
        returnTo("menu");
        break;

    default:
        invalidInput("invalid input: please specify 1, 2, 3, or 4", "decayMenu");
        break;
    }

    decayMenu();
}

// ------- \\

void menu()
{
    title("atom simulation - menu");
    displayInformation();

    char response{};

    cout << '\n';
    cout << "1. add a proton\n";
    cout << "2. add a neutron\n";
    cout << "3. add an electron\n\n";

    cout << "4. remove a proton\n";
    cout << "5. remove a neutron\n";
    cout << "6. remove an electron\n\n";

    cout << "7. radioactive decay menu\n";
    cout << "8. quit\n\n";

    cout << "> ";
    cin >> response;

    switch (response)
    {
    case '1':
        protons++;
        break;

    case '2':
        neutrons++;
        break;

    case '3':
        electrons++;
        break;

    case '4':
        protons--;
        break;

    case '5':
        neutrons--;
        break;

    case '6':
        electrons--;
        break;

    case '7':
        decayMenu();
        break;

    case '8':
        quit();
        break;

    default:
        invalidInput("invalid input: please specify 1, 2, 3, 4, 5, 6, 7, or 8", "menu");
        break;
    }

    menu();
}

// ------- \\

void returnTo(string returnFunction)
{
    if (returnFunction == "menu")
    {
        menu();
    }
    else if (returnFunction == "decayMenu")
    {
        decayMenu();
    }
}

int main()
{
    title("atom simulation - credits");

    cout << "written by chapel1337\n";
    cout << "made on 10/14/2022\n";
    
    // sleep(2);
    menu();
}

// ------- \\