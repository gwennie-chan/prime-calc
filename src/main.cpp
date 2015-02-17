//Prime Number Calculator, Ver. 4.2
//Public Domain

#include<iostream>
//#include<iomanip>
//#include<fstream>
using namespace std;


unsigned long addNum();
void errorNum(unsigned long &);
double runTest(unsigned long,bool &);
bool isPrime(double);
bool errorProgram(double,bool);
void programResult(bool,bool,unsigned long);
void errorChar(char &);
void exit();

int main()
{	unsigned long num;
	double result;
	bool prime,secondary;
	bool error=false;
	char decision='N';

	cout << "\n\tThis Program Calculates If A Inputted Answer Is Prime.\n";

	do
	{
		num=addNum();
		result=runTest(num,secondary);

		if((result==-5)||(result==-25))
			{	cout << "\n\tProgram Has Experienced An Error And Cannot Continue";
				cout << "\n\n\n";
			}

		prime=isPrime(result);
		error=errorProgram(result,prime);

		programResult(prime,error,num);

		cout << "\n\n\tProgram Has Completed.\n\tWould You Like To Run Again For Another Number? (Y/N) ";
		cin >> decision;
		errorChar(decision);

	}while((decision=='Y')||(decision=='y'));

		cout << "\n\n\tThank You For Using This Program!" << endl;
		cout << "\n\tPublic Domain\n\n";

    exit();
    return 0;
}

unsigned long addNum()
{	unsigned long temp;
	cout << "\n\tEnter A Number To Be Checked: ";
	cin >> temp;
	errorNum(temp);
	cout << endl;

	return temp;
}

void errorNum(unsigned long &temp)
{	while(temp<2)
	{	cout << "\n\tInvalid Input. To Calculate Prime Number,\n\tInput Must Not Equal Less Than 2";
		cout << "\n\tInput A Checkable Number: ";
		cin >> temp;
	}
}

double runTest(unsigned long num,bool &secondary)
{	bool test=false;
	secondary=false;
	double result=0;

 	for(unsigned long x=2; x <= num; x++)
	{	if((test==false)&&(secondary==false))
		{	if(x==num)
			{	test=true;
				result=0;
			}
			else if(x!=num)
			{	result=(num%x);
				if(result==0)
				{	test=false;
					secondary=true;
				}
			}
		}
	}


	if((test==true)&&(result==0))
	{	return result;}
	else if((test!=true)&&(result!=0))
	{	return result;}
	else if((test!=true)&&(result==0)&&(secondary==true))
	{	return 1;
	}
	else if((test!=true)&&(result==0)&&(secondary==false))
	{	return -5;
	}
	else if ((test==true)&&(result!=0))
	{	return -5;
	}
	else
	{	return -25;}
}

bool isPrime(double result)
{	if(result==0)
	{	return true;}
	else if (result!=0)
	{	return false;}

return false;
}

bool errorProgram(double result,bool prime)
{	if((result == 0 && prime == false) || (result != 0 && prime == true)){return true;}
    return false;
}

void programResult(bool prime,bool error,unsigned long num)
{	if(prime==true)
	{	cout << "\n\tProgram Determined " << num << " Is Prime.";}
	else if(prime==false)
	{	cout << "\n\tProgram Determined " << num << " Is Not Prime.";}

	if(error==true)
	{	cout << "\n\tProgram Faulted Due To Errors, Answer Unreliable.";}
	else if (error==false)
	{	cout << "\n\tProgram's Error Detections Were Not Triggered. Program Valid.";}
}

void errorChar(char &decision)
{	while((decision!='Y')&&(decision!='y')&&(decision!='N')&&(decision!='n'))
	{	cout << "\n\tYou Must Input A Valid Character Y or N Of Either Upper Or Lower Case";
		cout << "\n\tPlease Input A Usable Character Value: ";
		cin >> decision;
	}
}

void exit()
{   
    char temp = 'E';
    cout << "\tEnter 'E' To Exit... ";
    cin >> temp;
}
