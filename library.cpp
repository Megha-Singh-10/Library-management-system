#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
fstream f;
void quiz();
void game();
class player
{
  char name[20];
  public:
  int score;
  void read()
  {
    cout<<"\n Enter your name \n";
    gets(name);
   }
  void display()
  {
    cout<<"Name: "<<name<<"\n";
    cout<<"Score: "<<score<<"\n";
   }
  player()
  {
   score=0;
  }
};
//class ends here
class book
{
  char bno[6];
  char bname[50];
  char aname[20];
  public:
  void createbook()
  {
    cout<<"\n NEW BOOK ENTRY\n";
    cout<<"\n Enter the book no.\n";
    cin>>bno;
    cout<<"\n Enter the name of the book\n";
    gets(bname);
    cout<<"\n Enter the Author's name\n";
    gets(aname);
    cout<<"\n BOOK CREATED\n";
   }
  void showbook()
  {
    cout<<"\n Book No.:"<<bno;
    cout<<"\n Book Name:"<<bname;
    cout<<"\n Author's Name:"<<aname;
  }
  void modifybook()
  {
    cout<<"\n Book No.:"<<bno;
    cout<<"\n Modify Book Name:";
    gets(bname);
    cout<<"\n Modify Author's Name of Book\n";
    gets(aname);
  }
  char*retbno()
  {
    return bno;
  }
  void report()
  {
    cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
  }
};
//class ends here
class student
{
  char rno[6];
  char name[20];
  char sbno[6];
  int token;
  public:
  void createstudent()
  {
    clrscr();
    cout<<"\n NEW STUDENT ENTRY \n";
    cout<<"\n Enter the Roll No.\n";
    cin>>rno;
    cout<<"\n Enter the name of the student\n";
    gets(name);
    token=0;
    sbno[0]='\o';
    cout<<"\n Student Record Created\n";
  }
  void showstudent()
  {
    cout<<"\n Roll No.:"<<rno;
    cout<<"\nStudent Name:"<<name;
    cout<<"\n No. of Books Issued :"<<token;
    if(token==1)
      {
      cout<<"\n Book No."<<sbno;
      }
    }
  void modifystudent()
  {
    cout<<"\n Roll No.:"<<rno;
    cout<<"\n Modify Student Name:";
    gets(name);
  }
  char* retrno()
  {
    return rno;
  }
  char* retsbno()
  {
    return sbno;
  }
  int rettoken()
  {
    return token;
  }
  void addtoken()
  {
    token=1;
  }
  void resettoken()
  {
    token=0;
  }
  void getsbno(char t[])
  {
    strcpy(sbno,t);
  }
  void report()
  {
    cout<<"\t"<<rno<<setw(30)<<name<<setw(20)<<token<<endl;
  }
};
//class ends here
fstream f1,f2;
book b1;
student s1;
void writebook()
{
  char ch;
  f1.open("book.txt",ios::out|ios::app);
  do
  {
    clrscr();
    b1.createbook();
    f1.write((char*)&b1,sizeof(book));
    cout<<"\n Do you want to add more record\n";
    cin>>ch;
  }while(ch=='y'||ch=='Y');
  f1.close();
  }
//function ends here
void writestudent()
{
  char ch;
  f1.open("student.txt",ios::out|ios::app);
  do
  {
    clrscr();
    s1.createstudent();
    f1.write((char*)&s1,sizeof(student));
    cout<<"\n Do you want to add more record\n";
    cin>>ch;
  }while(ch=='y'||ch=='Y');
  f1.close();
  }
//function ends here
void displayspb(char n[])
{
  cout<<"\n BOOK DETAILS\n";
  int flag=0;
  f1.open("book.txt",ios::in|ios::binary);
  while(f1.read((char*)&b1,sizeof(book)))
  {
    if(strcmpi(b1.retbno(),n)==0)
    {
      b1.showbook();
      flag=1;
    }
  }
  f1.close();
  if(flag==0)
  {
    cout<<"\n Book does not exist\n";
  }
  getch();
  }
//function ends here
void displaysps(char n[])
{
  cout<<"\n STUDENT DETAILS\n";
  int flag=0;
  f1.open("student.txt",ios::in|ios::binary);
  while(f1.read((char*)&s1,sizeof(student)))
  {
    if(strcmpi(s1.retrno(),n)==0)
    {
      s1.showstudent();
      flag=1;
    }
  }
  f1.close();
  if(flag==0)
  {
    cout<<"\n Student does not exist\n";
  }
  getch();
  }
//function ends here
void modifybook()
{
  char n[6];
  int found=0;
  clrscr();
  cout<<"\n MODIFY BOOK RECORD\n";
  cout<<"\n Enter the Book no. of Book\n";
  cin>>n;
  f1.open("book.txt",ios::in|ios::out|ios::binary);
  while(f1.read((char*)&b1,sizeof(book))&&found==0)
  {
    if(strcmpi(b1.retbno(),n)==0)
    {
      b1.showbook();
      cout<<"\n Enter The New Details Of The Book\n";
      b1.modifybook();
      int pos=-1*sizeof(b1);
      f1.seekp(pos,ios::cur);
      f1.write((char *)&b1,sizeof(book));
      cout<<"\n Record Updated\n";
      found=1;
    }
  }
  f1.close();
  if(found==0)
  {
    cout<<"\n Record Not Found\n";
   }
  getch();
}
//function ends here
void modifystudent()
{
  char n[6];
  int found=0;
  clrscr();
  cout<<"\n MODIFY STUDENT RECORD\n";
  cout<<"\n Enter the Roll no. of Student\n";
  cin>>n;
  f1.open("student.txt",ios::in|ios::out|ios::binary);
  while(f1.read((char*)&s1,sizeof(student))&& found==0)
  {
    if(strcmpi(s1.retrno(),n)==0)
    {
      s1.showstudent();
      cout<<"\n Enter The New Details Of The Student\n";
      s1.modifystudent();
      int pos=-1*sizeof(s1);
      f1.seekp(pos,ios::cur);
      f1.write((char *)&s1,sizeof(student));
      cout<<"\n Record Updated\n";
      found=1;
    }
  }
  f1.close();
  if(found==0)
  {
  cout<<"\n Record Not Found\n";
  }
  getch();
  }
//function ends here
void deletestudent()
{
  char n[6];
  int flag=0;
  clrscr();
  cout<<"\n DELETE STUDENT\n";
  cout<<"\n Enter the rollno. of the student you want to delete:\n";
  cin>>n;
  f1.open("student.txt",ios::in|ios::out|ios::binary);
  fstream f3;
  f3.open("temp.txt",ios::out|ios::binary);
  f1.seekg(0,ios::beg);
  while(f1.read((char*)&s1,sizeof(student)))
  {
    if(strcmpi(s1.retrno(),n)!=0)
      f3.write((char*)&s1,sizeof(student));
  else
      flag=1;
  }
  f3.close();
  f1.close();
  remove("student.txt");
  rename("temp.txt","student.txt");
  if(flag==1)
  {
    cout<<"\n Record Deleted\n";
  }
  else
  {
    cout<<"\n Record Not Found\n";
  }
  getch();
  }
//function ends here
void deletebook()
{
  char n[6];
  clrscr();
  cout<<"\n DELETE BOOK\n";
  cout<<"\n Enter the bookno. of the book you want to delete:\n";
  cin>>n;
  f1.open("book.txt",ios::in|ios::out|ios::binary);
  fstream f3;
  f3.open("temp.txt",ios::out|ios::binary);
  f1.seekg(0,ios::beg);
  while(f1.read((char*)&b1,sizeof(book)))
  {
    if(strcmpi(b1.retbno(),n)!=0)
    {
      f3.write((char*)&b1,sizeof(book));
    }
  }
  f3.close();
  f1.close();
  remove("book.txt");
  rename("temp.txt","book.txt");
  cout<<"\n Record Deleted\n";
  getch();
  }
//function ends here
void displayalls()
{
  clrscr();
  f1.open("student.txt",ios::in|ios::binary);
  if(!f1)
  {
    cout<<"\n ERROR!!!!!!!FILE COULD NOT BE OPEN";
    getch();
    return;
  }
  cout<<"\n\n\t\t STUDENT LIST\n\n";
  cout<<"================================================
  ===================\n";
  cout<<"\t Roll No."<<setw(20)<<"Name"<<setw(30)<<"Book                            Issued \n";
  cout<<"================================================== =================\n";
  while(f1.read((char*)&s1,sizeof(student)))
  {
    s1.report();
  }
  f1.close();
  getch();
  }
//function ends here
void displayallb()
{
  clrscr();
  f1.open("book.txt",ios::in|ios::binary);
  if(!f1)
  {
    cout<<"\n ERROR!!!!!!!FILE COULD NOT BE OPEN";
    getch();
    return;
  }
  cout<<"\n\n\t\t BOOK LIST\n\n";
  cout<<"================================================
  ===================\n";
  cout<<"\t BOOK No."<<setw(20)<<"Book    Name"<<setw(30)<<"AUTHOR\n";
  cout<<"================================================
  ===================\n";
  while(f1.read((char*)&b1,sizeof(book)))
  {
    b1.report();
  }
  f1.close();
  getch();
  }
//function ends here
void bookissue()
{
  char sn[6],bn[6];
  int found=0,flag=0;
  clrscr();
  cout<<"\n\nBOOK ISSUE\n";
  cout<<"\n\n Enter the students rollno.\n";
  cin>>sn;
  f1.open("student.txt",ios::in|ios::out|ios::binary);
  f2.open("book.txt",ios::in|ios::out|ios::binary);
  while(f1.read((char*)&s1,sizeof(student))&&found==0)
  {
    if(strcmpi(s1.retrno(),sn)==0)
    {
      found=1;
      if(s1.rettoken()==0)
      {
        cout<<"\n\n\tEnter the book no.\n";
        cin>>bn;
        while(f2.read((char*)&b1,sizeof(book))&&flag==0)
        {
          if(strcmpi(b1.retbno(),bn)==0)
          {
            b1.showbook();
            flag=1;
            s1.addtoken();
            s1.getsbno(b1.retbno());
            int pos=-1*sizeof(s1);
            f1.seekp(pos,ios::cur);
            f1.write((char*)&s1,sizeof(student));
            cout<<"\n\n\t Book issued successfully\n\n";
            cout<<"\n Please Note:Write Current date in backside of book       and submit within 15 days.\nRs1/- fine for each day after 15 days  period.\n";
          }
        }
        if(flag==0)
        {
          cout<<"\n Book Does Not Exist\n";
        }
      }
      else
      {
        cout<<"You have not returned the last book\n";
      }
    }
  }
  if(found==0)
  {
    cout<<"\n Student record does not exist\n";
  }
  getch();
  f1.close();
  f2.close();
  }
//function ends here
void bookdeposit()
{
  char sn[6],bn[6];
  int found=0,flag=0,day,fine;
  clrscr();
  cout<<"\n\n BOOK DEPOSIT\n";
  cout<<"\n Enter the students rollno.\n";
  cin>>sn;
  f1.open("student.txt",ios::in|ios::out|ios::binary);
  f2.open("book.txt",ios::in|ios::out|ios::binary);
  while(f1.read((char*)&s1,sizeof(student))&&found==0)
  {
    if(strcmpi(s1.retrno(),sn)==0)
    {
      found=1;
      if(s1.rettoken()==1)
      {
      while(f2.read((char*)&b1,sizeof(book))&&flag==0)
      {
        if(strcmpi(b1.retbno(),s1.retsbno())==0)
        {
          b1.showbook();
          flag=1;
          cout<<"\n\n Book deposited in no. of days\n";
          cin>>day;
          if(day>15)
          {
             fine=(day-15)*1;
            cout<<"\nFine has to be deposited Rs"<<fine;
          }
          s1.resettoken();
          int pos=-1*sizeof(s1);
          f1.seekp(pos,ios::cur);
          f1.write((char*)&s1,sizeof(student));
          cout<<"\n\n\t Book deposited successfully";
        }
      }
      if(flag==0)
      cout<<"Book does not exist\n";
     }
      else
        cout<<"No book issued!! please check";
      }
    }
    if(found==0)
    {
      cout<<"\n Student record does not exist\n";
    }
    getch();
    f1.close();
    f2.close();
  }
//function ends here
void intro()
{
  textbackground(BLUE);
  textcolor(RED+BLINK);
  clrscr();
  cout<<"\n\n\t\t\t\t";
  cprintf("WELCOME");
  textcolor(BLACK);
  cout<<"\n\n\t\t\t\t";
  cprintf("LIBRARY");
  cout<<"\n\n\t\t\t\t";
  cprintf("MANAGEMENT");
  cout<<"\n\n\t\t\t\t";
  cprintf("SYSTEM");
  cout<<"\n\n\n\n MADE BY:\n MEGHA\n SHRUTI\n MISA";
  cout<<"\n\n SCHOOL: KV NO.2 JALAHALLI EAST BANGALORE 14";
  textcolor(WHITE);
  textbackground(BLACK);
  getch();
}
//function ends here
void adminmenu()
{
  clrscr();
  int op;
  cout<<"\n\n\n\t\t\t ADMINISTRATOR MENU\t\t\n";
  cout<<"\n\t 1.CREATE STUDENT RECORD";
  cout<<"\n\t 2.DISPLAY ALL STUDENT RECORD";
  cout<<"\n\t 3.DISPLAY SPECIFIC STUDENT RECORD";
  cout<<"\n\t 4.MODIFY STUDENT RECORD";
  cout<<"\n\t 5.DELETE STUDENT RECORD";
  cout<<"\n\t 6.CREATE BOOK";
  cout<<"\n\t 7.DISPLAY ALL BOOKS";
  cout<<"\n\t 8.DISPLAY SPECIFIC BOOK";
  cout<<"\n\t 9.MODIFY BOOK";
  cout<<"\n\t 10.DELETE BOOK";
  cout<<"\n\t 11.BACK TO MAIN MENU\n";
  cout<<"\n\n\t Please enter your choice(1-11) \n";
  cin>>op;
  switch(op)
  {
    case 1:  clrscr();
	        writestudent();
	        break;

    case 2:  displayalls();
	        break;

    case 3:  char num[6];
	        clrscr();
	        cout<<"\n\n\t Please enter the Rollno\n";
	        cin>>num;
	       displaysps(num);
	       break;

    case 4:  modifystudent();
	        break;

    case 5:  deletestudent();
	         break;

    case 6:  clrscr();
	        writebook();
	        break;

    case 7:  displayallb();
	        break;

    case 8:  {
	          char num[6];
	          clrscr();
	          cout<<"\n Please enter the book no.\n";
	          cin>>num;
	         displayspb(num);
	         break;
	       }

    case 9:  modifybook();
	        break;

    case 10: deletebook();
	          break;

    case 11: return;

    default: cout<<"\Enter valid choice";
  }
  adminmenu();
}
//function ends here
void main()
{
  int ch;
  intro();
  do
  {
    clrscr();
    cout<<"\n\n\n\n\tMAIN MENU";
    cout<<"\n\n\t01.BOOK ISSUE";
    cout<<"\n\t02.BOOK DEPOSIT";
    cout<<"\n\t03.ADMINISTRATOR MENU";
    cout<<"\n\t04.PLAY QUIZ ON BOOKS";
    cout<<"\n\t05.EXIT\n";
    cout<<"\n Please select your choice(1-5)\n";
    cin>>ch;
    switch(ch)
    {
      case 1:   clrscr();
	           bookissue();
	           break;

      case 2:   bookdeposit();
	            break;

      case 3:   adminmenu();
	           break;

      case 4:   game();
	           break;

      case 5:   exit(0);

      default:  cout<<"\Enter valid choice";
    }
  }while(ch!=4);
  getch();
}
void  quiz()
{
  int sc=0;
  char a[20];
  player p;
  f.open("game.txt",ios::out|ios::in|ios::binary);
  p.read();
  f.write((char*)&p,sizeof(p));
  clrscr();
   cout<<"\nQuestion 1:\n";
  cout<<"\nWho wrote the famous book-'WE THE PEOPLE'?\n";
  gets(a);
  if(strcmpi(a,"NANI PALKHIWALA")==0)
  {
    sc=sc+10;
    cout<<"Correct Answer";
  }
  else
  {
    sc=sc-5;
    cout<<"Wrong Answer\n\n\nThe correct answer is:\nNani   Palkhiwala\n";
  }
  clrscr();
  cout<<"\nQuestion 2:\n";
  cout<<"\nWho is the author of the book:'1984'?\n";
  gets(a);
  if(strcmpi(a,"GEORGE ORWELL")==0)
  {
    sc=sc+10;
    cout<<"\n Correct Answer\n ";
  }
  else
  {
    sc=sc-5;
    cout<<"\n Wrong Answer\n\n\nThe correct answer is:\nGeorge  Orwell\n";
  }
  clrscr();
  cout<<"\nQUESTION 3:\n";
  cout<<"\nAuthor of 'AROUND THE WORLD IN EIGHTY DAYS' is\n";
  gets(a);
  if(strcmpi(a,"WILLIAM SHAKESPEARE")==0)
  {
    sc=sc+10;
     cout<<"\n Correct Answer\n ";
  }
  else
  {
    sc=sc-5;
    cout<<"\n Wrong Answer\n\n\nThe correct answer is:\nWilliam  Shakespeare\n";
}
  clrscr();
  cout<<"\nQUESTION 4:\n";
  cout<<"\nWho said 'MAN IS A POLITICAL ANIMAL'?\n";
  gets(a);
  if(strcmpi(a,"PLATO")==0)
  {
    sc=sc+10;
    cout<<"\n Correct Answer\n ";
  }
  else
  {
    sc=sc-5;
    cout<<"\n Wrong Answer\n\n\n The correct answer is : \nPLATO\n";
  }
  clrscr();
  cout<<"\nQUESTION 5:\n";
  cout<<"\nWho is the author of the book 'FORBIDDEN VERSES'?\n";
  gets(a);
  if(strcmpi(a,"ABU NUWAS")==0)
  {
    sc=sc+10;
    cout<<"\n Correct Answer\n ";
  }
  else
  {
    sc=sc-5;
    cout<<"\n Wrong Answer\n\n\n The correct answer is:\nAbu   Nuwas\n";
  }
  clrscr();
  p.score=sc;
  f.write((char*)&p,sizeof(p));
  f.seekg(0);
  while(f.read((char*)&p,sizeof(p)))
  {
    clrscr();
    textbackground(BLUE);
    p.display();
  }
  f.close();
}
//function ends here
void game()
{
  char ch;
  int op;
  textbackground(BLUE);
  clrscr();
  textcolor(RED+BLINK);
  cout<<"\n\t\t\t\t   ";
  cprintf("\n\n\nWELCOME\n");
  textcolor(BLACK);
  cout<<"\t\t\t\t\t\t\t";
  cprintf("\n\n\nTHIS QUIZ IS BASED ON BOOKS YOU MIGHT HAVE   READ!!!\n");
  textcolor(YELLOW);
  cout<<"\n\n\n\n\n To continue press any key\n\nTo exit press  n\n\n\n";
  cin>>ch;
  while(ch!='n')
  {
    clrscr();
    textbackground(RED);
    cout<<"\t\t\tMENU"<<endl;
    cout<<"1.PLAY THE GAME\n";
    cout<<"2.QUIT\n";
    cout<<endl;
    cout<<"\n Enter your choice\n";
    cin>>op;
    switch(op)
    {
      case 1: quiz();
                    break;
      case 2: exit(0);
      default: cout<<"\n Enter valid choice\n";
	          cin>>op;
	          break;
    }
    cout<<"\n Do you want to play again\n";
    cin>>ch;
  }
}
//function ends here
//program ends here
