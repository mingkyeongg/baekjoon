#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int count = 0;
    
    getline(cin, str, '#');
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            count++;
        else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
            count++;
        else if (str[i] == '\n')
        {
            cout << count << '\n';
            count = 0;
        }
    }
    return 0;
}