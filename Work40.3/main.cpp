#include "logic.h"
#include "util.h"
#include <string>
 
int main() {
	srand(time(NULL));
	int human, group;
	do {
		cout << "Input quantity groups and humans in: ";
		cin >> group >> human;
	} while (group < 2 || human < 3);

	int** groups = new int* [group];

	for (int i = 0; i < group; i++)
	{
		groups[i] = new int[human];
	}

	rand_init(groups, human, group, 5, 0);
	system("cls");
	cout << show(groups, human, group) << endl;
	cout << output_result(groups, human, group) << endl;

	return 0;
}