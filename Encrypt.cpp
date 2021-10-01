
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
using std::pow;

long last_p_number=13, last_q_number=17;

long get_prime_number_p();
long get_prime_number_q();
long reset_q();

int main()
{
    bool pareja_encontrada= false;
    long e, n, d, p=13, q=17;
    long c;
    long producto, phi;
    cout << "Welcome to the encrypt program \r\n"<< "Please enter the value of n: \r\n";
    cin >> n;
    cout << "Now enter the value of e: \r\n";
    cin >> e;
    while (pareja_encontrada == false)
    {
        producto = p * q;
        cout << p << "\t x \t" << q << " = " << p * q << "\r\n";
        if ((p >= n) || (q >= n))
        {
            cout << "No es posible factorizar el valor digitado"
                 << "\r\n";
            break;
        }
        else if ((producto != n) && (producto < n))
        {
            q = get_prime_number_q();
        }
        else if ((producto != n) && (producto > n))
        {
            p = get_prime_number_p();
            q = reset_q();
        }
        else if (producto == n)
        {
            pareja_encontrada = true;
        }
   }

    //Hasta aqui todo bien
    phi=((p-1)*(q-1));
    cout << phi << "\r\n";
    if ((e > 1) && (e < phi) && (phi % e != 0))
    {
        d = (2 * phi + 1) / e;
   }
   else
   {

   }
   cout << d << "\r\n";
   c=pow(16,e);//Apartir de aquí crear el diccionario e incriptar 16 = P
   c=c % n;
   cout << c << "\r\n";
}

long get_prime_number_p()
{
    long divisor = 0;
    bool prime_number = false;
    while(prime_number == false)
    {
        last_p_number++;
        divisor = 0;
        for (int i = 1; i <= last_p_number; i++)
        {
            if((last_p_number % i)==0)
            {
                divisor++;
            }
        }
        if(divisor == 2)
        {
            prime_number=true;
        }
    }
    return last_p_number;
}

long get_prime_number_q()
{
    long divisor = 0;
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

long reset_q()
{
    last_q_number=17;
    return last_q_number;
}
