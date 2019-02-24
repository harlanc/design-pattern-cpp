 #include <memory>
 #include <string>
 #include <iostream>


 class User{
     private:
     int _id;
     std::string _name;
 };

 class UserOperation{
     public:
     virtual void Insert(const User &user) = 0;
     virtual User GetUser(int id) = 0;
 };

 class MongoUserOperation :public UserOperation{
     public :
     void Insert(const User &user){
         std::cout<<"MongoDB: insert user info"<<std::endl;
     }
     User GetUser(int id){
         std::cout<<"MongoDB: select User in id="<<id<<std::endl;
         return User();
     }
 };

 class MySQLUserOperation :public UserOperation{
     public :
     void Insert(const User &user){
         std::cout<<"MySQL: insert user info"<<std::endl;
     }
     User GetUser(int id){
         std::cout<<"MySQL: select User in id="<<id<<std::endl;
         return User();
     }
 };


 class Department{
     private:
     int _id;
     std::string _depName;

 };

 class DepartmentOperation{
     public:
     virtual void Insert(const Department &user) = 0;
     virtual Department GetDepartment(int id) = 0;
 };

 class MongoDepartmentOperation :public DepartmentOperation{
     public :
     void Insert(const Department &user){
         std::cout<<"MongoDB: insert Department info"<<std::endl;
     }
     Department GetDepartment(int id){
         std::cout<<"MongoDB: select Department in id="<<id<<std::endl;
         return Department();
     }
 };

 class MySQLDepartmentOperation :public DepartmentOperation{
     public :
     void Insert(const Department &user){
         std::cout<<"MySQL: insert Department info"<<std::endl;
     }
     Department GetDepartment(int id){
         std::cout<<"MySQL: select Department in id="<<id<<std::endl;
         return Department();
     }
 };

 class Factory{
     public:
     virtual std::shared_ptr<UserOperation> createUserOperation() = 0;
     virtual std::shared_ptr<DepartmentOperation> createDepartmentOperation() = 0;
 };

 class MySQLFactory:public Factory{
     std::shared_ptr<UserOperation> createUserOperation(){
         return std::make_shared<MySQLUserOperation>();
     }
     std::shared_ptr<DepartmentOperation> createDepartmentOperation(){
         return std::make_shared<MySQLDepartmentOperation>();
     }

 };

 class MongoFactory:public Factory{
     std::shared_ptr<UserOperation> createUserOperation(){
         return std::make_shared<MongoUserOperation>();
     }
     std::shared_ptr<DepartmentOperation> createDepartmentOperation(){
         return std::make_shared<MongoDepartmentOperation>();
     }
     
 };


 int main(){

     std::shared_ptr<Factory> f = std::make_shared<MongoFactory>();
     
     std::shared_ptr<UserOperation> useroperation = f->createUserOperation();
     User user = useroperation->GetUser(1);
     useroperation->Insert(user);

     std::shared_ptr<DepartmentOperation> depoperation = f->createDepartmentOperation();
     Department dep = depoperation->GetDepartment(2);
     depoperation->Insert(dep);
     
     return 0;
 }


