//g++ Visitor.cpp -Wc++11-extensions -std=c++11

#include <vector>
#include <iostream>

class ComputerPartVisitor;

class ComputerPart {
   public:
   virtual void accept(const ComputerPartVisitor *computerPartVisitor) = 0;
};

class Mouse;
class Keyboard;
class Monitor;
class Computer;

class ComputerPartVisitor {
   public:
   virtual void visit(const Computer *computer) const= 0;
   virtual void visit(const Mouse *mouse) const = 0;
   virtual void visit(const Keyboard *keyboard) const = 0;
   virtual void visit(const Monitor *monitor) const = 0;
};


class ComputerPartDisplayVisitor:public ComputerPartVisitor {
    public:
    void visit(const Computer *computer) const override{
      std::cout<<"Displaying Computer."<<std::endl;
   }
 
   void visit(const Mouse *mouse) const override {
      std::cout<<"Displaying Mouse."<<std::endl;
   }
 
 void visit(const Keyboard *keyboard) const override {
      std::cout<<"Displaying Keyboard."<<std::endl;
   }
 
   void visit(const Monitor *monitor) const override {
      std::cout<<"Displaying Monitor."<<std::endl;
   }
};

class Keyboard:public ComputerPart {
    public:
    void accept(const ComputerPartVisitor *computerPartVisitor) override{
    computerPartVisitor->visit(this);
    }
};
class Monitor:public ComputerPart {
    public:
    void accept(const ComputerPartVisitor *computerPartVisitor) override{
    computerPartVisitor->visit(this);
}
};
class Mouse:public ComputerPart {
    public:
    void accept(const ComputerPartVisitor *computerPartVisitor)override{
    computerPartVisitor->visit(this);
}
};

class Computer:public ComputerPart {
    public:
    std::vector<std::shared_ptr<ComputerPart> > parts;
    Computer(){
        parts.push_back(std::make_shared<Mouse>());
        parts.push_back(std::make_shared<Keyboard>());
        parts.push_back(std::make_shared<Monitor>());
    }
    void accept(const ComputerPartVisitor *computerPartVisitor){
        for(auto part:parts){
            part->accept(computerPartVisitor);
        }
        computerPartVisitor->visit(this);
    }
};

int main()
{
    ComputerPart *computer = new Computer();
    computer->accept(new ComputerPartDisplayVisitor());
    return 0;
}