#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define dim 20

char (*array)[dim];
char (*flag_array)[dim];

int readInput();
void readLiveCellPosition();
char readLiveCellKey();
void init();
void print();
void fill();
void simulation(int);
void gameOfLife();
int numberOfLiveNeighbours(int, int);
int numberOfNeighboursMiddle(int, int);
int numberOfNeighboursTop(int);
int numberOfNeighboursBottom(int);
int numberOfNeighboursLeft(int);
int numberOfNeighboursRight(int);
void killCell(int, int);
bool isDeadCell(int, int);
bool isLiveCell(int, int);
void rebirthCell(int, int);
int test();
int test2();
int test3();
int test4();

int main()
{

   init();
   fill();
   //int generations = readInput();
   int generations = test4();
   printf("\nSpiel des Lebens für %d Generationen:", generations);
   printf("\n--------------------------------\n\n");
   simulation(generations);

   return 1;
}
int test()
{
   array[9][9] = '#';
   array[10][9] = '#';
   array[11][9] = '#';
   return 3;
}

int test2()
{
   array[8][8] = '#';
   array[9][8] = '#';
   array[10][8] = '#';
   array[11][8] = '#';
   array[8][9] = '#';
   array[11][9] = '#';
   array[8][10] = '#';
   array[11][10] = '#';
   array[8][11] = '#';
   array[9][11] = '#';
   array[10][11] = '#';
   array[11][11] = '#';

   return 3;
}

int test3()
{
   array[5][5] = '#';
   array[6][5] = '#';
   array[7][5] = '#';
   array[8][5] = '#';
   array[9][5] = '#';
   array[10][5] = '#';
   array[11][5] = '#';
   array[12][5] = '#';
   array[13][5] = '#';
   array[14][5] = '#';
   array[5][6] = '#';
   array[14][6] = '#';
   array[5][7] = '#';
   array[14][7] = '#';
   array[5][8] = '#';
   array[14][8] = '#';
   array[5][9] = '#';
   array[14][9] = '#';
   array[5][10] = '#';
   array[14][10] = '#';
   array[5][11] = '#';
   array[14][11] = '#';
   array[5][12] = '#';
   array[14][12] = '#';
   array[5][13] = '#';
   array[14][13] = '#';
   array[5][14] = '#';
   array[6][14] = '#';
   array[7][14] = '#';
   array[8][14] = '#';
   array[9][14] = '#';
   array[10][14] = '#';
   array[11][14] = '#';
   array[12][14] = '#';
   array[13][14] = '#';
   array[14][14] = '#';

   return 10;
}

int test4()
{
   array[7][6] = '#';
   array[12][6] = '#';
   array[6][7] = '#';
   array[7][7] = '#';
   array[9][7] = '#';
   array[10][7] = '#';
   array[12][7] = '#';
   array[13][7] = '#';
   array[9][8] = '#';
   array[10][8] = '#';
   array[7][9] = '#';
   array[8][9] = '#';
   array[9][9] = '#';
   array[10][9] = '#';
   array[11][9] = '#';
   array[12][9] = '#';
   array[7][10] = '#';
   array[8][10] = '#';
   array[9][10] = '#';
   array[10][10] = '#';
   array[11][10] = '#';
   array[12][10] = '#';
   array[9][11] = '#';
   array[10][11] = '#';
   array[6][12] = '#';
   array[7][12] = '#';
   array[9][12] = '#';
   array[10][12] = '#';
   array[12][12] = '#';
   array[13][12] = '#';
   array[7][13] = '#';
   array[12][13] = '#';

   return 18;
}

/**
 * @brief allocate memory für das 2d arary anhand dim
 */
void init()
{
   array = malloc(sizeof(char[dim][dim]));
   flag_array = malloc(sizeof(char[dim][dim]));
}
void fill()
{
   for (int i = 0; i < dim; i++)
   {
      for (int j = 0; j < dim; j++)
      {
         array[i][j] = '.';
         flag_array[i][j] = '*';
      }
   }
}
void print()
{
   for (int i = 0; i < dim; i++)
   {
      for (int j = 0; j < dim; j++)
      {
         printf("%c", array[i][j]);
      }
      printf("\n");
   }
}
void simulation(int generation)
{
   for (int i = 0; i <= generation; i++)
   {
      printf("Generation %d:\n", i);
      print();
      gameOfLife();
      printf("\n");
   }
}

/**
 * @brief einlesen von benutzer eingaben für anzahl der Generationen
 * und die Indexen von lebenden Zellen
 *
 * @return int anzahl Generationen
 */
int readInput()
{
   int generation;
   scanf("%d", &generation);

   while (true)
   {
      char key = readLiveCellKey();
      if (key == 'e')
      {
         break;
      }
      readLiveCellPosition();
   }
   return generation;
}
void readLiveCellPosition()
{
   int i, j;
   scanf("%d %d", &j, &i);
   array[i][j] = '#';
}
char readLiveCellKey()
{
   char key;
   scanf(" %c", &key);
   return key;
}
void gameOfLife()
{
   for (int i = 0; i < dim; i++)
   {
      for (int j = 0; j < dim; j++)
      {

         int numberOfNeighbours = numberOfLiveNeighbours(i, j);

         if (isDeadCell(i, j) && (numberOfNeighbours == 3))
         {
            flag_array[i][j] = '#';
         }
         if (isLiveCell(i, j) && (numberOfNeighbours < 2 || numberOfNeighbours > 3))
         {
            flag_array[i][j] = '.';
         }
      }
   }

   for (int i = 0; i < dim; i++)
   {
      for (int j = 0; j < dim; j++)
      {
         if (flag_array[i][j] == '#')
         {
            rebirthCell(i, j);
         }
         if (flag_array[i][j] == '.')
         {
            killCell(i, j);
         }
      }
   }
}

void killCell(int i, int j)
{
   array[i][j] = '.';
}
void rebirthCell(int i, int j)
{
   array[i][j] = '#';
}
bool isLiveCell(int i, int j)
{
   return array[i][j] == '#';
}
bool isDeadCell(int i, int j)
{
   return array[i][j] == '.';
}
int numberOfLiveNeighbours(int i, int j)
{
   int neighbours = 0;
   if (i == 0)
   {
      neighbours = numberOfNeighboursTop(j);
   }
   else if (i == dim - 1)
   {
      neighbours = numberOfNeighboursBottom(j);
   }
   else if (j == 0)
   {
      neighbours = numberOfNeighboursLeft(i);
   }
   else if (j == dim - 1)
   {
      neighbours = numberOfNeighboursRight(i);
   }
   else
   {
      neighbours = numberOfNeighboursMiddle(i, j);
   }
   return neighbours;
}
int numberOfNeighboursMiddle(int i, int j)
{
   int neighbours = 0;
   if (array[i - 1][j] == '#')
   {
      neighbours++;
   }
   if (array[i + 1][j] == '#')
   {
      neighbours++;
   }
   if (array[i][j - 1] == '#')
   {
      neighbours++;
   }
   if (array[i][j + 1] == '#')
   {
      neighbours++;
   }
   if (array[i - 1][j - 1] == '#')
   {
      neighbours++;
   }
   if (array[i + 1][j + 1] == '#')
   {
      neighbours++;
   }
   if (array[i + 1][j - 1] == '#')
   {
      neighbours++;
   }
   if (array[i - 1][j + 1] == '#')
   {
      neighbours++;
   }
   return neighbours;
}
int numberOfNeighboursTop(int j)
{
   int neighbours = 0;
   if (array[0][j - 1] == '#')
   {
      neighbours++;
   }
   if (array[0][j + 1] == '#')
   {
      neighbours++;
   }
   if (array[1][j] == '#')
   {
      neighbours++;
   }
   if (array[1][j - 1] == '#')
   {
      neighbours++;
   }
   if (array[1][j + 1] == '#')
   {
      neighbours++;
   }
   return neighbours;
}
int numberOfNeighboursBottom(int j)
{
   int neighbours = 0;
   if (array[dim - 1][j - 1] == '#')
   {
      neighbours++;
   }
   if (array[dim - 1][j + 1] == '#')
   {
      neighbours++;
   }
   if (array[dim - 2][j] == '#')
   {
      neighbours++;
   }
   if (array[dim - 2][j - 1] == '#')
   {
      neighbours++;
   }
   if (array[dim - 2][j + 1] == '#')
   {
      neighbours++;
   }
   return neighbours;
}
int numberOfNeighboursLeft(int i)
{
   int neighbours = 0;
   if (array[i - 1][0] == '#')
   {
      neighbours++;
   }
   if (array[i - 1][0] == '#')
   {
      neighbours++;
   }
   if (array[i][1] == '#')
   {
      neighbours++;
   }
   if (array[i - 1][1] == '#')
   {
      neighbours++;
   }
   if (array[i + 1][1] == '#')
   {
      neighbours++;
   }
   return neighbours;
}
int numberOfNeighboursRight(int i)
{
   int neighbours = 0;
   if (array[i + 1][dim - 1] == '#')
   {
      neighbours++;
   }
   if (array[i - 1][dim - 1] == '#')
   {
      neighbours++;
   }
   if (array[i][dim - 2] == '#')
   {
      neighbours++;
   }
   if (array[i + 1][dim - 2] == '#')
   {
      neighbours++;
   }
   if (array[i - 1][dim - 2] == '#')
   {
      neighbours++;
   }
   return neighbours;
}