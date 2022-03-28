//FCAI – Programming 1 – 2022 - Assignment 2 
// Program Name: PolybiusSquare_20210406.cpp
// Program Description:encryption and decryption program which each letter is replaced by two numbers 
// Last Modification Date: 22/3/2022
// Author and ID and Group: 20210406, A
// Teaching Assistant:

#include <iostream>
#include <string>
using namespace std;

int encryption(char array[6][6], string encry_text);
int decryption(char array[6][6], string decry_text);


int main()
{
    char array[6][6] = { {0,'1','2','3','4','5'},
                         {'1','A','B','C','D','E'},
                         {'2','F','G','H','I','K'},
                         {'3','L','M','N','O','P'},
                         {'4','Q','R','S','T','U'},
                         {'5','V','W','X','Y','Z'} };

    string encry_text;
    int mode;
    string decry_text;

    //for checking if the entered input valid or not
    while (true)
    {
        cout << " please choose a number: \n 1- encryption \n 2- decryption \n :  ";
        cin >> mode;



        //calling the encryption function
        if (mode == 1)
        {
            cout << " please enter your encryption text: ";
            cin.ignore();
            getline(cin, encry_text, '\n');
            encryption(array, encry_text);
            break;
        }



        //caling the decryption function 
        if (mode == 2)
        {
            cout << " please enter your decryption text without spaces: ";
            cin >> decry_text;
            decryption(array, decry_text);
            break;
        }

        else
        {
            cout << " please enter a valid input!" << endl;
            continue;
        }
    }
}




//function to encrypt user's text 
int encryption(char array[6][6], string encry_text)
{

    //for reciving the cipher's keys 
    cout << " please enter your keys (must be 5 numbers): ";
    for (int s = 1; s < 6; s++)
    {
        cin >> array[0][s];
        array[s][0] = array[0][s];
    }


    //for looping over the user's text and extracting the required keys for each alphabet
    cout << " the encryprd text: ";
    for (int n = 0; n < encry_text.length(); n++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                encry_text[n] = toupper(encry_text[n]);
                if (encry_text[n] == 'I' or encry_text[n] == 'J')
                {
                    array[2][4] = encry_text[n];
                }
                if (encry_text[n] == array[i][j])
                {
                    cout << array[i][0] << array[0][j];
                }
            }
        }
    }
    cout << endl;
    cout << endl;


    //for printing the cipher table
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




//function to decrypt user's text
int decryption(char array[6][6], string decry_text)
{

    //for reciving the cipher's keys 
    cout << " please enter your keys (must be 5 numbers): ";
    for (int s = 1; s < 6; s++)
    {
        cin >> array[0][s];
        array[s][0] = array[0][s];
    }


    //for looping over the decryption's text to replace each two nubers with the sutiable alphabet
    cout << " the decryptioned text: ";
    for (int n = 0; n < decry_text.length(); n += 2)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (decry_text[n] == 'J')
                {
                    decry_text[n] = 'I';
                }
                if (decry_text[n] == array[i][0] and decry_text[n + 1] == array[0][j])
                {
                    cout << array[i][j];
                }
            }
        }
    }
    cout << endl;
    cout << endl;


    //for printing the cipher table
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}