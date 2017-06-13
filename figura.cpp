#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

#include <stdlib.h>

#include "figura.hpp"
#include "functions.hpp"

using namespace std;
/// --------------- FIGURA obj ---------------- ///
void Figura::setKontursRGBA(int kontursR, int kontursG, int kontursB, double kontursA){
    if(kontursR < 256 && kontursG < 256 && kontursB < 256 && kontursA <= 1 && kontursR >=0 && kontursG >= 0 && kontursB >= 0 && kontursA >= 0){
        this->kontursR = kontursR;
        this->kontursG = kontursG;
        this->kontursB = kontursB;
        this->kontursA = kontursA;
    }else{
        cout << "Error: Nepareizs RGBA formats! rgba(0-255,0-255,0-255,0-1)" << endl;
    }
}

void Figura::setFonsRGBA(int R, int G, int B, double A){
    if(R < 256 && G < 256 && B < 256 && A <= 1 && R >=0 && G >= 0 && B >= 0 && A >= 0){
        this->fonsR = R;
        this->fonsG = G;
        this->fonsB = B;
        this->fonsA = A;
    }else{
        cout << "Error: Nepareizs RGBA formats! rgba(0-255,0-255,0-255,0-1)" << endl;
    }
}

void Figura::setCord(int X, int Y){
    if(X >= 0 && Y >= 0){
        this->cordX = X;
        this->cordY = Y;
    }else{
        cout << "Error: koordinatem, jabut pozitivam." << endl;
    }
}

int Figura::returnId(void){
    return this->id;
}

void Figura::setId(int id){
    if(id >= 0){
        this->id = id;
    }
}

void Figura::hide(void){
    this->visible = 0;
}

void Figura::moveFigure(string direction, int number){
    if(direction == "up" &&  number > 0 /*&& number < this->cordY*/){
        this->cordY = this->cordY - number;
    }
    if(direction == "down" &&  number > 0){
        this->cordY = this->cordY + number;
    }
    if(direction == "left" &&  number > 0 /*&& number < this->cordX*/){
        this->cordY = this->cordX - number;
    }
    if(direction == "right" &&  number > 0){
        this->cordY = this->cordY + number;
    }
}

void Figura::rotate(int degree){
    this->rotateDegree = degree;
}

/// ----------------- END FIGURA OBJ ------------ ///




/// ----------------- TAISNSTURIS -------------- ///
Taisnsturis::Taisnsturis(int id){
    if(id>=0){
        this->id = id;
        this->type = 1;
        this->setMalas(1,1);
        this->setCord(1,1);
        this->setFonsRGBA(1,1,1,0);
        this->setKontursRGBA(1,1,1,0);
        this->visible = 1;
        this->rotateDegree = 0;
    }else{
        cout << "Error: Objekts nevar but izveidots" << endl;
    }
    /*
    if(malaA > 0 && malaB > 0){
        this->malaA = malaA;
        this->malaB = malaB;
    }else{
        cout << "Error: Malam jabut pozitiviem skaitliem." << endl;
    }
    */
}
Taisnsturis::~Taisnsturis(){

}

void Taisnsturis::setMalas(int malaA, int malaB){
    if(malaA > 0 && malaB > 0){
        this->malaA = malaA;
        this->malaB = malaB;
    }else{
        cout << "Error: Malam jabut pozitiviem skaitliem." << endl;
        this->malaA = 1;
        this->malaB = 1;
    }
}

void Taisnsturis::setMalaA(int mala){
    if(mala>0){
        this->malaA = mala;
    }else{
        cout << "Error: Malaij jabut pozitivam skaitlim!" << endl;
        this->malaA = 1;
    }
}
void Taisnsturis::setMalaB(int mala){
    if(mala>0){
        this->malaB = mala;
    }else{
        cout << "Error: Malaj jabut pozitivam skaitlim!" << endl;
        this->malaA = 1;
    }
}
string Taisnsturis::draw(){
    string html = "";

    html = html + "";
    html = html + "    <rect x=\"" + toString(this->cordX) + "\" y=\"" + toString(this->cordX) + "\"\n";
    html = html + "        width=\"" + toString(this->malaA) + "\" height=\"" + toString(this->malaB) + "\"\n";
    html = html + "        style=\"fill: " + toString(this->fonsR) + ", " + toString(this->fonsG) + ", " + toString(this->fonsB) + ";\n";
    html = html + "        stroke:rgb(" + toString(this->kontursR) + ", " + toString(this->kontursG) + ", " + toString(this->kontursB) + ")\"\n";
    html = html + "        transform=\"rotate(" + toString(this->rotateDegree) + " " + toString(this->cordX + (this->malaA / 2)) + " " + toString(this->cordY + (this->malaB / 2)) + ")\">\n";
    html = html + "    </rect>\n";
    html = html + "";

    return html;
}


string Taisnsturis::showData(){
    string info = "";

    info = info + "------------------------------------------------\n";
    info = info + "    Taisnsturis(" + toString(this->id) + "):" + "\n";
    info = info + "        Mala A= " + toString(this->malaA) + "   MalaB= " + toString(this->malaB) + "\n";
    info = info + "        Cord X= " + toString(this->cordX) + "   CordY= " + toString(this->cordY) + "\n";
    info = info + "        fona    RGBA(" + toString(this->fonsR) + ", " + toString(this->fonsG) + ", " + toString(this->fonsB) + ", " + toString(this->fonsA) + ")" + "\n";
    info = info + "        kontura RGBA(" + toString(this->kontursR) + ", " + toString(this->kontursG) + ", " + toString(this->kontursB) + ", " + toString(this->kontursA) + ")" + "\n";
    info = info + "        Pagrieziens:" + toString(this->rotateDegree) + "\n";
    info = info + "------------------------------------------------\n";
    return info;
}

int Taisnsturis::returnMalaA(void){
    return this->malaA;
}

int Taisnsturis::returnMalaB(void){
    return this->malaB;
}

/// ------------- END Taisnsturis -------------- ///


/// -------------- Ovals ------------------///


Ovals::Ovals(int id){
    if(id>=0){
        this->id = id;
        this->type = 2;
        this->setRad(1,1);
        this->setCord(1,1);
        this->setFonsRGBA(1,1,1,0);
        this->setKontursRGBA(1,1,1,0);
        this->visible = 1;
        this->rotateDegree = 0;
    }
    /*
    if(rad1 > 0 && rad2 > 0){
        this->rad1 = rad1;
        this->rad2 = rad2;
    }else{
        cout << "Error: Radiusiem jabut lielakiem par nuli!" << endl;
    }
    */
}
Ovals::~Ovals(){
    ///Destruktors
}
void Ovals::setOvals(int rad1, int rad2){
    if(rad1 > 0 && rad2 > 0){
        this->rad1 = rad1;
        this->rad2 = rad2;
    }else{
        cout << "Error: Radiusiem jabut lielakiem par nuli!" << endl;
        this->rad1 = 1;
        this->rad2 = 1;
    }
}
void Ovals::setRad1(int rad){
    if(rad > 0){
        this->rad1 = rad;
    }else{
        cout << "Error: Radiusam jabut pozitivam" << endl;
    }
}
void Ovals::setRad2(int rad){
    if(rad > 0){
        this->rad2 = rad;
    }else{
        cout << "Error: Radiusam jabut pozitivam" << endl;
    }
}

void Ovals::setRad(int Rad1, int Rad2){
    if(Rad1 > 0 && Rad2 > 0){
        this->rad1 = Rad1;
        this->rad2 = Rad2;
    }else{
        cout << "Error: Radiusiem jabut pozitiviem" << endl;
    }
}


int Ovals::returnRad1(void){
    return this->rad1;
}
int Ovals::returnRad2(void){
    return this->rad2;
}

string Ovals::showData(){
    string info = "";

    info = info + "------------------------------------------------\n";
    info = info + "    Ovals(" + toString(this->id) + "):" + "\n";
    info = info + "        RadA= " + toString(this->rad1) + "   RadB= " + toString(this->rad2) + "\n";
    info = info + "        Cord X= " + toString(this->cordX) + "   CordY= " + toString(this->cordY) + "\n";
    info = info + "        fona    RGBA(" + toString(this->fonsR) + ", " + toString(this->fonsG) + ", " + toString(this->fonsB) + ", " + toString(this->fonsA) + ")" + "\n";
    info = info + "        kontura RGBA(" + toString(this->kontursR) + ", " + toString(this->kontursG) + ", " + toString(this->kontursB) + ", " + toString(this->kontursA) + ")" + "\n";
    info = info + "------------------------------------------------\n";
    return info;
}

string Ovals::draw(){
    string html = "";
    html = html + "<ellipse cx=\"" + toString(this->cordX) + "\" cy=\"" + toString(this->cordY);
    html = html + "\" rx=\"" + toString(this->rad1) + "\" ry=\"" + toString(this->rad2) + "\" ";
    html = html + "style=\"fill:rgb(" + toString(this->fonsR) + ", " + toString(this->fonsG) + ", " + toString(this->fonsB) + ");";
    html = html + "stroke:rgb(" + toString(this->kontursR) + ", " + toString(this->kontursG) + ", " + toString(this->kontursB) + ");";
    html = html + " transform=\"rotate(" + toString(this->rotateDegree) + " " + toString(this->cordX + (this->rad1 / 2)) + " " + toString(this->cordY + (this->rad2 / 2)) + ")\" />\n";
    html = html + "stroke-width:2\" />\n";

    return html;
}


/// --------------- END OVALS -------------- ///

/// --------------- POLIGONS --------------- ///


Poligons::Poligons(int id){
    if(id>=0){
        this->id = id;
        this->type = 3;
        this->setCord(1,1);
        this->setFonsRGBA(1,1,1,0);
        this->setKontursRGBA(1,1,1,0);
        this->visible = 1;
        this->rotateDegree = 0;
    }
    ///Konstruktors
}
Poligons::~Poligons(){
    ///Destruktors
}
void Poligons::addCords(int X, int Y){
    if(X >= 0 && Y >=0){
        this->cordsX.insert(this->cordsX.end(), X);
        this->cordsY.insert(this->cordsY.end(), Y);
    }else{
        cout << "Error: Koordinatem jabut pozitivam!" << endl;
    }
}

int Poligons::deleteLastCords(void){
    if(this->cordsX.size() > 0 && this->cordsY.size() > 0){
        this->cordsX.erase(this->cordsX.end()-1,this->cordsX.end());
        this->cordsY.erase(this->cordsY.end()-1,this->cordsY.end());
        return 1;
    }else{
        cout << "Nav pievienoti koordinati" << endl;
        return 0;
    }
}

string Poligons::showData(){
    string info = "";
    int i;
    info = info + "------------------------------------------------\n";
    info = info + "    Poligons(" + toString(this->id) + "):" + "\n";
        info = info + "Cordinates: \n";
    for(i=0;i<this->cordsX.size();i++){
        info = info + "   -X: " + toString(this->cordsX[i]) + "   Y:" + toString(this->cordsY[i]) + "\n";
    }
    info = info + "        Cord X= " + toString(this->cordX) + "   CordY= " + toString(this->cordY) + "\n";
    info = info + "        fona    RGBA(" + toString(this->fonsR) + ", " + toString(this->fonsG) + ", " + toString(this->fonsB) + ", " + toString(this->fonsA) + ")" + "\n";
    info = info + "        kontura RGBA(" + toString(this->kontursR) + ", " + toString(this->kontursG) + ", " + toString(this->kontursB) + ", " + toString(this->kontursA) + ")" + "\n";
    info = info + "------------------------------------------------\n";
    return info;
}

string Poligons::draw(){
    string html = "";

    int left,right, width, top, bottom, heigth,i;
    left = cordsX[0];
    for(i = 0;i < this->cordsX.size(); i++){
        if(left < this->cordsX[i]){
            left = this->cordsX[i];
        }
    }
    right = cordsX[0];
    for(i = 0; i < this->cordsX.size(); i++){
        if(right < this->cordsX[i]){
            right = this->cordsX[i];
        }
    }
    top = cordsY[0];
    for(i = 0;i < this->cordsY.size(); i++){
        if(left < this->cordsY[i]){
            left = this->cordsY[i];
        }
    }
    bottom = cordsY[0];
    for(i = 0; i < this->cordsY.size(); i++){
        if(right < this->cordsY[i]){
            right = this->cordsY[i];
        }
    }
    width = right - left;
    heigth = bottom - top;
    if(width < 0){
        width = width * (-1);
    }
    if(heigth < 0){
        heigth = heigth * (-1);
    }
    string cords = "";
    for(i = 0; i < this->cordsX.size(); i++){
        cords = cords + toString(this->cordsX[i]) + "," + toString(this->cordsY[i]) + " ";
    }
    html = html + "";
    html = html + "<polygon points=\"" + cords + "\" style=\"";
    html = html + "fill:rgba(" + toString(this->fonsR) + ", " + toString(this->fonsG) + ", " + toString(this->fonsB) + ", " + toString(this->fonsA) + ");";
    html = html + "stroke:rgba(" + toString(this->kontursR) + ", " + toString(this->kontursG) + ", " + toString(this->kontursB) + ", " + toString(this->kontursA) + ");stroke-width:1\" \n";
    html = html + " transform=\"rotate(" + toString(this->rotateDegree) + " " + toString(this->cordX + (width / 2)) + " " + toString(this->cordY + (heigth / 2)) + ")\" />\n";
    html = html + "";

    return html;
}
