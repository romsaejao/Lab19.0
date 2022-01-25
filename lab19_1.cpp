#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores, vector<char> &grades)
{
    ifstream source;
    source.open(filename.c_str());
    string text;
    char format[] = "%[^:]: %d %d %d";
    char name[100];
    int a,b,c,sum;
    char g;
    while(getline(source,text))
    {
        sscanf(text.c_str(),format,name,&a,&b,&c);
        sum = a+b+c;
        g = score2grade(sum);
		names.push_back(name);
        scores.push_back(sum);
        grades.push_back(g);
    }
}

void getCommand(string &command,string &key)
{
    cout <<  "Please input your command: ";
    string input;
	getline(cin,input) ;
    int start = 0; 
    int end = input.find_first_of(" ");
    command = input.substr(start,end-start);
	key = input.substr(end+1);
	
}
void searchName(vector<string> &names,vector<int> &scores , vector<char> grades,string key)
{
bool check = 0;
cout <<"--------------------------------- "<<endl;
for(int i=0;i<(int)names.size();i++)
    {
        if(key==toUpperStr(names[i]))
		  {
			 check = 1;
			 cout << names[i] << "'s score = " << scores[i]<<endl;
			 cout << names[i] << "'s grade = "	<< grades[i]<<endl; 
		  }
	}
if(check==0)
		{
		    cout << "Cannot found."<< endl;
		}	 
cout <<"--------------------------------- "<<endl;
}

void searchGrade(vector<string> &names,vector<int> &scores , vector<char> grades,string key)
{
    bool check = 0;
	cout <<"--------------------------------- "<<endl;
	for(int i=0;i<(int)grades.size();i++)
     {
         
		if(key[0]==grades[i])
		{
			check =1;
			cout << names[i] << " ("<< scores[i] << ")"<<endl;	
		}	 
	  		
	}
	if(check==0)
		{
			 cout << "Cannot found."<< endl;
		}			
    cout <<"--------------------------------- "<<endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
