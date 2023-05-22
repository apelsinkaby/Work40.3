#include "main.h"
#include <string>
 


void rand_init(int** groups, int human, int group, int max, int min) {

	for (int j = 0; j < group; j++) {
		for (int i = 0; i < human; i++) {
			groups[j][i] = rand() % (max - min + 1) + min;
		}
	}


}

string show(int** groups, int human, int group) {
	string msg = "Marks: \n";
	for (int i = 0; i < group; i++)
	{
		for (int j = 0; j < human; j++)
		{
			msg += to_string(groups[i][j]) + " ";
		}
		msg += "\n";
	}
	return msg;
}