#include <iostream>
#include <string>
#include <fstream>

#include "saves.hpp"

using namespace std;

Saves::Saves(){
    /* costructor */
}
Saves::~Saves(){
    /* destrucor */
}
void Saves::inputPath()
{
    bool pathOk = false;
    while(pathOk != true){
        string path;
        cout << "Filepath:";
        cin >> path;

        this->path = path;

        ifstream fin(path.c_str());

        if (!fin.is_open()){
            cout << "Can't open file! Try again?(y/n)";
            string answ;
            while(answ != "n" || answ != "y"){
                cout << "Wrong command!" << endl;
                cout << "Try again(y/n):";
                cin >> answ;
            }
            if(answ == "n"){
                break;
            }
        }else{
            pathOk = true;
        }
    }
    if(pathOk != true){
        cout << "File " << this->path << " isn't opened!" << endl;
        this->path = "";
    }
}
