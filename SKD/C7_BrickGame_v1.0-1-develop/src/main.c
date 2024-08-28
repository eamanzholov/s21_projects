#include "./brick_game/tetris/tetris.h"
#include "./gui/cli/brick_game_frontend.h"

void tetris_game();
void init_colors() {
  if (has_colors()) {
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_pair(7, COLOR_RED, COLOR_BLACK);
    init_pair(8, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(9, COLOR_WHITE, COLOR_BLACK);
    init_pair(10, COLOR_BLUE, COLOR_BLACK);
  }
}

/*!

    \brief Точка входа в игровую консоль
*/
int main() {
  initscr();
  noecho();
  curs_set(0);
  init_colors();
  keypad(stdscr, TRUE);
  timeout(40);
  srand((unsigned int)time(NULL));

  print_overlay();
  while (1) {
    UserAction_t sig = get_signal(getch());
    if (sig == Action) {
      break;
    }
  }
  tetris_game();

  endwin();
  return 0;
}

/*!

    \brief Вход в игру Тетрис
*/
void tetris_game() {
  GameInfo_t gameInfo;
  infoInit(&gameInfo);
  change_GameInfo_t(&gameInfo);
  int state = -1;
  UserAction_t sig = -1;
  game_loop(NULL, sig);

  while (state != EXIT_STATE && state != GAMEOVER) {
    if (state == START || state == MOVING || state == PAUSE) {
      sig = get_signal(getch());
    }

    state = game_loop(&gameInfo, sig);
    updateCurrentState();
  }
  if (state == GAMEOVER) {
    print_banner(&gameInfo);
    while (1) {
      sig = get_signal(getch());
      if (sig == Terminate) {
        break;
      }
    }
  }

  infoFree(&gameInfo);
}