#include<iostream>
#include"../binary/datetime.h"
#include"../binary/payment.h"

using namespace std;
void d1read(string filename);
void d2read(string filename);
void d3read(string filename);
void d4read(string filename);
class appointment
{
public:
	datetime dt;
	char city[20];
	char patientname[20];
	char Doctorname[20];
	//char appsituation[20];
	easypaisa ep;
	jazzcash jc;
	paypak pp;
	unionpay up;
	
	appointment()
	{
	}
	void setdatetime()
	{
		int date,month,year,hour,min;
		cout << "Enter the date month year hour min with space: ";
		cin>>date>>month>>year>>hour>>min;
		dt.setdate(date);
		dt.setmonth(month);
		dt.setyear(year);
		dt.sethours(hour);
		dt.setmin(min);
	}
	void setcity(string city)
	{
		strcpy_s(this->city, city.c_str());
	}
	void setpatientname(string city)
	{
		strcpy_s(this->patientname, city.c_str());
	}
	void setdoctorname(string city)
	{
		strcpy_s(this->Doctorname, city.c_str());
	}
	void setappointment();
	void showappointment()
	{
		cout << "patient name: "<<patientname<< endl;
		cout << "Doctor name: " << Doctorname << endl;
		cout << "City: " <<city<< endl;
		cout << "datetime: "<< dt.getdate() << "/" << dt.getmonth() << "/" << dt.getyear() << "    " << dt.gethours() << ":" << dt.getmin() << endl;
	}
	
};
void appointmentread(string file_name)
{
	appointment obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
		obj.showappointment();
	fin.close();
}
void appointmentwrite(string file_name, appointment obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
class videoconsultation
{

};
class in_person
{

};