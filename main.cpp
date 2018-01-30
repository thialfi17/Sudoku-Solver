
#include <iostream>
#include <math.h>
using namespace std;

typedef enum { ROW, COLUMN, BLOCK } GroupType;

const int BOARD_SIZE = 9;
const int BLOCK_SIZE = sqrt(BOARD_SIZE);

void read_board(int (&board)[BOARD_SIZE*BOARD_SIZE]);
void load_group(GroupType t, int group, int* current_numbers[BOARD_SIZE], int (&board)[BOARD_SIZE*BOARD_SIZE]);

int main() 
{
  int board[BOARD_SIZE * BOARD_SIZE];
  int * current_numbers[BOARD_SIZE];
  read_board(board); 
  
  load_group(BLOCK, 2, current_numbers, board);
  
  cout << *current_numbers[2] << endl;
  cout << board[0] << board[10] << board[80] << endl;
  
}

void load_group(GroupType t, int group, int* current_numbers[BOARD_SIZE], int (&board)[BOARD_SIZE*BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (t == ROW) {
			current_numbers[i] = &board[i + group*BOARD_SIZE];
		}
		else if (t == COLUMN) {
			current_numbers[i] = &board[group + i * BOARD_SIZE];
		}
		else if (t == BLOCK) {
			current_numbers[i] = &board[group * BLOCK_SIZE + (i / BLOCK_SIZE * BOARD_SIZE + i % BLOCK_SIZE)];
		}
	}
}

void read_board(int (&board)[BOARD_SIZE*BOARD_SIZE])
{
  FILE * f = fopen("puzzle.txt", "r");
 
  int count = 0;
  while ( !feof(f) ) {
    char c = getc(f);
    
    if ( c > 47 && c < 58 ) {
     board[count++] = c - 48; 
    }
    if (count >= BOARD_SIZE * BOARD_SIZE) {
      break;
    }
  }
  fclose(f);
}
