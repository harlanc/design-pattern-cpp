#include <string>
#include <set>
#include <memory>
#include <iostream>

class Subject;
class Observer{
    public:
    virtual void Update() = 0;
    Observer(const std::string name,const std::shared_ptr<Subject> &sub);
    protected:
    std::shared_ptr<Subject> _sub;
    std::string _name;
};
class Farmer : public Observer{
    public:
    Farmer(const std::string &name,const std::shared_ptr<Subject> &sub);
    void Update();
};
class Worker : public Observer{
    public:
    Worker(const std::string &name,const std::shared_ptr<Subject> &sub);
    void Update();
};



//weather report subject
class Subject{
    public:
    void setSubjectState(std::string &&str);
    std::string getSubjectState();
    
    virtual void Attach(const std::shared_ptr<Observer> &obs) = 0;
    virtual void Detach(const std::shared_ptr<Observer> &obs) = 0;
    virtual void Notify() = 0;

    private:
    std::string subjectState;
};
class Wind: public Subject{

    public:
    
    void Attach(const std::shared_ptr<Observer> &obs);
    void Detach(const std::shared_ptr<Observer> &obs);
    void Notify();
    
    private:
    std::set<std::shared_ptr<Observer> > _observers;
};

class Rain: public Subject{

    public:

    void Attach(const std::shared_ptr<Observer> &obs);
    void Detach(const std::shared_ptr<Observer> &obs);
    void Notify();
    
    private:
    std::set<std::shared_ptr<Observer> > _observers;
};

