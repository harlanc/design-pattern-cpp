//g++ Interpreter.cpp -Wc++11-extensions -std=c++11
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <vector>

//using unique_ptr this example is not necessary，but only for being familar with grammar
class Expression{
    public:
    virtual bool interpret(const std::string &context) = 0;
    virtual ~Expression(){}

};

class TerminalExpression:public Expression {
   
   private:
    std::string data;
 
   public:
    TerminalExpression(const std::string &data){
      this->data = data; 
   }
 
   bool interpret(const std::string &context) override{
      if(context.find(data) != std::string::npos){
         return true;
      }
      return false;
   }
};

class OrExpression:public Expression {
    private:
    std::unique_ptr<Expression>  expr1;
    std::unique_ptr<Expression>  expr2;
 
   public:
    OrExpression( std::unique_ptr<Expression> &expr1, std::unique_ptr<Expression> &expr2) { 
      this->expr1 = std::move(expr1);
      this->expr2 = std::move(expr2);
   }
   bool interpret(const std::string &context) {      
      return expr1->interpret(context) || expr2->interpret(context);
   }
};

class AndExpression: public Expression {
    
   private:
    std::unique_ptr<Expression>  expr1;
    std::unique_ptr<Expression>  expr2;
 
   public:
   AndExpression( std::unique_ptr<Expression> &expr1, std::unique_ptr<Expression> &expr2) { 
      this->expr1 = std::move(expr1);
      this->expr2 = std::move(expr2);
   }
   bool interpret(const std::string &context) override {      
    return expr1->interpret(context) && expr2->interpret(context);
   }
};

int main(){
    std::unique_ptr<Expression>  robert(new TerminalExpression("Robert"));
    std::unique_ptr<Expression>  john(new TerminalExpression("John"));
    std::unique_ptr<Expression> isMale(new OrExpression(robert, john));

    std::unique_ptr<Expression>  julie(new TerminalExpression("Julie"));
    std::unique_ptr<Expression>  married(new TerminalExpression("Married"));
    std::unique_ptr<Expression> isMarriedWoman(new AndExpression(julie, married));

    std::cout<<"John is Male? "<<isMale->interpret("John")<<std::endl;
    std::cout<<"Julie is a married women? "<<isMarriedWoman->interpret("Married Julie")<<std::endl;

}