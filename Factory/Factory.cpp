#include <memory>
#include <string>
#include <iostream>

class Operation{

    public:
    
    Operation(){
        _numberA = 0;
        _numberB = 0;
    }
    virtual double GetResult(){
        return 0;
    }

    void SetNumberA(double a){
        _numberA =a;
    }
    void SetNumberB(double b){
        _numberB =b;
    }
    
    protected:

    double _numberA;
    double _numberB;


};

class Add:public Operation{
    public:
    double GetResult(){
        return _numberA + _numberB;
    }
};

class Sub:public Operation{
    public:
    double GetResult(){
        return _numberA - _numberB;
    }
};

class Mul:public Operation{
    public:
    double GetResult(){
        return _numberA * _numberB;
    }
};

class Del:public Operation{
    public:
    double GetResult(){

        if(_numberB == 0){
            throw(std::string("Dividend cannot be zero."));
        }
        return _numberA / _numberB;
    }
};

class Factory {
    public:
    virtual std::shared_ptr<Operation> createOperation(){return nullptr;};
};

class AddFactory:public Factory{
    public:
    std::shared_ptr<Operation> createOperation(){
         return std::make_shared<Add>();
    }
};
class SubFactory:public Factory{
    public:
    std::shared_ptr<Operation> createOperation(){
         return std::make_shared<Sub>();
    }
};
class MulFactory:public Factory{
    public:
    std::shared_ptr<Operation> createOperation(){
         return std::make_shared<Mul>();
    }
};
class DelFactory:public Factory{
    public:
    std::shared_ptr<Operation> createOperation(){
         return std::make_shared<Del>();
    }
};

int main(){
    
    std::shared_ptr<Factory> addfactory= std::make_shared<AddFactory>();
    std::shared_ptr<Operation> add =  addfactory->createOperation();
    add->SetNumberA(2);
    add->SetNumberB(3);
 
    std::cout<<"The add result is:"<<add->GetResult()<<std::endl;
  
    return 0;
}