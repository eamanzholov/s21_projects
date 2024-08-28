#include "brick_game_frontend.h"

UserAction_t get_signal(int user_input) {
  UserAction_t rc = -1;

  if (user_input == KEY_UP) rc = Up;
  if (user_input == KEY_DOWN)
    rc = Down;
  else if (user_input == KEY_LEFT)
    rc = Left;
  else if (user_input == KEY_RIGHT)
    rc = Right;
  else if (user_input == ESCAPE)
    rc = Terminate;
  else if (user_input == ENTER_KEY)
    rc = Action;
  else if (user_input == KEY_BACKSPACE)
    rc = Pause;

  return rc;
}

void print_overlay(void) {
  print_rectangle(0, 21, 0, 21);
  print_rectangle(2, 7, 24, 34);
  attron(COLOR_PAIR(2));
  mvprintw(1, 24, "NEXT");
  mvprintw(9, 24, "LEVEL - ");
  mvprintw(11, 24, "SPEED - ");
  mvprintw(13, 24, "SCORE - ");
  mvprintw(15, 24, "HIGH SCORE - ");

  mvprintw(17, 24, "ESC - exit");
  mvprintw(18, 24, "BACKSPACE - pause");
  mvprintw(19, 24, "arrows - move");
  mvprintw(20, 24, "key up - rotate");

  mvprintw(10, 1, "Press ENTER to START");
  attroff(COLOR_PAIR(2));
}
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x) {
  for (int y = top_y; y < bottom_y + 1; y++) {
    mvprintw(y, left_x, ".");
    mvprintw(y, right_x, ".");
  }

  for (int x = left_x; x < right_x + 1; x += 2) {
    mvaddch(top_y, x, '.');
  }
  for (int x = left_x; x < right_x + 1; x += 2) {
    mvaddch(bottom_y, x, '.');
  }
}
void print_stats(GameInfo_t *stats) {
  mvprintw(9, 32, "%d", stats->level);
  mvprintw(11, 32, "%d", stats->speed);
  mvprintw(13, 32, "%d", stats->score);
  mvprintw(15, 37, "%d", stats->high_score);
}

void print_board(GameInfo_t *board, int level) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 20; y++) {
      if (board->field[x][y] == 1) {
        attron(COLOR_PAIR(level));
        mvaddch(y + TOP_Y + 1, x * 2 + (LEFT_X + 1), '[');
        mvaddch(y + TOP_Y + 1, x * 2 + 1 + (LEFT_X + 1), ']');
        attroff(COLOR_PAIR(level));
      } else {
        mvaddch(y + TOP_Y + 1, x * 2 + (LEFT_X + 1), ' ');
        mvaddch(y + TOP_Y + 1, x * 2 + 1 + (LEFT_X + 1), ' ');
      }
    }
  }
}
void print_banner(GameInfo_t *stats) {
  attron(COLOR_PAIR(5));
  mvprintw(6, 4, "            ");
  mvprintw(7, 4, "  GAMEOVER  ");
  mvprintw(8, 4, "            ");
  mvprintw(9, 4, "  Level: %d  ", stats->level);
  mvprintw(10, 4, "              ");
  mvprintw(11, 3, "  Score: %d  ", stats->score);
  mvprintw(12, 3, "                 ");
  mvprintw(13, 2, "  High Score: %d  ", stats->high_score);
  mvprintw(14, 2, "                      ");
  mvprintw(15, 1, "  Press ESC to Quit  ");
  mvprintw(16, 1, "                     ");
  attroff(COLOR_PAIR(5));
}
void print_next_section(GameInfo_t *stats) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (stats->next[j][i] == 1) {
        attron(COLOR_PAIR(4));
        mvprintw(NEXT_TOP_Y + j + 2, NEXT_LEFT_X + 1 + i * 2, "[]");
        attroff(COLOR_PAIR(4));
      } else {
        mvprintw(NEXT_TOP_Y + j + 2, NEXT_LEFT_X + 1 + i * 2, "  ");
      }
    }
  }
}

void print_pause() { mvprintw(10, 4, " GAME PAUSED "); }

GameInfo_t updateCurrentState() {
  GameInfo_t *gameInfo = change_GameInfo_t(NULL);
  if (gameInfo->pause == 1) {
    print_pause(gameInfo);
  } else {
    print_board(gameInfo, gameInfo->level);
    print_next_section(gameInfo);
    print_stats(gameInfo);
  }
  return *gameInfo;
}

GameInfo_t *change_GameInfo_t(GameInfo_t *gameInfo) {
  static GameInfo_t *Info;
  if (gameInfo == NULL) return Info;
  Info = gameInfo;
  return Info;
}
