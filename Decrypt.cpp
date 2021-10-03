#include <iostream>
#include <sstream>
#include <gmpxx.h>

using namespace std;

class Decrypt
{
private:
    mpz_t c;
    unsigned long int d, n;
    int i = 0;
    unsigned char decrypt;
    string text;
    string number;
    string decode_text;
    unsigned int buffer[100];

public:
    /**
	 * Constructor
	 * @brief This function method create a obj
     * 
	 * @param _message	String with encode message, the string has numbers separate with commas.
	 * @param _n	    Number semi-prime 
	 * @param _d	    private key
	 */
    Decrypt(string _message, unsigned long int _n, unsigned long int _d);

    /**
	 * start decryption once the constructor method is called
	 */
    void init();

    /**
     * @brief: This method return the string with decode text
     * 
     * @return string
     */
    string get_decode_text();

    /**
     * @brief: This method clean the string with decode text
     * 
     * @return void
     */
    void reset_decode_text();
};

/**
	 * Constructor
	 * @brief This function method create a obj
     * 
	 * @param _message	String with encode message, the string has numbers separate with commas.
	 * @param _n	    Number semi-prime 
	 * @param _d	    private key
	 */
Decrypt::Decrypt(string _message, unsigned long int _n, unsigned long int _d)
{
    this->n = _n;
    this->d = _d;
    this->text = _message;
}

/**
	 * start decryption once the constructor method is called
	 */
void Decrypt::init()
{
    mpz_inits(c, NULL);
    stringstream input_stringstream(text);
    unsigned int buffer[100];
    i = 0;
    while (getline(input_stringstream, number, ','))
    {
        buffer[i] = stoi(number);
        i++;
    }
    i = 0;
    while (buffer[i])
    {
        mpz_ui_pow_ui(c, buffer[i], d);
        mpz_mod_ui(c, c, n);
        if (mpz_get_ui(c) != 27)
        {
            decrypt = mpz_get_ui(c) + 64;
            if ((decrypt > 64) && (decrypt < 91))
            {
                decode_text.append(1, decrypt);
            }
        }
        else if (mpz_get_ui(c) == 27)
        {
            decrypt = 32;
            decode_text.append(1, decrypt);
        }
        i++;
    }
}

/**
     * @brief: This method return the string with decode text
     * 
     * @return string
     */
string Decrypt::get_decode_text()
{
    return this->decode_text;
}

    /**
     * @brief: This method clean the string with decode text
     * 
     * @return void
     */
void Decrypt::reset_decode_text()
{
    decode_text.clear();
}

int main()
{
    unsigned long int d, n;
    string text;
    cout << "Welcome to the decrypt program, please enter the text to decrypt: \r\n";
    getline(cin, text);
    cout << "Now enter the private key value: \r\n";
    cin >> d;
    cout << "Finally, enter the value of n: \r\n";
    cin >> n;
    Decrypt message(text, n, d);
    message.reset_decode_text();
    message.init();
    cout << message.get_decode_text();
    return 0;
}