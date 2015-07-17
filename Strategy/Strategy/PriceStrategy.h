#pragma once
class PriceStrategy
{
public:
	PriceStrategy(void);
	~PriceStrategy(void);
	virtual double ComputeTotalPrice()
	{
		return 0;
	}
protected :
	double _signalPrice;
	double _productNum;
};

class PriceDiscount:public PriceStrategy
{
public:
	double ComputeTotalPrice()
	{
		return _signalPrice*_productNum*_discountRate;
	}
private:
	double _discountRate;

};

class PriceReturn:public PriceStrategy
{

};

