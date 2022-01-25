#include <iostream>
#include <ncurses.h>

void simpleText() {
    const std::string s = "Hello, World!";
	printw(s.c_str());	/* Print Hello World */
	refresh();			/* Print it on to the real screen */
    move(1, 0);         /* Moves the cursor */ 
	int i = getch();	/* Wait for user input */
	printw("%d", i);
    getch();

}

void simpleWindow() {

    int height = 10, width = 20, start_y = 0, start_x = 1;

    WINDOW * win = newwin(height, width, start_y, start_x); /* Creates a new window */
    refresh();
    box(win, 0, 0);                                         /* Draws a box around a window */
    mvwprintw(win, 1, 1, "This is a box!");                 /* Moves cursor relative to window, and prints */
    wrefresh(win);                                          /* Refreshs the window */
    getch();
}

void attributres() {

    

}


int main()
{	
    //Init curses
	initscr();			/* Start curses move */
    noecho();           /* Typed char don't show */
    cbreak();           /* ctrl+c will exit program (default) */
    //raw();            /* Special characters will be ignored */

    //Simple curses programs
    // simpleText();
    simpleWindow();

    //Clearn up after curses
    endwin();			/* End curses mode */
}


