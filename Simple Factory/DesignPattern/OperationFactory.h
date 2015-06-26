#pragma once
#include "Operation.h"
class OperationFactory
{
private:
	OperationFactory(void);
	static OperationFactory *_instance;


public:
	static Operation* GenerateOperation(char a)
	{
		Operation *op;
		switch(a)
		{
		    case '+':
			op = new AddOperation();
			break;
			case '-':
			op = new DelOperation();
			break;
			case '*':
			 op = new MultipleOperation();
			 break;
			case '/':
			 op = new DevideOperation();
			 break;
		}
		return  op;
	}




};

