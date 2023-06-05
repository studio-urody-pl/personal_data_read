//reads personal data stored in a file
#include <iostream>
#include <stdlib.h> // exit
#include <fstream> //file management

using namespace std;

string name, surname;
int phone_no;

int main()
{

    fstream file;
    file.open("personal_card.txt", ios::in); //read file

    if (file.good()== false) // true if exist false if not
    {
        cout<<"File doesn't exist!";
        exit(0);
    }

    string line;
    int line_no=1;

    while(getline(file, line))
    {
        switch (line_no)
        {
            case 1: name = line;
                break;
            case 2: surname = line;
                break;
            case 3: phone_no = ::atoi(line.c_str());
        }
        line_no++;
    }

    file << name << endl;
    file << surname << endl;
    file << phone_no << endl;

    file.close(); // close file

    cout<<name<<endl;
    cout<<surname<<endl;
    cout<<phone_no<<endl;

    return 0;
}