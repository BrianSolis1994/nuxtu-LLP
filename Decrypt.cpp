#include <iostream>
#include <sstream>
#include <gmpxx.h>

using namespace std;

int main(int argc, char **argv)
{
    mpz_t _c;
    unsigned long int d, n;
    mpz_inits(_c, NULL);
    unsigned char decrypt;
    string text, numero;
    cout << "Welcome to the decrypt program, please enter the text to decrypt: \r\n";
    getline(cin, text);
    cout << "Now enter the private key value: \r\n";
    cin >> d;
    cout << "Finally, enter the value of n: \r\n";
    cin >> n;
    stringstream input_stringstream(text);
    unsigned int buffer[100];
    int i = 0;
    while (getline(input_stringstream, numero, ','))
    {
        buffer[i] = stoi(numero);
        i++;
    }
    i = 0;
    while (buffer[i])
    {
        mpz_ui_pow_ui(_c, buffer[i], d);
        mpz_mod_ui(_c, _c, n);
        if (mpz_get_ui(_c) != 27)
        {
            decrypt = mpz_get_ui(_c) + 64;
        }
        else
        {
            decrypt = 32;
        }
        if((decrypt > 64)&&(decrypt < 91)||(decrypt == 32))
         cout<< (decrypt);
        i++;
    }
    return 0;
}
