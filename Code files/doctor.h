//
//class doctor : public user
//{
//public:
//	int clinictime;
//	int experience;
//	int fees;
//
//	doctor(int id = 1, string cnic = "", string name = "", string password = "", bool log = 0, int exp = 0, int ct = 0, int fee = 0)
//	{
//		this->id = id;
//		strcpy_s(this->cnic, cnic.c_str());
//		strcpy_s(this->username, name.c_str());
//		strcpy_s(this->password, password.c_str());
//		experience = exp;
//		clinictime = ct;
//		fees = fee;
//	}
//
//	void ddisplay()
//	{
//		//cout << "CNIC :" << cnic << endl;
//		cout << "UserName :" << username << endl;
//		//cout << "password :" << password << endl;
//		cout << "Clinchours :" << clinictime << endl;
//		cout << "experience :" << experience << endl;
//		cout << "Doctor fees :" << fees << endl;
//	}
//	void dmenu()
//	{
//		int choice;
//		cout << "1.for registering\n2.for loging in\n3.for loging out" << endl;
//		cin >> choice;
//
//		if (choice == 1)
//		{
//			dregister();
//
//		}
//		if (choice == 2)
//		{
//			dlogin();
//
//		}
//		if (choice == 3)
//		{
//			//dlogout();
//		}
//		if (choice == 4)
//		{
//			dupdate();
//
//		}
//		if (choice == 5)
//		{
//			dshowdata();
//		}
//
//	}
//	void seeapointments(string g)
//	{
//
//		appointment obj;
//		fstream f("appointment.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//
//			if (obj.Doctorname == g)
//			{
//				cout << "patients name: " << obj.patientname << endl;
//				cout << "City Name: " << obj.city << endl;
//			}
//		}
//	}
//	void dregister()
//	{
//		bool a = 0, b = 0, c = 0, d = 0, z = 0;
//		string usnm, pwd, CNIC = "";
//		int hrs, exp,fee;
//		cout << "registeration page : ";
//
//		while (CNIC.length() != 13)
//		{
//			cout << "Enter the CNIC:";
//			cin >> CNIC;
//			cout << CNIC.length();
//			if (CNIC.length() != 13)
//				cout << "wrong input<<endl";
//		}
//
//		cout << "Enter the username:";
//		cin >> usnm;
//		doctor obj;
//		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//
//			if (obj.cnic != CNIC)
//			{
//				while (z != 1)
//				{
//					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
//					cout << "Enter the password";
//					cin >> pwd;
//					if (pwd.length() >= 8)
//						a = true;
//					for (int i = 0; i < pwd.length(); i++) {
//						if (pwd[i] >= '0' && pwd[i] <= '9')
//							b = true;
//						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
//							c = true;
//						if (pwd[i] >= 33 && pwd[i] <= 47)
//							d = true;
//					}
//					cout << pwd.length();
//					if (a == 1 && b == 1 && c == 1 && d == 1)
//					{
//						z = 1;
//
//					}
//					else
//					{
//						cout << "weak password try again!" << endl;
//					}
//				}
//			}
//			else
//			{
//				cout << "user already existed: " << endl;
//				cout << "try another username:";
//				cin >> usnm;
//			}
//		}
//		cout << "Enter the clinic hours: ";
//		cin >> hrs;
//		cout << "Enter the experience in years: ";
//		cin >> exp;
//		cout << "Enter the Enter your fee: ";
//		cin >> fee;
//
//		experience = exp;
//		clinictime = hrs;
//		fees = fee;
//		strcpy_s(cnic, CNIC.c_str());
//		strcpy_s(username, usnm.c_str());
//		strcpy_s(password, pwd.c_str());
//		//id++;
//	}
//	void dlogin()
//	{
//		string g, h;
//		int choicer;
//		cout << "enter the username: " << endl;
//		cin >> g;
//		doctor obj;
//		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				while (obj.password != h)
//				{
//					cout << "Enter the password: ";
//					cin >> h;
//					if (obj.password == h)
//					{
//						cout << "Congratulations you are login!" << endl;
//						logging = 1;
//						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
//						cin >> choicer;
//						if (choicer == 1)
//						{
//							dupdate();
//
//						}
//						if (choicer == 2)
//						{
//							dshowdata();
//
//						}
//						if (choicer == 3)
//						{
//							seeapointments(g);
//
//						}
//					}
//					break;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//	void dupdate()
//	{
//		string g, h, n;
//		int e, r;
//		int choice;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("doctor.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == n)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					cout << "Enter the detail you change: ";
//					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
//					cin >> choice;
//					switch (choice)
//					{
//					case 1:
//						cout << "Enter the new username: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_username(g);
//								int a = f.tellg();
//								int s = sizeof(doctor);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//						break;
//
//					case 2:
//						cout << "Enter the new password: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_password(g);
//								int a = f.tellg();
//								int s = sizeof(doctor);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//							else
//							{
//								cout << "can't change the password";
//							}
//						}
//						break;
//					case 3:
//						cout << " Enter the updated experience hours: ";
//						cin >> e;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = e;
//								int a = f.tellg();
//								int s = sizeof(doctor);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 4:
//						cout << " Enter the updated clinic hours: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = r;
//								int a = f.tellg();
//								int s = sizeof(doctor);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 5:
//						cout << " Enter the updated fees: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.fees = r;
//								int a = f.tellg();
//								int s = sizeof(doctor);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					}
//
//				}
//			}
//			else
//			{
//				cout << "Incorrect Password!" << endl;
//			}
//			//f.write((char*)&obj, sizeof(obj));
//			break;
//		}
//		f.close();
//
//	}
//	void dshowdata()
//	{
//		string g, h, n;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					while (f.read((char*)&obj, sizeof(obj)))
//					{
//						if (obj.username == n)
//						{
//							cout << obj.cnic << endl;
//							cout << obj.username << endl;
//							cout << obj.password << endl;
//							break;
//
//						}
//					}
//				}
//				else
//				{
//					cout << "Incorrect Password!" << endl;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//
//};
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////specialization of doctor
//
//
//
//
//
//class gynecologist :public doctor
//{
//public:
//	void dregister()
//	{
//		bool a = 0, b = 0, c = 0, d = 0, z = 0;
//		string usnm, pwd, CNIC = "";
//		int hrs, exp, fee;
//		cout << "registeration page : ";
//
//		while (CNIC.length() != 13)
//		{
//			cout << "Enter the CNIC:";
//			cin >> CNIC;
//			cout << CNIC.length();
//			if (CNIC.length() != 13)
//				cout << "wrong input<<endl";
//		}
//
//		cout << "Enter the username:";
//		cin >> usnm;
//		gynecologist obj;
//		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//
//			if (obj.cnic != CNIC)
//			{
//				while (z != 1)
//				{
//					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
//					cout << "Enter the password";
//					cin >> pwd;
//					if (pwd.length() >= 8)
//						a = true;
//					for (int i = 0; i < pwd.length(); i++) {
//						if (pwd[i] >= '0' && pwd[i] <= '9')
//							b = true;
//						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
//							c = true;
//						if (pwd[i] >= 33 && pwd[i] <= 47)
//							d = true;
//					}
//					cout << pwd.length();
//					if (a == 1 && b == 1 && c == 1 && d == 1)
//					{
//						z = 1;
//
//					}
//					else
//					{
//						cout << "weak password try again!" << endl;
//					}
//				}
//			}
//			else
//			{
//				cout << "user already existed: " << endl;
//				cout << "try another username:";
//				cin >> usnm;
//			}
//		}
//		cout << "Enter the clinic hours: ";
//		cin >> hrs;
//		cout << "Enter the experience in years: ";
//		cin >> exp;
//		cout << "Enter the Enter your fee: ";
//		cin >> fee;
//
//		experience = exp;
//		clinictime = hrs;
//		fees = fee;
//		strcpy_s(cnic, CNIC.c_str());
//		strcpy_s(username, usnm.c_str());
//		strcpy_s(password, pwd.c_str());
//		//id++;
//	}
//	void dlogin()
//	{
//		string g, h;
//		int choicer;
//		cout << "enter the username: " << endl;
//		cin >> g;
//		doctor obj;
//		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				while (obj.password != h)
//				{
//					cout << "Enter the password: ";
//					cin >> h;
//					if (obj.password == h)
//					{
//						cout << "Congratulations you are login!" << endl;
//						logging = 1;
//						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
//						cin >> choicer;
//						if (choicer == 1)
//						{
//							dupdate();
//
//						}
//						if (choicer == 2)
//						{
//							dshowdata();
//
//						}
//						if (choicer == 3)
//						{
//							seeapointments(g);
//
//						}
//					}
//					break;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//	void dupdate()
//	{
//		string g, h, n;
//		int e, r;
//		int choice;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("doctor.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == n)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					cout << "Enter the detail you change: ";
//					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
//					cin >> choice;
//					switch (choice)
//					{
//					case 1:
//						cout << "Enter the new username: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_username(g);
//								int a = f.tellg();
//								int s = sizeof(gynecologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//						break;
//
//					case 2:
//						cout << "Enter the new password: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_password(g);
//								int a = f.tellg();
//								int s = sizeof(gynecologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//							else
//							{
//								cout << "can't change the password";
//							}
//						}
//						break;
//					case 3:
//						cout << " Enter the updated experience hours: ";
//						cin >> e;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = e;
//								int a = f.tellg();
//								int s = sizeof(gynecologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 4:
//						cout << " Enter the updated clinic hours: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = r;
//								int a = f.tellg();
//								int s = sizeof(gynecologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 5:
//						cout << " Enter the updated fees: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.fees = r;
//								int a = f.tellg();
//								int s = sizeof(gynecologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					}
//
//				}
//			}
//			else
//			{
//				cout << "Incorrect Password!" << endl;
//			}
//			//f.write((char*)&obj, sizeof(obj));
//			break;
//		}
//		f.close();
//
//	}
//	void dshowdata()
//	{
//		string g, h, n;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					while (f.read((char*)&obj, sizeof(obj)))
//					{
//						if (obj.username == n)
//						{
//							cout << obj.cnic << endl;
//							cout << obj.username << endl;
//							cout << obj.password << endl;
//							break;
//
//						}
//					}
//				}
//				else
//				{
//					cout << "Incorrect Password!" << endl;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//
//};
//
//////////////////////////////////////dermatologist
//
//
//
//class dermatologist :public doctor
//{
//public:
//	void dregister()
//	{
//		bool a = 0, b = 0, c = 0, d = 0, z = 0;
//		string usnm, pwd, CNIC = "";
//		int hrs, exp, fee;
//		cout << "registeration page : ";
//
//		while (CNIC.length() != 13)
//		{
//			cout << "Enter the CNIC:";
//			cin >> CNIC;
//			cout << CNIC.length();
//			if (CNIC.length() != 13)
//				cout << "wrong input<<endl";
//		}
//
//		cout << "Enter the username:";
//		cin >> usnm;
//		doctor obj;
//		fstream f("Dermatologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//
//			if (obj.cnic != CNIC)
//			{
//				while (z != 1)
//				{
//					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
//					cout << "Enter the password";
//					cin >> pwd;
//					if (pwd.length() >= 8)
//						a = true;
//					for (int i = 0; i < pwd.length(); i++) {
//						if (pwd[i] >= '0' && pwd[i] <= '9')
//							b = true;
//						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
//							c = true;
//						if (pwd[i] >= 33 && pwd[i] <= 47)
//							d = true;
//					}
//					cout << pwd.length();
//					if (a == 1 && b == 1 && c == 1 && d == 1)
//					{
//						z = 1;
//
//					}
//					else
//					{
//						cout << "weak password try again!" << endl;
//					}
//				}
//			}
//			else
//			{
//				cout << "user already existed: " << endl;
//				cout << "try another username:";
//				cin >> usnm;
//			}
//		}
//		cout << "Enter the clinic hours: ";
//		cin >> hrs;
//		cout << "Enter the experience in years: ";
//		cin >> exp;
//		cout << "Enter the Enter your fee: ";
//		cin >> fee;
//
//		experience = exp;
//		clinictime = hrs;
//		fees = fee;
//		strcpy_s(cnic, CNIC.c_str());
//		strcpy_s(username, usnm.c_str());
//		strcpy_s(password, pwd.c_str());
//		//id++;
//	}
//	void dlogin()
//	{
//		string g, h;
//		int choicer;
//		cout << "enter the username: " << endl;
//		cin >> g;
//		doctor obj;
//		fstream f("Dermatologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				while (obj.password != h)
//				{
//					cout << "Enter the password: ";
//					cin >> h;
//					if (obj.password == h)
//					{
//						cout << "Congratulations you are login!" << endl;
//						logging = 1;
//						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
//						cin >> choicer;
//						if (choicer == 1)
//						{
//							dupdate();
//
//						}
//						if (choicer == 2)
//						{
//							dshowdata();
//
//						}
//						if (choicer == 3)
//						{
//							seeapointments(g);
//
//						}
//					}
//					break;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//	void dupdate()
//	{
//		string g, h, n;
//		int e, r;
//		int choice;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("Dermatologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == n)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					cout << "Enter the detail you change: ";
//					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
//					cin >> choice;
//					switch (choice)
//					{
//					case 1:
//						cout << "Enter the new username: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_username(g);
//								int a = f.tellg();
//								int s = sizeof(dermatologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//						break;
//
//					case 2:
//						cout << "Enter the new password: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_password(g);
//								int a = f.tellg();
//								int s = sizeof(dermatologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//							else
//							{
//								cout << "can't change the password";
//							}
//						}
//						break;
//					case 3:
//						cout << " Enter the updated experience hours: ";
//						cin >> e;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = e;
//								int a = f.tellg();
//								int s = sizeof(dermatologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 4:
//						cout << " Enter the updated clinic hours: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = r;
//								int a = f.tellg();
//								int s = sizeof(dermatologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 5:
//						cout << " Enter the updated fees: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.fees = r;
//								int a = f.tellg();
//								int s = sizeof(dermatologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					}
//
//				}
//			}
//			else
//			{
//				cout << "Incorrect Password!" << endl;
//			}
//			//f.write((char*)&obj, sizeof(obj));
//			break;
//		}
//		f.close();
//
//	}
//	void dshowdata()
//	{
//		string g, h, n;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					while (f.read((char*)&obj, sizeof(obj)))
//					{
//						if (obj.username == n)
//						{
//							cout << obj.cnic << endl;
//							cout << obj.username << endl;
//							cout << obj.password << endl;
//							break;
//
//						}
//					}
//				}
//				else
//				{
//					cout << "Incorrect Password!" << endl;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//};
//
//////////////////////oncologist/////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//class oncologist :public doctor
//{
//	void dregister()
//	{
//		bool a = 0, b = 0, c = 0, d = 0, z = 0;
//		string usnm, pwd, CNIC = "";
//		int hrs, exp, fee;
//		cout << "registeration page : ";
//
//		while (CNIC.length() != 13)
//		{
//			cout << "Enter the CNIC:";
//			cin >> CNIC;
//			cout << CNIC.length();
//			if (CNIC.length() != 13)
//				cout << "wrong input<<endl";
//		}
//
//		cout << "Enter the username:";
//		cin >> usnm;
//		doctor obj;
//		fstream f("Oncologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//
//			if (obj.cnic != CNIC)
//			{
//				while (z != 1)
//				{
//					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
//					cout << "Enter the password";
//					cin >> pwd;
//					if (pwd.length() >= 8)
//						a = true;
//					for (int i = 0; i < pwd.length(); i++) {
//						if (pwd[i] >= '0' && pwd[i] <= '9')
//							b = true;
//						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
//							c = true;
//						if (pwd[i] >= 33 && pwd[i] <= 47)
//							d = true;
//					}
//					cout << pwd.length();
//					if (a == 1 && b == 1 && c == 1 && d == 1)
//					{
//						z = 1;
//
//					}
//					else
//					{
//						cout << "weak password try again!" << endl;
//					}
//				}
//			}
//			else
//			{
//				cout << "user already existed: " << endl;
//				cout << "try another username:";
//				cin >> usnm;
//			}
//		}
//		cout << "Enter the clinic hours: ";
//		cin >> hrs;
//		cout << "Enter the experience in years: ";
//		cin >> exp;
//		cout << "Enter the Enter your fee: ";
//		cin >> fee;
//
//		experience = exp;
//		clinictime = hrs;
//		fees = fee;
//		strcpy_s(cnic, CNIC.c_str());
//		strcpy_s(username, usnm.c_str());
//		strcpy_s(password, pwd.c_str());
//		//id++;
//	}
//	void dlogin()
//	{
//		string g, h;
//		int choicer;
//		cout << "enter the username: " << endl;
//		cin >> g;
//		doctor obj;
//		fstream f("Oncologoist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				while (obj.password != h)
//				{
//					cout << "Enter the password: ";
//					cin >> h;
//					if (obj.password == h)
//					{
//						cout << "Congratulations you are login!" << endl;
//						logging = 1;
//						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
//						cin >> choicer;
//						if (choicer == 1)
//						{
//							dupdate();
//
//						}
//						if (choicer == 2)
//						{
//							dshowdata();
//
//						}
//						if (choicer == 3)
//						{
//							seeapointments(g);
//
//						}
//					}
//					break;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//	void dupdate()
//	{
//		string g, h, n;
//		int e, r;
//		int choice;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("Oncologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == n)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					cout << "Enter the detail you change: ";
//					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
//					cin >> choice;
//					switch (choice)
//					{
//					case 1:
//						cout << "Enter the new username: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_username(g);
//								int a = f.tellg();
//								int s = sizeof(oncologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//						break;
//
//					case 2:
//						cout << "Enter the new password: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_password(g);
//								int a = f.tellg();
//								int s = sizeof(oncologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//							else
//							{
//								cout << "can't change the password";
//							}
//						}
//						break;
//					case 3:
//						cout << " Enter the updated experience hours: ";
//						cin >> e;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = e;
//								int a = f.tellg();
//								int s = sizeof(oncologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 4:
//						cout << " Enter the updated clinic hours: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = r;
//								int a = f.tellg();
//								int s = sizeof(oncologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 5:
//						cout << " Enter the updated fees: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.fees = r;
//								int a = f.tellg();
//								int s = sizeof(oncologist);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					}
//
//				}
//			}
//			else
//			{
//				cout << "Incorrect Password!" << endl;
//			}
//			//f.write((char*)&obj, sizeof(obj));
//			break;
//		}
//		f.close();
//
//	}
//	void dshowdata()
//	{
//		string g, h, n;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("Oncologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					while (f.read((char*)&obj, sizeof(obj)))
//					{
//						if (obj.username == n)
//						{
//							cout << obj.cnic << endl;
//							cout << obj.username << endl;
//							cout << obj.password << endl;
//							break;
//
//						}
//					}
//				}
//				else
//				{
//					cout << "Incorrect Password!" << endl;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//};
//
//////////////////////////////////////////////////////orthopedic//////////////////////////////////
//
//
//class orthopedic :public doctor
//{
//	void dregister()
//	{
//		bool a = 0, b = 0, c = 0, d = 0, z = 0;
//		string usnm, pwd, CNIC = "";
//		int hrs, exp, fee;
//		cout << "registeration page : ";
//
//		while (CNIC.length() != 13)
//		{
//			cout << "Enter the CNIC:";
//			cin >> CNIC;
//			cout << CNIC.length();
//			if (CNIC.length() != 13)
//				cout << "wrong input<<endl";
//		}
//
//		cout << "Enter the username:";
//		cin >> usnm;
//		doctor obj;
//		fstream f("orthopedic.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//
//			if (obj.cnic != CNIC)
//			{
//				while (z != 1)
//				{
//					cout << "Your password must have 8 letters and special symbol and numberic digit and capital letters" << endl;
//					cout << "Enter the password";
//					cin >> pwd;
//					if (pwd.length() >= 8)
//						a = true;
//					for (int i = 0; i < pwd.length(); i++) {
//						if (pwd[i] >= '0' && pwd[i] <= '9')
//							b = true;
//						if (pwd[i] >= 'A' && pwd[i] <= 'Z')
//							c = true;
//						if (pwd[i] >= 33 && pwd[i] <= 47)
//							d = true;
//					}
//					cout << pwd.length();
//					if (a == 1 && b == 1 && c == 1 && d == 1)
//					{
//						z = 1;
//
//					}
//					else
//					{
//						cout << "weak password try again!" << endl;
//					}
//				}
//			}
//			else
//			{
//				cout << "user already existed: " << endl;
//				cout << "try another username:";
//				cin >> usnm;
//			}
//		}
//		cout << "Enter the clinic hours: ";
//		cin >> hrs;
//		cout << "Enter the experience in years: ";
//		cin >> exp;
//		cout << "Enter the Enter your fee: ";
//		cin >> fee;
//
//		experience = exp;
//		clinictime = hrs;
//		fees = fee;
//		strcpy_s(cnic, CNIC.c_str());
//		strcpy_s(username, usnm.c_str());
//		strcpy_s(password, pwd.c_str());
//		//id++;
//	}
//	void dlogin()
//	{
//		string g, h;
//		int choicer;
//		cout << "enter the username: " << endl;
//		cin >> g;
//		doctor obj;
//		fstream f("Gynecologist.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				while (obj.password != h)
//				{
//					cout << "Enter the password: ";
//					cin >> h;
//					if (obj.password == h)
//					{
//						cout << "Congratulations you are login!" << endl;
//						logging = 1;
//						cout << "\n1.for update\n2. Show data\n3. See apointments" << endl;
//						cin >> choicer;
//						if (choicer == 1)
//						{
//							dupdate();
//
//						}
//						if (choicer == 2)
//						{
//							dshowdata();
//
//						}
//						if (choicer == 3)
//						{
//							seeapointments(g);
//
//						}
//					}
//					break;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//	void dupdate()
//	{
//		string g, h, n;
//		int e, r;
//		int choice;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("orthopedic.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == n)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					cout << "Enter the detail you change: ";
//					cout << "\n1.username\n2.password\n3. experience\n4.clinchours\n5.fees" << endl;
//					cin >> choice;
//					switch (choice)
//					{
//					case 1:
//						cout << "Enter the new username: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_username(g);
//								int a = f.tellg();
//								int s = sizeof(orthopedic);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//						break;
//
//					case 2:
//						cout << "Enter the new password: ";
//						cin >> g;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.set_password(g);
//								int a = f.tellg();
//								int s = sizeof(orthopedic);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//							else
//							{
//								cout << "can't change the password";
//							}
//						}
//						break;
//					case 3:
//						cout << " Enter the updated experience hours: ";
//						cin >> e;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = e;
//								int a = f.tellg();
//								int s = sizeof(orthopedic);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 4:
//						cout << " Enter the updated clinic hours: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.experience = r;
//								int a = f.tellg();
//								int s = sizeof(orthopedic);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					case 5:
//						cout << " Enter the updated fees: ";
//						cin >> r;
//						while (f.read((char*)&obj, sizeof(obj)))
//						{
//							if (obj.username == n)
//							{
//								obj.fees = r;
//								int a = f.tellg();
//								int s = sizeof(orthopedic);
//								f.seekp(a - s, ios::beg);
//								f.write((char*)&obj, sizeof(obj));
//								break;
//
//							}
//						}
//					}
//
//				}
//			}
//			else
//			{
//				cout << "Incorrect Password!" << endl;
//			}
//			//f.write((char*)&obj, sizeof(obj));
//			break;
//		}
//		f.close();
//
//	}
//	void dshowdata()
//	{
//		string g, h, n;
//		cout << "enter the username: " << endl;
//		cin >> n;
//		doctor obj;
//		fstream f("orthopedic.dat", ios::out | ios::in | ios::binary);
//		while (f.read((char*)&obj, sizeof(obj)))
//		{
//
//			if (obj.username == g)
//			{
//				cout << "Enter the password: ";
//				cin >> h;
//				if (obj.password == h)
//				{
//					cout << "Congratulations you are login!" << endl;
//					logging = 1;
//					while (f.read((char*)&obj, sizeof(obj)))
//					{
//						if (obj.username == n)
//						{
//							cout << obj.cnic << endl;
//							cout << obj.username << endl;
//							cout << obj.password << endl;
//							break;
//
//						}
//					}
//				}
//				else
//				{
//					cout << "Incorrect Password!" << endl;
//				}
//				//f.write((char*)&obj, sizeof(obj));
//				break;
//
//			}
//		}
//		f.close();
//
//	}
//};
