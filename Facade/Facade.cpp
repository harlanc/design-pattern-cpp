//g++ Facade.cpp -Wc++11-extensions -std=c++11
#include <iostream>
#include <memory>

class Shape{
    public:
    virtual void draw() = 0;
};

class Rectangle : public Shape{
    public:
    void draw() override {
        std::cout<<"draw Rectangle."<<std::endl;
    }
};

class Square : public Shape{
    public:
    void draw() override {
        std::cout<<"draw Square."<<std::endl;
    }
};

class Circle: public Shape{
    public:
    void draw() override {
        std::cout<<"draw Circle."<<std::endl;
    }
};

class ShapeMaker{

    private:
    std::shared_ptr<Rectangle> _rectangle;
    std::shared_ptr<Square> _square;
    std::shared_ptr<Circle> _circle;

    public:
    ShapeMaker(){
        _rectangle = std::make_shared<Rectangle>();
        _square = std::make_shared<Square>();
        _circle = std::make_shared<Circle>();
    }

    void drawCircle(){
        _circle->draw();
    }
    void drawSquare(){
        _square->draw();
    }
    void drawRectangle(){
        _rectangle->draw();
    }

};


int main(){

    std::shared_ptr<ShapeMaker> shapemaker(new ShapeMaker());
    shapemaker->drawCircle();
    shapemaker->drawRectangle();
    shapemaker->drawSquare();
    
    return 0;
}