//compile using  g++ Composite.cpp -Wc++11-extensions -std=c++11
#include <string>
#include <iostream>
#include <memory>
#include <set>

class Company{
    public:
    std::string _name;
    Company(const std::string &name){
        _name = name;
    }
    virtual void Add(const std::shared_ptr<Company> &c) = 0;
    virtual void Remove(const std::shared_ptr<Company> &c) = 0;
    virtual void Display(int depth) = 0;
    virtual void LineOfDuty() = 0;
};

class ConcreteCompany:public Company{
    public:
    ConcreteCompany(const std::string &name):Company(name){

    }
    void Add(const std::shared_ptr<Company> &c) override{

        _children.insert(c);
    }
    void Remove(const std::shared_ptr<Company> &c) override{

        _children.erase(c);
    }
    void Display(int depth) override{

        std::cout<<std::string(depth,'-')<<" "<<_name<<std::endl;
        for(auto c: _children){
            c->Display(depth+2);
        }
    }
    void LineOfDuty() override{

        for(auto c : _children){
            c->LineOfDuty();
        }
    }
    private:
    std::set<std::shared_ptr<Company> > _children;
};

class HRDepartment:public Company{
    public:
    HRDepartment(const std::string &name):Company(name){

    }
    void Add(const std::shared_ptr<Company> &c) override{

    }
    void Remove(const std::shared_ptr<Company> &c) override{
    
    }
    void Display(int depth) override{
        std::cout<<std::string(depth,'-')<<" "<<_name<<std::endl;
    }
    void LineOfDuty() override{
        std::cout<<_name<<" HRDepartment"<<std::endl;
    }
};

class ResearchDepartment:public Company{
    public:
    ResearchDepartment(const std::string &name):Company(name){

    }
    void Add(const std::shared_ptr<Company> &c) override{

    }
    void Remove(const std::shared_ptr<Company> &c) override{
    
    }
    void Display(int depth) override{
        std::cout<<std::string(depth,'-')<<" "<<_name<<std::endl;
    }
    void LineOfDuty() override{
        std::cout<<_name<<" ResearchDepartment"<<std::endl;
    }
};

int main(){
    std::shared_ptr<ConcreteCompany>  root = std::make_shared<ConcreteCompany>("北京总公司");
    root->Add(std::make_shared<HRDepartment>("总公司人力资源总部"));
    root->Add(std::make_shared<ResearchDepartment>("总公司研发总部"));

    std::shared_ptr<ConcreteCompany>  comp1 = std::make_shared<ConcreteCompany>("河北总公司");
    comp1->Add(std::make_shared<HRDepartment>("河北分公司人力资源部"));
    comp1->Add(std::make_shared<ResearchDepartment>("河北分公司研发部"));

    root->Add(comp1);

    root->Display(1);

    root->LineOfDuty();

    return 0;
}