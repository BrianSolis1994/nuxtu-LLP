#include <iostream>
#include <gmpxx.h>

using namespace std;

int main(int argc, char **argv)
{

    mpz_t a, b, c, d;
    mpz_inits(a, b, c, d,NULL);

    mpz_set_str(a, "3", 10);
    mpz_set_str(b, "221", 10); //Decimal base

    mpz_ui_pow_ui(c, 152, 77);
    mpz_mod(d, c, b);
    cout << "\nThe exact result is:";
    mpz_out_str(stdout, 10, d); //Stream, numerical base, var
    cout << endl;

    return 0;
}
