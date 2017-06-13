// string::find_first_of
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <cstddef>
#include <typeinfo>
#include <cctype>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "figura.hpp"
#include "functions.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    string bufferStr;
    int bufferInt;
    double bufferDouble;
    string html = "";
    string filename;
    string info = "";
    int cmd;
    int cmdR;
    int cmdG;
    int cmdB;
    int cmdPictureSizeX, cmdPictureSizeY;
    double cmdA;
    string cmdS;
    int lvl = 1;
    int id = 0;
    int i;
    vector<Figura *>figuraList;
/**

    Metodes, kuras ir izmantotas.:

        figuraList.insert(figuraList.end(), new Taisnsturis(id)); //pielikt pie vectora jaunu elementu
        figuraList[0]->setKontursRGBA(3,3,3,1); //RGBA konturam
        figuraList[0]->setFonsRGBA(15,211,88,1); //RGBA fonam
        figuraList[0]->setCord(100,100); // figuras koordinates
        figuraList[0]->setMalas(5,15); //taisnstura malas
        figuraList[0]->setRad(5,15); //ovala radiusi
        figuraList[0]->setRad(5,15); //ovala radiusi
        figuraList[0]->addCords(int X, int Y); // jauni poligona punkti
        figuraList[0]->deleteLastCords(void); // dzest iepriekðçjo
        figuraList[0]->draw(); // izvadit info, ka string. izvada figuru HTML/SVG formatâ
        figuraList[0]->showData(); // izvada teksta informaciju par firguru
        figuraList[0]->rotate(45); // pagrieþ figuru pret figuras centru pa noteiktiem gradiem.

    */

        cout << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|Console rastragraphics editor        |" << endl;
        cout << "|Programmer Nikita Cunskis            |" << endl;
      ///  cout << "|Alberta Koledzas majasdarba ietvaros |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|1 - help;                            |" << endl;
        cout << "|2 - new figure;                      |" << endl;
        cout << "|3 - delete figure by id;             |" << endl;
        cout << "|4 - show all figures;                |" << endl;
        cout << "|5 - Save as;                         |" << endl;
        cout << "|0 - Exit                             |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << "|Copyright \xa9 2016                     |" << endl;
        cout << "+-------------------------------------+" << endl;
        cout << endl;


        while(lvl == 1){
        cout << "cmd>>";
        cin >> cmd;
        switch(cmd){

        case 1:
            cout << "+----HELP-----------------------------+" << endl;
            cout << "|1 - help;                            |" << endl;
            cout << "|2 - new figure;                      |" << endl;
            cout << "|3 - delete figure by id;             |" << endl;
            cout << "|4 - show all figures;                |" << endl;
            cout << "|5 - Save as;                         |" << endl;
            cout << "|0 - Exit                             |" << endl;
            cout << "+-------------------------------------+" << endl;
            break;
        case 2:
            lvl = 2;
            while(lvl == 2){
                cout << "  +---Create new object--------+" << endl;
                cout << "  |1 - help                    |" << endl;
                cout << "  |2 - rectangle               |" << endl;
                cout << "  |3 - Oval                    |" << endl;
                cout << "  |4 - polygon                 |" << endl;
                cout << "  |0 - back                    |" << endl;
                cout << "  +----------------------------+" << endl;
                cout << "  cmd>>";
                cin >> cmd;

                switch(cmd){
                    case 1:
                        cout << "  +----HELP--------------------+" << endl;
                        cout << "  |1 - help                    |" << endl;
                        cout << "  |2 - rectangle               |" << endl;
                        cout << "  |3 - Oval                    |" << endl;
                        cout << "  |4 - polygon                 |" << endl;
                        cout << "  |0 - back                    |" << endl;
                        cout << "  +----------------------------+" << endl;
                        break;
                    case 2:
                        figuraList.insert(figuraList.end(), new Taisnsturis(id));
                        id++;
                        cout << "  Rectangle ID: " << figuraList[figuraList.size() - 1]->returnId() << " created." << endl;
                        lvl = 3;
                        while(lvl == 3){
                            cout << "   +---Rectangle--------------+" << endl;
                            cout << "   |1 - help;                 |" << endl;
                            cout << "   |2 - contour;              |" << endl;
                            cout << "   |3 - background;           |" << endl;
                            cout << "   |4 - cords;                |" << endl;
                            cout << "   |5 - sides;                |" << endl;
                            cout << "   |6 - rotate;               |" << endl;
                            cout << "   |7 - show rectangle;       |" << endl;
                            cout << "   |0 - back                  |" << endl;
                            cout << "   +--------------------------+" << endl;
                            cout << "   cmd>>";
                            cin >> cmd;

                            switch(cmd){
                                case 1:
                                    cout << "   +---Rectangle--------------+" << endl;
                                    cout << "   |1 - help;                 |" << endl;
                                    cout << "   |2 - contour;              |" << endl;
                                    cout << "   |3 - background;           |" << endl;
                                    cout << "   |4 - cords;                |" << endl;
                                    cout << "   |5 - sides;                |" << endl;
                                    cout << "   |6 - rotate;               |" << endl;
                                    cout << "   |7 - show rectangle;       |" << endl;
                                    cout << "   |0 - back                  |" << endl;
                                    cout << "   +--------------------------+" << endl;
                                    break;
                                case 2:
									cout << "\n    Red value:";
                                    cin >> cmdR;
									cout << "\n    Green value:";
                                    cin >> cmdG;
                                    cout << "\n    Blue value:";
                                    cin >> cmdB;
									cout << "\n    Alpha value:";
                                    cin >> cmdA;
									figuraList[figuraList.size()-1]->setKontursRGBA(cmdR,cmdG,cmdB,cmdA);
									cout << "    RGBA(" << figuraList[figuraList.size()-1]->kontursR << ", " << figuraList[figuraList.size()-1]->kontursG << ", " << figuraList[figuraList.size()-1]->kontursB << ", " << figuraList[figuraList.size()-1]->kontursA << ") " << endl;
                                    break;
                                case 3:
									cout << "\n    Red value:";
                                    cin >> cmdR;
									cout << "\n    Green value:";
                                    cin >> cmdG;
                                    cout << "\n    Blue value:";
                                    cin >> cmdB;
									cout << "\n    Alpha value:";
                                    cin >> cmdA;
                                    figuraList[figuraList.size()-1]->setFonsRGBA(cmdR,cmdG,cmdB,cmdA);
                                    cout << "    RGBA(" << figuraList[figuraList.size()-1]->fonsR << ", " << figuraList[figuraList.size()-1]->fonsG << ", " << figuraList[figuraList.size()-1]->fonsB << ", " << figuraList[figuraList.size()-1]->fonsA << ") " << endl;
                                    break;
                                case 4:
                                    cout << "\n    X value:";
                                    cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                                    cout << "\n    Y value:";
                                    cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                                    figuraList[figuraList.size() - 1]->setCord(cmdR,cmdG);
                                    cout << "    X:" << figuraList[figuraList.size() - 1]->cordX << " Y:" << figuraList[figuraList.size() - 1]->cordY << endl;
                                    break;
                                case 5:
                                    cout << "\n    Horizontal:";
                                    cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                                    cout << "\n    Vertical:";
                                    cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                                    figuraList[figuraList.size() - 1]->setMalas(cmdR,cmdG);
                                    cout << "    Horizontal:" << figuraList[figuraList.size() - 1]->returnMalaA() << " Vertical:" << figuraList[figuraList.size() - 1]->returnMalaB() << endl;
                                    break;
                                case 6:
                                    cout << "    Degree:";
                                    cin >> cmd;
                                    figuraList[figuraList.size() - 1]->rotate(cmd);
                                    cout << "    Rectangle is rotated by " << figuraList[figuraList.size() - 1]->rotateDegree << " degree." << endl;
                                    break;
                                case 7:
                                    cout << figuraList[figuraList.size()-1]->showData() << endl;
                                    break;
                                case 0:
                                    lvl = 1;
                            }
                        }
                        break;
                    case 3:
                        figuraList.insert(figuraList.end(), new Ovals(id));
                        id++;
                        cout << "  Ovals ID: " << figuraList[figuraList.size() - 1]->returnId() << " created." << endl;
                        lvl = 3;
                        while(lvl == 3){
                            cout << "   +---Ovals------------------+" << endl;
                            cout << "   |1 - help;                 |" << endl;
                            cout << "   |2 - contour;              |" << endl;
                            cout << "   |3 - background;           |" << endl;
                            cout << "   |4 - redius;               |" << endl;
                            cout << "   |5 - sides;                |" << endl;
                            cout << "   |6 - rotate;               |" << endl;
                            cout << "   |7 - show oval;            |" << endl;
                            cout << "   |0 - back                  |" << endl;
                            cout << "   +--------------------------+" << endl;
                            cout << "cmd>>";
                            cin >> cmd;

                            switch(cmd){
                                case 1:
                                    cout << "   +---Ovals------------------+" << endl;
                                    cout << "   |1 - help;                 |" << endl;
                                    cout << "   |2 - contour;              |" << endl;
                                    cout << "   |3 - background;           |" << endl;
                                    cout << "   |4 - redius;               |" << endl;
                                    cout << "   |5 - sides;                |" << endl;
                                    cout << "   |6 - rotate;               |" << endl;
                                    cout << "   |7 - show oval;            |" << endl;
                                    cout << "   |0 - back                  |" << endl;
                                    cout << "   +--------------------------+" << endl;
                                    break;
                                case 2:
									cout << "\n    Red value:";
                                    cin >> cmdR;
									cout << "\n    Green value:";
                                    cin >> cmdG;
                                    cout << "\n    Blue value:";
                                    cin >> cmdB;
									cout << "\n    Alpha value:";
                                    cin >> cmdA;
									figuraList[figuraList.size()-1]->setKontursRGBA(cmdR,cmdG,cmdB,cmdA);
                                    cout << "    RGBA(" << figuraList[figuraList.size()-1]->kontursR << ", " << figuraList[figuraList.size()-1]->kontursG << ", " << figuraList[figuraList.size()-1]->kontursB << ", " << figuraList[figuraList.size()-1]->kontursA << ") " << endl;
                               break;
                                case 3:
                                    cout << "\n    Red value:";
                                    cin >> cmdR;
                                    cout << "\n    Green value:";
                                    cin >> cmdG;
                                    cout << "\n    Blue value:";
                                    cin >> cmdB;
                                    cout << "\n    Alpha value:";
                                    cin >> cmdA;
                                    figuraList[figuraList.size()-1]->setFonsRGBA(cmdR,cmdG,cmdB,cmdA);
                                    cout << "    RGBA(" << figuraList[figuraList.size()-1]->fonsR << ", " << figuraList[figuraList.size()-1]->fonsG << ", " << figuraList[figuraList.size()-1]->fonsB << ", " << figuraList[figuraList.size()-1]->fonsA << ") " << endl;
                                    break;
                                case 4:
                                    cout << "\n    X:";
                                    cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                                    cout << "\n    Y:";
                                    cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                                    figuraList[figuraList.size() - 1]->setCord(cmdR,cmdG);
                                    cout << "    X:" << figuraList[figuraList.size() - 1]->cordX << " Y:" << figuraList[figuraList.size() - 1]->cordY << endl;
                                    break;
                                case 5:
                                    cout << "\n    Radius A:";
                                    cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                                    cout << "\n    Radius B:";
                                    cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                                    figuraList[figuraList.size() - 1]->setRad1(cmdR);
                                    figuraList[figuraList.size() - 1]->setRad2(cmdG);
                                    cout << "    Radius A:" << figuraList[figuraList.size() - 1]->returnRad1() << " Radius B:" << figuraList[figuraList.size() - 1]->returnRad2() << endl;
                                    break;
                                case 6:
                                    cout << "    degree:";
                                    cin >> cmd;
                                    figuraList[figuraList.size() - 1]->rotate(cmd);
                                    cout << "    Oval is rotated by " << figuraList[figuraList.size() - 1]->rotateDegree << " degree." << endl;
                                    break;
                                case 7:
                                    cout << figuraList[figuraList.size()-1]->showData() << endl;
                                    break;
                                case 0:
                                    lvl = 1;
                            }
                        }
                        break;
                    case 4:
                        figuraList.insert(figuraList.end(), new Poligons(id));
                        id++;
                        cout << "  Polygon ID: " << figuraList[figuraList.size() - 1]->returnId() << " created." << endl;
                        lvl = 3;
                        while(lvl == 3){
                            cout << "    +---Polygon--------------------+" << endl;
                            cout << "    |1 - Help;                     |" << endl;
                            cout << "    |2 - contour;                  |" << endl;
                            cout << "    |3 - background;               |" << endl;
                            cout << "    |4 - cords;                    |" << endl;
                            cout << "    |5 - add new point;            |" << endl;
                            cout << "    |6 - rotate;                   |" << endl;
                            cout << "    |7 - show polygon;             |" << endl;
                            cout << "    |0 - back                      |" << endl;
                            cout << "    +------------------------------+" << endl;
                            cout << "cmd>>";
                            cin >> cmd;

                            switch(cmd){
                                case 1:
                                    cout << "    +---Poligons-------------------+" << endl;
                                    cout << "    |1 - Help;                     |" << endl;
                                    cout << "    |2 - contour;                  |" << endl;
                                    cout << "    |3 - background;               |" << endl;
                                    cout << "    |4 - cords;                    |" << endl;
                                    cout << "    |5 - add new point;            |" << endl;
                                    cout << "    |6 - rotate;                   |" << endl;
                                    cout << "    |7 - show polygon;             |" << endl;
                                    cout << "    |0 - back                      |" << endl;
                                    cout << "    +------------------------------+" << endl;
                                    break;
                                case 2:
									cout << "\n    Red value:";
                                    cin >> cmdR;
									cout << "\n    Green value:";
                                    cin >> cmdG;
                                    cout << "\n    Blue value:";
                                    cin >> cmdB;
									cout << "\n    Alpha value:";
                                    cin >> cmdA;
									figuraList[figuraList.size()-1]->setKontursRGBA(cmdR,cmdG,cmdB,cmdA);
                                    cout << "    RGBA(" << figuraList[figuraList.size()-1]->kontursR << ", " << figuraList[figuraList.size()-1]->kontursG << ", " << figuraList[figuraList.size()-1]->kontursB << ", " << figuraList[figuraList.size()-1]->kontursA << ") " << endl;
                                    break;
                                case 3:
                                    cout << "\n    Red value:";
                                    cin >> cmdR;
                                    cout << "\n    Green value:";
                                    cin >> cmdG;
                                    cout << "\n    Blue value:";
                                    cin >> cmdB;
                                    cout << "\n    Alpha value:";
                                    cin >> cmdA;
                                    figuraList[figuraList.size()-1]->setFonsRGBA(cmdR,cmdG,cmdB,cmdA);
                                    cout << "    RGBA(" << figuraList[figuraList.size()-1]->fonsR << ", " << figuraList[figuraList.size()-1]->fonsG << ", " << figuraList[figuraList.size()-1]->fonsB << ", " << figuraList[figuraList.size()-1]->fonsA << ") " << endl;
                                    break;
                                case 4:
                                    cout << "\n    X:";
                                    cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                                    cout << "\n    Y:";
                                    cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                                    figuraList[figuraList.size() - 1]->setCord(cmdR,cmdG);
                                    cout << "    X:" << figuraList[figuraList.size() - 1]->cordX << " Y:" << figuraList[figuraList.size() - 1]->cordY << endl;
                                    break;
                                case 5:
                                    lvl = 4;
                                    while(lvl == 4){
                                        cout << "      +---Polygon points-------------+" << endl;
                                        cout << "      |1 - help;                     |" << endl;
                                        cout << "      |2 - new point;                |" << endl;
                                        cout << "      |3 - delete previous;          |" << endl;
                                        cout << "      |0 - end point add;            |" << endl;
                                        cout << "      +------------------------------+" << endl;
                                        cout << "      cmd>>";
                                        cin >> cmd;

                                        switch(cmd){
                                            case 1:
                                                cout << "      +---Poligona punkti------------+" << endl;
                                                cout << "      |1 - help;                     |" << endl;
                                                cout << "      |2 - new point;                |" << endl;
                                                cout << "      |3 - delete previous;          |" << endl;
                                                cout << "      |0 - end point add;            |" << endl;
                                                cout << "      +------------------------------+" << endl;
                                                break;
                                            case 2:
                                                cout << "\n      points X:";
                                                cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                                                cout << "\n      points Y:";
                                                cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                                                figuraList[figuraList.size() - 1]->addCords(cmdR,cmdG);
                                                break;
                                            case 3:
                                                if(figuraList[figuraList.size() - 1]->deleteLastCords()){
                                                    cout << "      Last point is deleted" << endl;
                                                }else{
                                                    cout << "      Can't delete last cord!" << endl;
                                                }
                                                break;
                                            case 0:
                                                lvl = 3;
                                                break;
                                        }
                                    }
                                    break;
                                case 6:
                                    cout << "    degree:";
                                    cin >> cmd;
                                    figuraList[figuraList.size() - 1]->rotate(cmd);
                                    cout << "    Polygon is rotated by " << figuraList[figuraList.size() - 1]->rotateDegree << " degree." << endl;
                                    break;
                                case 0:
                                    lvl = 1;
                                    break;
                            }
                        }
                        break;
                    case 0:
                        lvl = 1;
                        break;
                }
            }
            break;
        case 3:
            lvl = 2;
            while(lvl == 2){
                cout << "  Delete figure" << endl;
                cout << "  cmd>>";
                cin >> cmd;
                switch(cmd){
                    case 1:
                        cout << "    +--Figure delete-------+" << endl;
                        cout << "    |1 - help              |" << endl;
                        cout << "    |2 - delete last       |" << endl;
                        cout << "    |3 - delete by ID      |" << endl;
                        cout << "    |0 - cancel            |" << endl;
                        cout << "    +----------------------+" << endl;
                    case 2:
                        if(figuraList.size() > 0){
                            figuraList.erase(figuraList.end() - 1, figuraList.end());
                            cout << "    Last figure were deleted." << endl;
                        }else{
                            cout << "    No figures found." << endl;
                        }
                        break;
                    ///PIEVIENOT DZEST PEDEJO UN PEC ID!!!! 25/11/2016

                    case 3:
                        if(figuraList.size() > 0){
                            for(i = 1; i < figuraList.size(); i++){
                                info = info + figuraList[i]->showData() + "\n";
                            }
                            cout << info << endl;
                            cout << "    Inser figure ID" << endl;
                            cin >> cmd;
                            if(figuraList.size() > 0 && cmd <= figuraList.size()){
                                cout << "    Delete..." << endl;
                                cout << figuraList[cmd]->showData() << endl;
                                figuraList.erase(figuraList.begin() + cmd);
                            }else{
                                cout << "    Delete is impossible." << endl;
                            }
                        }else{
                            cout << "    You didn't created any figure." << endl;
                        }
                        break;
                    case 0:
                        lvl = 1;
                        break;

                }
                break;
            }
            break;
        case 4:
            cout << "  Show all figures:\n\n\n" << endl;
            if(figuraList.size() > 0){
                for(i = 0; i < figuraList.size(); i++){
                    info = info + figuraList[i]->showData() + "\n";
                }
                cout << info << endl;
            }else{
                cout << "  You didn't created any figure." << endl;
            }
            break;
        case 5:
        {
            lvl = 2;
            while(lvl == 2){
                cmdPictureSizeX = 0;
                cmdPictureSizeY = 0;
                do{
                    cout << "  Length:";
                    cin >> cmdPictureSizeX;
                    cout << "  Height:";
                    cin >> cmdPictureSizeY;
                    if(cmdPictureSizeX <= 0){
                        cout << "  Height is to short!" << endl;
                    }
                    if(cmdPictureSizeY <= 0){
                        cout << "  Length is to short!" << endl;
                    }
                }
                while(cmdPictureSizeX <= 0 && cmdPictureSizeY <= 0);
                cout << "  Save as:";
                cin >> filename;
                int countHtml = 0;
                if(filename.length() > 0){
                    if(filename[filename.length() - 5] == '.')
                        countHtml++;
                    if(filename[filename.length() - 4] == 'h')
                        countHtml++;
                    if(filename[filename.length() - 3] == 't')
                        countHtml++;
                    if(filename[filename.length() - 2] == 'm')
                        countHtml++;
                    if(filename[filename.length() - 1] == 'l')
                        countHtml++;
                    if(countHtml < 5){
                        lvl = 3;
                        while(lvl == 3){
                            cout << "  Do you want yo save as html? (y/n)" << endl;
                            cin >> cmdS;
                            if(cmdS == "y"){
                                filename = filename + ".html";
                                lvl = 1;
                                ofstream file(filename.c_str());
                                html = html + "<html>\n";
                                html = html + " <head>\n";
                                html = html + " </head>\n";
                                html = html + " <body>\n";
                                html = html + "<svg width =\"" + toString(cmdPictureSizeX) + "\" heigth=\"" + toString(cmdPictureSizeY) + "\">";
                                if(figuraList.size() > 0){
                                    for(i = 0; i < figuraList.size(); i++){
                                        html = html + figuraList[i]->draw();
                                    }
                                }else{
                                    html = html + "You didn't created any figure.\n";
                                }
                                html = html + "</svg>";
                                html = html + " </body>\n";
                                html = html + "</html>\n";
                                cout << html << endl;
                                file << html;
                                file.close();
                            }else if(cmdS == "n"){
                                lvl = 1;
                                ofstream file(filename.c_str());
                                html = html + "<html>\n";
                                html = html + " <head>\n";
                                html = html + " </head>\n";
                                html = html + " <body>\n";
                                html = html + "<svg width =\"" + toString(cmdPictureSizeX) + "\" heigth=\"" + toString(cmdPictureSizeY) + "\">";
                                if(figuraList.size() > 0){
                                    for(i = 0; i < figuraList.size(); i++){
                                        html = html + figuraList[i]->draw();
                                    }
                                }else{
                                    html = html + "You didn't created any figure.\n";
                                }
                                html = html + "</svg>";
                                html = html + " </body>\n";
                                html = html + "</html>\n";
                                cout << html << endl;
                                file << html;
                                file.close();
                            }else{
                                cout << "Unknown command..." << endl;
                            }
                        }
                    }else{
                        lvl = 1;
                        ofstream file(filename.c_str());
                        html = html + "<html>\n";
                        html = html + " <head>\n";
                        html = html + " </head>\n";
                        html = html + " <body>\n";
                        html = html + "<svg width =\"" + toString(cmdPictureSizeX) + "\" heigth=\"" + toString(cmdPictureSizeY) + "\">";
                        if(figuraList.size() > 0){
                            for(i = 0; i < figuraList.size(); i++){
                                html = html + figuraList[i]->draw();
                            }
                        }else{
                            html = html + "You didn't created any figure.\n";
                        }
                        html = html + "</svg>";
                        html = html + " </body>\n";
                        html = html + "</html>\n";
                        cout << html << endl;
                        file << html;
                        file.close();
                    }
                }else{
                    cout << "  Filename can't be empty." << endl;
                }

            }
        }
        break;
        case 0:
            cout << "  Bye" << endl;
            lvl = 0;
            break;
        }
    }
    return 0;
}
