#include <iostream>
using namespace std;

#pragma region Practice 01_Shapes
class Shape
{
protected:
	int Width;
	int Height;

public:
	void setWidth(int prmWidth)
	{
		Width = prmWidth;
	}

	void setHeight(int prmHeight)
	{
		Height = prmHeight;
	}
};

class PaintCost
{
public:
	int getCost(int Area)
	{
		return(Area * 8);
	}
};

class Rectangle : public Shape, public PaintCost
{
public:
	int getArea() {
		return (Width * Height);
	}
};
#pragma endregion

#pragma region Practice 02_Employees
class Employee {
protected:
	int Id;
	string Name;
	string Father_Name;
	string Department;
	int SallaryPerDay;
	int SallaryMonthly;
	string Designation;
	int Attend;

	int CalculateSallary()
	{
		SallaryMonthly = (Attend * SallaryPerDay);
		return SallaryMonthly;
	}

public:
	Employee(){}

	Employee(int prmId, string prmName, string prmFName, string prmDept, int prmSall, string prmDesg, int prmAttend)
	{
		Name = prmName;
		Father_Name = prmFName;
		Department = prmDept;
		SallaryPerDay = prmSall;
		Designation = prmDesg;
		Attend = prmAttend;

		CalculateSallary();
	}

	virtual void IntroduceEmployee() const
	{
		cout << "\nEmployee Details: "<<endl;
		cout << "\tName: " << Name <<endl;
		cout << "\tFather Name: " << Father_Name <<endl;
		cout << "\tDepartment: " << Department <<endl;
		cout << "\tSallary: " << SallaryMonthly <<endl;
		cout << "\tDesignaition: " << Designation <<endl;
		cout << endl;
	}
};

class Developer : public Employee
{
protected:
	int ActiveTasks;
	int CompletedTasks;
	int Bouns = 5000;
	bool BonusAward = false;

private:
	void CalcBonus() {
		if (CompletedTasks > 20)
		{
			SallaryMonthly += Bouns;
			Bouns = true;
		}
	}
public:
	Developer(int prmId, string prmName, string prmFName, string prmDept, int prmSall, string prmDesg, int prmAttend, int prmActiveTask, int prmCompletedTask)
	{
		Name = prmName;
		Father_Name = prmFName;
		Department = prmDept;
		SallaryPerDay = prmSall;
		Designation = prmDesg;
		Attend = prmAttend;
		ActiveTasks = prmActiveTask;
		CompletedTasks = prmCompletedTask;

		Employee::CalculateSallary();
	}

	virtual void IntroduceEmployee() const
	{
		Employee::IntroduceEmployee();
		if (Bouns)
		{
			cout << "Congratulations! '"<< Name <<"' You Worked So well." << Bouns << " is Added in your Sallery as Bonus.";
		}
	}
};

#pragma endregion



int main()
{

	//Rectangle Rect{};
	//Rect.setHeight(5);
	//Rect.setWidth(6);
	//int Area = Rect.getArea();
	//cout << "Area of Reactangle is: " << Area << endl;
	//cout << "Price of Reactangle is: " << Rect.getCost(Area) << endl;

	Developer Emp1 = Developer(123, "Nasir", "Wasiq", "IT Center", 2500, "Senior Developer", 30, 1, 22);
	Emp1.IntroduceEmployee();

	Developer Emp2 = Developer(123, "Wahab", "Akram", "IT Center", 2000, "Jonier Developer", 23, 5, 14);
	Emp2.IntroduceEmployee();

	return 0;
}