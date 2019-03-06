//g++ Bridge.cpp -Wc++11-extensions -std=c++11

#include <iostream>
#include <memory>
class DrawAPI{
    public:
    virtual void drawCircle(int radius,int x,int y) = 0;
};

class RedCircle:public DrawAPI{
    public:
    void drawCircle(int radius,int x,int y){
        std::cout<<"Drawing Circle[ color: red, radius: "<<radius<<", x: "<<x<<", "<<y<<"]";
    }
};

class GreenCircle:public DrawAPI{
    public:
    void drawCircle(int radius,int x,int y){
        std::cout<<"Drawing Circle[ color: green, radius: "<<radius<<", x: "<<x<<", "<<y<<"]";
    }
};


class Shape{
    protected:
    std::shared_ptr<DrawAPI> _drawAPI;
    Shape(const std::shared_ptr<DrawAPI> &drawapi){
        _drawAPI = drawapi;
    }
    public:
    virtual void draw() = 0;
};


class Circle:public Shape{
    private:
    int _x, _y, _radius;
    
    public:
    Circle(int x, int y, int radius, const std::shared_ptr<DrawAPI> &drawapi):Shape(drawapi) {
        _x = x;  
        _y = y;  
        _radius = radius;
    }
 
   void draw(){
      _drawAPI->drawCircle(_radius,_x,_y);
   }
};

int main(){
    std::shared_ptr<Shape> redcircle = std::make_shared<Circle>(100,100,10,std::make_shared<RedCircle>());

    redcircle->draw();

    return 0;

}