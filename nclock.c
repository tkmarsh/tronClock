#include <stdio.h>
#include <time.h>
#include <ncurses.h>

int main(){
	int row, col;
	int year, month, day, hour, minute, second;
	int milli = 0; //not time accurate milliseconds
	initscr();
	curs_set(0);

	while(1){
	    	char buff[100];
		time_t now = time(0);
		getmaxyx(stdscr, row, col);
		struct tm now_t = *localtime(&now);
		strftime (buff, 100, "%d-%m-%Y %H:%M:%S", &now_t);

		year = now_t.tm_year - 100;
		month = now_t.tm_mon + 1;
		day = now_t.tm_mday;
		hour = now_t.tm_hour;
		minute = now_t.tm_min;
		second = now_t.tm_sec;
		
		if (milli == 99){
			milli=0;
		}
		else{
			milli+=1;
		}

	move(row/2,(col-20)/2);
	printw("%d:%02d:%02d:%02d:%02d:%02d:%d",year,month,day,hour,minute,second,milli);
	refresh();
 	usleep(10000);
	}
endwin();	
return 0;
}
