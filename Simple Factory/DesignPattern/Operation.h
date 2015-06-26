#pragma once
  class Operation abstract
{
public:
	Operation(void);

	virtual double compute()=0;
	void SetA(double A)
	{
		_numberA = A;
	}
	void SetB(double B)
	{
		_numberB = B;
	}
protected:
	double _numberA , _numberB;
	

};

 class AddOperation:public Operation
{
public :
	
	virtual double compute() override
	{
		return _numberA + _numberB;
	}


};

 class DelOperation:public Operation
{
	public :
  
	virtual double compute() override
	{
		return _numberA - _numberB;
	}
};

 class MultipleOperation:public Operation
{
	public :

	  virtual double compute() override
	{
		return _numberA * _numberB;
	}

};

 class DevideOperation:public Operation
{
	public :

	virtual double compute() override
	{
		return _numberA / _numberB;
	}

};

