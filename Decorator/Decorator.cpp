 //g++ Decorator.cpp -Wc++11-extensions -std=c++11
#include <string>
#include <iostream>
#include <memory>

class Person{
    public:
    std::string _name;
    Person(){}
    Person(std::string &&name){
        //std::cout<<"call move Person"<<std::endl;
        _name = name;
    }
    Person(Person &&component){
        this->_name = std::move(component._name);
    }
    // Person& operator= (Person &&component){
    //     std::cout<<"call move operator ="<<std::endl;
    //     this->_name = std::move(component._name);
    //     return *this;
    // }
    virtual void Show(){
        std::cout<<"decorate for "<<_name<<std::endl;
    }

};

class Finery:public Person{
    public:
    Finery(){}

    void Decorate(const std::shared_ptr<Person> &person){
        this->_person = person;
    }
    void Show(){
         _person->Show();
    }

    private:
    std::shared_ptr<Person> _person;
    
};

class TShirts:public Finery{
    public:
    TShirts(){}
    void Show(){
        std::cout<<"T Shirts ";
        Finery::Show();
    }
};

class BigTrouser:public Finery{

    public:
    BigTrouser(){}
    void Show(){
        std::cout<<"Big Trousers ";
        Finery::Show();
    }
};

int main(){

    std::string name("Simon");
    std::shared_ptr<Person> xc = std::make_shared<Person>(std::move(name));
    
    std::shared_ptr<Finery> bt = std::make_shared<BigTrouser>();
    std::shared_ptr<Finery> ts = std::make_shared<TShirts>();


    ts->Decorate(xc);
    bt->Decorate(ts);

    bt->Show();

    return 0;
}