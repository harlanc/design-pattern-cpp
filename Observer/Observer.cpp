#include "Observer.h"

Observer::Observer(const std::string name,const std::shared_ptr<Subject> &sub){
        _name = name;
        _sub = sub;
}

Farmer::Farmer(const std::string &name,const std::shared_ptr<Subject> &sub):Observer(name,sub){

}
void Farmer::Update(){
    std::cout<<_name<<":"<<_sub->getSubjectState()<<std::endl;
}

Worker::Worker(const std::string &name,const std::shared_ptr<Subject> &sub):Observer(name,sub){

}
void Worker::Update(){
    std::cout<<_name<<":"<<_sub->getSubjectState()<<std::endl;
}

void Subject::setSubjectState(std::string &&str){
    subjectState = str;
}
std::string Subject::getSubjectState(){
    return subjectState;
}

void Wind::Attach(const std::shared_ptr<Observer> &obs){
    _observers.insert(obs);
}
void Wind::Detach(const std::shared_ptr<Observer> &obs){
    _observers.erase(obs);
}
void Wind::Notify()
{
    for(auto v: _observers){
        v->Update();
    }
}

void Rain::Attach(const std::shared_ptr<Observer> &obs){
    _observers.insert(obs);
}
void Rain::Detach(const std::shared_ptr<Observer> &obs){
    _observers.erase(obs);
}
void Rain::Notify()
{
    for(auto v: _observers){
        v->Update();
    }
}

int main(){

std::shared_ptr<Subject> sub = std::make_shared<Wind>();

std::shared_ptr<Observer> farmer = std::make_shared<Farmer>("farmer",sub);
std::shared_ptr<Observer> worker = std::make_shared<Worker>("worker",sub);

sub->Attach(farmer);
sub->Attach(worker);

sub->setSubjectState("The wind is coming!!!!!");

sub->Notify();



return 0;
}