/*
 * For handling records
 */
#include <string>
#include "difficulty.h"


static int RECORD[3] = {1, 1, 1};

void reload_records(std::string fileName){
	
}


int get_record(Difficulty difficulty){
	int index = (int) difficulty - 1;
	return RECORD[index];
}


void put_record(int score, Difficulty difficulty){
	int index = (int) difficulty - 1;
	if(score > RECORD[index]) RECORD[index] = score;
}

