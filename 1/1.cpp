#include<iostream>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

void reverse(char *s,char *r)
{
	int j,len;
	for(len=0;s[len]!='\0';len++);		
	for(j=len-1;j>=0;j--)
		r[len-j-1]=s[j];
	r[len]='\0';
}
int main()
{
	char name[10][20],rev[10][20],input[20],output[20],str[20],rstr[20];
	int i,n,len;
	fstream ifile,ofile;
	cout<<"Enter the number of Strings to read "<<endl;
	cin>>n;
	cout<<"Enter the Strings"<<endl;

		for(i=0;i<n;i++)
			cin>>name[i];
		for(i=0;i<n;i++)
			reverse(name[i],rev[i]);
	cout<<"The Strings and its reverese order are as follows"<<endl;
	cout<<"-------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
		cout<<name[i]<<setw(25)<<rev[i]<<endl;
	cout<<"-------------------------------------------------"<<endl;
	cout<<"Enter the filename which contain list of Strings"<<endl;
	cin>>input;
	ifile.open(input,ios::in);
	if(!ifile)
	{
		cout<<"Make sure there is a file in the cwd with a list of Strings and try again";
		exit(1);
	}
	cout<<"Enter the name of the file to which the output is to be stored"<<endl;
	cin>>output;
	ofile.open(output,ios::out);
	while(!ifile.eof())
	{
		ifile.getline(str,20); 
		reverse(str,rstr);
		ofile<<rstr<<endl;
	}
cout<<"The Reversed Strings are successfully stored in "<<output<<" file"<<endl;
cout<<"------------------------End-----------------------";
	
}