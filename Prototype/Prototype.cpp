//https://codereview.stackexchange.com/questions/65284/polymorphic-template-cloning-class

#include <string>
#include <iostream>
#include <memory>

template <typename T>
class ICloneable{
    public:
    virtual std::shared_ptr<T> clone() const = 0;
};


class WorkExperience{
    public:
    WorkExperience(){}
    WorkExperience(std::string &&date,std::string company){
        std::cout<<"constructor"<<std::endl;
        _workDate = std::move(date);
        _company = std::move(company);
    }
    //deep copy
    WorkExperience(const WorkExperience &work){
        std::cout<<"copy constructor"<<std::endl;
        this->_company = work._company;
        this->_workDate = work._workDate;
    }
    WorkExperience& operator = (const WorkExperience &work){
        std::cout<<"operator = "<<std::endl;
        _workDate = work._workDate;
        _company = work._company;
        return *this;
    }

    void setWorkDate(const std::string &date){
        _workDate = date;
    }

    void setCompany(const std::string &company){
        _company = company;
    }
    

    std::string _workDate;
    std::string _company;
};

class Resume : public ICloneable<Resume>{
    private:
    std::string _name;
    std::string _sex;
    std::string _age;
    std::shared_ptr<WorkExperience> _work;
    public:

    Resume(){
        _work = std::make_shared<WorkExperience>();

    }

    Resume(std::string &name,std::string &sex,std::string &age,std::string &date,std::string &company){

        _name = std::move(name);
        _sex = std::move(sex);
        _age = std::move(age);
        _work = std::make_shared<WorkExperience>(std::move(date),std::move(company));
    }

    void setCompany(const std::string &company){
        _work->setCompany(company);
    }

    void setWorkDate(const std::string &date){
        _work->setWorkDate(date);
    }

    std::shared_ptr<Resume> clone() const{

        std::shared_ptr<Resume> rv = std::make_shared<Resume>();

        rv->_name = this->_name;
        rv->_age = this->_age;
        rv->_sex = this->_sex;
        

        rv->setCompany(this->_work->_company);
        rv->setWorkDate(this->_work->_workDate);

        //*(rv->_work) = *(this->_work);

        return rv;
    }

    void PrintResume(){
        std::cout<<"Name: "<<_name<<std::endl;
        std::cout<<"Age: "<<_age<<std::endl;
        std::cout<<"Sex: "<<_sex<<std::endl;
        std::cout<<"Company: "<<_work->_company<<std::endl;
        std::cout<<"Date: "<<_work->_workDate<<std::endl;
    }
};



int main()
{

    std::string name("David");
    std::string sex("male");
    std::string age("18");
    std::string company("huawei");
    std::string date("2014-2019");

    Resume resume(name,sex,age,date,company);

    resume.PrintResume();

    std::shared_ptr<Resume> resume2 = resume.clone();

    resume2->PrintResume();

    resume2->setWorkDate("2013-2019");
    
    resume.PrintResume();
    resume2->PrintResume();

    return 0;

    //std::
    
}