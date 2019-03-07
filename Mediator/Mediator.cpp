//compile using  g++ Mediator.cpp -Wc++11-extensions -std=c++11

#include <string>
#include <iostream>
#include <memory>
class User;
class ChatRoom {
   public:
   static void showMessage(User *user, const std::string &message);
};

class User {
    private:
    std::string name;
    public :
    std::string getName() {
      return name;
    }
 
    void setName(const std::string &name) {
      this->name = name;
    }
 
    User(const std::string &name){
      this->name  = name;
    }
 
    void sendMessage(const std::string &message){
      ChatRoom::showMessage(this,message);
    }
};

void ChatRoom::showMessage(User *user, const std::string &message){
    std::cout<<" ["<<user->getName()<<"] : "<<message<<std::endl;
}


int main(){
    User robert("Robert");
    User john("John");

    robert.sendMessage("Hi! join!");
    john.sendMessage("Hellp! robert!");

}