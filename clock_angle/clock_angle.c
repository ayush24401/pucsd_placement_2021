//clock angle

#include <stdio.h>
#include <stdlib.h>

float clock_angle(int hour, int min){
	
	if(hour<0 || hour>12 || min<0 || min>60){	
		printf("Invalid Input\n");
		return -1;
	}
	//how much hour hand has moved from 0 degree
	float hr=hour*30 + min*0.5; //since in 1 min hour hand moves 0.5 degree
	float mn=min*6;

	float result=abs(hr-mn);
	if (result>180){
		result=(360-result);
	}

	return abs(result);
}


void main(int argc, char *argv[]){
	int hour=atoi(argv[1]);
	int min=atoi(argv[2]);
	float angle = clock_angle(hour,min);
	printf("%.2f\n",angle);
}

