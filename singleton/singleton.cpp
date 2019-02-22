
#include <thread>
#include <iostream>
#include <memory>

template <class T>
class Singleton{

    public:
    static T* GetInstance(){

        if(_instance == nullptr){
            _lock->lock();
            if(_instance == nullptr){
                _instance = new T();
            }
            _lock->unlock();
        }
        return _instance;
    }
 
    private:
    Singleton(){}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    static T *_instance;//非const 的static 成员必须在列外进行初始化
    static std::mutex *_lock;
};

template <class T>
T* Singleton<T>::_instance = nullptr;

template <class T>
std::mutex* Singleton<T>::_lock = new std::mutex();

template <class T>
class Singleton11{
    public:
    static std::unique_ptr<T> GetInstance(){

        return _instance;

    }
    private:
    Singleton11(){
        
    }
    static std::unique_ptr<T> _instance;
};

template<class T>
std::unique_ptr<T> Singleton11<T>::_instance = std::unique_ptr<T>(new T());




template<class T>
class Singlenton_ehan{

    public:
    static T& GetInstance(){
        return _instance;
    }
    private:
    Singlenton_ehan(){}
    static T _instance;
};

template<class T>
T Singlenton_ehan<T>::_instance;


class TestSingleton{
    public:
    void PrintMyself(){
        std::cout<<static_cast<void*>(this)<<std::endl;
    }
};

int main()
{
    TestSingleton *instance = Singleton<TestSingleton>::GetInstance();
    std::cout<<static_cast<void*>(instance)<<std::endl;
    instance->PrintMyself();

    TestSingleton *instance2 = Singleton<TestSingleton>::GetInstance();
    instance2->PrintMyself();

    TestSingleton &instance3 = Singlenton_ehan<TestSingleton>::GetInstance();
    instance3.PrintMyself();

     TestSingleton &instance4 = Singlenton_ehan<TestSingleton>::GetInstance();
    instance4.PrintMyself();

    auto instance5 = Singleton11<TestSingleton>::GetInstance();
    instance5->PrintMyself();

    auto instance6 = Singleton11<TestSingleton>::GetInstance();
    instance6->PrintMyself();
    
    return 0;

}