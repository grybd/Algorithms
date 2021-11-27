#include <bits/stdc++.h>
using namespace std;

enum CarType{BENZ,BMW};

class Car{
public:
  virtual void createCar(void)=0;
};
class BenzCar:public Car
{
  public:
    BenzCar(){
      cout<<"Benz::Benz()"<<endl;
    }
    virtual void createCar(void){
      cout<<"BenzCar::createdCar()"<<endl;
    }
    ~BenzCar(){

    }
};
class BmwCar:public Car{
public:
  BmwCar(){
    cout<<"Bmw::Bmw()"<<endl;
  }
  virtual void createCar(void){
    cout<<"BmwCar::createCar()"<<endl;
  }
};

class CarFactory{
public:
  Car* createSpecificCar(CarType type){
    switch(type){
      case BENZ:
        return new BenzCar();
        break;
      case BMW:
        return new BmwCar();
        break;
      default:
        return NULL;
        break;
    }
  }
};

int main(){
  CarFactory carfac;
  Car* specificCarA = carfac.createSpecificCar(BENZ);
  Car* specificCarB = carfac.createSpecificCar(BMW);
  delete specificCarA;
  delete specificCarB;
  return 0;
}
