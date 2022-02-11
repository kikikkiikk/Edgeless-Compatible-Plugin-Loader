#include<iostream>
#include<fstream>
#include<sys/types.h>
#include<direct.h>
#include<dirent.h>
#include<string.h>
#include<cstdio>
#include<vector>
#include<windows.h>
using namespace std;
int choose;
char* pathnow,*grep,*all_true_pluginname[512];
string pathnow_string,plugin_path,name_loading,grep_string;
dirent* all_pluginname[512];
FILE* true_pluginname_file;
ofstream tempfile("C:\\temp\\ECPLtemp");

int chooses(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	int year=1900+ltm->tm_year;
	cout<<"@Copyright "<<year<<" 谭麒峰 版权所有"<<endl<<"Edgeless Compatible Plugin Loader v0.1 Alpha"<<endl<<"由于内存限制，本程序只能加载512个插件（反正普通人也不用那么多）"<<endl<<"是否加载Plugin目录下的所有插件？（1=确认 2=取消）";
	cin>>choose;
	return choose;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
	choose = chooses();
	pathnow = getcwd(NULL,0);
	pathnow_string = pathnow;
	plugin_path = pathnow_string + "\\Plugin\\";
	const char* plugin = plugin_path.data();
	DIR *d=opendir(plugin);
	while(((all_pluginname[1] = readdir(d)) != NULL))
	{
        tempfile<<all_pluginname[1]->d_name<<endl;
	}
	tempfile.close();
	grep = pathnow;
	grep_string=grep;
	grep_string="cmd /c \"\""+grep_string;
	grep=(char*)grep_string.data();
	strcat(grep,"\\bin\\grep.exe\" .7z \"C:\\temp\\ECPLtemp\" >> C:\\temp\\ECPLtemp2\"");
	cout<<grep<<endl;
	WinExec(grep,SW_HIDE);
	ifstream tempin("C:\\temp\\ECPLtemp2");
	while(tempin.eof()==true){
		tempin>>name_loading;
		cout<<name_loading<<endl;
	}
	tempin.close();
	WinExec("cmd /c \"del C:\\temp\\ECPLtemp C:\\temp\\ECPLtemp2",SW_HIDE);
	return 0;
}
