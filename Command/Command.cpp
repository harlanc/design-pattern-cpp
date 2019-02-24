
#include <iostream>
#include <vector>
using namespace std;

class Receiver{
    public:
    static void CookRice(){
        cout<<"炒米饭"<<endl;
    }
    static void CookNoodles(){
        cout<<"煮面条"<<endl;
    }
};

class Command{
    public:
    Receiver _receiver;
    Command(const Receiver &rec){
        _receiver = rec;
    }
    virtual void Execute() = 0;
};

class CookRiceCommand: public Command{
    public:
    CookRiceCommand(const Receiver &receiver):Command(receiver){

    }
    void Execute(){
        _receiver.CookRice();
    }
};

class CookNoodlesCommand: public Command{
    public:
    CookNoodlesCommand(const Receiver &receiver):Command(receiver){

    }
    void Execute(){
        _receiver.CookNoodles();
    }
};

class Waiter{
    public:
    vector<shared_ptr<Command> > _orders;
    void SetOrder(const shared_ptr<Command> command){
         _orders.push_back(command);
    }

    void Notify(){
        for(auto o:_orders){
            o->Execute();
        }
    }
};

int main(){

    Receiver receiver;
    // Command *rice =new CookRiceCommand(receiver);
    // Command *noodles = new CookNoodlesCommand(receiver);

    shared_ptr<Command> rice = make_shared<CookRiceCommand>(receiver);
    shared_ptr<Command> noodles = make_shared<CookNoodlesCommand>(receiver);

    Waiter waiter ;
    waiter.SetOrder(rice);
    waiter.SetOrder(move(noodles));

    waiter.Notify();
    return 0;
}

