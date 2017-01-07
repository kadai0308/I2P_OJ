# include <stdio.h>
# include <stdlib.h>
int height = 0, width = 0;
int space[10][10] = {0};
int tiles[10][2] = {0};

int set_tiles (int row, int col, int tiles_amount);

int main(int argc, char const *argv[])
{
  int tiles_amount = 0;
  scanf("%d %d", &height, &width);

  // make wall
  for (int i = 0; i <= height; ++i) {
    space[i][width] = 9;
  }
  for (int i = 0; i <= width; ++i) {
    space[height][i] = 9;
  }

  // initial space
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      space[i][j] = 0;
    }
  }

  scanf(" %d", &tiles_amount);

  // input tiles
  int true_amount = 0;
  for (int i = 0; i < tiles_amount; ++i) {
    int row = 0, col = 0;
    scanf(" %d %d", &row, &col);
    if (row <= height && col <= width) {
      tiles[true_amount][0] = row;
      tiles[true_amount][1] = col;
      ++true_amount;
    }
  }
  tiles_amount = true_amount;


  // check and add the reverse tile
  int j = tiles_amount;
  for (int i = 0; i < tiles_amount; ++i) {
    if (tiles[i][0] != tiles[i][1]) {
      int judge = 1;

      // check whether the reverse tile already in tiles or not
      for (int k = 0; k < tiles_amount; ++k) {
        if (tiles[k][0] == tiles[i][1] && tiles[k][1] == tiles[i][0]) judge = 0;
      }

      if (judge) {
        tiles[j][0] = tiles[i][1];
        tiles[j][1] = tiles[i][0];
        ++j;
      }
    }
  }
  tiles_amount = j;

  // test
  // for (int i = 0; i < tiles_amount; ++i) {
  //   printf("tile: %d %d\n", tiles[i][0], tiles[i][1]);
  // }

  int answer = 0;
  answer = set_tiles (0, 0, tiles_amount);


  printf("%d\n", answer);
  return 0;
}

int set_tiles (int row, int col, int tiles_amount) {
  if (row >= height)
    return 1;
  if (col >= width)
    return set_tiles(row+1, 0, tiles_amount);
  if (space[row][col] != 0)
    return set_tiles(row, col+1, tiles_amount);

  int answer = 0;
  for (int k = 0; k < tiles_amount; ++k) {
    int is_filled = 0;
    for (int i = 0; i < tiles[k][0]; ++i) {
      for (int j = 0; j < tiles[k][1]; ++j) {
        if (space[row+i][col+j] != 0)
          is_filled++;
      }
    }
    if (is_filled != 0) continue;

    // filling
    for (int i = 0; i < tiles[k][0]; ++i) {
      for (int j = 0; j < tiles[k][1]; ++j) {
        space[row+i][col+j] = 1;
      }
    }

    answer += set_tiles(row, col+1, tiles_amount);

    // resume
    for (int i = 0; i < tiles[k][0]; ++i) {
      for (int j = 0; j < tiles[k][1]; ++j) {
        space[row+i][col+j] = 0;
      }
    }
  }
  return answer;
}



  