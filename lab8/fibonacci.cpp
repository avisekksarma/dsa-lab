#include <iostream>

using namespace std;

int fibo(int term)
{
    if (term == 1)
        return 0;
    else if (term == 2)
        return 1;
    return fibo(term - 2) + fibo(term - 1);
}
int fibo_loop(unsigned int term)
{
    int a = 0, b = 1, sum;
    if (term == 1)
        return 0;
    else if (term == 2)
        return 1;
    for (int i = 3; i <= term; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int fibo_tail(unsigned int term, int a = 0, int b = 1)
{
    if (term == 1)
    {
        return a;
    }
    else if (term == 2)
    {
        return b;
    }
    return fibo_tail(term - 1, b, a + b);
}
int main()
{
    int n;
    cout << "Enter the term: ";
    cin >> n;
    cout << "Fibonacci of term - " << n << " is: " << fibo(n) << endl;
    cout << "Fibonacci of term - " << n << " is: " << fibo_loop(n) << endl;
    cout << "Fibonacci of term - " << n << " is: " << fibo_tail(n) << endl;

    return 0;
}