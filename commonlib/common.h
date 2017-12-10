// common.h
//
// header file for common.c


#ifndef COMMON_H
#define COMMON_H

void die(char *msg);
void info_die(char *msg); 
int addCommas_ul(char  *commaNumStr, unsigned long ulNum);
int maxIntAr(int *ar, int numElements);
int minIntAr(int *ar, int numElements);
int checkDupeIntAr(int *ar, int numElements, int *dupeNum);

#endif
