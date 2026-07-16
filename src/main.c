#include <stdbool.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void randhashpos(int *x, int *y, int max_y, int max_x) {
    srand(time(NULL));
    *y = rand() % max_y + 1;
    *x = rand() % max_x + 1;
}

int randomsymbol() {
    char symbols[] = "#+-_/.;:<>|{}()[]=&$!~,'@";
    srand(time(NULL));
    int pos = rand() % sizeof(symbols) + 1;

    return symbols[pos];
}

int display(int max_y, int max_x) {
    curs_set(0);
    int y, x;

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
    init_pair(7, COLOR_YELLOW, COLOR_BLACK);
    int pair = 1;
    
    while (1) {
        randhashpos(&x, &y, max_y, max_x);
        attron(COLOR_PAIR(pair));
        mvprintw(y, x, "%c", randomsymbol());
        attroff(COLOR_PAIR(pair));
        pair++;
        usleep(500000);
        if (pair >= 8) {
            pair = 1;
        } else {
            pair = pair;
        }

        refresh();
    }

    return 1;
}

int main(int argc, const char *argv[]) {
    initscr();
    noecho();

    if (has_colors() == false) {
        endwin();
        printf("Your terminal does not support colors.\n");
        return 1;
    }

    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    int y, x;
    int ch;

    nodelay(stdscr, TRUE);

    while (display(max_y, max_x)) {
	
        ch = getch();

        if (ch == 27 || ch == 'q') { // this doesnt work for some reason, just press ctrl+c
            break;
        } else { continue; }
    }

    endwin();
    return 0;
}
