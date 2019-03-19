#include<bits/stdc++.h>
using namespace std;

const string dotfile2_source="H:\\file_version_control\\dotfile.txt";
const string dotfolder_source="H:\\file_version_control\\dotfolder\\";

class file{
	private:
		string s1;
		ofstream fout;
		ifstream fin,fin2;
		
	public:
		string file_source,file_name;
		
						
		int check_existence()  //check if already exists in dotfile
		{
			fin.open(dotfile2_source.c_str(),ios::in);
			while(!fin.eof())
			{
				fin>>s1;
				if(s1==file_name)
					{
						fin.close();	
						return 1;
					}					
			}
			fin.close();
			return 0;
		}
		
		void add_to_dotfile()  //If not already present
		{
			fout.open(dotfile2_source.c_str(),ios::out|ios::app);
			fout<<file_name;
			fout<<" ";
			fout.close();			
		}
		
			
		int add_to_dotfolder(string ver="0")  
		{
			string s;
			s=dotfolder_source;
			s.append(file_name);
			fout.open(s.c_str(),ios::out);
			fin.open(file_source.c_str(),ios::in);
			fout<<ver;
			fout<<'\n';
			while(!fin.eof())
			{
				fin>>s;
				fout<<s<<" ";
			}
			fin.close();
			fout.close();
			
		}
		
		int check_content()      //compares the content of given file with a file of same name previously stored
		{
			
			int i;
			string old_source,s1,s2;
			old_source=dotfolder_source;
			old_source.append(file_name);
			fin.open(old_source.c_str(),ios::in);
			fin2.open(file_source.c_str(),ios::in);
			fin.seekg(1);
			while(!fin2.eof())
			{
				fin>>s1;
				fin2>>s2;
				if(s1!=s2)
					{
						fin.close();
						fin2.close();
						return 1;	
					}
			}
			fin.close();
			fin2.close();			
			return 0;			
		}
		
};

int main()
{
	file obj;
	string s1,ver;
	int c;
	ifstream fin;
	ofstream fout;
	
	cout<<"Enter file source : (Use \' \\\\ \' while writing location)  ";
	cin>>obj.file_source;
	obj.file_source.append("\\\\");
	cout<<"Enter file name : ";
	cin>>obj.file_name;
	
	obj.file_source.append(obj.file_name);
	
	c=obj.check_existence();
	
	if(c==1)  //if the file already exixts
	{
		cout<<"\nThe file already exists in dotfile.\n";
		c=obj.check_content();
		if(c==1)  //content is new
		{
			cout<<"\nThe file has new content.\n";
			
			string s;
			s=dotfolder_source;
			s.append(obj.file_name);
			fin.open(s.c_str(),ios::in);
			cout<<"Previous Version : ";
			fin>>s;
			cout<<s;
			
			cout<<"\n\nEnter new version number : ";
			cin>>ver;
			fin.seekg(0);
									
			char ch;
			cout<<"\nDo you want to access previous version of the file ?(Y/N) ";
			cin>>ch;
	
			if(ch=='Y'||ch=='y')
			{
				cout<<"\nHere is the content of the previous version of this file...\n";
				
				int size,i;
				fin.seekg(0,ios::end);
				size=fin.tellg();
		
				fin.seekg(1);
				for(i=0;i<size;i++)
				{
					s=fin.get();
					cout<<s;
				}
				fin.close();
			}
			
			obj.add_to_dotfolder(ver);
		}
		else  //content has not changed
		{
			cout<<"\nThe content of the file has not been changed.\n";
		}
	}
	else  //if it is a new file
	{
		cout<<"\nThe file has been added to dotfile.\n";
		
		obj.add_to_dotfile();
		obj.add_to_dotfolder();	
	}
	
	int e;
	cout<<"\n\nEnter any integer to exit.\n";
	cin>>e;
	
	return 0;
}
