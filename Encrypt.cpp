
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;
using std::pow;

class Encrypt
{
private:
    long last_p_number = 13, last_q_number = 17;
    string message;
    unsigned long c;
    unsigned long d;
    unsigned long e;
    unsigned long n;
    unsigned long p = last_p_number;
    unsigned long q = last_q_number;
    unsigned long product;
    unsigned long phi;

    unsigned long get_next_prime_number_p();
    unsigned long get_next_prime_number_q();
    unsigned long get_p_value();
    unsigned long get_q_value();
    void reset_q();
    void calculation_p_q();
    void calculation_phi_d();

public:
    Encrypt(string _message, unsigned long _n, unsigned long _e);
    void init_encrypt();
    void print_encrypt_code();
};

Encrypt::Encrypt(string _message, unsigned long _n, unsigned long _e)
{
    this->message = _message;
    this->n = _n;
    this->e = _e;
}

unsigned long Encrypt::get_next_prime_number_p()
{
    long divisor = 0;
    bool prime_number = false;
    while (prime_number == false)
    {
        last_p_number++;
        divisor = 0;
        for (int i = 1; i <= last_p_number; i++)
        {
            if ((last_p_number % i) == 0)
            {
                divisor++;
            }
        }
        if (divisor == 2)
        {
            prime_number = true;
        }
    }
    return last_p_number;
}

unsigned long Encrypt::get_next_prime_number_q()
{
    int divisor = 0;
    bool prime_number = false;
    while (prime_number == false)
    {
        last_q_number++;
        divisor = 0;
        for (int i = 1; i <= last_q_number; i++)
        {
            if ((last_q_number % i) == 0)
            {
                divisor++;
            }
        }
        if (divisor == 2)
        {
            prime_number = true;
        }
    }
    return last_q_number;
}
void Encrypt::reset_q()
{
    last_q_number = 17;
    q = last_p_number;
}

void Encrypt::calculation_p_q()
{
    bool calculation = false;
    while (calculation == false)
    {
        product = p * q;
        if ((p >= n) || (q >= n))
        {
            cout << "The value of n is invalid, closing the program."<< "\r\n";
            exit(-1);
            break;
        }
        else if ((product != n) && (product < n))
        {
            q = get_next_prime_number_q();
        }
        else if ((product != n) && (product > n))
        {
            p = get_next_prime_number_p();
            reset_q();
        }
        else if (product == n)
        {
            calculation = true;
        }
    }
}

unsigned long Encrypt::get_p_value()
{
    return p;
}

unsigned long Encrypt::get_q_value()
{
    return q;
}

void Encrypt::calculation_phi_d()
{
    phi = ((p - 1) * (q - 1));
    if ((e > 1) && (e < phi) && (phi % e != 0))
    {
        d = (2 * phi + 1) / e;
    }
    else
    {
        cout << "The value of e is invalid, closing the program."
             << "\r\n";
        exit(-1);
    }
}

void Encrypt::print_encrypt_code()
{
    int ascii_to_table_value;
    for (int i = 0; i < message.size(); i++)
    {
        if (message[i] == 32)
        {
            ascii_to_table_value = 27;
        }
        else
        {
            ascii_to_table_value = message[i] - 64;
        }
        c = pow(ascii_to_table_value, e);
        c = c % n;
        cout << c << ",";
    }
}

void Encrypt::init_encrypt()
{
    calculation_p_q();
    calculation_phi_d();
}

int main()
{
    string text;
    unsigned long e, n;
    cout << "Welcome to the encrypt program, please enter the text to encrypt: \r\n";
    getline(cin, text);
    cout << "Now enter the value of n: \r\n";
    cin >> n;
    cout << "Finally enter the value of e: \r\n";
    cin >> e;
    Encrypt message(text, n, e);
    message.init_encrypt();
    message.print_encrypt_code();
}