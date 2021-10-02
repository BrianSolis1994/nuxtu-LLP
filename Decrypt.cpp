#include <iostream>
#include <sstream>
#include <gmpxx.h>

using namespace std;

int main(int argc, char **argv)
{

    /*
    mpz_t a, b, c, d;
    mpz_inits(a, b, c, d,NULL);

    mpz_set_str(a, "3", 10);
    mpz_set_str(b, "221", 10); //Decimal base

    mpz_ui_pow_ui(c, 152, 77);
    mpz_mod(d, c, b);
    cout << "\nThe exact result is:";
    mpz_out_str(stdout, 10, d); //Stream, numerical base, var
    cout << endl;
*/

    mpz_t _c, _n, _d;
    mpz_inits(_c, _n, _d, NULL);
    unsigned char decrypt;
    string text, numero;
    getline(cin, text);
    stringstream input_stringstream(text);
    unsigned int buffer[10];
    int i = 0;
    while (getline(input_stringstream, numero, ','))
    {
        cout << "Un valor: " << stoi(numero) << endl;
        buffer[i] = stoi(numero);
        i++;
    }
    i = 0;
    while (buffer[i])
    {
        mpz_ui_pow_ui(_c, buffer[i], 77);
        mpz_mod_ui(_c, _c, 221);
        if (mpz_get_ui(_c) != 27)
        {
            decrypt = mpz_get_ui(_c) + 64;
        }
        else
        {
            decrypt = 32;
        }
        cout << "The exact result is: " << (decrypt) << "\r\n";
        i++;
    }
    return 0;
}
