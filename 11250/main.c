# include <stdio.h>
# include <stdlib.h>

int result = 100000000;
void find_path (char** map, int height, int width, int now_row, int now_col, int end_row, int end_col, int steps);

int main(int argc, char const *argv[])
{
  int row = 0, col = 0;

  scanf (" %d %d", &row, &col);

  int start_row = 0, start_col = 0;
  int end_row = 0, end_col = 0;
  char **map;
  map = (char **) malloc (sizeof (char *) * row);
  for (int i = 0; i < row; i++) {
    map [i] = (char *) malloc (sizeof (char) * col);
  }

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < col; ++j) {
      char input;
      scanf(" %c", &input);
      map[i][j] = input;
      if (input == 'S') {
        start_row = i;
        start_col = j;
      } else if (input == 'T') {
        end_row = i;
        end_col = j;
      }
    }
  }

  find_path(map, row, col, start_row, start_col, end_row, end_col, 0);

  if (result == 100000000) {
    result = 0;
  }
  printf("%d\n", result);

  return 0;
}

void find_path (char** map, int height, int width, int now_row, int now_col, int end_row, int end_col, int steps) {
  if (now_row == end_row && now_col == end_col) {
    if (steps < result) result = steps;
  } else {

    if (now_row+1 < height) {
      if (map[now_row+1][now_col] != '*' && map[now_row+1][now_col] != '!') {
        
        char **next_map;
        next_map = (char **) malloc (sizeof (char *) * height);
        for (int i = 0; i < height; i++) {
          next_map [i] = (char *) malloc (sizeof (char) * width);
        }        

        for (int i = 0; i < height; ++i) {
          for (int j = 0; j < width; ++j) {
            next_map[i][j] = map[i][j];
          }
        }

        next_map[now_row][now_col] = '!';

        find_path(next_map, height, width, now_row+1, now_col, end_row, end_col, steps+1);
      }
    }

    if (now_row-1 >= 0) {
      if (map[now_row-1][now_col] != '*' && map[now_row-1][now_col] != '!') {
        
        char **next_map;
        next_map = (char **) malloc (sizeof (char *) * height);
        for (int i = 0; i < height; i++) {
          next_map [i] = (char *) malloc (sizeof (char) * width);
        }        

        for (int i = 0; i < height; ++i) {
          for (int j = 0; j < width; ++j) {
            next_map[i][j] = map[i][j];
          }
        }

        next_map[now_row][now_col] = '!';

        find_path(next_map, height, width, now_row-1, now_col, end_row, end_col, steps+1);
      }
    }

    if (now_col+1 < width) {
      if (map[now_row][now_col+1] != '*' && map[now_row][now_col+1] != '!') {
        
        char **next_map;
        next_map = (char **) malloc (sizeof (char *) * height);
        for (int i = 0; i < height; i++) {
          next_map [i] = (char *) malloc (sizeof (char) * width);
        }        

        for (int i = 0; i < height; ++i) {
          for (int j = 0; j < width; ++j) {
            next_map[i][j] = map[i][j];
          }
        }

        next_map[now_row][now_col] = '!';

        find_path(next_map, height, width, now_row, now_col+1, end_row, end_col, steps+1);
      }
    }

    if (now_col-1 >= 0) {
      if (map[now_row][now_col-1] != '*' && map[now_row][now_col-1] != '!') {
        
        char **next_map;
        next_map = (char **) malloc (sizeof (char *) * height);
        for (int i = 0; i < height; i++) {
          next_map [i] = (char *) malloc (sizeof (char) * width);
        }        

        for (int i = 0; i < height; ++i) {
          for (int j = 0; j < width; ++j) {
            next_map[i][j] = map[i][j];
          }
        }

        next_map[now_row][now_col] = '!';

        find_path(next_map, height, width, now_row, now_col-1, end_row, end_col, steps+1);
      }
    }
  }
}