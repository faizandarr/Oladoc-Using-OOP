#include<iostream>
using namespace std;

class feedback
{
public:
	int stars;
	char feedbk[50];
	char patientname[50];
	char doctorname[50];
	


	feedback(int star=0,string haha="",string hehe = "",string hoho = "")
	{
		stars = star;
		strcpy_s(this->feedbk, haha.c_str());
		strcpy_s(this->patientname, hehe.c_str());
		strcpy_s(this->doctorname, hoho.c_str());
	}
	void fddisplay()
	{
		if (stars > 5 && stars<0)
			stars = 5;
		cout << "Stars by patient: " << stars<<endl;
		cout << "feedback by patient: " << feedbk << endl;
		cout << "Patient Name: " << patientname << endl;
		cout << "Doctor Name: " << doctorname << endl;
		cout << "****************************************" << endl;
	}

};
void fdwrite(string file_name, feedback obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
void fdread(string file_name)
{
	feedback obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
		obj.fddisplay();
	fin.close();
}