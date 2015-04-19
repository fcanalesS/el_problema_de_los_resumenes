#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

void opcion_1(string comando)
{
	char *py = new char[comando.length() + 1];
	strcpy(py, comando.c_str());
	system(py);


	delete [] py;
}

int main(int argc, char const *argv[])
{
	//2015/01/27 2015/11/16 python fichero.py

	

	if (argc == 4)
	{
		if (strcmp(argv[1], "-so") == 0)
		{
			string com = "python fichero.py";
			string desde = string(argv[2]);
			string hasta = string(argv[3]);

			string comando = com + " " + desde + " " + hasta;

            opcion_1(comando);
		}
	}


	
	return 0;
}