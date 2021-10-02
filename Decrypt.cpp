#include <iostream>
#include <string.h>
#include <gmpxx.h>

using namespace std;
using std::to_string;
using std::stoi;

int main()
{
    unsigned long n, d;
    string message, n_str, d_str;

    mpz_t _c, _n, _d;
    mpz_inits(_c, _n, _d, NULL);

    cout << "Welcome to the decript program, please enter the encript: \r\n";
    cin >> message;
    cout << "Now enter the value of n: \r\n";
    cin >> n;
    cout << "Finally enter the value of d (private key): \r\n";
    cin >> d;

    long message_int = stoi(message);

    mpz_ui_pow_ui(_c, message_int, d);
    mpz_mod_ui(_c, _c, n);
    unsigned char decrypt = mpz_get_ui(_c) +64;
    cout << "The exact result is:" << (decrypt) << "\r\n";
}