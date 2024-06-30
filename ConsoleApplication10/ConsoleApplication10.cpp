#include <iostream>
using namespace std;

int main()

{
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Sum23: " << a * b << endl;

    cerr << "This is an error message." << endl;

    clog << "Log information." << endl;

    return 0;
}
//////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int main()
 {
    string fullName;

    cout << "Enter your external name: ";

    getline(cin, fullName);

    cout << "Your outside name: " << fullName << std::endl;

    return 0;
}


////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
 {
    string phrase;
    cout << "Enter a phrase: ";
    getline(std::cin, phrase);

    string result;


    for (char ch : phrase)
    {
        if (ch == '!')
        {
            result += '$';
        } else if (ch != '#')
         {
            result += ch;
         }

    }

    cout << "Modified phrase: " << result << endl;

    return 0;
}
