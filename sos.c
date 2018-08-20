#include <iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
/* Aman Raj 170101006  */

typedef struct _file
{
	struct _file *nextFile;
	char name[];

}file ;

typedef struct _folder
{
	struct _node *nextFolder;
	struct _node *parentFolder;
	struct _file *file;
	char name[];

}folder ;

createFile(){

}


int main()
{
	folder *root;
	root->name="root";
	root->parentFolder=NULL;

	string s,name;
	cin>>s;
	while(s!="-1")
	{
		if(s[0]=='B'){
			back();
		}else if(s[0]=='N'){
			cin>>name;
			createFolder(name);
		}else if(s[0]=='C'){
			cin>>name;
			createFile(name);
		}else {
			deleteFile();
		}

		cin>>s;
	}
}