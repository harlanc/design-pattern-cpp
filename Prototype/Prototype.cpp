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
    private:

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

        *(rv->_work) = *(this->_work);

        return rv;
    }
};



int main()
{

    Resume resume(std::string("David"),std::string("male"),std::string("23"),std::string("HUAWEI"),std::string("2007-2009"));

    //std::
    
}