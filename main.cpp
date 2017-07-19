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
#include "saves.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    string bufferStr;
    int bufferInt;
    double bufferDouble;
    string html = "";
    string filename;
    string info = "";
    int cmd = -1;
    int cmdR;
    int cmdG;
    int cmdB;
    int cmdPictureSizeX, cmdPictureSizeY;
    double cmdA;
    string cmdS;
    int lvl = 1;
    int id = 0; //for figure list(When new figure created, put id++;)
    int i;
    int menuId = 0;
    string filepath = "";
    vector<Figure *>figureList;
    /**
        Method usage:
            figureList.insert(figureList.end(), new Rectangle(id)); //add new element to Figures vector.
            figureList[0]->setBackgroundRGBA(3,3,3,1); //RGBA outline
            figureList[0]->setBackgroundRGBA(15,211,88,1); //RGBA background
            figureList[0]->setCord(100,100); // figure cords
            figureList[0]->setMalas(5,15); //Rectangle sides
            figureList[0]->setRad(5,15); //ovala radiusi
            figureList[0]->setRad(5,15); //ovala radiusi
            figureList[0]->addCords(int X, int Y); // jauni poligona punkti
            figureList[0]->deleteLastCords(void); // dzest iepriekðçjo
            figureList[0]->draw(); // izvadit info, ka string. izvada figuru HTML/SVG formatâ
            figureList[0]->showData(); // izvada teksta informaciju par firguru
            figureList[0]->rotate(45); // pagrieþ figuru pret figures centru pa noteiktiem gradiem.
    */

    cout << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "|Console rastragraphics editor        |" << endl;
    cout << "|Programmer Nikita Cunskis            |" << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "|1 - Help;                            |" << endl;
    cout << "|2 - New figure;                      |" << endl;
    cout << "|3 - Delete figure by id;             |" << endl;
    cout << "|4 - Show all figures;                |" << endl;
    cout << "|5 - Save as...;                      |" << endl;
    cout << "|6 - Open File; (in progress)         |" << endl;
    cout << "|0 - Exit                             |" << endl;
    cout << "+-------------------------------------+" << endl;
    cout << "|Copyright \xa9 2016                     |" << endl;
    cout << "+-------------------------------------+" << endl;
    cout << endl;


    while(lvl == 1)
    {
        cout << "cmd>>";
        menuId = 1;
        cmdIn(cmd,menuId) ;
        switch(cmd)
        {

        case 101:
            cout << "+----HELP-----------------------------+" << endl;
            cout << "|1 - help;                            |" << endl;
            cout << "|2 - new figure;                      |" << endl;
            cout << "|3 - delete figure by id;             |" << endl;
            cout << "|4 - show all figures;                |" << endl;
            cout << "|5 - Save as...;                      |" << endl;
            cout << "|6 - Open File; (in progress)         |" << endl;
            cout << "|0 - Exit                             |" << endl;
            cout << "+-------------------------------------+" << endl;
            break;
        case 102:
        {
            lvl = 2;
            while(lvl == 2)
            {
                cout << "  +---Create new object--------+" << endl;
                cout << "  |1 - Help                    |" << endl;
                cout << "  |2 - Rectangle               |" << endl;
                cout << "  |3 - Oval                    |" << endl;
                cout << "  |4 - Polygon                 |" << endl;
                cout << "  |0 - back                    |" << endl;
                cout << "  +----------------------------+" << endl;
                cout << "  cmd>>";
                menuId = 2;
                cmdIn(cmd,menuId);

                switch(cmd)
                {
                case 201:
                    cout << "  +----HELP--------------------+" << endl;
                    cout << "  |1 - Help                    |" << endl;
                    cout << "  |2 - Rectangle               |" << endl;
                    cout << "  |3 - Oval                    |" << endl;
                    cout << "  |4 - Polygon                 |" << endl;
                    cout << "  |0 - back                    |" << endl;
                    cout << "  +----------------------------+" << endl;
                    break;
                case 202:
                    figureList.insert(figureList.end(), new Rectangle(id));
                    id++;
                    cout << "  Rectangle ID: " << figureList[figureList.size() - 1]->returnId() << " created." << endl;
                    lvl = 3;
                    while(lvl == 3)
                    {
                        cout << "   +---Rectangle--------------+" << endl;
                        cout << "   |1 - help;                 |" << endl;
                        cout << "   |2 - outline;              |" << endl;
                        cout << "   |3 - background;           |" << endl;
                        cout << "   |4 - cords;                |" << endl;
                        cout << "   |5 - sides;                |" << endl;
                        cout << "   |6 - rotate;               |" << endl;
                        cout << "   |7 - show rectangle;       |" << endl;
                        cout << "   |0 - back                  |" << endl;
                        cout << "   +--------------------------+" << endl;
                        cout << "   cmd>>";
                        menuId = 3;
                        cmdIn(cmd,menuId);

                        switch(cmd)
                        {
                        case 301:
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
                        case 302:
                            cout << "\n    Red value:";
                            cin >> cmdR;
                            cout << "\n    Green value:";
                            cin >> cmdG;
                            cout << "\n    Blue value:";
                            cin >> cmdB;
                            cout << "\n    Alpha value:";
                            cin >> cmdA;
                            figureList[figureList.size()-1]->setBackgroundRGBA(cmdR,cmdG,cmdB,cmdA);
                            cout << "    RGBA(" << figureList[figureList.size()-1]->backgroundR << ", " << figureList[figureList.size()-1]->backgroundG << ", " << figureList[figureList.size()-1]->backgroundB << ", " << figureList[figureList.size()-1]->backgroundA << ") " << endl;
                            break;
                        case 303:
                            cout << "\n    Red value:";
                            cin >> cmdR;
                            cout << "\n    Green value:";
                            cin >> cmdG;
                            cout << "\n    Blue value:";
                            cin >> cmdB;
                            cout << "\n    Alpha value:";
                            cin >> cmdA;
                            figureList[figureList.size()-1]->setBackgroundRGBA(cmdR,cmdG,cmdB,cmdA);
                            cout << "    RGBA(" << figureList[figureList.size()-1]->backgroundR << ", " << figureList[figureList.size()-1]->backgroundG << ", " << figureList[figureList.size()-1]->backgroundB << ", " << figureList[figureList.size()-1]->backgroundA << ") " << endl;
                            break;
                        case 304:
                            cout << "\n    X value:";
                            cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                            cout << "\n    Y value:";
                            cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                            figureList[figureList.size() - 1]->setCord(cmdR,cmdG);
                            cout << "    X:" << figureList[figureList.size() - 1]->cordX << " Y:" << figureList[figureList.size() - 1]->cordY << endl;
                            break;
                        case 305:
                            cout << "\n    Horizontal:";
                            cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                            cout << "\n    Vertical:";
                            cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                            figureList[figureList.size() - 1]->setSides(cmdR,cmdG);
                            cout << "    Horizontal:" << figureList[figureList.size() - 1]->returnSideA() << " Vertical:" << figureList[figureList.size() - 1]->returnSideB() << endl;
                            break;
                        case 306:
                            cout << "    Degree:";
                            cin >> cmd;
                            figureList[figureList.size() - 1]->rotate(cmd);
                            cout << "    Rectangle is rotated by " << figureList[figureList.size() - 1]->rotateDegree << " degree." << endl;
                            break;
                        case 307:
                            cout << figureList[figureList.size()-1]->showData() << endl;
                            break;
                        case 300:
                            lvl = 1;
                        }
                    }
                    break;
                case 203:
                    figureList.insert(figureList.end(), new Oval(id));
                    id++;
                    cout << "  Oval ID: " << figureList[figureList.size() - 1]->returnId() << " created." << endl;
                    lvl = 3;
                    while(lvl == 3)
                    {
                        cout << "   +---Oval-------------------+" << endl;
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
                        menuId = 4;
                        cin >> cmd;

                        switch(cmd)
                        {
                        case 401:
                            cout << "   +---Oval-------------------+" << endl;
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
                        case 402:
                            cout << "\n    Red value:";
                            cin >> cmdR;
                            cout << "\n    Green value:";
                            cin >> cmdG;
                            cout << "\n    Blue value:";
                            cin >> cmdB;
                            cout << "\n    Alpha value:";
                            cin >> cmdA;
                            figureList[figureList.size()-1]->setBackgroundRGBA(cmdR,cmdG,cmdB,cmdA);
                            cout << "    RGBA(" << figureList[figureList.size()-1]->backgroundR << ", " << figureList[figureList.size()-1]->backgroundG << ", " << figureList[figureList.size()-1]->backgroundB << ", " << figureList[figureList.size()-1]->backgroundA << ") " << endl;
                            break;
                        case 403:
                            cout << "\n    Red value:";
                            cin >> cmdR;
                            cout << "\n    Green value:";
                            cin >> cmdG;
                            cout << "\n    Blue value:";
                            cin >> cmdB;
                            cout << "\n    Alpha value:";
                            cin >> cmdA;
                            figureList[figureList.size()-1]->setBackgroundRGBA(cmdR,cmdG,cmdB,cmdA);
                            cout << "    RGBA(" << figureList[figureList.size()-1]->backgroundR << ", " << figureList[figureList.size()-1]->backgroundG << ", " << figureList[figureList.size()-1]->backgroundB << ", " << figureList[figureList.size()-1]->backgroundA << ") " << endl;
                            break;
                        case 404:
                            cout << "\n    X:";
                            cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                            cout << "\n    Y:";
                            cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                            figureList[figureList.size() - 1]->setCord(cmdR,cmdG);
                            cout << "    X:" << figureList[figureList.size() - 1]->cordX << " Y:" << figureList[figureList.size() - 1]->cordY << endl;
                            break;
                        case 405:
                            cout << "\n    Radius A:";
                            cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                            cout << "\n    Radius B:";
                            cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                            figureList[figureList.size() - 1]->setRad1(cmdR);
                            figureList[figureList.size() - 1]->setRad2(cmdG);
                            cout << "    Radius A:" << figureList[figureList.size() - 1]->returnRad1() << " Radius B:" << figureList[figureList.size() - 1]->returnRad2() << endl;
                            break;
                        case 406:
                            cout << "    degree:";
                            cin >> cmd;
                            figureList[figureList.size() - 1]->rotate(cmd);
                            cout << "    Oval is rotated by " << figureList[figureList.size() - 1]->rotateDegree << " degree." << endl;
                            break;
                        case 407:
                            cout << figureList[figureList.size()-1]->showData() << endl;
                            break;
                        case 400:
                            lvl = 1;
                        }
                    }
                    break;
                case 204:
                    figureList.insert(figureList.end(), new Polygon(id));
                    id++;
                    cout << "  Polygon ID: " << figureList[figureList.size() - 1]->returnId() << " created." << endl;
                    lvl = 3;
                    while(lvl == 3)
                    {
                        cout << "    +---Polygon--------------------+" << endl;
                        cout << "    |1 - Help;                     |" << endl;
                        cout << "    |2 - outline;                  |" << endl;
                        cout << "    |3 - background;               |" << endl;
                        cout << "    |4 - cords;                    |" << endl;
                        cout << "    |5 - add new point;            |" << endl;
                        cout << "    |6 - rotate;                   |" << endl;
                        cout << "    |7 - show polygon;             |" << endl;
                        cout << "    |0 - back                      |" << endl;
                        cout << "    +------------------------------+" << endl;
                        cout << "cmd>>";
                        menuId = 5;
                        cin >> cmd;

                        switch(cmd)
                        {
                        case 501:
                            cout << "    +---Polygon--------------------+" << endl;
                            cout << "    |1 - Help;                     |" << endl;
                            cout << "    |2 - outline;                  |" << endl;
                            cout << "    |3 - background;               |" << endl;
                            cout << "    |4 - cords;                    |" << endl;
                            cout << "    |5 - add new point;            |" << endl;
                            cout << "    |6 - rotate;                   |" << endl;
                            cout << "    |7 - show polygon;             |" << endl;
                            cout << "    |0 - back                      |" << endl;
                            cout << "    +------------------------------+" << endl;
                            break;
                        case 502:
                            cout << "\n    Red value:";
                            cin >> cmdR;
                            cout << "\n    Green value:";
                            cin >> cmdG;
                            cout << "\n    Blue value:";
                            cin >> cmdB;
                            cout << "\n    Alpha value:";
                            cin >> cmdA;
                            figureList[figureList.size()-1]->setBackgroundRGBA(cmdR,cmdG,cmdB,cmdA);
                            cout << "    RGBA(" << figureList[figureList.size()-1]->backgroundR << ", " << figureList[figureList.size()-1]->backgroundG << ", " << figureList[figureList.size()-1]->backgroundB << ", " << figureList[figureList.size()-1]->backgroundA << ") " << endl;
                            break;
                        case 503:
                            cout << "\n    Red value:";
                            cin >> cmdR;
                            cout << "\n    Green value:";
                            cin >> cmdG;
                            cout << "\n    Blue value:";
                            cin >> cmdB;
                            cout << "\n    Alpha value:";
                            cin >> cmdA;
                            figureList[figureList.size()-1]->setBackgroundRGBA(cmdR,cmdG,cmdB,cmdA);
                            cout << "    RGBA(" << figureList[figureList.size()-1]->backgroundR << ", " << figureList[figureList.size()-1]->backgroundG << ", " << figureList[figureList.size()-1]->backgroundB << ", " << figureList[figureList.size()-1]->backgroundA << ") " << endl;
                            break;
                        case 504:
                            cout << "\n    X:";
                            cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                            cout << "\n    Y:";
                            cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                            figureList[figureList.size() - 1]->setCord(cmdR,cmdG);
                            cout << "    X:" << figureList[figureList.size() - 1]->cordX << " Y:" << figureList[figureList.size() - 1]->cordY << endl;
                            break;
                        case 505:
                            lvl = 4;
                            while(lvl == 4)
                            {
                                cout << "      +---Polygon points-------------+" << endl;
                                cout << "      |1 - help;                     |" << endl;
                                cout << "      |2 - new point;                |" << endl;
                                cout << "      |3 - delete previous;          |" << endl;
                                cout << "      |0 - end point add;            |" << endl;
                                cout << "      +------------------------------+" << endl;
                                cout << "      cmd>>";
                                menuId = 6;
                                cin >> cmd;

                                switch(cmd)
                                {
                                case 601:
                                    cout << "      +---Polygon points-------------+" << endl;
                                    cout << "      |1 - help;                     |" << endl;
                                    cout << "      |2 - new point;                |" << endl;
                                    cout << "      |3 - delete previous;          |" << endl;
                                    cout << "      |0 - end point add;            |" << endl;
                                    cout << "      +------------------------------+" << endl;
                                    break;
                                case 602:
                                    cout << "\n      points X:";
                                    cin >> cmdR;                ///I'm using Red and Green, becous they are integer;
                                    cout << "\n      points Y:";
                                    cin >> cmdG;                ///I'm using Red and Green, becous they are integer;
                                    figureList[figureList.size() - 1]->addCords(cmdR,cmdG);
                                    break;
                                case 603:
                                    if(figureList[figureList.size() - 1]->deleteLastCords())
                                    {
                                        cout << "      Last point is deleted" << endl;
                                    }
                                    else
                                    {
                                        cout << "      Can't delete last cord!" << endl;
                                    }
                                    break;
                                case 600:
                                    lvl = 3;
                                    break;
                                }
                            }
                            break;
                        case 506:
                            cout << "    degree:";
                            cin >> cmd;
                            figureList[figureList.size() - 1]->rotate(cmd);
                            cout << "    Polygon is rotated by " << figureList[figureList.size() - 1]->rotateDegree << " degree." << endl;
                            break;
                        case 500:
                            lvl = 1;
                            break;
                        }
                    }
                    break;
                case 200:
                    lvl = 1;
                    break;
                }
            }
        }
        break;
        case 103:
        {
            lvl = 2;
            while(lvl == 2)
            {
                cout << "    +--Figure delete-------+" << endl;
                cout << "    |1 - help              |" << endl;
                cout << "    |2 - delete last       |" << endl;
                cout << "    |3 - delete by ID      |" << endl;
                cout << "    |0 - cancel            |" << endl;
                cout << "    +----------------------+" << endl;
                cout << "  cmd>>";
                menuId = 7;
                cin >> cmd;
                switch(cmd)
                {
                case 701:
                    cout << "    +--Figure delete-------+" << endl;
                    cout << "    |1 - help              |" << endl;
                    cout << "    |2 - delete last       |" << endl;
                    cout << "    |3 - delete by ID      |" << endl;
                    cout << "    |0 - cancel            |" << endl;
                    cout << "    +----------------------+" << endl;
                case 702:
                    if(figureList.size() > 0)
                    {
                        figureList.erase(figureList.end() - 1, figureList.end());
                        cout << "    Last figure were deleted." << endl;
                    }
                    else
                    {
                        cout << "    No figures found." << endl;
                    }
                    break;

                case 703:
                    if(figureList.size() > 0)
                    {
                        for(i = 1; i < figureList.size(); i++)
                        {
                            info = info + figureList[i]->showData() + "\n";
                        }
                        cout << info << endl;
                        cout << "    Inser figure ID" << endl;
                        cin >> cmd;
                        if(figureList.size() > 0 && cmd <= figureList.size())
                        {
                            cout << "    Delete..." << endl;
                            cout << figureList[cmd]->showData() << endl;
                            figureList.erase(figureList.begin() + cmd);
                        }
                        else
                        {
                            cout << "    Delete is impossible." << endl;
                        }
                    }
                    else
                    {
                        cout << "    You didn't created any figure." << endl;
                    }
                    break;
                case 700:
                    lvl = 1;
                    break;

                }
                break;
            }
        }
        break;
        case 104:
        {
            cout << "  Show all figures:\n\n\n" << endl;
            if(figureList.size() > 0)
            {
                for(i = 0; i < figureList.size(); i++)
                {
                    info = info + figureList[i]->showData() + "\n";
                }
                cout << info << endl;
            }
            else
            {
                cout << "  You didn't created any figure." << endl;
            }
        }
        break;
        case 105:
        {
            lvl = 2;
            while(lvl == 2)
            {
                cmdPictureSizeX = 0;
                cmdPictureSizeY = 0;
                do
                {
                    cout << "  Length:";
                    cin >> cmdPictureSizeX;
                    cout << "  Height:";
                    cin >> cmdPictureSizeY;
                    if(cmdPictureSizeX <= 0)
                    {
                        cout << "  Height is to short!" << endl;
                    }
                    if(cmdPictureSizeY <= 0)
                    {
                        cout << "  Length is to short!" << endl;
                    }
                }
                while(cmdPictureSizeX <= 0 && cmdPictureSizeY <= 0);
                cout << "  Save as:";
                cin >> filename;
                int countHtml = 0;
                if(filename.length() > 0)
                {
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
                    if(countHtml < 5)
                    {
                        lvl = 3;
                        while(lvl == 3)
                        {
                            cout << "  Do you want yo save add .html as extension of file? (y/n)" << endl;
                            cin >> cmdS;
                            if(cmdS == "y")
                            {

                                /* Find if there is other extension and if is, we need to change it to html */

                                filename = filename + ".html";
                                lvl = 1;
                                ofstream file(filename.c_str());
                                html = html + "<html>\n";
                                html = html + " <head>\n";
                                html = html + "  <title>Created with console-SVG-creator</title>";
                                html = html + " </head>\n";
                                html = html + " <body>\n";
                                html = html + "     <svg width =\"" + toString(cmdPictureSizeX) + "\" heigth=\"" + toString(cmdPictureSizeY) + "\">";
                                if(figureList.size() > 0)
                                {
                                    for(i = 0; i < figureList.size(); i++)
                                    {
                                        html = html + figureList[i]->draw();
                                    }
                                }
                                else
                                {
                                    html = html + "You didn't created any figure.\n";
                                }
                                html = html + "</svg>";
                                html = html + " </body>\n";
                                html = html + "</html>\n";
                                cout << html << endl;
                                file << html;
                                file.close();
                            }
                            else if(cmdS == "n")
                            {
                                lvl = 1;
                                ofstream file(filename.c_str());
                                html = html + "<html>\n";
                                html = html + " <head>\n";
                                html = html + " </head>\n";
                                html = html + " <body>\n";
                                html = html + "<svg width =\"" + toString(cmdPictureSizeX) + "\" heigth=\"" + toString(cmdPictureSizeY) + "\">";
                                if(figureList.size() > 0)
                                {
                                    for(i = 0; i < figureList.size(); i++)
                                    {
                                        html = html + figureList[i]->draw();
                                    }
                                }
                                else
                                {
                                    html = html + "You didn't created any figure.\n";
                                }
                                html = html + "</svg>";
                                html = html + " </body>\n";
                                html = html + "</html>\n";
                                cout << html << endl;
                                file << html;
                                file.close();
                            }
                            else
                            {
                                cout << "Unknown command..." << endl;
                            }
                        }
                    }
                    else
                    {
                        lvl = 1;
                        ofstream file(filename.c_str());
                        html = html + "<html>\n";
                        html = html + " <head>\n";
                        html = html + " </head>\n";
                        html = html + " <body>\n";
                        html = html + "<svg width =\"" + toString(cmdPictureSizeX) + "\" heigth=\"" + toString(cmdPictureSizeY) + "\">";
                        if(figureList.size() > 0)
                        {
                            for(i = 0; i < figureList.size(); i++)
                            {
                                html = html + figureList[i]->draw();
                            }
                        }
                        else
                        {
                            html = html + "You didn't created any figure.\n";
                        }
                        html = html + "</svg>";
                        html = html + " </body>\n";
                        html = html + "</html>\n";
                        cout << html << endl;
                        file << html;
                        file.close();
                    }
                }
                else
                {
                    cout << "  Filename can't be empty." << endl;
                }

            }
        }
        break;
        case 106:
        {
            /* under construction */
            lvl = 2;

            Saves* save();
            save.inputPath();

            lvl = 1;
        }
        break;
        case 100:
            cout << "  Bye!" << endl;
            lvl = 0;
            break;
        }
    }
    return 0;
}
