
//compile using  g++ testMove.cpp -Wc++11-extensions -std=c++11
#include <iostream>
using namespace std;

class Widget{

};

void process(const Widget &lval){
    cout<<"left value"<<endl;
}

void process(const Widget &&lval){
    cout<<"right value"<<endl;
}

template<typename T>
void logAndProcess(T&& param){
    process(std::forward<T>(param));
}


int main(){
    Widget w;
    logAndProcess(w);
    logAndProcess(std::move(w));
    return 0;
}