#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Saves
{
private:
    string path = "";

public:
    Saves();
    ~Saves();
    string getPath();
    void inputPath();
    void saveAs();
    void save();
    void load();
};
