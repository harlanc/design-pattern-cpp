 //g++ Iterator.cpp -Wc++11-extensions -std=c++11

 #include <iostream>
 #include <memory>
 #include <vector>
 #include <string>
template <typename T>
 class Iterator{
     public:
     virtual bool hasNext() = 0;
     virtual T& next() = 0;

 };

template <typename T>
class Container{
    public:
    virtual Iterator<T>* getIterator() = 0;
    virtual void add(const T &data) = 0;
    virtual T& get(int idx) = 0;
    virtual int count() = 0;
};

template <typename T>
class NameRepository;

template <typename T>
class NameIterator : public Iterator<T>{

    public:
    NameIterator(Container<T> *namerepository){
        _namerepository = namerepository;
        _index = 0;
    }
    bool hasNext() override{
        return _index < _namerepository->count();
    }
    T& next() override{
        if(hasNext()){
            return _namerepository->get(_index++);
        }
        return _end;
    }

    private:
    Container<T> *_namerepository;
    int _index;
    static T _end;
};

template <typename T>
T NameIterator<T>::_end;

template <typename T>
class NameRepository:public Container<T> {
    public:
    NameRepository(){}

    Iterator<T>* getIterator() override{
        return new NameIterator<T>(this);
    }
    void add(const T &data) override{
        _data.push_back(data);
    }
    T& get(int idx) override{
        return _data[idx];
    }
    int count() override{
        return _data.size();
    }
    private:
    std::vector<T> _data; 
};



int main(){

    std::shared_ptr <NameRepository<std::string> > name = std::make_shared<NameRepository<std::string> >();

    name->add("one");
    name->add("two");
    name->add("three");

    std::cout<<"Count:"<<name->count()<<std::endl;
    Iterator<std::string> *iterator =  name->getIterator();

    //std::shared_ptr<Iterator<std::string> > iterator = name->getIterator();


//    std::cout<<"Count:"<<name->count()<<std::endl;
    while(iterator->hasNext()){
        std::cout<<iterator->next()<<std::endl;
    }

    delete iterator;
    // name.getIterator
    

    return 0;
}