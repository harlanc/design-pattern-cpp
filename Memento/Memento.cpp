//compile using  g++ Memento.cpp -Wc++11-extensions -std=c++11
#include <string>
#include <iostream>
#include <memory>
#include <vector>

class Memento{
    public:
    Memento(const std::string &state){
        _state = state;
    }

    std::string getState(){
        return _state;
    }

    private:
    std::string _state;

};

class Originator{
    public:
    void setState(const std::string &state){
        _state = state;
    }

    std::string getState(){
        return _state;
    }

    std::shared_ptr<Memento> saveStateToMemento(){
        return std::make_shared<Memento>(_state);
    }
    
    void getStateFromMemento(const std::shared_ptr<Memento> &memento){
        _state = memento->getState();
    }
    private:
    std::string _state;
};

class CareTaker{
    public:
    void add (const std::shared_ptr<Memento> &state){
        _mementos.push_back(state);
    }
    std::shared_ptr<Memento> get(int idx){
        return _mementos[idx];
    }
    private:
    std::vector<std::shared_ptr<Memento> > _mementos;
};


int main(){

    std::shared_ptr<Originator> originator =  std::make_shared<Originator>();
    std::shared_ptr<CareTaker> caretaker =  std::make_shared<CareTaker>(); 

    originator->setState("State #1");
    originator->setState("State #2");
    caretaker->add(originator->saveStateToMemento());
    originator->setState("State #3");
    caretaker->add(originator->saveStateToMemento());

    originator->setState("State #4");
    std::cout<<"Current State: "<<originator->getState()<<std::endl;
    originator->getStateFromMemento(caretaker->get(0));
    std::cout<<"First saved State: "<<originator->getState()<<std::endl;
    originator->getStateFromMemento(caretaker->get(1));
    std::cout<<"Second saved State: "<<originator->getState()<<std::endl;

    
    return 0;
}


