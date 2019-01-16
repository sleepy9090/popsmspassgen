/**
 ************************************************************************************************************************
 *
 *  @file                   popsmspasgen.cpp
 *  @brief                  Prince of Persia password generator
 *                          for Sega Master System version
 *  @copyright              2019 Shawn M. Crawford
 *  @date                   January 16th, 2019
 *
 *  @remark Author:         Shawn M. Crawford
 *
 *  @note                   N/A
 *
 ************************************************************************************************************************
 */

/* Includes */
#include <iostream>
#include <sstream>

using namespace std;

/**
 ************************************************************************************************************************
 *
 * @brief   Encodes password
 *
 * @param   num The number to match to the cypher
 *
 * @return  The letter matched in the cyper or ? if not found
 *
 * @note 
 * Cypher
 * 0 = A
 * 1 = B
 * 2 = C
 * ...
 * ...
 * ...
 * 23 = X
 * 24 = Y
 * 25 = Z
 *
 ************************************************************************************************************************
 */
string encodePassword(int num)
{
    string result = "";

    switch (num)
    {
        case 0:
            result = "A";
            break;
        case 1:
            result = "B";
            break;
        case 2:
            result = "C";
            break;
        case 3:
            result = "D";
            break;
        case 4:
            result = "E";
            break;
        case 5:
            result = "F";
            break;
        case 6:
            result = "G";
            break;
        case 7:
            result = "H";
            break;
        case 8:
            result = "I";
            break;
        case 9:
            result = "J";
            break;
        case 10:
            result = "K";
            break;
        case 11:
            result = "L";
            break;
        case 12:
            result = "M";
            break;
        case 13:
            result = "N";
            break;
        case 14:
            result = "O";
            break;
        case 15:
            result = "P";
            break;
        case 16:
            result = "Q";
            break;
        case 17:
            result = "R";
            break;
        case 18:
            result = "S";
            break;
        case 19:
            result = "T";
            break;
        case 20:
            result = "U";
            break;
        case 21:
            result = "V";
            break;
        case 22:
            result = "W";
            break;
        case 23:
            result = "X";
            break;
        case 24:
            result = "Y";
            break;
        case 25:
            result = "Z";
            break;
        default:
            result = "?";
            cout << "  Got a value less than 0 or greater than 25. Should not happen. Password generation Failed." << endl;
    }
    return result;
}

/**
 ************************************************************************************************************************
 *
 * @brief   Runs the program
 *
 * @param   N/A
 *
 * @return  N/A
 *
 * @note    N/A
 *
 ************************************************************************************************************************
 */
int main (int argc, char *argv[])
{
    int level = 0;
    int health = 0;
    int time = 0;
    int digit1 = 0;
    int digit2 = 0;
    int digit3 = 0;
    int digit4 = 0;
    int digit5 = 0;
    int digit6 = 0;
    string pw1 = "";
    string pw2 = "";
    string pw3 = "";
    string pw4 = "";
    string pw5 = "";
    string pw6 = "";
    string input = "";

    cout << "Prince of Persia (Sega Master System) password generator v 1.0" << endl;
    cout << "Coded by: sleepy9090" << endl;
    cout << "======================================" << endl;
    cout << endl;

    while (true) {
        cout << "Enter level number (1..14): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> level)
        {
            if (level >= 1 && level <= 14)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Enter health amount (0..7): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> health)
        {
            if (health >= 0 && health <= 7)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    while (true) {
        cout << "Enter time left (0..99): ";
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> time)
        {
            if (time >= 0 && time <= 99)
            {
                break;
            }
        }
        
        cout << "Invalid number, please try again." << endl;
    }

    digit1 = level - 1;
    digit3 = time % 10;
    digit2 = (time - digit3) / 10;
    digit4 = health;
    digit5 = 0;
    digit6 = (10 + digit1 + digit2 + digit3 + digit4 + digit5) % 26;

    // cout << "Generated password before cipher: " << digit1 << digit2 << digit3 << digit4 << digit5 << digit6 << endl;

    pw1 = encodePassword(digit1);
    pw2 = encodePassword(digit2);
    pw3 = encodePassword(digit3);
    pw4 = encodePassword(digit4);
    pw5 = encodePassword(digit5);
    pw6 = encodePassword(digit6);

    cout << "Generated password: " << pw1 << pw2 << pw3 << pw4 << pw5 << pw6 << endl;
    return(0);
}

