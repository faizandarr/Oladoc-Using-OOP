#include<iostream>
using namespace std;
class payment
{
public:
	int ammount;

	
};
class etransaction :public payment
{
public:
	char phoneno[12];
};
class jazzcash: public etransaction
{

};
class easypaisa : public etransaction
{

};

///   off transaction
class bank_transfer:public payment
{
	char accountno[16];
};
class paypak: public bank_transfer
{

};
class unionpay : public bank_transfer
{

};