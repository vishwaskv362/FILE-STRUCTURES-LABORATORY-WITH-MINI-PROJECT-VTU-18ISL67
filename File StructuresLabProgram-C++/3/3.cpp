#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

#define filename "std3.txt"
using namespace std;
fstream ifile;

class student
{
	 char usn[15],name[20],age[5],branch[6],sem[5];
	public:
		void fopen(fstream&ifile,char *fn,std::_Ios_Openmode  mode);


		void read();
		void pack();
		void display();
		void unpack();
		int search();
		void modify(int);
};

// function  to  open a file
void student::fopen(fstream&sfile,char *fn,std::_Ios_Openmode  mode)
{
	sfile.open(fn,mode);
	if(!sfile)
	{
		cout<<"unable to open a file"<<endl;
		exit(1);
	}
}

//function to read the student record
void student::read()
{
cout<<"enter the usn number:";	cin>>(usn);
cout<<"enter the name:";        cin>>(name);
cout<<"enter the age:";         cin>>(age);
cout<<"enter the branch:";      cin>>(branch);
cout<<"enter the sem:";         cin>>(sem);
pack();

}

// function to pack the student record using delimiter

void student::pack()
{
char buffer[75];
strcpy(buffer,usn);  			strcat(buffer,"|");
strcat(buffer,name); 			strcat(buffer,"|");
strcat(buffer,age);  			strcat(buffer,"|");
strcat(buffer,branch);  		strcat(buffer,"|");
strcat(buffer,sem);       		strcat(buffer,"|");
ifile<<buffer<<"#";
}





//function to display student record
void student::display()
 {
char buffer[75];
cout<<setiosflags(ios::left);
cout<<setw(15)<<"USN"<<setw(20)<<"NAME"<<setw(5)<<"AGE";
cout<<setw(10)<<"BRANCH"<<setw(5)<<"SEM"<<endl;
while(1)
  {
	unpack();
	if(ifile.eof())
	break;
	if(usn[0]!='$')
	 {
		cout<<setw(15)<<usn<<setw(20)<<name<<setw(5)<<age;
		cout<<setw(10)<<branch<<setw(5)<<sem<<endl;
	 }
   }
}

// function to  unpack
void student::unpack()
{
	char dummy[75];
	ifile.getline(usn,15,'|');
	ifile.getline(name,20,'|');
	ifile.getline(age,5,'|');
	ifile.getline(branch,6,'|');
	ifile.getline(sem,5,'|');
	ifile.getline(dummy,75,'#');
}

//function to search student record based on USN.
int student::search()
{
	int flag;
	char susn[15];
	cout<<"enter the usn to be searched:";
	cin>>susn;
	while(!ifile.eof())
	 {
		flag=ifile.tellg();
		unpack();
		if(usn[0]!='$' &&strcmp(usn,susn)==0)
		 {
	cout<<"USN:"<<usn<<"\n"<<"NAME:"<<name<<"\n"<<"AGE:"<<age;


		cout<<"\n"<<"BRANCH:"<<branch<<"\n"<<"SEM:"<<sem<<"\n";
		return flag;
		 }
	 }
	return -1;
}
//function to modify record.
void student::modify(int recpos)
{
ifile.seekp(recpos,ios::beg);
ifile.put('$');
ifile.seekp(0,ios::end);
read();
}

//main program
int main()
{
int ch,flag;
student s;



for(;;)
 {
cout<<" ----------------Menu----------------- \n1.Read\n2.Display\n3.Search\n4.Modify\n5.Exit"<<endl;
cout<<"enter the choice:";
cin>>ch;
switch(ch)
{
			case 1: s.fopen(ifile,filename,ios::app);
				cout<<"enter the student details\n";
				s.read();
				break;
			case 2: s.fopen(ifile,filename,ios::in);
				cout<<"The student details are:"<<endl;
				s.display();
				break;
			case 3:s.fopen(ifile,filename,ios::in);
				cout<<"Searching based on USN number"<<endl;
				flag=s.search();
				if(flag==-1)
					cout<<"Record not found"<<endl;
				break;

			case 4:s.fopen(ifile,filename,ios::in|ios::out);
				cout<<"To modify the record based on USN"<<endl;
				flag=s.search();
				if(flag==-1)
					cout<<"Record not found"<<endl;
				else
					s.modify(flag);
				break;
	default:
				exit(0);
		}
	ifile.close();
   }
}

