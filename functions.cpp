#include <iostream>
#include <string>
#include <sstream>
#include "functions.hpp"

string toString(double number)
{
    ostringstream sstream;
    sstream.precision(2);
    sstream << fixed;
    sstream << number;
    string varAsString = sstream.str();
    return varAsString;
}

string toString(int number)
{
    ostringstream sstream;
    sstream << number;
    string varAsString = sstream.str();
    return varAsString;
}

string err(int id)
{
    string err = "";
    if(id == 0)
    {
        err = "Radiusiem jabut lielakiem par nuli!";
    }
    if(id == 1)
    {
        err = "Nepareizs RGBA formats! rgba(0-255,0-255,0-255,0-1)";
    }
    if(id == 2)
    {
        err = "Koordinatem, jabut pozitivam.";
    }
    if(id == 3)
    {
        err = "Objekts nevar but izveidots";
    }
    if(id == 4)
    {
        err = "Malam jabut pozitiviem skaitliem.";
    }
    if(id == 5)
    {
        err = "Malam jabut pozitiviem skaitliem.";
    }
    return err;
}

/* This is menu functions
    If you want to add new element to existing menu, menu's id.
    If you want to create new menu ID
    Maximal items in menu is 100

    Example

    First menu
    100 - item 1
    101 - item 2
    ..
    199 - item 100
    Second menu
    200 - item 1
    201 - item 2
    ..
    299 - item 100

    This function get commands string value and returns it's unique ID

    * In one menu can't be 2 identical commands
    * Multiple commands can do same action, like exit, bye, close, stop, if you give for it identical cmdId;

*/
void cmdIn(int& IntegerCmd, int menuId)
{

    string cmd;
    cin >> cmd;
    int cmdId = -1;
    bool wrong = true;

    if(menuId == 1)  ///main menu
    {
        if(cmd == "help")
        {
            wrong = false;
            cmdId = 1;
        }
        else
        {
            wrong = true;
            if(cmd == "nf")
            {
                wrong = false;
                cmdId = 2;
            }
            else
            {
                wrong = true;
                if(cmd == "rmfig")
                {
                    wrong = false;
                    cmdId = 3;
                }
                else
                {
                    wrong = true;
                    if(cmd == "lsfig")
                    {
                        wrong = false;
                        cmdId = 4;
                    }
                    else
                    {
                        wrong = true;
                        if(cmd == "sv")
                        {
                            wrong = false;
                            cmdId = 5;
                        }
                        else
                        {
                            wrong = true;
                            if(cmd == "sv")
                            {
                                wrong = false;
                                cmdId = 5;
                            }
                            else
                            {
                                wrong = true;
                                if(cmd == "op")
                                {
                                    wrong = false;
                                    cmdId = 6;
                                }
                                else
                                {
                                    wrong = true;
                                    if(cmd == "exit")
                                    {
                                        wrong = false;
                                        cmdId = 0;
                                    }
                                    else
                                    {
                                        wrong = true;
                                        if(cmd == "close")
                                        {
                                            wrong = false;
                                            cmdId = 0;
                                        }
                                        else
                                        {
                                            wrong = true;
                                            if(cmd == "bye")
                                            {
                                                wrong = false;
                                                cmdId = 0;
                                            }
                                            else
                                            {
                                                wrong = true;
                                                if(cmd == ".")
                                                {
                                                    wrong = false;
                                                    cmdId = 0;
                                                }
                                                else
                                                {
                                                    wrong = true;
                                                    if(cmd == "stop")
                                                    {
                                                        wrong = false;
                                                        cmdId = 0;
                                                    }
                                                    else
                                                    {
                                                        wrong = true;
                                                        if(cmd == "cancel")
                                                        {
                                                            wrong = false;
                                                            cmdId = 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        wrong = true;
        if(menuId == 2)  ///Figure choose menu
        {
            wrong = true;
            if(cmd == "help")
            {
                wrong = false;
                cmdId = 1;
            }
            else
            {
                wrong = true;
                if(cmd == "rectangle")
                {
                    wrong = false;
                    cmdId = 2;
                }
                else
                {
                    wrong = true;
                    if(cmd == "rect")
                    {
                        wrong = false;
                        cmdId = 2;
                    }
                    else
                    {
                        wrong = true;
                        if(cmd == "oval")
                        {
                            wrong = false;
                            cmdId = 3;
                        }
                        else
                        {
                            wrong = true;
                            if(cmd == "polygon")
                            {
                                wrong = false;
                                cmdId = 4;
                            }
                            else
                            {
                                wrong = true;
                                if(cmd == "back")
                                {
                                    wrong = false;
                                    cmdId = 0;
                                }
                                else
                                {
                                    wrong = true;
                                    if(cmd == "cancel")
                                    {
                                        wrong = false;
                                        cmdId = 0;
                                    }
                                    else
                                    {
                                        wrong = true;
                                        if(cmd == "../")
                                        {
                                            wrong = false;
                                            cmdId = 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            wrong = true;
            if(menuId == 3)  ///Rectangle menu
            {
                if(cmd == "help")
                {
                    wrong = false;
                    cmdId = 1;
                }
                else
                {
                    wrong = true;
                    if(cmd == "outln")
                    {
                        wrong = false;
                        cmdId = 2;
                    }
                    else
                    {
                        wrong = true;
                        if(cmd == "outline")
                        {
                            wrong = false;
                            cmdId = 2;
                        }
                        else
                        {
                            wrong = true;
                            if(cmd == "bg")
                            {
                                wrong = false;
                                cmdId = 3;
                            }
                            else
                            {
                                wrong = true;
                                if(cmd == "background")
                                {
                                    wrong = false;
                                    cmdId = 3;
                                }
                                else
                                {
                                    wrong = true;
                                    if(cmd == "cords")
                                    {
                                        wrong = false;
                                        cmdId = 4;
                                    }
                                    else
                                    {
                                        wrong = true;
                                        if(cmd == "sides")
                                        {
                                            wrong = false;
                                            cmdId = 5;
                                        }
                                        else
                                        {
                                            wrong = true;
                                            if(cmd == "rt")
                                            {
                                                wrong = false;
                                                cmdId = 6;
                                            }
                                            else
                                            {
                                                wrong = true;
                                                if(cmd == "rotate")
                                                {
                                                    wrong = false;
                                                    cmdId = 6;
                                                }
                                                else
                                                {
                                                    wrong = true;
                                                    if(cmd == "sh")
                                                    {
                                                        wrong = false;
                                                        cmdId = 7;
                                                    }
                                                    else
                                                    {
                                                        wrong = true;
                                                        if(cmd == "print")
                                                        {
                                                            wrong = false;
                                                            cmdId = 7;
                                                        }
                                                        else
                                                        {
                                                            wrong = true;
                                                            if(cmd == "show")
                                                            {
                                                                wrong = false;
                                                                cmdId = 7;
                                                            }
                                                            else
                                                            {
                                                                wrong = true;
                                                                if(cmd == "back")
                                                                {
                                                                    wrong = false;
                                                                    cmdId = 0;
                                                                }
                                                                else
                                                                {
                                                                    wrong = true;
                                                                    if(cmd == "cancel")
                                                                    {
                                                                        wrong = false;
                                                                        cmdId = 0;
                                                                    }
                                                                    else
                                                                    {
                                                                        wrong = true;
                                                                        if(cmd == "../")
                                                                        {
                                                                            wrong = false;
                                                                            cmdId = 0;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                wrong = true;
                if(menuId == 4)  ///Oval menu
                {
                    if(cmd == "help")
                    {
                        wrong = false;
                        cmdId = 1;
                    }
                    else
                    {
                        wrong = true;
                        if(cmd == "outln")
                        {
                            wrong = false;
                            cmdId = 2;
                        }
                        else
                        {
                            wrong = true;
                            if(cmd == "outline")
                            {
                                wrong = false;
                                cmdId = 2;
                            }
                            else
                            {
                                wrong = true;
                                if(cmd == "bg")
                                {
                                    wrong = false;
                                    cmdId = 3;
                                }
                                else
                                {
                                    wrong = true;
                                    if(cmd == "bg")
                                    {
                                        wrong = false;
                                        cmdId = 3;
                                    }
                                    else
                                    {
                                        wrong = true;
                                        if(cmd == "background")
                                        {
                                            wrong = false;
                                            cmdId = 3;
                                        }
                                        else
                                        {
                                            wrong = true;
                                            if(cmd == "rad")
                                            {
                                                wrong = false;
                                                cmdId = 4;
                                            }
                                            else
                                            {
                                                wrong = true;
                                                if(cmd == "radius")
                                                {
                                                    wrong = false;
                                                    cmdId = 4;
                                                }
                                                else
                                                {
                                                    wrong = true;
                                                    if(cmd == "sides")
                                                    {
                                                        wrong = false;
                                                        cmdId = 5;
                                                    }
                                                    else
                                                    {
                                                        wrong = true;
                                                        if(cmd == "rt")
                                                        {
                                                            wrong = false;
                                                            cmdId = 6;
                                                        }
                                                        else
                                                        {
                                                            wrong = true;
                                                            if(cmd == "rotate")
                                                            {
                                                                wrong = false;
                                                                cmdId = 6;
                                                            }
                                                            else
                                                            {
                                                                wrong = true;
                                                                if(cmd == "sh")
                                                                {
                                                                    wrong = false;
                                                                    cmdId = 7;
                                                                }
                                                                else
                                                                {
                                                                    wrong = true;
                                                                    if(cmd == "print")
                                                                    {
                                                                        wrong = false;
                                                                        cmdId = 7;
                                                                    }
                                                                    else
                                                                    {
                                                                        wrong = true;
                                                                        if(cmd == "show")
                                                                        {
                                                                            wrong = false;
                                                                            cmdId = 7;
                                                                        }
                                                                        else
                                                                        {
                                                                            wrong = true;
                                                                            if(cmd == "back")
                                                                            {
                                                                                wrong = false;
                                                                                cmdId = 0;
                                                                            }
                                                                            else
                                                                            {
                                                                                wrong = true;
                                                                                if(cmd == "cancel")
                                                                                {
                                                                                    wrong = false;
                                                                                    cmdId = 0;
                                                                                }
                                                                                else
                                                                                {
                                                                                    wrong = true;
                                                                                    if(cmd == "../")
                                                                                    {
                                                                                        wrong = false;
                                                                                        cmdId = 0;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    wrong = true;
                    if(menuId == 5)  ///Polygon menu
                    {
                        if(cmd == "help")
                        {
                            wrong = false;
                            cmdId = 1;
                        }
                        else
                        {
                            wrong = true;
                            if(cmd == "outln")
                            {
                                wrong = false;
                                cmdId = 2;
                            }
                            else
                            {
                                wrong = true;
                                if(cmd == "outline")
                                {
                                    wrong = false;
                                    cmdId = 2;
                                }
                                else
                                {
                                    wrong = true;
                                    if(cmd == "bg")
                                    {
                                        wrong = false;
                                        cmdId = 3;
                                    }
                                    else
                                    {
                                        wrong = true;
                                        if(cmd == "background")
                                        {
                                            wrong = false;
                                            cmdId = 3;
                                        }
                                        else
                                        {
                                            wrong = true;
                                            if(cmd == "cords")
                                            {
                                                wrong = false;
                                                cmdId = 4;
                                            }
                                            else
                                            {
                                                wrong = true;
                                                if(cmd == "addpt")
                                                {
                                                    wrong = false;
                                                    cmdId = 5;
                                                }
                                                else
                                                {
                                                    wrong = true;
                                                    if(cmd == "addpoint")
                                                    {
                                                        wrong = false;
                                                        cmdId = 5;
                                                    }
                                                    else
                                                    {
                                                        wrong = true;
                                                        if(cmd == "newpoint")
                                                        {
                                                            wrong = false;
                                                            cmdId = 5;
                                                        }
                                                        else
                                                        {
                                                            wrong = true;
                                                            if(cmd == "newpt")
                                                            {
                                                                wrong = false;
                                                                cmdId = 5;
                                                            }
                                                            else
                                                            {
                                                                wrong = true;
                                                                if(cmd == "npt")
                                                                {
                                                                    wrong = false;
                                                                    cmdId = 5;
                                                                }
                                                                else
                                                                {
                                                                    wrong = true;
                                                                    if(cmd == "addnewpoint")
                                                                    {
                                                                        wrong = false;
                                                                        cmdId = 5;
                                                                    }
                                                                    else
                                                                    {
                                                                        wrong = true;
                                                                        if(cmd == "rt")
                                                                        {
                                                                            wrong = false;
                                                                            cmdId = 6;
                                                                        }
                                                                        else
                                                                        {
                                                                            wrong = true;
                                                                            if(cmd == "rotate")
                                                                            {
                                                                                wrong = false;
                                                                                cmdId = 6;
                                                                            }
                                                                            else
                                                                            {
                                                                                wrong = true;
                                                                                if(cmd == "sh")
                                                                                {
                                                                                    wrong = false;
                                                                                    cmdId = 7;
                                                                                }
                                                                                else
                                                                                {
                                                                                    wrong = true;
                                                                                    if(cmd == "print")
                                                                                    {
                                                                                        wrong = false;
                                                                                        cmdId = 7;
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        wrong = true;
                                                                                        if(cmd == "show")
                                                                                        {
                                                                                            wrong = false;
                                                                                            cmdId = 7;
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            wrong = true;
                                                                                            if(cmd == "back")
                                                                                            {
                                                                                                wrong = false;
                                                                                                cmdId = 0;
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                wrong = true;
                                                                                                if(cmd == "cancel")
                                                                                                {
                                                                                                    wrong = false;
                                                                                                    cmdId = 0;
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    wrong = true;
                                                                                                    if(cmd == "../")
                                                                                                    {
                                                                                                        wrong = false;
                                                                                                        cmdId = 0;
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        wrong = true;
                        if(menuId == 6)
                        {
                            if(cmd == "help")
                            {
                                wrong = false;
                                cmdId = 1;
                            }
                            else
                            {
                                wrong = true;
                                if(cmd == "npt")
                                {
                                    wrong = false;
                                    cmdId = 2;
                                }
                                else
                                {
                                    wrong = true;
                                    if(cmd == "newpoint")
                                    {
                                        wrong = false;
                                        cmdId = 2;
                                    }
                                    else
                                    {
                                        wrong = true;
                                        if(cmd == "rmpt")
                                        {
                                            wrong = false;
                                            cmdId = 3;
                                        }
                                        else
                                        {
                                            wrong = true;
                                            if(cmd == "removepoint")
                                            {
                                                wrong = false;
                                                cmdId = 3;
                                            }
                                            else
                                            {
                                                wrong = true;
                                                if(cmd == "back")
                                                {
                                                    wrong = false;
                                                    cmdId = 0;
                                                }
                                                else
                                                {
                                                    wrong = true;
                                                    if(cmd == "cancel")
                                                    {
                                                        wrong = false;
                                                        cmdId = 0;
                                                    }
                                                    else
                                                    {
                                                        wrong = true;
                                                        if(cmd == "../")
                                                        {
                                                            wrong = false;
                                                            cmdId = 0;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            wrong = true;
                            if(menuId == 7)  ///Delete figure menu
                            {
                                if(cmd == "help")
                                {
                                    wrong = false;
                                    cmdId = 1;
                                }
                                else
                                {
                                    wrong = true;
                                    if(cmd == "rm-last")
                                    {
                                        wrong = false;
                                        cmdId = 2;
                                    }
                                    else
                                    {
                                        wrong = true;
                                        if(cmd == "remove-last")
                                        {
                                            wrong = false;
                                            cmdId = 2;
                                        }
                                        else
                                        {
                                            wrong = true;
                                            if(cmd == "rm-id")
                                            {
                                                wrong = false;
                                                cmdId = 3;
                                            }
                                            else
                                            {
                                                wrong = true;
                                                if(cmd == "remove-id")
                                                {
                                                    wrong = false;
                                                    cmdId = 3;
                                                }
                                                else
                                                {
                                                    wrong = true;
                                                    if(cmd == "back")
                                                    {
                                                        wrong = false;
                                                        cmdId = 0;
                                                    }
                                                    else
                                                    {
                                                        wrong = true;
                                                        if(cmd == "cancel")
                                                        {
                                                            wrong = false;
                                                            cmdId = 0;
                                                        }
                                                        else
                                                        {
                                                            wrong = true;
                                                            if(cmd == "../")
                                                            {
                                                                wrong = false;
                                                                cmdId = 0;
                                                            }
                                                            else
                                                            {
                                                                wrong = true;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(wrong == true)
    {
        cout << "Wrong command!" << endl;
        IntegerCmd = -1;
    }
    else
    {
        IntegerCmd = menuId * 100 + cmdId;
    }

}
