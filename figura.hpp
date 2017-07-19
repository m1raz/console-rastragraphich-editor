#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Figure
{
public:
    int id;
    int visible;

    int outlineR;
    int outlineG;
    int outlineB;
    double outlineA;

    int backgroundR;
    int backgroundG;
    int backgroundB;
    double backgroundA;

    int cordX;
    int cordY;
    int rotateDegree;

    int type; ///Rectangle - 1; oval - 2; polygon - 3

    void setOutlineRGBA(int outlineR, int outlineG, int outlineB, double outlineA);
    void setBackgroundRGBA(int R, int G, int B, double A);
    void setCord(int X, int Y);
    void rotate(int degree);
    void setId(int id);
    void hide(void);
    int returnId(void);
    void moveFigure(string direction, int number);

    virtual void setSides(int mSideA, int SideB) {};
    virtual void setSideA(int side) {};
    virtual void setSideB(int side) {};
    virtual int returnSideA(void) {};
    virtual int returnSideB(void) {};
    virtual int returnRad1(void) {};
    virtual int returnRad2(void) {};
    virtual void setOval(int rad1, int rad2) {};
    virtual void setRad1(int rad) {};
    virtual void setRad2(int rad) {};
    virtual void addCords(int X, int Y) {};
    virtual int deleteLastCords(void) {};
    virtual string draw() {};
    virtual string showData() {};
};

class Rectangle : public Figure
{
public:
    int sideA;
    int sideB;
    Rectangle(int id);
    ~Rectangle();
    void setSides(int sideA, int sideB);
    void setSideA(int side);
    void setSideB(int side);
    int returnSideA(void);
    int returnSideB(void);
    string showData();
    string draw();
};

class Oval : public Figure
{
public:
    int rad1;
    int rad2;
    Oval(int id);
    ~Oval();
    void setOval(int rad1, int rad2);
    void setRad1(int rad);
    void setRad2(int rad);
    void setRad(int Rad1, int Rad2);
    int returnRad1(void);
    int returnRad2(void);
    string showData();
    string draw();
};


class Polygon : public Figure
{
public:
    vector<int> cordsX;
    vector<int> cordsY;
    Polygon(int id);
    ~Polygon();
    void addCords(int X, int Y);
    int deleteLastCords(void);
    string showData();
    string draw();
};
