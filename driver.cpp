//Quinn Joseph Contaldi
//02/22/23
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#define AMOUNTOFNUM 8
using namespace std;
void readTxtFile(string, int);
void addHex(unsigned long long int, unsigned long long int);
void subtractHex(unsigned long long int, unsigned long long int);
void displayDefault();
void displayError();
int main(int argc, char *argv[])
{
    //checks if the user enetered the accompaning file
    if (argc == 1)
    {
        displayError();
        cout << "please use the following format: " << argv[0] << " hexNum" << endl;
        return 0;
    }
    if (argc == 2)
    {
    
    int menuOption, hex1, hex2;
        do
        {
            cout << "0: exit the program" << endl;
            cout << "1: Add Hex Numbers" << endl;
            cout << "2: Subtract Hex Numbers" << endl;
            cout << "User Input: ";
            cin >> menuOption;
            switch(menuOption)
            {
                case 1:
                    {
                        readTxtFile(argv[1],1);
                    }
                    break;
                case 2:
                    {
                        readTxtFile(argv[1],2);
                    }
                    break;
                case 0:
                    {
                        return 0;
                    }
                    break;
                default:
                    {
                        displayDefault();
                    }
            }
        } 
        while (menuOption == 0);
    }
return 0;
}

void readTxtFile(string fname, int controler)
{
    unsigned long long int dec1, dec2,counter = 0;
    string hex1, hex2;
//declares the input stream of the file
    ifstream fin (fname.c_str());
//if the file is open the program proceds with the operation
    if(fin.is_open())
    {
        while(!fin.eof())
        {       
//stores the hex values as strings
            fin >> hex1;
            dec1 = stoll(hex1,0,16);
//converts the hex values into decimal
            fin >> hex2;
            dec2 = stoll(hex2,0,16);
//determines to add or subtract and can be expanded to hold other arthmetic operations
            switch(controler)
            {
                case 1:
                    addHex(dec1,dec2);
                    break;
                case 2:
                    subtractHex(dec1,dec2);
                    break;
            }
        }
    }
    else
    {
       cout << "Sorry cannot open your file!" << endl;
    }
    fin.close();
}

void addHex(unsigned long long int hex1, unsigned long long int hex2)
{
    unsigned long long int hexSum;
    hexSum = hex1 + hex2;
    cout << "Hex Addition: ";
    cout << hex << hexSum << endl;
}

void subtractHex(unsigned long long int hex1,  unsigned long long int hex2)
{
    unsigned long long int hexSum;
    hexSum = hex1 - hex2;
    cout << "Hex SUbtraction: ";
    cout << hex << hexSum << endl;
}

void displayDefault()
{
cout << R"(
⣿⡟⠙⠛⠋⠩⠭⣉⡛⢛⠫⠭⠄⠒⠄⠄⠄⠈⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⡇⠄⠄⠄⠄⣠⠖⠋⣀⡤⠄⠒⠄⠄⠄⠄⠄⠄⠄⠄⠄⣈⡭⠭⠄⠄⠄⠉⠙
⣿⡇⠄⠄⢀⣞⣡⠴⠚⠁⠄⠄⢀⠠⠄⠄⠄⠄⠄⠄⠄⠉⠄⠄⠄⠄⠄⠄⠄⠄
⣿⡇⠄⡴⠁⡜⣵⢗⢀⠄⢠⡔⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⣿⡇⡜⠄⡜⠄⠄⠄⠉⣠⠋⠠⠄⢀⡄⠄⠄⣠⣆⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸
⣿⠸⠄⡼⠄⠄⠄⠄⢰⠁⠄⠄⠄⠈⣀⣠⣬⣭⣛⠄⠁⠄⡄⠄⠄⠄⠄⠄⢀⣿
⣏⠄⢀⠁⠄⠄⠄⠄⠇⢀⣠⣴⣶⣿⣿⣿⣿⣿⣿⡇⠄⠄⡇⠄⠄⠄⠄⢀⣾⣿
⣿⣸⠈⠄⠄⠰⠾⠴⢾⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⢁⣾⢀⠁⠄⠄⠄⢠⢸⣿⣿
⣿⣿⣆⠄⠆⠄⣦⣶⣦⣌⣿⣿⣿⣿⣷⣋⣀⣈⠙⠛⡛⠌⠄⠄⠄⠄⢸⢸⣿⣿
⣿⣿⣿⠄⠄⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠈⠄⠄⠄⠄⠄⠈⢸⣿⣿
⣿⣿⣿⠄⠄⠄⠘⣿⣿⣿⡆⢀⣈⣉⢉⣿⣿⣯⣄⡄⠄⠄⠄⠄⠄⠄⠄⠈⣿⣿
⣿⣿⡟⡜⠄⠄⠄⠄⠙⠿⣿⣧⣽⣍⣾⣿⠿⠛⠁⠄⠄⠄⠄⠄⠄⠄⠄⠃⢿⣿
⣿⡿⠰⠄⠄⠄⠄⠄⠄⠄⠄⠈⠉⠩⠔⠒⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠐⠘⣿
⣿⠃⠃⠄⠄⠄⠄⠄⠄⣀⢀⠄⠄⡀⡀⢀⣤⣴⣤⣤⣀⣀⠄⠄⠄⠄⠄⠄⠁⢹
NYAAAA WRONG CHOICE PEWASE CHOOOSE WIGHT NEXT TIME :3)";
}

void displayError()
{
cout << R"(
⠀⢀⣴⣾⣿⣿⣿⣷⣦⡄⠀⣴⣾⣿⣿⣿⣿⣶⣄⠀⠀
⣰⣿⣿⣿⣿⣿⣿⣿⠋⢠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣌⠛⣿⣿⣿⣿⣿⣿⣿⣿⡆
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢁⣼⣿⣿⣿⣿⣿⣿⣿⣿⠁
⠸⣿⣿⣿⣿⣿⣿⣿⡟⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀
⠀⠙⣿⣿⣿⣿⣿⣿⣄⠻⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀
⠀⠀⠈⠻⣿⣿⣿⣿⣿⣧⡈⢿⣿⣿⣿⣿⡟⠁⠀⠀⠀
⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⡇⢸⣿⣿⠟⠉⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⠙⢿⡿⠀⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀
This Error almost hurt me as much as she did ;-;)";
}