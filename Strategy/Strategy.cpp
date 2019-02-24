#include <memory>
#include <iostream>

class CashSuper{
    public:
    virtual double acceptCash(double money) = 0;    
};
//正常收费
class CashNormal: public CashSuper{
    public:
    double acceptCash(double money) {
        return money;
    }
};
//打折
class CashRebate: public CashSuper{
    public:
    CashRebate(double moneyRebate){
        _moneyRebate = moneyRebate;
    }
    double acceptCash(double money) {
        return money*_moneyRebate;
    }

    private:
    double _moneyRebate;
};

class CashContext{
    public:
    CashContext(const std::shared_ptr<CashSuper> &cs){
        _cs = cs;
    }
    double GetResult(double money){
        return _cs->acceptCash(money);
    }
    private:
    std::shared_ptr<CashSuper> _cs;
};


int main(){
    auto ptr = std::make_shared<CashNormal>();
    auto rv = ptr->acceptCash(100);
    std::cout<<"Normal Cash is "<<rv<<std::endl;

    double rebate = 0.8;

    auto ptr2 = std::make_shared<CashRebate>(rebate);
    auto rv2 = ptr2->acceptCash(100);
    std::cout<<"Rebate Cash (0.8) is "<<rv2<<std::endl;

    return 0;
}