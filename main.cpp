#include <stdlib.h>

#include <stdio.h>

#include <getopt.h>

#include <string>

#include <iostream>



using namespace std;



int main (int argc, char *argv[]){



	const char* short_opt = "havn::";



	const struct option long_opt[] = {

		{"help",no_argument,NULL,'h'},

		{"author",no_argument,NULL,'a'},

		{"version",no_argument,NULL,'v'},

		{"number",optional_argument,NULL,'n'},

		{NULL,0,NULL,0}

	};

	

	int opt_ind;

	int rez = getopt_long(argc, argv, short_opt, long_opt, &opt_ind);

	int amount_of_h = 0;

	int amount_of_a = 0;

	int amount_of_v = 0;

	string author = "Denis Kryvoshey";

	float version = 2.15;



	while (rez!=-1){

		switch(rez){

			case 'h': {

				if (not amount_of_h) {

					puts("Arguments:\n"

					"-h, --help - print help\n"

					"-a, --author - print author\n"

					"-v, --version - print version\n");

					amount_of_h++;

				};

				break;

			};



			case 'a': {

				if (not amount_of_a) {	  

					cout << "Author: " << author << endl;

					amount_of_a++;

				};

				break;

			};



			case 'v': {

				if (not amount_of_v) {

					printf("Version: %.2f \n", version);

					amount_of_v++;

				};

				break;

			};



			case '?': {


				break;

			};



			default: {	

				break;

			};

		};

		rez = getopt_long(argc, argv, short_opt, long_opt, &opt_ind);

	};



	if (amount_of_h) {

		printf("Argument: Help \n");

	};



	if (amount_of_a) {

		printf("Argument: Author \n");

	};

	

	if (amount_of_v) {

		printf("Argument: Version \n");

	};


	return 0;

};