#ifndef RS_RECORD_H
#define RS_RECORD_H

#include <string>
#include "difficulty.h"


void reload_records(std::string filename);
int get_record(Difficulty difficulty);
void put_record(int score, Difficulty difficulty);


#endif
