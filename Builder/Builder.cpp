//g++ Builder.cpp -Wc++11-extensions -std=c++11
#include <string>
#include <vector>
#include <iostream>

class Packing{
    public:
    virtual std::string pack() = 0;
};

class Item{
    public:
    virtual std::string name() = 0;
    virtual std::shared_ptr<Packing> packing() = 0;
    virtual float price() = 0;
};


class Wrapper : public Packing{
    public:
    std::string pack() override{
        return "Wrapper";
    }
};

class Bottle : public Packing{
    public:
    std::string pack() override{
        return "Bottle";
    }
};

class Burger : public Item{
    public:
    std::shared_ptr<Packing> packing() override{
        return std::make_shared<Wrapper>();
    }
};

class ColdDrink:public Item{
    std::shared_ptr<Packing> packing() override{
        return std::make_shared<Bottle>();
    }
};


class VegBurger : public Burger{
    public:
    float price() override{
        return 25.0;
    }
    std::string name() override{
        return "Veg BUrger";
    }

};

class ChickenBurger : public Burger{
    public:
    float price() override{
        return 50.0;
    }
    std::string name() override{
        return "Chicken BUrger";
    }

};

class Coke : public ColdDrink{
    public:
    float price() override{
        return 30.0f;
    }
    std::string name() override{ 
        return "Coke";
    }
};

class Pepsi : public ColdDrink{
    public:
    float price() override{
        return 31.0f;
    }
    std::string name() override{
        return "Pepsi";
    }
};

class Meal{
    public:
    std::vector<std::shared_ptr<Item> > _items;

    void addItem(const std::shared_ptr<Item> &item){
        _items.push_back(item);
    }

    float getTotalCost(){
        float cost = 0.0;
        for(auto v:_items){
            cost += v->price();
        }
        return cost;
    }

    void showItems(){
        for(auto v: _items){
            std::cout<<"Item :"<<v->name();
            std::cout<<", Packing :"<<v->packing()->pack();
            std::cout<<", Price :"<<v->price()<<std::endl;

        }
        std::cout<<"Total cost : "<<getTotalCost()<<std::endl;
    }
};

class MealBuilder{
    public:

    Meal prepareVegMeal(){
        Meal meal;

        meal.addItem(std::make_shared<VegBurger>());
        meal.addItem(std::make_shared<Coke>());
        return meal;
    }
};

int main(){

    MealBuilder builder;
    Meal meal = builder.prepareVegMeal();
    meal.showItems();


    return 0;
}