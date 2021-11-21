#include <windows.h>
#include "mmsystem.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;
class diary
{    
	char place[100],note[500000],note1[500000],time[20],time1[20];
	double date,date1;
	public:
		void input()       //To input information
	 	{    
	 		cout<<"\n\n\n\n";
			cout << "\t\t\t Enter the Date(2018) in this format only DD.MM  ";
	 		PlaySound(TEXT("e_date.wav"),NULL,SND_SYNC);
	 		cin>>date;
	 		fflush(stdin);
	 		cout<<"\n\n"; 
			cout << "\t\t\t Enter time in this format 00.00(am/pm)  ";
	 		PlaySound(TEXT("e_time.wav"),NULL,SND_SYNC);
	 		cin.getline(time,20);
	 		fflush(stdin);
	 		cout<<"\n\n ";
			cout << "\t\t\t Enter place  ";
	 		PlaySound(TEXT("p.wav"),NULL,SND_SYNC);
	 		cin.getline(place,100);
	 		fflush(stdin);
	 		cout<<"\n\n";
			cout << "\t\t\t Write your note in diary  ";
	 		PlaySound(TEXT("e_note.wav"),NULL,SND_SYNC);
	 		cin.getline(note,500000);
	 		fflush(stdin);
		 }
		 void display() //To display particular information
		 {
		 	cout << "\n\n";
			cout << "\t\t "<<date;
			cout << "\t\t "<<time;
			cout << "\t\t "<<place;
			cout << "\n\n\n "<<note;
			cout << "-------------------------------------------------------------------------------------------------";
			cout << "-------------------------------------------------------------------------------------------------";
			cout <<"\n\n\n";
		 }
		  void complete_display() //To display complete information
		 {
		 	cout << "\n\n";
			cout << "\t\t "<<date;
			cout << "\t\t "<<time;
			cout << "\t\t "<<place;
			cout << "\n\n\n "<<note;
			cout << "-------------------------------------------------------------------------------------------------";
			cout << "-------------------------------------------------------------------------------------------------";
			cout <<"\n\n\n";
			getch();
		 }
		 void modify()      //To input information for modification in daily diary
	 	{    
	 		cout << "\n\n\n";
			cout << "\t\t\t Enter the date in this format only DD.MM.YYYY ";
			PlaySound(TEXT("e_date.wav"),NULL,SND_SYNC);
			cin >> date;
			fflush(stdin);
			cout << "\n\n\n";
			cout << "\t\t\t Enter modified time in this format 00.00(am/pm) ";
			PlaySound(TEXT("e_time.wav"),NULL,SND_SYNC);
			cin.getline(time,20);
			fflush(stdin);
			cout << "\n\n\n";
			cout << "\t\t\t Enter modified place ";
			PlaySound(TEXT("p.wav"),NULL,SND_SYNC);
			cin.getline(place,100);
			fflush(stdin);
			cout << "\n\n\n";
			cout << "\t\t\t Write your modified note in diary ";
			PlaySound(TEXT("mod_note.wav"),NULL,SND_SYNC);
			cin.getline(note,500000);
			fflush(stdin);
			getch();
		 }
		 
		 void reminder()
		 {
		 	cout << "\n\n\n ";
			cout << "\t\t\t Enter the date in this format only DD.MM.YYYY ";
			PlaySound(TEXT("e_date.wav"),NULL,SND_SYNC);
			cin >> date1;
			fflush(stdin);
			cout << "\n\n\n";
			cout << "\t\t\t Enter time in this format only 00.00(am/pm) ";
			PlaySound(TEXT("e_time.wav"),NULL,SND_SYNC);
			cin.getline(time1,20);
			fflush(stdin);
			cout << "\n\n\n";
			cout << "\t\t\t Add reminder ";
			PlaySound(TEXT("add_rem.wav"),NULL,SND_SYNC);
			cin.getline(note1,500000);
			getch();
		 }
		  void rem_show()
		  {
		  	cout << "\n\n\n";
			cout << "\t\t\t--------Reminder--------";
			cout << "\t\t "<< date1 << endl;
			cout << "\t\t "<< time1 << endl;
			cout << "\n\n\n "<< note1 << "\n\n";
			cout << "-------------------------------------------------------------------------------------------------";
			cout << "-------------------------------------------------------------------------------------------------";
			cout <<"\n\n\n";
			getch();
		  }
		  
		 double return_date() // It returns the date which is entered.
		 {
		 	return date;
		 }
		 

};
class DiaryFile :public diary
{
	diary obj;
	ifstream read_file;
	ofstream write_file;
	public:
		//function declerations.
		void enter_info();                 //function declered for information
		void view_info(double);           //function declered for viewing particular information
		void modify(double);             //function declered  for modifying information
		void remove(double);            //function declered for removing information
		void view_comp();              //function declared for seeing complete information of diary
		void diary_information();      //function declared to show the information about diary.
		void add_reminder();          //function declared to add content in reminder
		void show_reminder();         // function to show reminder
};


//enter information

void DiaryFile::enter_info()
{ 
	char choice ='y';
	write_file.open("diary007.dat",ios::binary|ios::app);
	while(choice=='y'|| choice=='Y')
	{
		obj.input();
		write_file.write((char*)(&obj), sizeof(diary));
	 	cout << "\n\n\n";
		cout << "\t\t\t Do you want to add another(y/n)  ";
	 	PlaySound(TEXT("d_want.wav"),NULL,SND_SYNC);
	 	cin>>choice;
	}
	write_file.close();
	 		
}
		 
		 
//view particular information
void DiaryFile::view_info(double dat)
{   
	system("color 4f");
	bool flag=false;
	read_file.open("diary007.dat",ios::binary);
	if(!read_file)
	{
		cout<<"\t\t\t File could not be open.";
		return;
	}
	while(read_file.read((char *)(&obj), sizeof(diary)))
	{	
		if(obj.return_date()==dat)
	    {
	    	obj.display();
	    	flag=true;
		} 
	}
	read_file.close();
	if(flag==false)
	cout<<"\n\n";
	cout << "\t\t\t Information does not exist";
	getch();
}
		 
///modify information
void DiaryFile::modify(double dat)
{
	bool f=false;
	fstream m_file;
	m_file.open("diary007.dat",ios::binary|ios::in|ios::out);
	 	 	
	if(!m_file)
	{
	 	cout<<"\t\t\t File can not be open.";
	 	return;
	}
	while(!m_file.eof() && f==false)
	{
		m_file.read((char *) (&obj), sizeof(diary));
	 	if(obj.return_date()==dat)
	 	{
	 		obj.complete_display();
	 		cout<<"\n\n\n";
			cout << "\t\t\t Make Changes in your Diary\n\n\n";
	 		obj.modify();
	 		double pos=(-1)*static_cast<double>(sizeof (diary));  // style cast to make it signed so that 
	 		m_file.seekg(pos,ios::cur);
	 		m_file.write((char *) (&obj), sizeof(diary));
	 		cout<<"\n\n\n";
			cout << "\t\t\t Content changed successfully..\n";
	 		f=true;
	 		getch();
		}
	}
	m_file.close();
	if(f==false)
	cout<<"\n\n\n";
	cout << "\t\t\t Record does not exist.\n";
	getch();

}

//remove information
void DiaryFile::remove(double dat)
{
	system("color 4f");
	read_file.open("diary007.dat",ios::binary);
	if(!read_file)
	{
		cout << "File could not be open ";
		return;
	}
	write_file.open("copy.dat",ios::binary);
	read_file.seekg(0,ios::beg);
	while(read_file.read((char *)(&obj),sizeof(diary)))
	{
		if(obj.return_date()!=dat)
		{
			write_file.write((char *)(&obj),sizeof(diary));
		}
	}
    read_file.close();
	write_file.close();
	//remove("diary007.dat");
	rename("copy.dat","diary007.dat");
	cout<<"\n\n\tRecord Removed ..";
	getch();
}

//view complete information
void DiaryFile::view_comp()
{   
	system("color 4f");
	read_file.open("diary007.dat",ios::binary);
	if(!read_file)
	{
		cout<<"File could not be open ";
		return;
	}
	while(read_file.read((char *) (&obj), sizeof(diary)))
	{
	    obj.complete_display();	
	}
	read_file.close();
}		 

//add reminder to new reminder file
void DiaryFile::add_reminder()
{
	char choice ='y';
	write_file.open("reminder1.dat",ios::binary|ios::app);
	while(choice=='y'|| choice=='Y')
	{
		obj.reminder();
	 	write_file.write((char*)(&obj), sizeof(diary));
	 	cout<<"\n\n\n ";
		cout << "\t\t\t Do you want to add another(y/n)  ";
	 	PlaySound(TEXT("d_want.wav"),NULL,SND_SYNC);
	 	cin>>choice;
	}
	write_file.close();
	 		
}
  
// show reminder
void DiaryFile::show_reminder()
{   
	system("color 4f");
	read_file.open("reminder1.dat",ios::binary);
	if(!read_file)
	{
		cout<<"File could not be open ";
		return;
	}
	while(read_file.read((char *) (&obj), sizeof(diary)))
	{
		obj.rem_show();	
	}
	read_file.close();
	getch();
}	

//diary introduction

void diary_info()
{
	string note;
	cout << "\n\n\n";
	cout << "\t\t ......PERSONAL DIALY DIARY......\n\n\n";
	ifstream read_file("Information.txt");
	if(read_file.is_open())
	{
		while(getline(read_file,note))
		{
			cout << note << endl;
			Sleep(120);
		}
	}
	else
	cout << "File could note be opened ";
	getch();
}


// Main
int main()
{
	char c='1';
	DiaryFile diaryfile;
	int choice, n=1;
	int counter=0;
	int p;
	double txt;
	char password[20]="12345";
	char pass[20];
	int remi=1;    //It is for reminder 
	
	while(1)
	{
		system("cls");
		system("color 4f");
		system("cls");
		fstream object1("pass.txt",ios::app);
		ifstream object2("pass.txt");
		cout<<"\n\n\n";
		if(n==1)
		{
			PlaySound(TEXT("dd.wav"),NULL,SND_SYNC);
		}
		cout<<" \t\t\t\t DAILY DIARY";
		cout<<"\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t ENTER PASSWORD TO OPEN DIARY ";
    	PlaySound(TEXT("password.wav"),NULL,SND_SYNC);
	  	object1<<"12345"<<endl;     // default password //
		cout<<"\n\n\n\n";
		cout << "\t\t\t\t Password- ";
		cin>>pass;
      	object2.seekg(0);
	  	object2>>password;
	  	object1.close();
	  	object2.close();
	  	if(strcmp(pass,password)==0)
		{
			system("cls");
			if(remi==1)
			{
				PlaySound(TEXT("per.wav"),NULL,SND_SYNC);
				diary_info();
				Sleep(100);
				system("cls");
				PlaySound(TEXT("e_any.wav"),NULL,SND_SYNC);
				diaryfile.show_reminder();
				getch();
			}
			remi=0;
			system("cls");

				do
				{	
					system("cls");
					system("color 30");
					cout << "\n\n\n";
					cout << "\t\t\t DAILY DIARY";
					cout << "\n\n\n\n";
					cout << "\t\t 1. Enter Information \n\n";
					PlaySound(TEXT("info.wav"),NULL,SND_SYNC);
					cout << "\t\t 2- View  particular page\n\n";
        			PlaySound(TEXT("particular_page.wav"),NULL,SND_SYNC);
					cout << "\t\t 3- Modify Information\n\n";
					PlaySound(TEXT("modify_info.wav"),NULL,SND_SYNC);
        			cout << "\t\t 4- Remove Information of page\n\n";                      
        			PlaySound(TEXT("remove.wav"),NULL,SND_SYNC);
					cout << "\t\t 5- Change password\n\n";
       				PlaySound(TEXT("change_password.wav"),NULL,SND_SYNC);
					cout << "\t\t 6- View complete pages\n\n";
        			PlaySound(TEXT("view_complete_info.wav"),NULL,SND_SYNC);
					cout << "\t\t 7- Add Reminder\n\n";
        			PlaySound(TEXT("add_reminder.wav"),NULL,SND_SYNC);
					cout << "\t\t 8- Exit\n\n\n\n";
       				PlaySound(TEXT("exit.wav"),NULL,SND_SYNC);
					cout << "\t\t Enter Your Choice... ";
        			PlaySound(TEXT("choice.wav"),NULL,SND_SYNC);
					cin >> choice;
        			system("cls");//Clear screen
        			switch (choice)
        			{
        				case 1:
        				{
        					system("cls");
        					cout << "\n\n\n";                    
							cout << "\t\t\t Enter Information\n";
        					system("color 1f");
        					diaryfile.enter_info();
        				}
        				break;//break case 1
        				case 2:
        				{
        					system("cls");
							system("color 2f");	
        					cout << "\n\n\n";
							cout << "\t\t\t Enter date in this format only DD.MM.YYYY  ";
        				    cin >> txt;
        				    diaryfile.view_info(txt);
        				}
        				break;//break case 2
        				case 3:
        				{
        					system("cls");
							system("color 5f");
        					cout << "\n\n\n";
							cout << "\t\t\t Enter date in this format only DD.MM.YYYY  ";
        					cin >> txt;
        					diaryfile.modify(txt);
        				}
        				break;//break case 3
        				case 4:
        				{
        					system("cls");
							system("color 6f");
		    				cout<<"\n\n\n";
							cout << "\t\t\t Enter date in this format only DD.MM.YYYY  ";
        					cin >> txt;
        					diaryfile.remove(txt);
        				}
        				break;//break case 4
        				case 5:
        				{
        					system("cls");
							system("color 7f");
        					cout << "\n\n\n";
							cout << "\t\t\t Change password\n\n";
	                        ofstream object("pass.txt");
		                    cout << " \t\t\t Enter new password: ";
							PlaySound(TEXT("n_pass.wav"),NULL,SND_SYNC); 
		                    cin >> password;
		                    object<<password<<endl;
		                    object.close();
		                	cout << "password changed successfully\n";
		                    PlaySound(TEXT("ch_pass.wav"),NULL,SND_SYNC);
		                    PlaySound(TEXT("e_any.wav"),NULL,SND_SYNC);
		                    getch();
        				}
        				break;//break case 5
		                case 6:
		                {
		                	system("cls");
							system("color 2f");
        					diaryfile.view_comp();
		            	}
        				break;//break case 6
        				case 7:
        				{
        					system("cls");
        					cout << "\n\n\n";                
							cout << "\t\t\t Add Reminder\n";
        					PlaySound(TEXT("add_rem.wav"),NULL,SND_SYNC);
        					system("color 1f");
        					diaryfile.add_reminder();
        				}
        				break;//break case 7
        				case 8:
        				{
        					system("cls");
							system("color 9f");
							cout << "\n\n\n\n";
        					cout << "\t\t\t Good Bye\n";
							cout << "\n\n\n";
        					cout << "\t\t\t See You Soon";
       						PlaySound(TEXT("b_exit.wav"),NULL,SND_SYNC);
        					cout << "\n\n\n\n";
							exit(1);
						}
						break;//break case 8
					} // switch (choice)
				}while(choice!=8); // Do-While

		} // If
		else
		{
			if(counter==3)
	  		{
				exit(1);
	  		}
	   		else
	    	++counter;
			cout<<"\n\n\n";                    
			cout << "\t\t\t WRONG PASSWORD "<<endl;
			cout<<"\n\n";
			cout << "\t\t\t PRESS ANY KEY TO RE-ENTER PASSWORD ";
			PlaySound(TEXT("e_any.wav"),NULL,SND_SYNC);
			getch();
		} // Else
		n=0;
	} // While(1)
	system("pause");
	return 0;
} // Main

