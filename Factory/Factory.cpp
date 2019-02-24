#include <memory>
#include <string>
#include <iostream>

class ArithmeticOperation{

    public:
    
    ArithmeticOperation(){
        _numberA = 0;
        _numberB = 0;
    }
    virtual double GetResult() = 0;

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

class Add:public ArithmeticOperation{
    public:
    double GetResult(){
        return _numberA + _numberB;
    }
};

class Sub:public ArithmeticOperation{
    public:
    double GetResult(){
        return _numberA - _numberB;
    }
};

class Mul:public ArithmeticOperation{
    public:
    double GetResult(){
        return _numberA * _numberB;
    }
};

class Del:public ArithmeticOperation{
    public:
    double GetResult(){

        if(_numberB == 0){
            throw(std::string("Dividend cannot be zero."));
        }
        return _numberA / _numberB;
    }
};

class IFactory {
    public:
    virtual std::shared_ptr<ArithmeticOperation> createArithmeticOperation() = 0;
};

class AddFactory:public IFactory{
    public:
    std::shared_ptr<ArithmeticOperation> createArithmeticOperation(){
         return std::make_shared<Add>();
    }
};
class SubFactory:public IFactory{
    public:
    std::shared_ptr<ArithmeticOperation> createArithmeticOperation(){
         return std::make_shared<Sub>();
    }
};
class MulFactory:public IFactory{
    public:
    std::shared_ptr<ArithmeticOperation> createArithmeticOperation(){
         return std::make_shared<Mul>();
    }
};
class DelFactory:public IFactory{
    public:
    std::shared_ptr<ArithmeticOperation> createArithmeticOperation(){
         return std::make_shared<Del>();
    }
};

int main(){
    
    std::shared_ptr<IFactory> addfactory= std::make_shared<AddFactory>();
    std::shared_ptr<ArithmeticOperation> add =  addfactory->createArithmeticOperation();
    add->SetNumberA(2);
    add->SetNumberB(3);
 
    std::cout<<"The add result is:"<<add->GetResult()<<std::endl;
  
    return 0;
}