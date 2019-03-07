//compile using  g++ Chain.cpp -Wc++11-extensions -std=c++11
#include <string>
#include <memory>
#include <iostream>

class AbstractLogger{
    public:
    const static int INFO = 1;
    const static int DEBUG = 2;
    const static int ERROR = 3;
    void logMessage(int level,const std::string &message){
        if(this->level <= level){
            write(message);
        }
        if(nextLogger != nullptr){
            nextLogger->logMessage(level,message);
        }
    }

    void setNextLogger(std::shared_ptr<AbstractLogger> nextLogger){
      this->nextLogger = nextLogger;
    }

    protected:
    int level;
    std::shared_ptr<AbstractLogger> nextLogger;
    virtual void write(const std::string &message) = 0;

};

const int AbstractLogger::INFO;
const int AbstractLogger::DEBUG;
const int AbstractLogger::ERROR;

class ConsoleLogger:public AbstractLogger {
 
   public:
   ConsoleLogger(int level){
      this->level = level;
   }
   
   protected:
   void write(const std::string &message) override {    
      std::cout<<"Standard Console::Logger: "<<message<<std::endl;
   }
};

class ErrorLogger:public AbstractLogger {
 
   public:
   ErrorLogger(int level){
      this->level = level;
   }
   
   protected:
   void write(const std::string &message) override {    
      std::cout<<"Error Console::Logger: "<<message<<std::endl;
   }
};

class FileLogger:public AbstractLogger {
 
   public:
   FileLogger(int level){
      this->level = level;
   }
   
   protected:
   void write(const std::string &message) override {    
      std::cout<<"File::Logger: "<<message<<std::endl;
   }
};

std::shared_ptr<AbstractLogger> getChainOfLoggers(){
   
   std::shared_ptr<AbstractLogger> errorLogger = std::make_shared<ErrorLogger>(ConsoleLogger::ERROR);
   std::shared_ptr<AbstractLogger> fileLogger = std::make_shared<FileLogger>(ConsoleLogger::DEBUG);
   std::shared_ptr<AbstractLogger> consoleLogger = std::make_shared<ConsoleLogger>(ConsoleLogger::INFO);

   errorLogger->setNextLogger(fileLogger);
   fileLogger->setNextLogger(consoleLogger);
   return errorLogger;  
}


int main(){




    std::shared_ptr<AbstractLogger> loggerChain = getChainOfLoggers();

    loggerChain->logMessage(AbstractLogger::INFO, 
         "This is an information.");
 
    loggerChain->logMessage(AbstractLogger::DEBUG, 
         "This is an debug level information.");
 
    loggerChain->logMessage(AbstractLogger::ERROR, 
         "This is an error information.");

    return 0;
}