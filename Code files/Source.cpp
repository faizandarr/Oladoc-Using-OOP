#include<iostream>
#include<fstream>
#include<istream>
#include<string>
#include<cstring>
#include<string.h>
#include"../binary/appointment.h"
#include"../binary/feedback.h"

//#include"../binary/datetime.h"
using namespace std;
void pread(string file_name);

//void doctor::dregister();
class user {
public:
	int id;
	char cnic[20];
	char username[20];
	char password[20];
	char city[20];
	bool logging;


	int get_id()
	{
		return id;
	}
	char get_username()
	{
		return *username;
	}
	void set_cnic(string cnic)
	{
		strcpy_s(this->cnic, cnic.c_str());
	}
	void set_username(string name)
	{
		strcpy_s(this->username, name.c_str());
	}
	void set_password(string password)
	{
		strcpy_s(this->password, password.c_str());
	}
	void set_city(string ct)
	{
		strcpy_s(this->city, ct.c_str());
	}
};





void allapwrite(string file_name, appointment obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
void allapread(string file_name)
{
	appointment obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
		obj.showappointment();
	fin.close();
}







/////////////////////////////////////doctor//////////////////////////////////////////////////////////////////


class doctor : public user
{
public:
	int clinictime;
	int experience;
	int fees;
	int account;

	doctor(int id = 1, string cnic = "", string name = "", string password = "", bool log = 0, int exp = 0, int ct = 0, int fee = 0, int accounts = 0)
	{
		this->id = id;
		strcpy_s(this->cnic, cnic.c_str());
		strcpy_s(this->username, name.c_str());
		strcpy_s(this->password, password.c_str());
		experience = exp;
		clinictime = ct;
		fees = fee;
		account = accounts;
	}

	void ddisplay()
	{
		//cout << "CNIC :" << cnic << endl;
		cout << "UserName :" << username << endl;
		//cout << "password :" << password << endl;
		cout << "Clinchours :" << clinictime << endl;
		cout << "experience :" << experience << endl;
		cout << "Doctor fees :" << fees << endl;
	}
	void dmenu()
	{
		int choice;
		cout << "1.for registering\n2.for loging in\n3.for loging out" << endl;
		cin >> choice;

		if (choice == 1)
		{
			dregister();

		}
		if (choice == 2)
		{
			dlogin();

		}
		if (choice == 3)
		{
			//dlogout();
		}
		if (choice == 4)
		{
			dupdate();

		}
		if (choice == 5)
		{
			dshowdata();
		}

	}
	void seeapointments(string g)
	{

		appointment obj;
		fstream f("appointment.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{


			if (obj.Doctorname == g)
			{
				cout << "patients name: " << obj.patientname << endl;
				cout << "City Name: " << obj.city << endl;
			}
		}
	}
	void dregister()
	{
		bool a = 0, b = 0, c = 0, d = 0, z = 0;
		string usnm, pwd, CNIC = "";
		int hrs, exp, fee;
		cout << "registeration page : ";

		while (CNIC.length() != 13)
		{
			cout << "Enter the CNIC:";
			cin >> CNIC;
			cout << CNIC.length();
			if (CNIC.length() != 13)
				cout << "wrong input<<endl";
		}

		cout << "Enter the username:";
		cin >> usnm;
		doctor obj;
		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{


			if (obj.cnic != CNIC)
			{
				while (z != 1)
				{
					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
					cout << "Enter the password";
					cin >> pwd;
					if (pwd.length() >= 8)
						a = true;
					for (int i = 0; i < pwd.length(); i++) {
						if (pwd[i] >= '0' && pwd[i] <= '9')
							b = true;
						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
							c = true;
						if (pwd[i] >= 33 && pwd[i] <= 47)
							d = true;
					}
					cout << pwd.length();
					if (a == 1 && b == 1 && c == 1 && d == 1)
					{
						z = 1;

					}
					else
					{
						cout << "weak password try again!" << endl;
					}
				}
			}
			else
			{
				cout << "user already existed: " << endl;
				cout << "try another username:";
				cin >> usnm;
			}
		}
		cout << "Enter the clinic hours: ";
		cin >> hrs;
		cout << "Enter the experience in years: ";
		cin >> exp;
		cout << "Enter the Enter your fee: ";
		cin >> fee;

		experience = exp;
		clinictime = hrs;
		fees = fee;
		strcpy_s(cnic, CNIC.c_str());
		strcpy_s(username, usnm.c_str());
		strcpy_s(password, pwd.c_str());
		//id++;
	}
	void dlogin()
	{
		string g, h;
		int choicer;
		cout << "enter the username: " << endl;
		cin >> g;
		doctor obj;
		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				while (obj.password != h)
				{
					cout << "Enter the password: ";
					cin >> h;
					if (obj.password == h)
					{
						cout << "Congratulations you are login!" << endl;
						logging = 1;
						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
						cin >> choicer;
						if (choicer == 1)
						{
							dupdate();

						}
						if (choicer == 2)
						{
							dshowdata();

						}
						if (choicer == 3)
						{
							seeapointments(g);

						}
					}
					break;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
	void dupdate()
	{
		string g, h, n;
		int e, r;
		int choice;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("doctor.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == n)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					cout << "Enter the detail you change: ";
					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "Enter the new username: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_username(g);
								int a = f.tellg();
								int s = sizeof(doctor);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
						break;

					case 2:
						cout << "Enter the new password: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_password(g);
								int a = f.tellg();
								int s = sizeof(doctor);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
							else
							{
								cout << "can't change the password";
							}
						}
						break;
					case 3:
						cout << " Enter the updated experience hours: ";
						cin >> e;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = e;
								int a = f.tellg();
								int s = sizeof(doctor);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 4:
						cout << " Enter the updated clinic hours: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = r;
								int a = f.tellg();
								int s = sizeof(doctor);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 5:
						cout << " Enter the updated fees: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.fees = r;
								int a = f.tellg();
								int s = sizeof(doctor);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					}

				}
			}
			else
			{
				cout << "Incorrect Password!" << endl;
			}
			//f.write((char*)&obj, sizeof(obj));
			break;
		}
		f.close();

	}
	void dshowdata()
	{
		string g, h, n;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					while (f.read((char*)&obj, sizeof(obj)))
					{
						if (obj.username == n)
						{
							cout << obj.cnic << endl;
							cout << obj.username << endl;
							cout << obj.password << endl;
							cout << obj.account << endl;
							break;

						}
					}
				}
				else
				{
					cout << "Incorrect Password!" << endl;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}

};




















//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////specialization of doctor





class gynecologist :public doctor
{
public:
	void dmenu()
	{
		int choice;
		cout << "1.for registering\n2.for loging in\n3.for loging out" << endl;
		cin >> choice;

		if (choice == 1)
		{
			dregister();

		}
		if (choice == 2)
		{
			gynecologist::dlogin();

		}
		if (choice == 3)
		{
			//dlogout();
		}
		if (choice == 4)
		{
			dupdate();

		}
		if (choice == 5)
		{
			dshowdata();
		}

	}

	void dregister()
	{
		bool a = 0, b = 0, c = 0, d = 0, z = 0;
		string usnm, pwd, CNIC = "";
		int hrs=0, exp=0, fee=0;
		cout << "registeration page : ";

		while (CNIC.length() != 13)
		{
			cout << "Enter the CNIC:";
			cin >> CNIC;
			cout << CNIC.length();
			if (CNIC.length() != 13)
				cout << "wrong input<<endl";
		}

		cout << "Enter the username:";
		cin >> usnm;
		gynecologist obj;
		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{


			if (obj.username != usnm)
			{
				while (z != 1)
				{
					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
					cout << "Enter the password";
					cin >> pwd;
					if (pwd.length() >= 8)
						a = true;
					for (int i = 0; i < pwd.length(); i++) {
						if (pwd[i] >= '0' && pwd[i] <= '9')
							b = true;
						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
							c = true;
						if (pwd[i] >= 33 && pwd[i] <= 47)
							d = true;
					}
					cout << pwd.length();
					if (a == 1 && b == 1 && c == 1 && d == 1)
					{
						z = 1;

					}
					else
					{
						cout << "weak password try again!" << endl;
					}
					cout << "Enter the clinic hours: ";
					cin >> hrs;
					cout << "Enter the experience in years: ";
					cin >> exp;
					cout << "Enter the Enter your fee: ";
					cin >> fee;
				}
			}
			
		}
		

		experience = exp;
		clinictime = hrs;
		fees = fee;
		strcpy_s(cnic, CNIC.c_str());
		strcpy_s(username, usnm.c_str());
		strcpy_s(password, pwd.c_str());
		//id++;
	}
	void dlogin()
	{
		string g, h;
		int choicer;
		cout << "enter the username: " << endl;
		cin >> g;
		doctor obj;
		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				while (obj.password != h)
				{
					cout << "Enter the password: ";
					cin >> h;
					if (obj.password == h)
					{
						cout << "Congratulations you are login!" << endl;
						logging = 1;
						cout << "\n1.for update\n2. Show data\n3. See apointments\n4. See feedback" << endl;
						cin >> choicer;
						if (choicer == 1)
						{
							dupdate();

						}
						if (choicer == 2)
						{
							cout << "CNIC: " << obj.cnic << endl;
							cout << "USERNAME: " << obj.username << endl;
							cout << "PASSWORD: " << obj.password << endl;
							cout << "ACCOUNT:" << obj.account << endl;

						}
						if (choicer == 3)
						{
							seeapointments(g);
						}
						if (choicer == 4)
						{
							feedback oj;
							ifstream fin("feedback.dat", ios::binary | ios::app);
							while (fin.read((char*)&oj, sizeof(oj)))
								if (g == oj.doctorname)
								{
									oj.fddisplay();
								}
							fin.close();
						}
					}
					break;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
	void dupdate()
	{
		string g, h, n;
		int e, r;
		int choice;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("doctor.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == n)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					cout << "Enter the detail you change: ";
					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "Enter the new username: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_username(g);
								int a = f.tellg();
								int s = sizeof(gynecologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
						break;

					case 2:
						cout << "Enter the new password: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_password(g);
								int a = f.tellg();
								int s = sizeof(gynecologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
							else
							{
								cout << "can't change the password";
							}
						}
						break;
					case 3:
						cout << " Enter the updated experience hours: ";
						cin >> e;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = e;
								int a = f.tellg();
								int s = sizeof(gynecologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 4:
						cout << " Enter the updated clinic hours: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = r;
								int a = f.tellg();
								int s = sizeof(gynecologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 5:
						cout << " Enter the updated fees: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.fees = r;
								int a = f.tellg();
								int s = sizeof(gynecologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					}

				}
			}
			else
			{
				cout << "Incorrect Password!" << endl;
			}
			//f.write((char*)&obj, sizeof(obj));
			break;
		}
		f.close();

	}
	void dshowdata()
	{
		string g, h, n;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == n)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
							cout << obj.cnic << endl;
							cout << obj.username << endl;
							cout << obj.password << endl;
							cout << obj.account << endl;
							break;
				}
				else
				{
					cout << "Incorrect Password!" << endl;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}

};

////////////////////////////////////dermatologist



class dermatologist :public doctor
{
public:
	void dregister()
	{
		bool a = 0, b = 0, c = 0, d = 0, z = 0;
		string usnm, pwd, CNIC = "";
		int hrs, exp, fee;
		cout << "registeration page : ";

		while (CNIC.length() != 13)
		{
			cout << "Enter the CNIC:";
			cin >> CNIC;
			cout << CNIC.length();
			if (CNIC.length() != 13)
				cout << "wrong input<<endl";
		}

		cout << "Enter the username:";
		cin >> usnm;
		doctor obj;
		fstream f("Dermatologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{


			if (obj.cnic != CNIC)
			{
				while (z != 1)
				{
					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
					cout << "Enter the password";
					cin >> pwd;
					if (pwd.length() >= 8)
						a = true;
					for (int i = 0; i < pwd.length(); i++) {
						if (pwd[i] >= '0' && pwd[i] <= '9')
							b = true;
						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
							c = true;
						if (pwd[i] >= 33 && pwd[i] <= 47)
							d = true;
					}
					cout << pwd.length();
					if (a == 1 && b == 1 && c == 1 && d == 1)
					{
						z = 1;

					}
					else
					{
						cout << "weak password try again!" << endl;
					}
				}
			}
			else
			{
				cout << "user already existed: " << endl;
				cout << "try another username:";
				cin >> usnm;
			}
		}
		cout << "Enter the clinic hours: ";
		cin >> hrs;
		cout << "Enter the experience in years: ";
		cin >> exp;
		cout << "Enter the Enter your fee: ";
		cin >> fee;

		experience = exp;
		clinictime = hrs;
		fees = fee;
		strcpy_s(cnic, CNIC.c_str());
		strcpy_s(username, usnm.c_str());
		strcpy_s(password, pwd.c_str());
		//id++;
	}
	void dlogin()
	{
		string g, h;
		int choicer;
		cout << "enter the username: " << endl;
		cin >> g;
		doctor obj;
		fstream f("Dermatologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				while (obj.password != h)
				{
					cout << "Enter the password: ";
					cin >> h;
					if (obj.password == h)
					{
						cout << "Congratulations you are login!" << endl;
						logging = 1;
						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
						cin >> choicer;
						if (choicer == 1)
						{
							dupdate();

						}
						if (choicer == 2)
						{
							dshowdata();

						}
						if (choicer == 3)
						{
							seeapointments(g);

						}
					}
					break;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
	void dupdate()
	{
		string g, h, n;
		int e, r;
		int choice;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("Dermatologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == n)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					cout << "Enter the detail you change: ";
					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "Enter the new username: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_username(g);
								int a = f.tellg();
								int s = sizeof(dermatologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
						break;

					case 2:
						cout << "Enter the new password: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_password(g);
								int a = f.tellg();
								int s = sizeof(dermatologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
							else
							{
								cout << "can't change the password";
							}
						}
						break;
					case 3:
						cout << " Enter the updated experience hours: ";
						cin >> e;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = e;
								int a = f.tellg();
								int s = sizeof(dermatologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 4:
						cout << " Enter the updated clinic hours: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = r;
								int a = f.tellg();
								int s = sizeof(dermatologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 5:
						cout << " Enter the updated fees: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.fees = r;
								int a = f.tellg();
								int s = sizeof(dermatologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					}

				}
			}
			else
			{
				cout << "Incorrect Password!" << endl;
			}
			//f.write((char*)&obj, sizeof(obj));
			break;
		}
		f.close();

	}
	void dshowdata()
	{
		string g, h, n;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					while (f.read((char*)&obj, sizeof(obj)))
					{
						if (obj.username == n)
						{
							cout << obj.cnic << endl;
							cout << obj.username << endl;
							cout << obj.password << endl;
							cout << obj.account << endl;
							break;

						}
					}
				}
				else
				{
					cout << "Incorrect Password!" << endl;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
};

////////////////////oncologist/////////////////////////////////////////////////////////////////






class oncologist :public doctor
{
public:
	void dregister()
	{
		bool a = 0, b = 0, c = 0, d = 0, z = 0;
		string usnm, pwd, CNIC = "";
		int hrs, exp, fee;
		cout << "registeration page : ";

		while (CNIC.length() != 13)
		{
			cout << "Enter the CNIC:";
			cin >> CNIC;
			cout << CNIC.length();
			if (CNIC.length() != 13)
				cout << "wrong input<<endl";
		}

		cout << "Enter the username:";
		cin >> usnm;
		doctor obj;
		fstream f("Oncologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{


			if (obj.cnic != CNIC)
			{
				while (z != 1)
				{
					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
					cout << "Enter the password";
					cin >> pwd;
					if (pwd.length() >= 8)
						a = true;
					for (int i = 0; i < pwd.length(); i++) {
						if (pwd[i] >= '0' && pwd[i] <= '9')
							b = true;
						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
							c = true;
						if (pwd[i] >= 33 && pwd[i] <= 47)
							d = true;
					}
					cout << pwd.length();
					if (a == 1 && b == 1 && c == 1 && d == 1)
					{
						z = 1;

					}
					else
					{
						cout << "weak password try again!" << endl;
					}
				}
			}
			else
			{
				cout << "user already existed: " << endl;
				cout << "try another username:";
				cin >> usnm;
			}
		}
		cout << "Enter the clinic hours: ";
		cin >> hrs;
		cout << "Enter the experience in years: ";
		cin >> exp;
		cout << "Enter the Enter your fee: ";
		cin >> fee;

		experience = exp;
		clinictime = hrs;
		fees = fee;
		strcpy_s(cnic, CNIC.c_str());
		strcpy_s(username, usnm.c_str());
		strcpy_s(password, pwd.c_str());
		//id++;
	}
	void dlogin()
	{
		string g, h;
		int choicer;
		cout << "enter the username: " << endl;
		cin >> g;
		doctor obj;
		fstream f("Oncologoist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				while (obj.password != h)
				{
					cout << "Enter the password: ";
					cin >> h;
					if (obj.password == h)
					{
						cout << "Congratulations you are login!" << endl;
						logging = 1;
						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
						cin >> choicer;
						if (choicer == 1)
						{
							dupdate();

						}
						if (choicer == 2)
						{
							dshowdata();

						}
						if (choicer == 3)
						{
							seeapointments(g);

						}
					}
					break;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
	void dupdate()
	{
		string g, h, n;
		int e, r;
		int choice;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("Oncologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == n)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					cout << "Enter the detail you change: ";
					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "Enter the new username: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_username(g);
								int a = f.tellg();
								int s = sizeof(oncologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
						break;

					case 2:
						cout << "Enter the new password: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_password(g);
								int a = f.tellg();
								int s = sizeof(oncologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
							else
							{
								cout << "can't change the password";
							}
						}
						break;
					case 3:
						cout << " Enter the updated experience hours: ";
						cin >> e;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = e;
								int a = f.tellg();
								int s = sizeof(oncologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 4:
						cout << " Enter the updated clinic hours: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = r;
								int a = f.tellg();
								int s = sizeof(oncologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 5:
						cout << " Enter the updated fees: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.fees = r;
								int a = f.tellg();
								int s = sizeof(oncologist);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					}

				}
			}
			else
			{
				cout << "Incorrect Password!" << endl;
			}
			//f.write((char*)&obj, sizeof(obj));
			break;
		}
		f.close();

	}
	void dshowdata()
	{
		string g, h, n;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("Oncologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					while (f.read((char*)&obj, sizeof(obj)))
					{
						if (obj.username == n)
						{
							cout << obj.cnic << endl;
							cout << obj.username << endl;
							cout << obj.password << endl;
							cout << obj.account << endl;
							break;

						}
					}
				}
				else
				{
					cout << "Incorrect Password!" << endl;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
};

////////////////////////////////////////////////////orthopedic//////////////////////////////////


class orthopedic :public doctor
{
public:
	void dregister()
	{
		bool a = 0, b = 0, c = 0, d = 0, z = 0;
		string usnm, pwd, CNIC = "";
		int hrs, exp, fee;
		cout << "registeration page : ";

		while (CNIC.length() != 13)
		{
			cout << "Enter the CNIC:";
			cin >> CNIC;
			cout << CNIC.length();
			if (CNIC.length() != 13)
				cout << "wrong input<<endl";
		}

		cout << "Enter the username:";
		cin >> usnm;
		doctor obj;
		fstream f("orthopedic.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{


			if (obj.cnic != CNIC)
			{
				while (z != 1)
				{
					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
					cout << "Enter the password";
					cin >> pwd;
					if (pwd.length() >= 8)
						a = true;
					for (int i = 0; i < pwd.length(); i++) {
						if (pwd[i] >= '0' && pwd[i] <= '9')
							b = true;
						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
							c = true;
						if (pwd[i] >= 33 && pwd[i] <= 47)
							d = true;
					}
					cout << pwd.length();
					if (a == 1 && b == 1 && c == 1 && d == 1)
					{
						z = 1;

					}
					else
					{
						cout << "weak password try again!" << endl;
					}
				}
			}
			else
			{
				cout << "user already existed: " << endl;
				cout << "try another username:";
				cin >> usnm;
			}
		}
		cout << "Enter the clinic hours: ";
		cin >> hrs;
		cout << "Enter the experience in years: ";
		cin >> exp;
		cout << "Enter the Enter your fee: ";
		cin >> fee;

		experience = exp;
		clinictime = hrs;
		fees = fee;
		strcpy_s(cnic, CNIC.c_str());
		strcpy_s(username, usnm.c_str());
		strcpy_s(password, pwd.c_str());
		//id++;
	}
	void dlogin()
	{
		string g, h;
		int choicer;
		cout << "enter the username: " << endl;
		cin >> g;
		doctor obj;
		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				while (obj.password != h)
				{
					cout << "Enter the password: ";
					cin >> h;
					if (obj.password == h)
					{
						cout << "Congratulations you are login!" << endl;
						logging = 1;
						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
						cin >> choicer;
						if (choicer == 1)
						{
							dupdate();

						}
						if (choicer == 2)
						{
							dshowdata();

						}
						if (choicer == 3)
						{
							seeapointments(g);

						}
					}
					break;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
	void dupdate()
	{
		string g, h, n;
		int e, r;
		int choice;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("orthopedic.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == n)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					cout << "Enter the detail you change: ";
					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "Enter the new username: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_username(g);
								int a = f.tellg();
								int s = sizeof(orthopedic);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
						break;

					case 2:
						cout << "Enter the new password: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_password(g);
								int a = f.tellg();
								int s = sizeof(orthopedic);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
							else
							{
								cout << "can't change the password";
							}
						}
						break;
					case 3:
						cout << " Enter the updated experience hours: ";
						cin >> e;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = e;
								int a = f.tellg();
								int s = sizeof(orthopedic);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 4:
						cout << " Enter the updated clinic hours: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.experience = r;
								int a = f.tellg();
								int s = sizeof(orthopedic);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					case 5:
						cout << " Enter the updated fees: ";
						cin >> r;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.fees = r;
								int a = f.tellg();
								int s = sizeof(orthopedic);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
					}

				}
			}
			else
			{
				cout << "Incorrect Password!" << endl;
			}
			//f.write((char*)&obj, sizeof(obj));
			break;
		}
		f.close();

	}
	void dshowdata()
	{
		string g, h, n;
		cout << "enter the username: " << endl;
		cin >> n;
		doctor obj;
		fstream f("orthopedic.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == g)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					while (f.read((char*)&obj, sizeof(obj)))
					{
						if (obj.username == n)
						{
							cout << obj.cnic << endl;
							cout << obj.username << endl;
							cout << obj.password << endl;
							cout << obj.account << endl;
							break;

						}
					}
				}
				else
				{
					cout << "Incorrect Password!" << endl;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////

void d1write(string file_name, gynecologist obj);
void d2write(string file_name, dermatologist obj);
void d3write(string file_name, oncologist obj);
void d4write(string file_name, orthopedic obj);



void deletee(string file_name, int id)
{
	doctor obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.get_id() == id)
		{
			obj.set_username("");
			obj.set_cnic("");
			obj.set_password("");
			int a = f.tellg();
			int s = sizeof(gynecologist);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			break;

		}
	}

	f.close();
}



class admin : public user
{

public:
	admin(string usnm, string paascode)
	{
		strcpy_s(this->username, usnm.c_str());
		strcpy_s(this->password, paascode.c_str());
	}
	void amenu()
	{
		string h, g,dc;
		int choice, dchoice;
		doctor j;
		gynecologist q;
		dermatologist w;
		oncologist e;
		orthopedic r;


		while (h != "hasham")
		{
			cout << "ENter your username to login" << endl;
			cin >> h;
			if (h == "hasham")
			{
				while (g != "flamingo")
				{
					cout << "Enter the password: ";
					cin >> g;
					if (g == "flamingo")
					{
						cout << "congratulation your are login!" << endl;
						cout << "1.add doctor\n2.edit doctor\n3.delete doctor\n4.view doctor\n5.view all patient\n6.Appointments" << endl;
						cin >> choice;

						if (choice == 1)
						{
							cout << "Of Which specialization: " << endl;
							cout << "1. Gynecologist\n2. Dermatologist3. Oncologist\n4. Orthopedic" << endl;
							cin >> dchoice;
							switch (dchoice)
							{
							case 1:
								q.gynecologist::dregister();
								d1write("Gynecologist.dat", q);
								break;

							case 2:
								w.dermatologist::dregister();
								d2write("Dermatologist.dat", w);
								break;

							case 3:
								e.oncologist::dregister();
								d3write("Oncologist.dat", e);
								break;
							case 4:
								r.orthopedic::dregister();
								d4write("orthopedic.dat", r);
								break;
							}

							break;
						}
						if (choice == 2)
						{
							cout << "Of Which specialization: " << endl;
							cout << "1. Gynecologist\n2. Dermatologist3. Oncologist\n4. Orthopedic" << endl;
							cin >> dchoice;
							switch (dchoice)
							{
							case 1:
								q.gynecologist::dupdate();
								d1write("Gynecologist.dat", q);
								break;

							case 2:
								w.dermatologist::dupdate();
								d2write("Dermatologist.dat", w);
								break;

							case 3:
								e.oncologist::dupdate();
								d3write("Oncologist.dat", e);
								break;
							case 4:
								r.orthopedic::dupdate();
								d4write("orthopedic.dat", r);
								break;
							}

							break;
						}
						if (choice == 3)
						{
							gynecologist obj;
							fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
							dermatologist obj1;
							fstream g("Dermatologist.dat", ios::out | ios::in | ios::binary);
							oncologist obj2;
							fstream k("Oncologist.dat", ios::out | ios::in | ios::binary);
							orthopedic obj3;
							fstream l("orthopedic.dat", ios::out | ios::in | ios::binary);
							cout << "Of Which specialization: " << endl;
							cout << "1. Gynecologist\n2. Dermatologist3. Oncologist\n4. Orthopedic" << endl;
							cin >> dchoice;
							switch (dchoice)
							{
							case 1:
								d1read("Gynecologist.dat");
								cout << "enter the name of doctor: ";
								cin >> dc;
								//doctor obj;
								while (f.read((char*)&obj, sizeof(obj)))
								{
									if (obj.username == dc)
									{
										obj.set_username("");
										obj.set_cnic("");
										obj.set_password("");
										int a = f.tellg();
										int s = sizeof(gynecologist);
										f.seekp(a - s, ios::beg);
										f.write((char*)&obj, sizeof(obj));
										break;

									}
								}
								break;

							case 2:
								w.dermatologist::dupdate();
								d2write("Dermatologist.dat", w);
								break;

							case 3:
								e.oncologist::dupdate();
								d3write("Oncologist.dat", e);
								break;
							case 4:
								r.orthopedic::dupdate();
								d4write("orthopedic.dat", r);
								break;
							}
						}
						if (choice == 4)
						{
							d1read("Gynecologist.dat");
							d2read("Dermatologist.dat");
							d3read("Oncologist.dat");
							d4read("orthopedic.dat");
						}
						if (choice == 5)
						{
							pread("patient.dat");
							break;
						}
						if (choice == 6)
						{
							allapread("appointment.dat");
						}
					}
					else
					{
						cout << "wrong password" << endl;
					}
				}
			}
			else
			{
				cout << "No admin with this name" << endl;
			}
		}

	}
};










class patient:public user
{
	appointment o;
	feedback fbk;
public:
	patient(int id=1, string cnic="", string name = "", string password = "",bool log=0)
	{
		//f = new feedback;
		//o = new appointment;
		this->id = id;
		strcpy_s(this->cnic, cnic.c_str());
		strcpy_s(this->username, name.c_str());
		strcpy_s(this->password, password.c_str());
	}

	void pdisplay()
	{
		cout << "Id : " << id << endl;
		cout << "CNIC :" << cnic << endl;
		cout << "UserName :" << username << endl;
		cout << "password :" << password << endl;
		
	}
	void pmenu()
	{
		int choice;
		cout << "1.for registering\n2.for loging in" << endl;
		cin >> choice;

		if (choice == 1)
		{
			pregister();
		}
		if (choice == 2)
		{
			plogin();
			//appointmentwrite("appointments", o);
		}
		
		
		//cout << "DO you want to continue: ";
		//cin >> x;
	}
	void pregister()
	{
		bool a=0, b=0, c=0,d=0,z=0;
		string usnm, pwd, CNIC = "";
		cout << "registeration page : ";

		while (CNIC.length() != 13)
		{
			cout << "Enter the CNIC:";
			cin >> CNIC;
			cout << CNIC.length();
			if (CNIC.length() != 13)
				cout << "wrong input"<<endl;
		}
		patient obj;
		fstream f("patient.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.cnic == CNIC)
			{
				cout << "user already existed: " << endl;
				//f.write((char*)&obj, sizeof(obj));
				return;

			}
		}
		



		cout << "Enter the username:";
		cin >> usnm;
		if (username == usnm)
		{
			cout << "Username already exists" << endl;
			return;
		}
		
		while (z!=1)
		{
			cout << "Enter the password";
			cin >> pwd;
			if (pwd.length() >= 8)
				a = true;
			for (int i = 0; i < pwd.length(); i++) {
				if (pwd[i] >= '0' && pwd[i] <= '9')
					b = true;
				if (pwd[i] >= 'A' && pwd[i] <= 'Z')
					c = true;
				if (pwd[i] >= 33 && pwd[i] <= 47)
					d = true;
			}
			cout << pwd.length();
			if (a == 1 && b == 1 && c == 1 && d == 1)
			{
				z = 1;
				
			}
			else
			{
				cout << "weak password try again!" << endl;
			}
		}


		strcpy_s(cnic, CNIC.c_str());
		strcpy_s(username, usnm.c_str());
		strcpy_s(password, pwd.c_str());
		//id++;
	}
	void plogin()
	{
			string g, h;
			int pchoice;
			cout << "enter the username: " << endl;
			cin >> g;
			patient obj;
			fstream f("patient.dat", ios::out | ios::in | ios::binary);
			while (f.read((char*)&obj, sizeof(obj)))
			{

				if (obj.username == g)
				{
					while (obj.password != h)
					{
						cout << "Enter the password: ";
						cin >> h;
						if (obj.password == h)
						{
							cout << "Congratulations you are login!" << endl;
							logging = 1;
							cout << "What do you want to do! " << endl << "1. update\n2. show data\n3. book appointment: \n4. show my appointment:\n5. give feedback:\n5. cancel appointment:" << endl;
							cin >> pchoice;
							if (pchoice == 1)
							{
								pupdate();
							}
							if (pchoice == 2)
							{
								pshowdata();
							}
							if (pchoice == 3)
							{
								pappointment();
							}
							if (pchoice == 4)
							{
								string f;
								cout << "\nEnter the patient name: ";
								cin >> f;
								appointment ob;
								ifstream fin("appointment.dat", ios::binary | ios::app);
								while (fin.read((char*)&ob, sizeof(ob)))
								{
									if (ob.patientname == f)
									{
										ob.showappointment();
									}
								}
								fin.close();
							}
							if (pchoice == 6)
							{
								string ff;
								cout << "\nEnter the patient name: ";
								cin >> ff;
								appointment ob;
								gynecologist oo;
								dermatologist dd;
								oncologist on;
								orthopedic ot;
								ifstream fin("appointment.dat", ios::binary | ios::app);
								while (fin.read((char*)&ob, sizeof(ob)))
								{
									if (ob.patientname == ff)
									{
										gynecologist obj;
										fstream f("Gynecologist", ios::out | ios::in | ios::binary);
										cout << "haha" << endl;
										while (f.read((char*)&obj, sizeof(obj)))
										{
											if (ob.Doctorname == obj.username)
											{
												cout << "hahaaaaa" << endl;
												obj.account= obj.account-obj.fees;
												int a = f.tellg();
												int s = sizeof(gynecologist);
												f.seekp(a - s, ios::beg);
												f.write((char*)&obj, sizeof(obj));
												break;

											}
										}
										cout << "hhhhhhhhhh" << endl;
										ob.setpatientname("");
										ob.setcity("");
										ob.setdoctorname("");
										int a = f.tellg();
										int s = sizeof(appointment);
										f.seekp(a - s, ios::beg);
										f.write((char*)&ob, sizeof(ob));

									}
								}
								fin.close();
							}
							if (pchoice == 5)
							{
								char a[50];
								string h, d, fback;
								int s;
								cout << "Enter the doctor name: ";
								cin >> d;
								doctor ddd;
								ifstream fin("Gynecologist.dat", ios::binary | ios::app);
								while (fin.read((char*)&ddd, sizeof(ddd)))
								{
									if (ddd.username == d)
									{
										cout << "Enter the feedback: ";
										cin >> fback;
										cout << "Give the stars: ";
										cin >> s;
										strcpy_s(fbk.feedbk, fback.c_str());
										strcpy_s(fbk.doctorname, d.c_str());
										strcpy_s(fbk.patientname, g.c_str());
										fbk.stars = s;
										fdwrite("feedback.dat", fbk);
									}
								}
								fin.close();


							}
							appointmentwrite("appointment.dat", o);
						}
					}
					
					//f.write((char*)&obj, sizeof(obj));
					break;

				}
			}
			f.close();
			
	}
	void pupdate()
	{
		string g, h,n;
		int choice;
		cout << "enter the username: " << endl;
		cin >> n;
		patient obj;
		fstream f("patient.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == n)
			{
				cout << "Enter the password: ";
				cin >> h;
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					cout << "Enter the detail you change: ";
					cout << "1.username\n2.password" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
						cout << "Enter the new username: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_username(g);
								int a = f.tellg();
								int s = sizeof(patient);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
						}
						break;

					case 2:
						cout << "Enter the new password: ";
						cin >> g;
						while (f.read((char*)&obj, sizeof(obj)))
						{
							if (obj.username == n)
							{
								obj.set_password(g);
								int a = f.tellg();
								int s = sizeof(patient);
								f.seekp(a - s, ios::beg);
								f.write((char*)&obj, sizeof(obj));
								break;

							}
							else
							{
								cout << "can't change the password";
							}
						}
						break;
					}
				}
				else
				{
					cout << "Incorrect Password!" << endl;
				}
				//f.write((char*)&obj, sizeof(obj));
				break;

			}
		}
		f.close();

	}
	void pshowdata()
	{
		string g, h, n ;
		cout << "enter the username: " << endl;
		cin >> n;
		patient obj;
		fstream f("patient.dat", ios::out | ios::in | ios::binary);
		while (f.read((char*)&obj, sizeof(obj)))
		{

			if (obj.username == n)
			{
				while (obj.password != h)
				{

					cout << "Enter the password: ";
					cin >> h;
				}
				if (obj.password == h)
				{
					cout << "Congratulations you are login!" << endl;
					logging = 1;
					while (f.read((char*)&obj, sizeof(obj)))
					{
						if (obj.username == n)
						{
							cout << obj.cnic << endl;
							cout << obj.username << endl;
							cout << obj.password << endl;
							break;

						}
					}
				}
				else
				{
					cout << "Incorrect Password!" << endl;
				}
				//f.write((char*)&obj, sizeof(obj));
			}
		}
		f.close();

	}
	void pappointment()
	{
		o.setappointment();
	}
};



/////////////////////////////////File handling matters///////////////////////////////////////////////////////////////////


void pwrite(string file_name, patient obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
void pread(string file_name)
{
	patient obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
		obj.pdisplay();
	fin.close();
}


////doctors
void d1write(string file_name, gynecologist obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
void d1read(string file_name)
{
	gynecologist obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while(fin.read((char*)&obj, sizeof(obj)))
	obj.ddisplay();
	fin.close();
}
void d2write(string file_name, dermatologist obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
void d2read(string file_name)
{
	dermatologist obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
		obj.ddisplay();
	fin.close();
}
//
void d4write(string file_name, orthopedic obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
void d4read(string file_name)
{
	orthopedic obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
		obj.ddisplay();
	fin.close();
}
//
void d3write(string file_name, oncologist obj)
{
	ofstream fout(file_name, ios::binary | ios::app);
	fout.write((char*)&obj, sizeof(obj));
	fout.close();
}
void d3read(string file_name)
{
	oncologist obj;
	ifstream fin(file_name, ios::binary | ios::app);
	while (fin.read((char*)&obj, sizeof(obj)))
		obj.ddisplay();
	fin.close();
}
void deleteee(string file_name, int id, string updated_name)
{
	patient obj;
	fstream f(file_name, ios::out | ios::in | ios::binary);
	while (f.read((char*)&obj, sizeof(obj)))
	{
		if (obj.get_id() == id)
		{
			obj.set_username("");
			obj.set_cnic("");
			obj.set_password("");
			int a = f.tellg();
			int s = sizeof(patient);
			f.seekp(a - s, ios::beg);
			f.write((char*)&obj, sizeof(obj));
			break;

		}
	}
	
	f.close();
}

int main()
{		
	/*appointmentread("appointment.dat");
	cout << ".............................................................................................." << endl;
	fdread("feedback.dat");
	cout << ".............................................................................................." << endl;
	pread("patient.dat");
	cout << ".............................................................................................." << endl;
	d1read("Gynecologist.dat");*/
		int choice,dchoice;
		patient s;
		user *d;
		d = new doctor;
		//doctor d;
		gynecologist q;
		dermatologist w;
		oncologist e;
		orthopedic r;
		admin a("","");
		cout << "WELCOME TO THE APPLICATION OF OLADOC" << endl;
		char x = 'y';

		while (x == 'Y' || x == 'y')
		{
			cout << "Select the login type: " << endl;
			cout << "1.Admin\n2.Doctor\n3.patient" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:

				a.amenu();
				break;
			case 2:
				cout << "Which specialization you belong: " << endl;
				cout << "1. Gynecologist\n2. Dermatologist3. Oncologist\n4. Orthopedic" << endl;
				cin >> dchoice;
				switch (dchoice)
				{
				case 1:
					q.gynecologist::dmenu();
					d1write("Gynecologist.dat",q);
					break;

				case 2:
					w.dmenu();
					d2write("Dermatologist.dat",w);
					break;

				case 3:
					e.dmenu();
					d3write("Oncologist.dat",e);
					break;
				case 4:
					r.dmenu();
					d4write("orthopedic.dat",r);
					break;
				}
				//d.dmenu();
				
				break;
			case 3:
				s.pmenu();
				if (s.cnic[0] != '\0')
				{
					pwrite("patient.dat", s);
				}
				break;
			
			}
			x = '\0';
			cout << "Would you like to continue:(y/n) ";
			cin >> x;
		}
}

void appointment:: setappointment()
{
	string pt;
	doctor obj;
	fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
	int dchoice;
	int paymentchoice;
	int paymentchoice2;
	string e;
	cout << "Which catagory of doctor you want to deal:" << endl;
	cout << "1. Gynecologist\n2. Dermatologist3. Oncologist\n4. Orthopedic" << endl;
	cin >> dchoice;
	switch (dchoice)
	{
	case 1:
		cout << "Here all the gynecologist doctor: ";
		d1read("Gynecologist.dat");
		cout << "enter the doctor name: ";
		cin >> e;



		while (f.read((char*)&obj, sizeof(obj)))
		{
			if (obj.username == e)
			{
				setdatetime();
				cout << "Enter the name of Patient: " << endl;
				cin >> pt;
				setpatientname(pt);
				cout << "Enter the name of City: " << endl;
				cin >> pt;
				setcity(pt);
				strcpy_s(Doctorname, e.c_str());
				cout << "Enter the payment option: " << endl<<"1.bank payment\n2.e-transaction\n";
				cin >> paymentchoice;
				if (paymentchoice == 1)
				{
					cout << "1.PayPak\n2.UnionPay";
					cin >> paymentchoice2;
					if (paymentchoice2 == 1)
					{
						string acn;
						cout << "enter your Bank account number: ";
						while (acn.length() != 16)
						{
							cin >> acn;
							if (acn.length() != 16)
							{
								cout << "enter correct number: " << endl;
							}
						}
						strcpy_s(this->ep.phoneno, acn.c_str());
						obj.account = obj.account + obj.fees;
						int a = f.tellg();
						int s = sizeof(gynecologist);
						f.seekp(a - s, ios::beg);
						f.write((char*)&obj, sizeof(obj));

					}
					if (paymentchoice == 2)
					{
						string acn;
						cout << "enter your Union pay account number: ";
						while (acn.length() != 11)
						{
							cin >> acn;
							if (acn.length() != 11)
							{
								cout << "enter correct number: " << endl;
							}
						}
						strcpy_s(this->ep.phoneno, acn.c_str());
						obj.account = obj.account + obj.fees;
						int a = f.tellg();
						int s = sizeof(gynecologist);
						f.seekp(a - s, ios::beg);
						f.write((char*)&obj, sizeof(obj));

					}
				}
				if (paymentchoice == 2)
				{
					cout << "1.Easypaisa\n2.JazzCash";
					cin >> paymentchoice2;
					if (paymentchoice2 == 1)
					{
						string acn;
						cout << "enter your easypaisa account number: ";
						while (acn.length() != 11)
						{
							cin >> acn;
							if (acn.length() != 11)
							{
								cout << "enter correct number: " << endl;
							}
						}
						strcpy_s(this->ep.phoneno, acn.c_str());
						obj.account = obj.account + obj.fees;
						int a = f.tellg();
						int s = sizeof(gynecologist);
						f.seekp(a - s, ios::beg);
						f.write((char*)&obj, sizeof(obj));

					}
					if (paymentchoice2 == 2)
					{
						string acn;
						cout << "enter your jazzCash account number: ";
						while (acn.length() != 11)
						{
							cin >> acn;
							if (acn.length() != 11)
							{
								cout << "enter correct number: " << endl;
							}
						}
						strcpy_s(this->ep.phoneno, acn.c_str());
						obj.account = obj.account + obj.fees;
						int a = f.tellg();
						int s = sizeof(gynecologist);
						f.seekp(a - s, ios::beg);
						f.write((char*)&obj, sizeof(obj));
					}
				}
				cout << "appointment book with dr " << Doctorname << endl;
				return;
			}
		}
		break;
	case 2:
		cout << "Here all the dermatalogist doctor: ";
		d2read("Dermatologist.dat");
		cout << "enter the doctor name: ";
		cin >> e;



		while (f.read((char*)&obj, sizeof(obj)))
		{
			if (obj.username == e)
			{
				setdatetime();
				cout << "Enter the name of Patient: " << endl;
				cin >> pt;
				setpatientname(pt);
				cout << "Enter the name of City: " << endl;
				cin >> pt;
				setcity(pt);
				strcpy_s(Doctorname, e.c_str());
				cout << "appointment book with dr " << Doctorname << endl;
				return;
			}
		}
		break;
		break;
	case 3:
		cout << "Here all the oncologist doctor: ";
		d3read("Oncologist.dat");
		cout << "enter the doctor name: ";
		cin >> e;



		while (f.read((char*)&obj, sizeof(obj)))
		{
			if (obj.username == e)
			{
				setdatetime();
				cout << "Enter the name of Patient: " << endl;
				cin >> pt;
				setpatientname(pt);
				cout << "Enter the name of City: " << endl;
				cin >> pt;
				setcity(pt);
				strcpy_s(Doctorname, e.c_str());
				cout << "appointment book with dr " << Doctorname << endl;
				return;
			}
		}
		break;
		break;
	case 4:
		cout << "Here all the orthopedic doctor: ";
		d4read("Orthopedic.dat");
		cout << "enter the doctor name: ";
		cin >> e;



		while (f.read((char*)&obj, sizeof(obj)))
		{
			if (obj.username == e)
			{
				setdatetime();
				cout << "Enter the name of Patient: " << endl;
				cin >> pt;
				setpatientname(pt);
				cout << "Enter the name of City: " << endl;
				cin >> pt;
				setcity(pt);
				strcpy_s(Doctorname, e.c_str());
				cout << "appointment book with dr " << Doctorname << endl;
				return;
			}
		}
		break;
		
	}
}