//g++ State.cpp -Wc++11-extensions -std=c++11
#include <memory>
#include <iostream>
class State;
class Context{
    private:
    std::shared_ptr<State> _state;
    public:
    Context(){
        _state = nullptr;
    }
    void setState(const std::shared_ptr<State> &state){
        _state = state;
    }
    std::shared_ptr<State> getState(){
        return _state;
    }
};
class State:public std::enable_shared_from_this<State>{
    public:
    virtual void doAction(const std::shared_ptr<Context> &context) = 0;
    virtual std::string toString() = 0;
};


class StartState : public State{
    public:
    void doAction(const std::shared_ptr<Context> &context){
        std::cout<<"Player is in start state"<<std::endl;
        context->setState(std::shared_ptr<State>(shared_from_this()));
    }

    std::string toString(){
        return "Start State";
    }
};

class StopState : public State{
    public:
    void doAction(const std::shared_ptr<Context> &context){
        std::cout<<"Player is in stop state"<<std::endl;
        context->setState(std::shared_ptr<State>(shared_from_this()));
    }

    std::string toString(){
        return "Stop State";
    }
};

int main(){
    std::shared_ptr<Context> context = std::make_shared<Context>();

    std::shared_ptr<State> startstate = std::make_shared<StartState>();
    startstate->doAction(context);
    std::cout<<context->getState()->toString()<<std::endl;
    
    std::shared_ptr<State> stopstate = std::make_shared<StopState>();
    stopstate->doAction(context);
    std::cout<<context->getState()->toString()<<std::endl;
    
    return 0;
}