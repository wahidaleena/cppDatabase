#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <mysql.h>
#include <stdlib>

using namespace std;

struct Data
{
    string i_num;
    string m_stat;
    string s_loc;
};

int main () {
  
	ifstream myfile;
	struct Data d[100];
	char DB_NAME[1000],USER[1000],PASS[1000],FILEN[1000];
	
	strcpy(DB_NAME, getenv('DBNAME'));
	strcpy(USER, getenv('USERNAME'));
	strcpy(PASS, getenv('PASSWORD'));
	strcpy(FILENAME, getenv('FILENAME'));

	myfile.open (FILENAME);
	int i=0;
	
	while (myfile)
	{
		getline(myfile, d[i].i_num, ',');
		getline(myfile, d[i].m_stat, ',');
		getline(myfile, d[i++].s_loc, '\n');
	}

	MYSQL *mysql;
	mysql = mysql_init(NULL);
	mysql_real_connect(mysql, "localhost", USER, PASS, DB_NAME, 0, 0, 0);

	int j = 0;
	while (j<i)
	{
		string i_num = d[j].i_num;
		string stat = d[j].m_stat;
		mysql_query(mysql1, "UPDATE DB_NAME SET movement_status = stat WHERE item_nbr = i_num");
		j++;
	}
	
	myfile.close();
	return 0;
}