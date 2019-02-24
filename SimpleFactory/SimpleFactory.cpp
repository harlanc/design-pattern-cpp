#include <memory>
#include <string>
#include <iostream>

class ArithmeticOperation{

    public:
    
    ArithmeticOperation(){
        _numberA = 0;
        _numberB = 0;
    }
    virtual double GetResult()=0;

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

class OperationFactory {

    public:

    static std::shared_ptr<ArithmeticOperation> createArithmeticOperation(char operation){

        switch (operation)
        {
            case '+':
            return std::make_shared<Add>();
            break;
            case '-':
            return std::make_shared<Sub>();
            break;
            case '*':
            return std::make_shared<Mul>();
            break;
            case '/':
            return std::make_shared<Del>();
            break;
            default:
            return nullptr;
            break;
        }
    }
};

int main(){
    std::shared_ptr<ArithmeticOperation> add = OperationFactory::createArithmeticOperation('+');
    if(add ==nullptr){
        std::cout<<"operation is invalid."<<std::endl;
        return -1;
    }
    add->SetNumberA(4);
    add->SetNumberB(5);
    std::cout<<"The add result is: "<<add->GetResult()<<std::endl;

    try{
        std::shared_ptr<ArithmeticOperation> del = OperationFactory::createArithmeticOperation('/');
        if(del ==nullptr){
            std::cout<<"operation is invalid."<<std::endl;
            return -1;
        }
        del->SetNumberA(4);
        del->SetNumberB(0);
        std::cout<<"The add result is: "<<del->GetResult()<<std::endl;
    }catch(std::string msg){
        std::cout<<msg<<std::endl;
        return -1;
    }
    return 0;
}