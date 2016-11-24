#include <iostream>
#include "Miner.h"

using namespace std;

void PrintHelp(int);

int main(int argc, char const *argv[])
{
	if(argc == 1){
		PrintHelp(1);
		return 0;	
	}
	else {
		PrintHelp(0);
	}

	Miner tom; // Our humble miner tom ;)

	tom.GetFileData(argv[1]);
	tom.ParseFileSections(argv[1]);
	char * File = tom.LoadPE(argv[1]);
	tom.StartMiner(File);
	tom.Result();

	string Clean = "rm ";
	Clean += argv[1];
	Clean += ".bak";
	system(&Clean[0]);
	return 0;
}




void PrintHelp(int mode){
	cout << BOLDGREEN << "                    ___       \n"
					 "                 .-' \\\\\".     \n"
					 "                /`    ;--:    \n"
					 "               |     (  (_)== \n"
					 "               |_ ._ '.__.;   \n"
					 "               \\_/`--_---_|   \n"
					 "                (`--(./-\\.)   \n"
					 "                `|     _\\ |   \n"
					 "                 | \\  __ /    \n"
					 "                /|  '.__/     \n"
					 "             .'` \\     |_     \n"
					 "                   '-__ / `-    \n" << RESET;


	cout << BOLDRED << "   _____           _           \n"
					   "  / ____|         (_)                \n"
					   " | |     _ __ ___  _ _ __   ___ _ __ \n"
					   " | |    | '_ ` _ \\| | '_ \\ / _ \\ '__|\n"
					   " | |____| | | | | | | | | |  __/ |   \n"
					   "  \\_____|_| |_| |_|_|_| |_|\\___|_|   \n\n" << RESET;

	cout << BOLDBLUE << "Github: github.com/EgeBalci/Cminer\n" << RESET;
	if(mode == 1) {
		cout << BOLDGREEN << "\nUsage: Cminer <file>\n\n" << RESET;
		cout << GREEN << "Cminer is a tool for enumerating code caves inside PE files.\n"
	  				 	 "(All code caves under the size of 300 bytes will be ignored)\n" << RESET;
	}


}