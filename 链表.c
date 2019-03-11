#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
struct phonebook
{
  string name;
  string phonenumber,tel;
  string qqnumber;
};
int i;
void login()
{
	string pkm;
	cout<<"\n\n\n  登陆个人电话本\n\n";
	 cout<<"  请输入密码：";
	while ((cin>>pkm)&&pkm!="000000")
	{
	  cout<<"请输入正确密码!\n\n\n\n";
	  system("pause");
	  system("cls");
	  cout<<"\n\n\n  登陆个人电话本\n\n";
	  cout<<"  请输入密码：";
	}
}
void inputdata(phonebook * myphone)
{
	ifstream fin("D:\pukuiminphone.pkm");
	i=0;
	while (fin>>myphone[i].name)
	{
		fin>>myphone[i].phonenumber;
		fin>>myphone[i].tel;
		fin>>myphone[i].qqnumber;
		i++;
	}
	fin.close();
}
void outputdata(phonebook * myphone)
{	
	ofstream fout("D:\pukuiminphone.pkm");
	for(int j=0;j<=i;j++)
	{
		fout<<setw(7)<<myphone[j].name<<" ";
		fout<<setw(12)<<myphone[j].phonenumber<<" ";
		fout<<setw(15)<<myphone[j].tel<<" ";
		fout<<setw(11)<<myphone[j].qqnumber<<endl;
	}
	fout.close();
}
void shownumber(phonebook * myphone)
{
	inputdata(myphone);
	system("cls");
	cout<<"\n\n\n  全部号码如下\n\n";
		cout<<setw(7)<<"姓名"<<" ";
		cout<<setw(10)<<"手机号"<<" ";
		cout<<setw(14)<<"电话号"<<" ";
		cout<<setw(12)<<"QQ号"<<endl;
	for(int j=0;j<i;j++)
	{
		cout<<setw(7)<<myphone[j].name<<" ";
		cout<<setw(12)<<myphone[j].phonenumber<<" ";
		cout<<setw(15)<<myphone[j].tel<<" ";
		cout<<setw(11)<<myphone[j].qqnumber<<endl;
	}
	cout<<"\n\n\n";
	system("pause");
	system("cls");
}
void insertnumber(phonebook * myphone)
{
	inputdata(myphone);
	cerr<<"  姓名:";
	cin>>myphone[i].name;
	cerr<<"  手机号码(如果没有请输入“无”):";
	cin>>myphone[i].phonenumber;
	cerr<<"  电话号码(如果没有请输入“无”):";
	cin>>myphone[i].tel;
	cerr<<"  QQ号码(如果没有请输入“无”):";
	cin>>myphone[i].qqnumber;
	ofstream fout("D:\pukuiminphone.pkm");
	for(int j=0;j<=i;j++)
	{
		fout<<setw(7)<<myphone[j].name<<" ";
		fout<<setw(12)<<myphone[j].phonenumber<<" ";
		fout<<setw(15)<<myphone[j].tel<<" ";
		fout<<setw(11)<<myphone[j].qqnumber<<endl;
	}
	fout.close();
	system("pause");
	system("cls");
}
void modify(phonebook * myphone)
{
	inputdata(myphone);
	cout<<"要修改资料的姓名：";
	string xinmin;
	cin>>xinmin;
	for(int j=0;j<i;j++)
		if (myphone[j].name==xinmin)
		{  
			cout<<"  信息如下：\n";
			cout<<"  手机号："<<myphone[j].phonenumber;
			cout<<"\n  电话号："<<myphone[j].tel;
			cout<<"\n  Q Q 号："<<myphone[j].qqnumber;
			int temp,flag=0;
			string temp2;
			while (1)
			{		
				cout<<"\n\n     1-改手机号  2-改电话号  3-改QQ号  其它-退出修改\n";
				cout<<"     请输入操作代号："	;
                cin>>temp;
				switch(temp)
				{
				case 1:
					cout<<"请输入新的手机号：";
					cin>>temp2;
					myphone[j].phonenumber=temp2;
					break;
				case 2:
					cout<<"请输入新的电话号码：";
					cin>>temp2;
					myphone[j].tel=temp2;
					break;
				case 3:
					cout<<"请输入新的QQ号码：";
					cin>>temp2;
					myphone[j].qqnumber=temp2;break;
				default:flag=1;
				}
				if(flag==1) break;
			}

		}
		i--;
		system("cls");
		outputdata(myphone);
}
void search_by_name(phonebook * myphone)
{
	int isexit=0;
		inputdata(myphone);
	cout<<"要查的姓名：";
	string name;
	cin>>name;
	for(int j=0;j<i;j++)
		if (myphone[j].name==name)
		{  
			cout<<"  信息如下：\n";
			cout<<"  手机号："<<myphone[j].phonenumber;
			cout<<"\n  电话号："<<myphone[j].tel;
			cout<<"\n  Q Q 号："<<myphone[j].qqnumber<<"\n\n";
			isexit=1;
		}
		if(isexit==0) cout<<"\n  此人无存档!\n\n";
			system("pause");
			system("cls");
}

void backup(phonebook * myphone)
{
	system("cls");
	ifstream fin("D:\pukuiminphone.pkm");
	i=0;
	while (fin>>myphone[i].name)
	{
		fin>>myphone[i].phonenumber;
		fin>>myphone[i].tel;
		fin>>myphone[i].qqnumber;
		i++;
	}
	fin.close();
  	cout<<"\n\n\n   请输入文件名：";
	string filename;
	cin>>filename;
	ofstream fout(filename.c_str());
		fout<<setw(7)<<"姓名"<<" ";
		fout<<setw(10)<<"手机号"<<" ";
		fout<<setw(14)<<"电话号"<<" ";
		fout<<setw(12)<<"QQ号"<<endl;
	for(int j=0;j<=i;j++)
	{
		fout<<setw(7)<<myphone[j].name<<" ";
		fout<<setw(12)<<myphone[j].phonenumber<<" ";
		fout<<setw(15)<<myphone[j].tel<<" ";
		fout<<setw(11)<<myphone[j].qqnumber<<endl;
	}
	fout.close();
}
void del(phonebook * myphone)
{
	inputdata(myphone);
	system("cls");
	cout<<"\n\n 要删除的姓名：";
	int isexit=0;
	string name;
	cin>>name;
		for(int j=0;j<i;j++)
		if (myphone[j].name==name)
		{  
			cout<<"  信息如下：\n";
			cout<<"  手机号："<<myphone[j].phonenumber;
			cout<<"\n  电话号："<<myphone[j].tel;
			cout<<"\n  Q Q 号："<<myphone[j].qqnumber<<"\n\n";
			cout<<"真的要删除吗？ 1-删除  0-返回\n\n";
			int isdel;
			cin>>isdel;
			while (isdel!=0 && isdel!=1)
			{
				cout<<"请输入1或0\n";
				cin>>isdel;
			}
			if(isdel==1)
			{
					ofstream fout("D:\pukuiminphone.pkm");
	for(int j=0;j<i;j++)
	{
		if(myphone[j].name==name) continue;
		fout<<setw(7)<<myphone[j].name<<" ";
		fout<<setw(12)<<myphone[j].phonenumber<<" ";
		fout<<setw(15)<<myphone[j].tel<<" ";
		fout<<setw(11)<<myphone[j].qqnumber<<endl;
	}
	fout.close();
			}
			isexit=1;
		}
		if(isexit==0) cout<<"\n  无此人!\n\n";
			system("pause");
			system("cls");

}

int main()
{
	system("color 1d");
	login();
	system("cls");
	phonebook pkm[100];
	int chioce;
	while (1)
	{
		cout<<"\n\n\n\n           *******个人电话本*******   \n\n\n";
		cout<<"           1-显示号码    2-录入号码    3-修改信息\n\n";
		cout<<"           4-查找        5-备份        6-删除\n\n";
		cout<<"           0-退出\n\n";
		cout<<"   请输入操作代号："	;
		cin>>chioce;
		switch(chioce)
		{
		case 1:
		shownumber(pkm);break;
		case 2:	
		insertnumber(pkm);break;
		case 3:
		modify(pkm);break;
		case 4:
			search_by_name(pkm);
			break;
		case 5:
			backup(pkm);
			break;
		case 6:
			del(pkm);
			break;
		case 0:
			return 0;
		default:
			system("echo ");
			system("pause");
			system("cls");
		}
	}
	return 0;
}
