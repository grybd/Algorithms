#include <string>
using namespace std;
class ZooAnimal{
public:
    ZooAnimal();
    ZooAnimal(string _name): name(_name){};
    virtual ~ZooAnimal();
    virtual void rotate();

  protected:
    int loc;
    string name;
};
/*
ZooAnimal za("Zoey");
ZooAnimal *pza=&za;*/

class Bear:public ZooAnimal{
public:
   Bear();
   ~Bear();
   void rotate();
   virtual void dance();
 protected:
   int  cell_block;
};
