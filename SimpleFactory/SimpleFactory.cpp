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

class OperationFactory {

    public:

    static std::shared_ptr<Operation> createOperation(char operation){

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
    std::shared_ptr<Operation> add = OperationFactory::createOperation('+');
    if(add ==nullptr){
        std::cout<<"operation is invalid."<<std::endl;
        return -1;
    }
    add->SetNumberA(4);
    add->SetNumberB(5);
    std::cout<<"The add result is: "<<add->GetResult()<<std::endl;

    try{
        std::shared_ptr<Operation> del = OperationFactory::createOperation('/');
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