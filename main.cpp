#include<iostream>
#include<sstream>
#include<vector>
#include <fstream>
#include <string>
#include <unistd.h>
#include<filesystem>

//name spaces 
namespace fs = std::filesystem;
using namespace std;

//global declarations
char cwd[1024];

//All functions 

//echp
void echo(string s)
{
    cout<<s<<endl;
}

//help
void uhelp()
{
cout<<"This is the reverse terminal means you have to type the command reverse like \necho - > ohce \ncd - > dc\nls - > sl\nmkdir - > ridkm \nlike this \nIf there is any doubt about the command please type COMMAND --help \n\n";
}

//prints the content of file (cat)
void readf(string fname)
{
   ifstream file(fname);

   if(!file.is_open())
    {
        cout<<"\033[31m"<<"There is no file in the directory\n";
    }
    else
    {
        string s;
        while(getline(file,s))
        {
            cout<<s<<endl;
        }
    }
  file.close();
}

//Geting current working directory 
void currworkdir()
{

  getcwd(cwd,sizeof(cwd));
}

//ls
void getfiles()
{
  cout<<"\033[34m";
  for(const auto & entry :fs::directory_iterator("."))
  {
    cout<<entry<<endl;
  }
}

//cd
void changedir(const char * path )
{
  if(chdir(path)!=0)
 cout<<"\033[31m"<<"Given path is not found\n";
}

//mkdir
void makedir(string name)
{
  if(!filesystem::create_directory(name))
    cout<<"\033[31m"<<"Failed to create a new directory\n";
}

//rmdir
void removedir(string name)
{
  if(!filesystem::remove(name))
     cout<<"\033[31m"<<"Directory not found \n";
}

//touch
void makefile(string name)
{
  ofstream file(name);
  
  if(!file.is_open())
  {
    cout<<"\033[31m"<<"Failed to create the file \n";
  }
  file.close();
}

void cpfile(string file1,string file2)
{
  ofstream file(file2);
  ifstream file11(file1);
  string s="";string m;
  if(!file11.is_open())
  {
    cout<<"\033[31m"<<"   "<<file1<<" There is no file in the directory\n";
  }
  else
  {
    while(file11>>m)
    {
        s+=m;
        s+="\n";
    }
  }

  if(!file.is_open())
  {
    cout<<"\033[31m"<<"Cant create the file please try again";
  }
  else
  {
    file<<s;
  }
}


int  main()
{
    while(1){ 
       currworkdir();
    string s;
    cout<<"\033[32m"<<"xunil@user:"<<"\033[33m"<<cwd<<"\033[37m"<<"$  ";
   getline(cin,s);
   stringstream m(s);
   string w;
   vector<string> tokens;
   while(m>>w)
    tokens.push_back(w);
 int f=0;
  s="";
  if(!tokens.size())
    continue;
  if(tokens[0]=="ohce")
     {  
        if(tokens.size()<2 ){
         cout<<"Argument is missing "<<endl<<endl;
         uhelp();
        }
        else
        if(tokens[1]=="--help")
          uhelp();
          else
        if(tokens[1][0]!='"' || tokens[1][tokens[1].size()-3]!='"'){
          cout<<"Syntax error"<<endl<<endl;
          uhelp();
        }
     else{
     for(int i=1;i<tokens.size();i++)
      {
        s+=tokens[i];
        s+=" ";
      }
      echo(s);
     }
    }

  else
    {
        if(tokens[0]=="tixe" && tokens.size()==1)
          break;
        else{
             if(tokens[0]=="raelc" && tokens.size()==1)
                system("clear");
             else{
                if(tokens[0]=="tac" && tokens.size()==2)
                  {
                    readf(tokens[1]);
                  }
                  else
              {
                    if(tokens[0]=="dwp" && tokens.size()==1)
                      {
                        cout<<cwd<<endl;
                      }
                      else
                    {
                         if(tokens[0]=="sl" && tokens.size()==1)
                            {
                              getfiles();
                            }
                          else
                          {
                             if(tokens[0]=="dc")
                             {
                              if(tokens.size()!=2)
                                cout<<"Invalid path \n";
                              else
                                {
                                  string temp=tokens[1];
                                  changedir(temp.c_str());
                                }
                             }
                             else{
                               if(tokens[0]=="ridkm" && tokens.size()==2)
                                {
                                  makedir(tokens[1]);
                                }
                                else
                                {
                                  if(tokens[0]=="ridmr" && tokens.size()==2)
                                   {
                                    removedir(tokens[1]);
                                   }
                                  else{
                                    if(tokens[0]=="hcuot")
                                    {
                                      if(tokens.size()!=2)
                                        cout<<"Invalid filename \n";
                                      else
                                        makefile(tokens[1]);
                                    }
                                    else{
                                      if(tokens[0]=="pc")
                                      {
                                        if(tokens.size()!=3)
                                        {
                                          cout<<"\033[031m"<<"Invalid syntax for copying \n";
                                        }
                                        else
                                        {
                                          cpfile(tokens[1],tokens[2]);
                                        }
                                      }
                                      else
                                      {
                                  cout<<"\033[31m"<<"! Command not found !\n\033[37m";
                                  uhelp();
                                      }
                                    }
                                  }
                                }
                              }
                            }
                        }
                      }
             }
        }
         
    }
}
    
   return 0;
}