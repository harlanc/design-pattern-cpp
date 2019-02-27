//g++ Template.cpp -Wc++11-extensions -std=c++11
#include <iostream>
#include <memory>

class Game{
    protected:
    virtual void initialize() = 0;
    virtual void startPlay() = 0;
    virtual void endPlay() = 0;

    public:

    virtual void play () final{
        initialize();
        startPlay();
        endPlay();
    }
};

class Football : public Game{
    protected:
    
    void initialize(){
        std::cout<<"start football game."<<std::endl;
    }
    void startPlay(){
        std::cout<<"start play football"<<std::endl;
    }
    void endPlay(){
        std::cout<<"end play football"<<std::endl;
    }

};


class Pingpong : public Game{
    protected:
    
    void initialize(){
        std::cout<<"start Pingpong game."<<std::endl;
    }
    void startPlay(){
        std::cout<<"start play Pingpong"<<std::endl;
    }
    void endPlay(){
        std::cout<<"end play Pingpong"<<std::endl;
    }

};

int main(){
    std::shared_ptr<Game> football = std::make_shared<Football>();
    football->play();

    std::shared_ptr<Game> pingpong = std::make_shared<Pingpong>();
    pingpong->play();

    return 0;
}