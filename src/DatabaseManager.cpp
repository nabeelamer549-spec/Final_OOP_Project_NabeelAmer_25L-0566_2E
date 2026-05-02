#include "DatabaseManager.h"
#include <fstream>
#include <iostream>
#include <string>

void DatabaseManager::readfile(string fname)
{
    ifstream file(fname);
    if (file.is_open())
    {
        while (getline(file, str))
        {
            cout << str << endl;
        }
    }
    else
    {
        cout << "Error opening file!" << endl;
    }
}
void DatabaseManager::writefile(string fname, string nstr)
{
    str = nstr;
    ofstream file(fname);
    if (file.is_open())
    {
        file << str << endl;
    }
    else
    {
        cout << "Error opening file!" << endl;
    }
}
