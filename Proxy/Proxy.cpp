
#include <string>
#include <iostream>

//compile using  g++ Proxy.cpp -Wc++11-extensions -std=c++11
class NetworkOperator{
    public:
    virtual void Login(const std::string &url) = 0;
    virtual void DownloadResources(const std::string &url) = 0; 
};

class ChinaUnicom: public NetworkOperator{

    public:
    std::string _name;
    ChinaUnicom(){
        //std::cout<<"Call default constructor"<<std::endl;
    }

    ChinaUnicom(const std::string &name){
        _name = name;
    }

    ChinaUnicom & operator=(ChinaUnicom &&unicom){
        //std::cout<<"call move operator = "<<std::endl;
        this->_name =  std::move(unicom._name);
        return *this;
        //
    }
    void Login(const std::string &url){
        std::cout<<"Login webset: "<<url<<std::endl;
    }
    void DownloadResources(const std::string &url){
        std::cout<<"Download resources from "<<url<<std::endl;
    }
};

class NetworkProxy: public NetworkOperator{
    private:
    ChinaUnicom _unicom;
    void LoginProxy(){
        std::cout<<"First Login Proxy"<<std::endl;
    }
    public:
    
    NetworkProxy(ChinaUnicom &&unicom){
        _unicom = std::move(unicom);
        std::cout<<"The network operator name is "<<_unicom._name<<std::endl;
        LoginProxy();
    }

    void Login(const std::string &url){
        _unicom.Login(url);

    }
    void DownloadResources(const std::string &url){
        _unicom.DownloadResources(url);
    }
};

int main(){
 
    ChinaUnicom unicom("China Unicom");
    //why here call the default constructor first??
    NetworkProxy proxy(std::move(unicom));

    proxy.Login("https://www.google.com");
    proxy.DownloadResources("https://www.americaresources.com");

    return 0;
}




