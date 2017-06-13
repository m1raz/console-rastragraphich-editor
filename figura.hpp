#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Figura{
    public:
        int id;
        int visible;

        int kontursR;
        int kontursG;
        int kontursB;
        double kontursA;

        int fonsR;
        int fonsG;
        int fonsB;
        double fonsA;

        int cordX;
        int cordY;
        int rotateDegree;

        int type; ///taisnsturis - 1; ovals - 2; poligons - 3

        void setKontursRGBA(int kontursR, int kontursG, int kontursB, double kontursA);
        void setFonsRGBA(int R, int G, int B, double A);
        void setCord(int X, int Y);
        void rotate(int degree);
        void setId(int id);
        void hide(void);
        int returnId(void);
        void moveFigure(string direction, int number);

        virtual void setMalas(int malaA, int malaB){};
        virtual void setMalaA(int mala){};
        virtual void setMalaB(int mala){};
        virtual int returnMalaA(void){};
        virtual int returnMalaB(void){};
        virtual int returnRad1(void){};
        virtual int returnRad2(void){};
        virtual void setOvals(int rad1, int rad2){};
        virtual void setRad1(int rad){};
        virtual void setRad2(int rad){};
        virtual void addCords(int X, int Y){};
        virtual int deleteLastCords(void){};
        virtual string draw(){};
        virtual string showData(){};
};

class Taisnsturis : public Figura{
    public:
        int malaA;
        int malaB;
        Taisnsturis(int id);
        ~Taisnsturis();
        void setMalas(int malaA, int malaB);
        void setMalaA(int mala);
        void setMalaB(int mala);
        int returnMalaA(void);
        int returnMalaB(void);
        string showData();
        string draw();
};

class Ovals : public Figura{
    public:
        int rad1;
        int rad2;
        Ovals(int id);
        ~Ovals();
        void setOvals(int rad1, int rad2);
        void setRad1(int rad);
        void setRad2(int rad);
        void setRad(int Rad1, int Rad2);
        int returnRad1(void);
        int returnRad2(void);
        string showData();
        string draw();
};


class Poligons : public Figura{
    public:
        vector<int> cordsX;
        vector<int> cordsY;
        Poligons(int id);
        ~Poligons();
        void addCords(int X, int Y);
        int deleteLastCords(void);
        string showData();
        string draw();
};
