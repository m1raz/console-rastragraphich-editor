#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

#include <stdlib.h>

#include "figura.hpp"
#include "functions.hpp"

using namespace std;
/// --------------- Figure obj ---------------- ///
void Figure::setOutlineRGBA(int backgroundR, int backgroundG, int backgroundB, double backgroundA)
{
    if(backgroundR < 256 && backgroundG < 256 && backgroundB < 256 && backgroundA <= 1 && backgroundR >=0 && backgroundG >= 0 && backgroundB >= 0 && backgroundA >= 0)
    {
        this->backgroundR = backgroundR;
        this->backgroundG = backgroundG;
        this->backgroundB = backgroundB;
        this->backgroundA = backgroundA;
    }
    else
    {
        cout << err(1) << endl;
    }
}

void Figure::setBackgroundRGBA(int R, int G, int B, double A)
{
    if(R < 256 && G < 256 && B < 256 && A <= 1 && R >=0 && G >= 0 && B >= 0 && A >= 0)
    {
        this->backgroundR = R;
        this->backgroundG = G;
        this->backgroundB = B;
        this->backgroundA = A;
    }
    else
    {
        cout << err(1) << endl;
    }
}

void Figure::setCord(int X, int Y)
{
    if(X >= 0 && Y >= 0)
    {
        this->cordX = X;
        this->cordY = Y;
    }
    else
    {
        cout << err(2) << endl;
    }
}

int Figure::returnId(void)
{
    return this->id;
}

void Figure::setId(int id)
{
    if(id >= 0)
    {
        this->id = id;
    }
}

void Figure::hide(void)
{
    this->visible = 0;
}

void Figure::moveFigure(string direction, int number)
{
    if(direction == "up" &&  number > 0 /*&& number < this->cordY*/)
    {
        this->cordY = this->cordY - number;
    }
    if(direction == "down" &&  number > 0)
    {
        this->cordY = this->cordY + number;
    }
    if(direction == "left" &&  number > 0 /*&& number < this->cordX*/)
    {
        this->cordY = this->cordX - number;
    }
    if(direction == "right" &&  number > 0)
    {
        this->cordY = this->cordY + number;
    }
}

void Figure::rotate(int degree)
{
    this->rotateDegree = degree;
}

/// ----------------- END Figurer OBJ ------------ ///




/// ----------------- Rectangle -------------- ///
Rectangle::Rectangle(int id)
{
    if(id>=0)
    {
        this->id = id;
        this->type = 1;
        this->setSides(1,1);
        this->setCord(1,1);
        this->setBackgroundRGBA(1,1,1,0);
        this->setBackgroundRGBA(1,1,1,0);
        this->visible = 1;
        this->rotateDegree = 0;
    }
    else
    {
        cout << err(3) << endl;
    }
}
Rectangle::~Rectangle()
{

}

void Rectangle::setSides(int sideA, int sideB)
{
    if(sideA > 0 && sideB > 0)
    {
        this->sideA = sideA;
        this->sideB = sideB;
    }
    else
    {
        cout << err(4) << endl;
        this->sideA = 1;
        this->sideB = 1;
    }
}

void Rectangle::setSideA(int side)
{
    if(side>0)
    {
        this->sideA = side;
    }
    else
    {
        cout << err(4) << endl;
        this->sideA = 1;
    }
}
void Rectangle::setSideB(int side)
{
    if(side>0)
    {
        this->sideB = side;
    }
    else
    {
        cout << err(4) << endl;
        this->sideA = 1;
    }
}
string Rectangle::draw()
{
    string html = "";

    html = html + "";
    html = html + "    <rect x=\"" + toString(this->cordX) + "\" y=\"" + toString(this->cordX) + "\"\n";
    html = html + "        width=\"" + toString(this->sideA) + "\" height=\"" + toString(this->sideB) + "\"\n";
    html = html + "        style=\"fill: " + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ";\n";
    html = html + "        stroke:rgb(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ")\"\n";
    html = html + "        transform=\"rotate(" + toString(this->rotateDegree) + " " + toString(this->cordX + (this->sideA / 2)) + " " + toString(this->cordY + (this->sideB / 2)) + ")\">\n";
    html = html + "    </rect>\n";
    html = html + "";

    return html;
}


string Rectangle::showData()
{
    string info = "";

    info = info + "------------------------------------------------\n";
    info = info + "    Rectangle(" + toString(this->id) + "):" + "\n";
    info = info + "        side A= " + toString(this->sideA) + "   sideB= " + toString(this->sideB) + "\n";
    info = info + "        Cord X= " + toString(this->cordX) + "   CordY= " + toString(this->cordY) + "\n";
    info = info + "        Background    RGBA(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ", " + toString(this->backgroundA) + ")" + "\n";
    info = info + "        Outline RGBA(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ", " + toString(this->backgroundA) + ")" + "\n";
    info = info + "        Rotation:" + toString(this->rotateDegree) + "\n";
    info = info + "------------------------------------------------\n";
    return info;
}

int Rectangle::returnSideA(void)
{
    return this->sideA;
}

int Rectangle::returnSideB(void)
{
    return this->sideB;
}

/// ------------- END Rectangle -------------- ///


/// -------------- Oval ------------------///


Oval::Oval(int id)
{
    if(id>=0)
    {
        this->id = id;
        this->type = 2;
        this->setRad(1,1);
        this->setCord(1,1);
        this->setBackgroundRGBA(1,1,1,0);
        this->setOutlineRGBA(1,1,1,0);
        this->visible = 1;
        this->rotateDegree = 0;
    }
}
Oval::~Oval()
{
    ///Destructor
}
void Oval::setOval(int rad1, int rad2)
{
    if(rad1 > 0 && rad2 > 0)
    {
        this->rad1 = rad1;
        this->rad2 = rad2;
    }
    else
    {
        cout << err(0) << endl;
        this->rad1 = 1;
        this->rad2 = 1;
    }
}
void Oval::setRad1(int rad)
{
    if(rad > 0)
    {
        this->rad1 = rad;
    }
    else
    {
        cout << err(0) << endl;
    }
}
void Oval::setRad2(int rad)
{
    if(rad > 0)
    {
        this->rad2 = rad;
    }
    else
    {
        cout << err(0) << endl;
    }
}

void Oval::setRad(int Rad1, int Rad2)
{
    if(Rad1 > 0 && Rad2 > 0)
    {
        this->rad1 = Rad1;
        this->rad2 = Rad2;
    }
    else
    {
        cout << err(0) << endl;
    }
}


int Oval::returnRad1(void)
{
    return this->rad1;
}
int Oval::returnRad2(void)
{
    return this->rad2;
}


//console use
string Oval::showData()
{
    string info = "";

    info = info + "------------------------------------------------\n";
    info = info + "    Oval(" + toString(this->id) + "):" + "\n";
    info = info + "        RadA= " + toString(this->rad1) + "   RadB= " + toString(this->rad2) + "\n";
    info = info + "        Cord X= " + toString(this->cordX) + "   CordY= " + toString(this->cordY) + "\n";
    info = info + "        Background    RGBA(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ", " + toString(this->backgroundA) + ")" + "\n";
    info = info + "        Outline RGBA(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ", " + toString(this->backgroundA) + ")" + "\n";
    info = info + "------------------------------------------------\n";
    return info;
}


//returns SVG ellipse code generated from user's data
string Oval::draw()
{
    string html = "";
    html = html + "<ellipse cx=\"" + toString(this->cordX) + "\" cy=\"" + toString(this->cordY);
    html = html + "\" rx=\"" + toString(this->rad1) + "\" ry=\"" + toString(this->rad2) + "\" ";
    html = html + "style=\"fill:rgb(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ");";
    html = html + "stroke:rgb(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ");";
    html = html + " transform=\"rotate(" + toString(this->rotateDegree) + " " + toString(this->cordX + (this->rad1 / 2)) + " " + toString(this->cordY + (this->rad2 / 2)) + ")\" />\n";
    html = html + "stroke-width:2\" />\n";

    return html;
}


/// --------------- END Oval -------------- ///

/// --------------- Polygon --------------- ///


Polygon::Polygon(int id)
{
    if(id>=0)
    {
        this->id = id;
        this->type = 3;
        this->setCord(1,1);
        this->setBackgroundRGBA(1,1,1,0);
        this->setOutlineRGBA(1,1,1,0);
        this->visible = 1;
        this->rotateDegree = 0;
    }
    ///Constructor
}
Polygon::~Polygon()
{
    ///Destructor
}
void Polygon::addCords(int X, int Y)
{
    if(X >= 0 && Y >=0)
    {
        this->cordsX.insert(this->cordsX.end(), X);
        this->cordsY.insert(this->cordsY.end(), Y);
    }
    else
    {
        cout << "Error: Koordinatem jabut pozitivam!" << endl;
    }
}

int Polygon::deleteLastCords(void)
{
    if(this->cordsX.size() > 0 && this->cordsY.size() > 0)
    {
        this->cordsX.erase(this->cordsX.end()-1,this->cordsX.end());
        this->cordsY.erase(this->cordsY.end()-1,this->cordsY.end());
        return 1;
    }
    else
    {
        cout << "Nav pievienoti koordinati" << endl;
        return 0;
    }
}

string Polygon::showData()
{
    string info = "";
    int i;
    info = info + "------------------------------------------------\n";
    info = info + "    Polygon(" + toString(this->id) + "):" + "\n";
    info = info + "Cordinates: \n";
    for(i=0; i<this->cordsX.size(); i++)
    {
        info = info + "   -X: " + toString(this->cordsX[i]) + "   Y:" + toString(this->cordsY[i]) + "\n";
    }
    info = info + "        Cord X= " + toString(this->cordX) + "   CordY= " + toString(this->cordY) + "\n";
    info = info + "        fona    RGBA(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ", " + toString(this->backgroundA) + ")" + "\n";
    info = info + "        kontura RGBA(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ", " + toString(this->backgroundA) + ")" + "\n";
    info = info + "------------------------------------------------\n";
    return info;
}

string Polygon::draw()
{
    string html = "";

    int left,right, width, top, bottom, heigth,i;
    left = cordsX[0];
    for(i = 0; i < this->cordsX.size(); i++)
    {
        if(left < this->cordsX[i])
        {
            left = this->cordsX[i];
        }
    }
    right = cordsX[0];
    for(i = 0; i < this->cordsX.size(); i++)
    {
        if(right < this->cordsX[i])
        {
            right = this->cordsX[i];
        }
    }
    top = cordsY[0];
    for(i = 0; i < this->cordsY.size(); i++)
    {
        if(left < this->cordsY[i])
        {
            left = this->cordsY[i];
        }
    }
    bottom = cordsY[0];
    for(i = 0; i < this->cordsY.size(); i++)
    {
        if(right < this->cordsY[i])
        {
            right = this->cordsY[i];
        }
    }
    width = right - left;
    heigth = bottom - top;
    if(width < 0)
    {
        width = width * (-1);
    }
    if(heigth < 0)
    {
        heigth = heigth * (-1);
    }
    string cords = "";
    for(i = 0; i < this->cordsX.size(); i++)
    {
        cords = cords + toString(this->cordsX[i]) + "," + toString(this->cordsY[i]) + " ";
    }
    html = html + "";
    html = html + "<polygon points=\"" + cords + "\" style=\"";
    html = html + "fill:rgba(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ", " + toString(this->backgroundA) + ");";
    html = html + "stroke:rgba(" + toString(this->backgroundR) + ", " + toString(this->backgroundG) + ", " + toString(this->backgroundB) + ", " + toString(this->backgroundA) + ");stroke-width:1\" \n";
    html = html + " transform=\"rotate(" + toString(this->rotateDegree) + " " + toString(this->cordX + (width / 2)) + " " + toString(this->cordY + (heigth / 2)) + ")\" />\n";
    html = html + "";

    return html;
}
