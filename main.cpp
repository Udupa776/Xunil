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
        cout<<"There is no file in the directory\n";
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
  for(const auto & entry :fs::directory_iterator("."))
  {
    cout<<entry<<endl;
  }
}

//cd
void changedir(const char * path )
{
  if(chdir(path)!=0)
 cout<<"Given path is not found\n";
}

//mkdir
void makedir(string name)
{
  if(!filesystem::create_directory(name))
    cout<<"Failed to create a new directory\n";
}

//rmdir
void removedir(string name)
{
  if(!filesystem::remove(name))
     cout<<"Directory not found \n";
}

//touch
void makefile(string name)
{
  ofstream file(name);
  
  if(!file.is_open())
  {
    cout<<"Failed to create the file \n";
  }
  file.close();
}

int  main()
{
    while(1){ 
       currworkdir();
    string s;
    cout<<"xunil@"<<cwd<<":";
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
                                  cout<<"! Command not found !";
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
    
   return 0;
}