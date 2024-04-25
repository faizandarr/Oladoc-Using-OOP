#include<iostream>
using namespace std;

class datetime
{
	int date;
	int month;
	int year;
	int hour;
	int min;
public:
	void setdate(int d)
	{
		date = d;
	}
	void setmonth(int m)
	{
		month = m;
	}
	void setyear(int y)
	{
		year = y;
	}
	void sethours(int h)
	{
		hour = h;
	}
	void setmin(int m)
	{
		min = m;
	}
	int getdate()
	{
		return date;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}
	int gethours()
	{
		return hour;
	}
	int getmin()
	{
		return min;
	}
};
