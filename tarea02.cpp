#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <cstring>


using namespace std;

string fecha_access;

/*void BuscarFecha(string line)
{
	string fecha_1= "16/Mar/2013";
	string fecha_2= "16/Mar/2015";

	istringstream s(line);

	while(s >> token) {
	    cout << token << endl;
	}

	cout << endl << "Separar buscar la fecha en la linea" << endl << endl;

	int pos = line.find(fecha_1);

	if (pos != -1)
		cout << "EUREKA!";
	else
		cout << "PFFF";
}*/

void fecha_linea(string line, string fechainicio, string fechahasta)
{
	char *linea = (char*)line.c_str();
	char *ptr;

	ptr = strtok(linea, " ");
	int c=0;
	string tokens[100];
	string fecha_access = "";

	cout << endl << endl;

	while (ptr != NULL)
	{
		tokens[c] = ptr;
		ptr = strtok(NULL, " ");
		c++;
	}

	for (int i=1; i<12; i++)
		fecha_access = fecha_access + tokens[3][i];
	///////////////////////////////////////////////

	

}

void limpia_fecha(string fechainicio, string fechahasta)
{
	string a="", a1="", m="", m1="", d="", d1="";
	int mes;

	a = a + fechainicio[0]+ fechainicio[1]+ fechainicio[2]+ fechainicio[3];
	a1 = a1 + fechahasta[0]+ fechahasta[1]+ fechahasta[2]+ fechahasta[3];

	m = m + fechainicio[5] + fechainicio[6];
	m1 = m1 + fechahasta[5] + fechahasta[6];

	d = d + fechainicio[8] + fechainicio[9];
	d1 = d1 + fechahasta[8] + fechahasta[9];

	if(m == "01") {
		m = "/Jan/";
		m1 = "/Jan/";
	}
	else if(m == "02") {
		m = "/Feb/";
		m1 = "/Feb/";
	}
	else if(m == "03") {
		m = "/Mar/";
		m1 = "/Mar/";
	}
	else if(m == "04") {
		m = "/Apr/";
		m1 = "/Apr/";
	}

	fechainicio = a + m + d;
	fechahasta = a1 + m1 + d1;


	ifstream file("access.log");
   	string aux;
   	int i=0;

   	if(file.is_open())
   	{
   		string line;
   		while(true)
   		{
   			while(getline(file, line) && i != 20)
   			{
   				cout << line << "\n";
	   			fecha_linea(line, fechainicio, fechahasta);
	   			getchar();
	   			i++;
   			}

   			if (!file.eof()) break;
   			file.clear();

   			getchar();
   		}
   	}
}

int main(int argc, char *argv[]) {

   if (argc == 4)
    {
        if (strcmp(argv[1], "-so") == 0)
            limpia_fecha(argv[2], argv[3]);
    }
    else
    {
        cout << "ERROR...FUNCION NO ENCONTRADA" << endl;
    }
   

   return 0;
}
