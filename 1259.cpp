#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int check_f(int n)
{
    stringstream s;
    s << n;
    string str = s.str();
    
    int start = 0;
    int end = str.length() - 1;
    
    while (start < end)
    {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main() {
    int N;
    
    while(1)
    {
        cin >> N;
        if (N == 0)
            break;
        if (check_f(N))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
        
    }
    return 0;
}