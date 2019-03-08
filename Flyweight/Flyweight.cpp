//g++ Flyweight.cpp -Wc++11-extensions -std=c++11
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <vector>
class Shape{

    public:
    virtual void draw() = 0;
};

class Circle: public Shape{

    public:
    Circle(const std::string &color){
        this->color = color;     
    }
 
    void setX(int x) {
        this->x = x;
    }
 
    void setY(int y) {
        this->y = y;
    }
 
    void setRadius(int radius) {
        this->radius = radius;
    }
    
    void draw() override {
        std::cout<<"Circle: Draw() [Color : "<<color 
         <<", x : "<<x<<", y :"<<y<<", radius :"<<radius<<std::endl;
    }
    
    private:
    std::string color;
    int x,y,radius;
};

class ShapeFactory {
   public :
   static  std::map<std::string, std::shared_ptr<Circle> > circleMap;
 
   public:
   static std::shared_ptr<Circle> getCircle(const std::string &color) {
       
       if(circleMap.count(color) == 0) {
         std::shared_ptr<Circle> shape = std::make_shared<Circle>(color);
         circleMap.insert(std::pair<std::string,std::shared_ptr<Circle> >(color,shape));
         std::cout<<"Creating circle of color : "<<color;
      }
      return circleMap[color];
   }
};

void print(){
    for(auto a:ShapeFactory::circleMap){
        std::cout<<a.first<<":"<<a.second<<std::endl;
    }
}

std::map<std::string, std::shared_ptr<Circle> > ShapeFactory::circleMap;

int main()
{
    std::vector<std::string> colors;
    colors.push_back("Red");
    colors.push_back("Green");
    colors.push_back("Blue");
    colors.push_back("White");
    colors.push_back("Black");

    for(int i=0; i < 20; ++i) {
        std::shared_ptr<Circle>  circle = 
            ShapeFactory::getCircle(colors[i%5]);
        circle->setX(i);
        circle->setY(i+3);
        circle->setRadius(100);
        circle->draw();
        //print();
        std::cout<<"-------"<<std::endl;
    }

}