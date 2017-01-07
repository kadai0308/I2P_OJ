# include <stdio.h>
# include <stdlib.h>

void set_tile (int* space, int** tiles_area, int tiles_amount, int space_height, int space_width);

int main(int argc, char const *argv[])
{
  int width = 0, height = 0;
  int tiles_amount = 0;

  scanf("%d %d", &width, &height);

  int space[height][width];
  // initial space
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      space[i][j] = 0;
    }
  }

  scanf(" %d", &tiles_amount);

  int **tiles_area = malloc(sizeof(int)*tiles_amount*2);
  int count_loop = 0;

  for (int i = 0; i < tiles_amount; i++){
    
    int tile_width = 0, tile_height = 0;

    scanf("%d %d", &tile_width, &tile_height);

    int tile[2] = {tile_height, tile_width};
    int vector_amount = tile_width*tile_height;

    // tile area < space area
    if (vector_amount < height*width) {
      int judge = 1;
      
      for (int j = 0; j < count_loop; ++j) {
        if (tiles_area[j][0] == tile_width && tiles_area[j][1] == tile_height) {
          judge = 0;
        }
      }

      if (judge) {
        if (tile_width != tile_height) {
          int tile_re[2] = {tile_width, tile_height};
          tiles_area[i] = tile;
          tiles_area[i+1] = tile_re;
          ++i;
        } else {
          tiles_area[i] = tile;
        }
      }

      count_loop += 1;
    }
  }

  set_tile(&space[0][0], tiles_area, tiles_amount, height, width);

  return 0;
}

void set_tile (int* space, int** tiles_area, int tiles_amount,int space_height, int space_width) {
  for (int i = 0; i < space_height*space_width; ++i) {
    if (space[i] == 0) {
      
    }
  }
}



