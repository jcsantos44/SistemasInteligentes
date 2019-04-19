#include "environment.h"


Environment::Environment()
{
    int r;
    char url[]="Env.txt";
    char ch;
    FILE *arq;

    arq = fopen(url, "r");
    if(arq == NULL)
    printf("Error, it is not possible to open the Env.txt file!\n");
    fscanf(arq, "%d\n", &n_rows);
    fscanf(arq, "%d\n", &n_cols);
    mat temp(MAX_ROWS, std::vector<int>(MAX_COLS));
    Matrix = temp;
    graph = new Graph(n_rows, n_cols, NUMBERDIRECTIONS);
}

void Environment::scan_state_from_file()
{

int r,c;
char url[]="Env.txt";
char ch;
FILE *arq;

arq = fopen(url, "r");
if(arq == NULL)
    printf("Error, it is not possible to open the Env.txt file!\n");
fscanf(arq, "%d\n", &n_rows);
fscanf(arq, "%d\n", &n_cols);
for(r=0;r<n_rows;r++)
	{
    	for(c=0;c<n_cols;c++)
    	{
    		ch=fgetc(arq);
	 //     printf("%d,%d = %c\t",r,c,ch);
		if ( ch == '*' ) {
			Matrix[r][c] = WALL;
     			}
		else if ( ch == 'x' ) {
			Matrix[r][c] = TARGET;
			x_target = r;
			y_target = c;
     			}
		else if ( ch == '^' ) {
			Matrix [r][c] = ROBOT;
			Rob1.setLocation(r,c);
			Rob1.setFacing(NORTH);
			}
		else if ( ch == '>' ) {
			Matrix [r][c] = ROBOT;
			Rob1.setLocation(r,c);
			Rob1.setFacing(EAST);
     			}
		else if ( ch == 'v' ) {
			Matrix [r][c] = ROBOT;
			Rob1.setLocation(r,c);
			Rob1.setFacing(SOUTH);
			}
		else if ( ch == '<' ) {
			Matrix [r][c] = ROBOT;
			Rob1.setLocation(r,c);
			Rob1.setFacing(WEST);
			}
		else {
			Matrix [r][c] = NONE;
			}//end of if...else
		}//end of for(c)
	fscanf(arq,"\n");// to cath the new line
	}//end of for(r)
fclose(arq);
}

void Environment::scan_state()
{
  int ch;
  int r,c;


  printf("Number of Lines:");
  scanf("%d\n", &n_rows);
  printf("Number of Columns:");
  scanf("%d\n", &n_cols);
  for(r=0;r<n_rows;r++)
   {
    for(c=0;c<n_cols;c++)
    {

     ch=getchar();
//     printf("%d,%d = %c\t",r,c,ch);
     if ( ch == '*' ) {
      Matrix[r][c] = WALL;
     }
     else if ( ch == 'x' ) {
      Matrix[r][c] = TARGET;
      x_target = r;
      y_target = c;
     }
     else if ( ch == '^' ) {
      Matrix [r][c] = ROBOT;
      Rob1.setLocation(r,c);
      Rob1.setFacing(NORTH);
     }
     else if ( ch == '>' ) {
      Matrix [r][c] = ROBOT;
      Rob1.setLocation(r,c);
      Rob1.setFacing(EAST);
     }
     else if ( ch == 'v' ) {
      Matrix [r][c] = ROBOT;
      Rob1.setLocation(r,c);
      Rob1.setFacing(SOUTH);
     }
     else if ( ch == '<' ) {
      Matrix [r][c] = ROBOT;
      Rob1.setLocation(r,c);
      Rob1.setFacing(WEST);
     }
     else {
      Matrix [r][c] = NONE;
     }//end of if...else
    }//end of for(c)
    scanf("\n");// to cath the new line
   }//end of for(r)
}


void Environment::print_state()
{

int r,c;
 printf("    ");
 for(int i=0;i<n_cols;i++)
   printf("  %d ",i);
 printf("\n");
 printf("    ");
 for(int i=0;i<n_cols;i++)
   printf("+---");
 printf("+\n");
 for( r=0; r < n_rows ; r++ )
 {
 printf("  %d ",r);
   for( c=0; c < n_cols; c++ ) {
      if (Matrix[r][c] == WALL)
       {
        printf( "|***" );
       }

      if (Matrix[r][c] == TARGET)
       {
        printf( "| X " );
       }

      if (Matrix[r][c] == NONE)
       {
        printf( "|   " );
       }

      if ( Matrix[r][c] == ROBOT )
       {
        if (Rob1.getFacing() == NORTH)
        {
          printf("| ^ ");
        }
        else if (Rob1.getFacing() == NORTHEAST)
        {
          printf("| / ");
        }
        else if (Rob1.getFacing() == EAST)
        {
          printf("| > ");
        }
        else if (Rob1.getFacing() == SOUTHEAST)
        {
          printf("| \\ ");
        }
        else if (Rob1.getFacing() == SOUTH)
        {
          printf("| v ");
        }
        else if (Rob1.getFacing() == SOUTHWEST)
        {
          printf("| %% ");
        }
        else if (Rob1.getFacing() == WEST)
        {
          printf("| < ");
        }
	else if (Rob1.getFacing() == NORTHWEST)
        {
          printf("| # ");
        }//end of if(Rob1...)else
      }//end of if(Matrix....)

   }//end of for(c)
   printf( "|\n" );
   printf("    ");
   for(int i=0;i<n_cols;i++)
     printf("+---");
   printf("+\n");
 }//end of for(r)
 Rob1.print_state();
}


void Environment::move_robot(int direction)
{
	if ((direction == NORTH) && (Rob1.getFacing() == NORTH) && (Matrix[Rob1.getX()-1][Rob1.getY()]!=WALL) && (Rob1.getX() > 0))
	{
		Matrix[Rob1.getX()][Rob1.getY()] = NONE;
		Matrix[Rob1.getX()-1][Rob1.getY()] = ROBOT;
		Rob1.move(NORTH);
	}
	else
	if ((direction == NORTHWEST) && (Rob1.getFacing() == NORTHWEST) && (Matrix[Rob1.getX()-1][Rob1.getY()-1]!=WALL) && (Rob1.getX() > 0) && (Rob1.getY() > 0))
	{
		Matrix[Rob1.getX()][Rob1.getY()] = NONE;
		Matrix[Rob1.getX()-1][Rob1.getY()-1] = ROBOT;
		Rob1.move(NORTHWEST);
	}
       else
	if ((direction == SOUTH) && (Rob1.getFacing() == SOUTH) && (Matrix[Rob1.getX()+1][Rob1.getY()]!=WALL) && (Rob1.getX() < n_rows-1))
	{
		Matrix[Rob1.getX()][Rob1.getY()] = NONE;
		Matrix[Rob1.getX()+1][Rob1.getY()] = ROBOT;
		Rob1.move(SOUTH);
	}
	else
	if ((direction == SOUTHEAST) && (Rob1.getFacing() == SOUTHEAST) && (Matrix[Rob1.getX()+1][Rob1.getY()+1]!=WALL) && (Rob1.getX() < n_rows-1) && (Rob1.getY() < n_cols-1))
	{
		Matrix[Rob1.getX()][Rob1.getY()] = NONE;
		Matrix[Rob1.getX()+1][Rob1.getY()+1] = ROBOT;
		Rob1.move(SOUTHEAST);
	}
	else
	if ((direction == EAST) && (Rob1.getFacing() == EAST) && (Matrix[Rob1.getX()][Rob1.getY()+1]!=WALL) && (Rob1.getY() < n_cols-1))
	{
		Matrix[Rob1.getX()][Rob1.getY()] = NONE;
		Matrix[Rob1.getX()][Rob1.getY()+1] = ROBOT;
		Rob1.move(EAST);
	}
	else
	if ((direction == SOUTHWEST) && (Rob1.getFacing() == SOUTHWEST) && (Matrix[Rob1.getX()+1][Rob1.getY()-1]!=WALL) && (Rob1.getX() < n_rows-1) && (Rob1.getY() >0))
	{
		Matrix[Rob1.getX()][Rob1.getY()] = NONE;
		Matrix[Rob1.getX()+1][Rob1.getY()-1] = ROBOT;
		Rob1.move(SOUTHWEST);
	}
        else
	if ((direction == WEST) && (Rob1.getFacing() == WEST) && (Matrix[Rob1.getX()][Rob1.getY()-1]!=WALL) && (Rob1.getY() > 0))
	{
		Matrix[Rob1.getX()][Rob1.getY()] = NONE;
		Matrix[Rob1.getX()][Rob1.getY()-1] = ROBOT;
		Rob1.move(WEST);
	}
	else
	if ((direction == NORTHEAST) && (Rob1.getFacing() == NORTHEAST) && (Matrix[Rob1.getX()-1][Rob1.getY()+1]!=WALL) && (Rob1.getX() >0) && (Rob1.getY() < n_cols-1))
	{
		Matrix[Rob1.getX()][Rob1.getY()] = NONE;
		Matrix[Rob1.getX()-1][Rob1.getY()+1] = ROBOT;
		Rob1.move(NORTHEAST);
	}

}

void Environment::rotate_robot(int clock_or_counterclock_90_degrees)
{
int local_facing;
   if(clock_or_counterclock_90_degrees == CLOCKWISE)
   {
	local_facing = Rob1.getFacing();
	local_facing--;
	if(local_facing<0) local_facing = 7;
	Rob1.setFacing(local_facing);
/*     if(Rob1.getFacing()==SOUTH) Rob1.setFacing(WEST);
     else
     if(Rob1.getFacing()==WEST) Rob1.setFacing(NORTH);
     else
     if(Rob1.getFacing()==NORTH) Rob1.setFacing(EAST);
     else
     if(Rob1.getFacing()==EAST) Rob1.setFacing(SOUTH);
*/   }
   else
   if(clock_or_counterclock_90_degrees == COUNTERCLOCK)
   {
	local_facing = Rob1.getFacing();
	local_facing++;
	if(local_facing>7) local_facing = 0;
	Rob1.setFacing(local_facing);
   }
/*     if(Rob1.getFacing()==SOUTH) Rob1.setFacing(EAST);
     else
     if(Rob1.getFacing()==EAST) Rob1.setFacing(NORTH);
     else
     if(Rob1.getFacing()==NORTH) Rob1.setFacing(WEST);
     else
     if(Rob1.getFacing()==WEST) Rob1.setFacing(SOUTH);
   }
*/}

void Environment::addForwardWalkToGraph(int ux, int uy, int udirection)
{
    switch(udirection)
    {
    case NORTH: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy);
            break;
    case NORTHEAST: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy+1);
            break;
    case EAST:
            //std::cout << std::endl << ux << uy << udirection << " " << ux << uy+1;
            graph->addCoordinateChange(ux, uy, udirection, ux, uy+1);
            break;
    case SOUTHEAST: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy+1);
            break;
    case SOUTH: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy);
            break;
    case SOUTHWEST: graph->addCoordinateChange(ux, uy, udirection, ux+1, uy-1);
            break;
    case WEST: graph->addCoordinateChange(ux, uy, udirection, ux, uy-1);
            break;
    case NORTHWEST: graph->addCoordinateChange(ux, uy, udirection, ux-1, uy-1);
            break;
    }
//    counter++;
}

void Environment::addRotationClockwiseToGraph(int ux, int uy, int udirection)
{
    if (udirection == 7)
        graph->addDirectionChange(ux, uy, udirection, 0);
    else
        graph->addDirectionChange(ux, uy, udirection, udirection+1);
//    counter++;
}

void Environment::addRotationAnticlockwiseToGraph(int ux, int uy, int udirection)
{
    if (udirection == 0)
        graph->addDirectionChange(ux, uy, udirection, 7);
    else
        graph->addDirectionChange(ux, uy, udirection, udirection-1);
//    counter++;
}

void Environment::traverseMatrixMakeStateGraph()
{
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            for (int direction = 0; direction < NUMBERDIRECTIONS; direction ++)
            {
                switch (direction)
                {
                    case NORTH : //north
                        if (i-1 >= 0 && Matrix[i-1][j] != WALL)
                            addForwardWalkToGraph(i, j, direction);
                        break;
                    case NORTHEAST : //northeast
                        if (i-1 >= 0 && j+1 < n_cols && Matrix[i-1][j+1] != WALL)
                            addForwardWalkToGraph(i, j, direction);
                        break;
                    case EAST : //east
                        if (j+1 < n_cols && Matrix[i][j+1] != WALL)
                            addForwardWalkToGraph(i, j, direction);
                        break;
                    case SOUTHEAST : //southeast
                        if (i+1 < n_rows && j+1 < n_cols && Matrix[i+1][j+1] != WALL)
                            addForwardWalkToGraph(i, j, direction);
                        break;
                    case SOUTH : //south
                        if (i+1 < n_rows && Matrix[i+1][j] != WALL)
                            addForwardWalkToGraph(i, j, direction);
                        break;
                    case SOUTHWEST : //southwest
                        if (i+1 < n_rows && j-1 >= 0 && Matrix[i+1][j-1] != WALL)
                            addForwardWalkToGraph(i, j, direction);
                        break;
                    case WEST :
                        if (j-1 >= 0 && Matrix[i][j-1] != WALL)
                            addForwardWalkToGraph(i, j, direction);
                        break;
                    case NORTHWEST :
                        if (i-1 >= 0 && j-1 >= 0 && Matrix[i-1][j-1] != WALL)
                            addForwardWalkToGraph(i, j, direction);
                        break;
                }
                addRotationClockwiseToGraph(i, j, direction);
                addRotationAnticlockwiseToGraph(i, j, direction);
            }
        }
    }
}

std::vector<std::vector<int> > Environment::getMatrix()
{
    return Matrix;
}

Graph* Environment::getGraph()
{
    return graph;
}

int Environment::getN_Rows()
{
    return n_rows;
}

int Environment::getN_Cols()
{
    return n_rows;
}

int Environment::getX_Target()
{
    return x_target;
}

int Environment::getY_Target()
{
    return y_target;
}

Robot Environment::getAgent()
{
    return Rob1;
}

void Environment::traverseShortestPath(std::vector<Estado> ShortestPath)
{
    print_state();
    Estado predecessor;
    for (int i=ShortestPath.size() - 1; i>0; i--)
    {
        predecessor = ShortestPath[i-1];
        if (ShortestPath[i].getX() == predecessor.getX() && ShortestPath[i].getY() == predecessor.getY())
        {
            if (ShortestPath[i].getDirection() == 0 && predecessor.getDirection() == 7)
            {
                std::cout << std::endl << "Rotating CLOCKWISE" << std::endl;
                rotate_robot(CLOCKWISE);
            }
            else if (ShortestPath[i].getDirection() == 7 && predecessor.getDirection() == 0)
            {
                std::cout << std::endl << "Rotating COUNTERCLOCK" << std::endl;
                rotate_robot(COUNTERCLOCK);
            }
            else if (ShortestPath[i].getDirection() < predecessor.getDirection())
            {
                std::cout << std::endl << "Rotating COUNTERCLOCK" << std::endl;
                rotate_robot(COUNTERCLOCK);
            }
            else
            {
                std::cout << std::endl << "Rotating CLOCKWISE" << std::endl;
                rotate_robot(CLOCKWISE);
            }

        }
        else if (Rob1.getFacing() != ShortestPath[i].getDirection())
        {
            std::cout << "erro";
            return;
        }
        else
        {
        std::cout << std::endl << "MOVING FORWARD" << std::endl;
        move_robot(Rob1.getFacing());
        }
        //predecessor = ShortestPath[i];
        print_state();
    }
    std::cout << "Numero de passos: " << ShortestPath.size();
}
