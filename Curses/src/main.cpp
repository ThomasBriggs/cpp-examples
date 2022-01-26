#include <iostream>
#include <ncurses.h>

void simpleText() {
    const std::string s = "Hello, World!";
    printw(s.c_str());	/* Print Hello World */
    refresh();			/* Print it on to the real screen */
    move(1, 0);         /* Moves the cursor */
    int i = getch();	/* Wait for user input */
    printw("%d", i);

}

void simpleWindow() {

    int height = 10, width = 20, start_y = 0, start_x = 1;

    WINDOW* win = newwin(height, width, start_y, start_x); /* Creates a new window */
    refresh();
    box(win, 0, 0);                                         /* Draws a box around a window */
    mvwprintw(win, 1, 1, "This is a box!");                 /* Moves cursor relative to window, and prints */
    wrefresh(win);                                          /* Refreshs the window */
}

void attributres() {

    /* List of available attributes
     * A_NORMAL
     * A_STANDOUT
     * A_REVERSE
     * A_BLINK
     * A_DIM
     * A_BOLD
     * A_PROTECT
     * A_INVIS
     * A_ALTCHARSET
     * A_CHARTEXT
     */

    clear();
    printw("STANDARD");

    int y, x;

    attron(A_STANDOUT);
    getyx(stdscr, y, x);
    mvprintw(y+1, 0, "STANDOUT");
    attroff(A_STANDOUT);

    attron(A_BLINK);
    getyx(stdscr, y, x);
    mvprintw(y+1, 0, "BLINK");
    attroff(A_BLINK);

    attron(A_DIM);
    getyx(stdscr, y, x);
    mvprintw(y+1, 0, "DIM");
    attroff(A_DIM);


    attron(A_BOLD);
    getyx(stdscr, y, x);
    mvprintw(y+1, 0, "BOLD");
    attroff(A_BOLD);


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
    // simpleWindow();
    attributres();

    //Clearn up after curses
    getch();
    endwin();			/* End curses mode */
}


