#include "util.h"

 
double find_gpa(int** groups, int human, int index) {
	double gpa = 0;


	for (int i = 0; i < human; i++)
	{
		gpa += groups[index][i];
	}

	gpa /= human;

	return gpa;
}
int find_group_min_gpa(int** groups, int human, int group) {
	int gpa_min = 0;

	for (int i = 1; i < group; i++)
	{
		double gpa1 = find_gpa(groups, human, gpa_min);
		double gpa2 = find_gpa(groups, human, i);


		if (gpa1 > gpa2) {
			gpa_min = i;
		}

	}


	return gpa_min;
}
int find_group_max_gpa(int** groups, int human, int group) {
	int gpa_max = 0;

	for (int i = 1; i < group; i++)
	{
		double gpa1 = find_gpa(groups, human, gpa_max);
		double gpa2 = find_gpa(groups, human, i);


		if (gpa1 < gpa2) {
			gpa_max = i;
		}

	}


	return gpa_max;
}

int cout_max_mark(int** groups, int human, int index) {
	int count = 0;
	for (int i = 0; i < human; i++)
	{
		if (groups[index][i] == 5) {
			count++;
		}
	}


	return count;
}
int find_group_max_mark(int** groups, int human, int group) {
	int max = 0;

	for (int i = 1; i < group; i++)
	{
		int count1 = cout_max_mark(groups, human, max);
		int count2 = cout_max_mark(groups, human, i);

		if (count1 < count2) {
			max = i;
		}

	}


	return max;
}

int cout_min_mark(int** groups, int human, int index) {
	int count = 0;
	for (int i = 0; i < human; i++)
	{
		if (groups[index][i] == 0 || groups[index][i] == 1 || groups[index][i] == 2) {
			count++;
		}
	}


	return count;
}
int find_group_min_mark(int** groups, int human, int group) {
	int min = 0;

	for (int i = 1; i < group; i++)
	{
		int count1 = cout_min_mark(groups, human, min);
		int count2 = cout_min_mark(groups, human, i);

		if (count1 < count2) {
			min = i;
		}

	}


	return min;
}

int ovr_average_performance(int** groups, int human, int group) {
	double gpa = 0;

	for (int i = 0; i < group; i++)
	{
		gpa += find_gpa(groups, human, i);
	}
	gpa /= group;

	return gpa;
}
void increase_per_ball(int** groups, int human, int index) {

	for (int i = 0; i < human; i++)
	{
		groups[index][i]++;
	}


}

void find_groups_best_av_per(int** groups, int human, int group) {
	int av_per = ovr_average_performance(groups, human, group);

	for (int i = 0; i < group; i++)
	{
		double gpa1 = find_gpa(groups, human, i);
		if (gpa1 > av_per) {
			increase_per_ball(groups, human, i);
		}
	}
}

void swap_index(int** groups, int human, int index) {


	for (int i = 0; i < human; i++)
	{
		int t = groups[index][i];
		groups[index][i] = groups[index + 1][i];
		groups[index + 1][i] = t;
	}

}

void sorting_d(int** groups, int human, int group) {
	for (int z = 0; z < group; z++)
	{
		for (int i = 0; i < group - 1; i++)
		{
			for (int j = 0; j < human; j++)
			{
				if (find_gpa(groups, human, i) < find_gpa(groups, human, i + 1)) {
					swap_index(groups, human, i);
				}
			}

		}
	}




}


string output_result(int** groups, int human, int group) {
	string msg = "";

	msg += "Groups with minand max GPA:\n";
	msg += "Min: " + to_string(find_group_min_gpa(groups, human, group)) + "\n";
	msg += "Max: " + to_string(find_group_max_gpa(groups, human, group)) + "\n";

	msg += "Groups with max count best marks: " + to_string(find_group_max_mark(groups, human, group)) + "\n";
	msg += "Groups with max count bad marks: " + to_string(find_group_min_mark(groups, human, group)) + "\n\n";
	find_groups_best_av_per(groups, human, group);
	sorting_d(groups, human, group);
	msg += "Resuls tabl: \n" + show(groups, human, group);


	return msg;
}
