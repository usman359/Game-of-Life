#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include<cstring>                                                                       // for file reading and writing
using namespace std;
// function prototype
int y=0;                                                                                // this will be used for delection of nerighbor array and storing values
int p=0;                                                                                // this variable will be used for generations
int r=0;
int step=0;                                                                             // for step counting, initially the step starts from 0
int generation =0;                                                                      // initially the gerneration is 0, when the file is read
int outputCount=0;                                                                      // in the final step, we need only the live cells until all the generations 
                                                                                        // are complete so this varaible will be used for it and initially it is 0.


void start();                                                                           // this function is to start the game
void fileRead(string);                                                                  // this function will read the file

bool checkifCellHasbeenChecked(int i, int j, int checkInThisArray[500][500]);           // this function will check whether the cell in neighbourHood has been already inserted
                                                                                        // in neighbourHood array. if yes then that cell won't appear again (no duplication)

bool checkifCellHasbeenChecked2(int s, int d, int checkInThisArray2[500][500]);         // this function will check whether the cell in neighbourHood has been already inserted
                                                                                        // in neighbourHood array. if yes then that cell won't appear again (no duplication)

bool checkifCellIsNotAlive(int count);                                                     // this function will function whether the cell is alive or not
bool checkifCellHasExactly3Neighbors(int counter);                                      // this function will check that the nei - array cell has exactly 3 neighbors or not

bool checkifCellHasbeenChecked3(int s, int d, int checkInThisArray4[500][500]);         // this function will check whether the cell in neighbourHood has been already inserted
                                                                                        // in neighbourHood array. if yes then that cell won't appear again (no duplication)

int removeAllElementFromNeighborArray(int count, int neighbourHood[]);                  // this function is to remove all elements from nei - array according to the rules
int removeAllElementFromNeighborArray2(int count, int neighbourHood[]);                 // this function is to remove all elements from nei - array according to the rules

bool checkifCellHasbeenChecked4(int s, int d, int checkInThisArray5[500][500]);         // this function will check whether the cell in neighbourHood has been already inserted
                                                                                        // in neighbourHood array. if yes then that cell won't appear again (no duplication)

bool checkifCellHasbeenChecked5(int s, int d, int checkInThisArray6[500][500]);         // this function will check whether the cell in neighbourHood has been already inserted
                                                                                        // in neighbourHood array. if yes then that cell won't appear again (no duplication)

bool checkifCellHasbeenChecked6(int s, int d, int checkInThisArray7[500][500]);         // this function will check whether the cell in neighbourHood has been already inserted
                                                                                        // in neighbourHood array. if yes then that cell won't appear again (no duplication)

bool checkifCellIsAlive2(int );                                                         // this function will function whether the cell is alive or not

// main function to start the game only
int main()
{
        start();        // function call, this is where the game begins
return 0;
}

// line 51 function definition
// the user will input the name of the file
void start()
{
                string file;                                                            // as name of the file is a string so we need the string data type
                cout << "Enter the name of the file " << endl;
                cin >> file;                                                            // user will input the name of the file 
                cout << endl;
                fileRead(file); // function call
}

// line 63 function definition
// this function is to read the file
// read the generations, number of cells in the object to be read and the coordinates for the various cells of the object 
void fileRead(string file)
{
        ifstream fileName(file.c_str());                                                // fileName is the ifstream object and the file with data type
                                                                                        // data type string is the file name as input by the user
        
        if (fileName.is_open())                                                         // if the file is open then display the message
        cout << "File found successfully " << endl;

        else
        cout << "File not found " << endl << endl;                                      // if it is not open then display the message

 
int store[p];                                                                           // in this array, the values that will be read from the file will be stored. Initially
                                                                                        // p is initialized to 0 before the main function to avoid any errors 

        while (fileName >> store[p])                                                    // the first line which contains the generations will be read from the 
                                                                                        // ifstream object and it will be store in array store[0]. Size 0 initially 
        {
            cout << "The number of generations are: ";
            cout << store[p];                                                           // the number of generations will be displayed in the screen
            break;                                                                      // break the while loop 
        }
        int gene=store[p];                                                              // stored in a variable because this will be used further
        p++;                                                                            // increment the p value 
        cout << endl;

            while (fileName >> store[p])                                                // now from the second line it will read the total number of inputs
            {
                cout << "The number of total inputs are: ";
                cout << store[p];
                p = store[p]; 			                                   // whatever the total number of inputs will be, the 
                                                                                        // coordinates x and y quantity. It will be assigned to p
                break;
            }
        
        cout << endl;

        string gridSize;                                                                // to read x and y coordinates from the file
        const int rows=20, columns=20;                                                  // these constant values for rows and 
                                                                                        // columns will never be changed

        int grid[rows][columns];                                                        // created an array for rows and columns

        int k=300;                                                                      // k variable is to read the coordinates from 
                                                                                        // the file. Its value is 300 to avoid errors                                                              
        
        int coordinates[k];                                                             // created an array to read the coordinates 
	cout << "The coordinates for the various cells of the object are: " << endl;
	k=0;                                                                             // we have total size till 300 so we can start storing the values from 0

        for (int i=0; i<p; i++)			                                   // p value is the total number of cells in the object about to be read
        {
        	cout << setw(20);
            for (int j=0; j<2; j++)			                                            // condition is less than 2 because we only have x and y coordinates
            {
                fileName >> gridSize;                                                   // getting the coordinates from the file. We need to avoid the space between the 
                                                                                        // coordinates so we a string varable to get the values and avoid space
                
                grid[i][j] = stoi(gridSize);                                            // converting the string to int and storing the values in the grid array
                coordinates[k] = grid[i][j];                                            // storing the coordinates read from the file in coordinates array
                cout << grid[i][j] << " ";                                              // first time value is 2, then second time 3.
            k++;
            }
            	cout << endl;
        }
        
        
       // we need to print 0s and 1s for rows 20 and columns 20
       for (int i=0; i<rows; i++)                                                       
       {
       	    for (int j=0; j<columns; j++)
       	    {
       		    
                   grid[i][j] = 0;                                                       // initially assign all grid coordinates to 0 to avoid errors 
                                                                                        // when assigning 1 to the coordinates read from the file
       	    }
       }
			
            		
        for (int i=0; i< p*2; i +=2)                                                    // this loop will run till coordinates inputs * 2 as we have x and y so
                                                                                        // we need to multiply it with 2 or simply add 2 to it (no difference)
        {
        	
            grid[coordinates[i]][coordinates[i+1]]  = 1;                                // now 2 dimensional grid size will be the coordinates x and y  
                                                                                        // as read from the file and that will be initilized to 1 only
        }
        			
        cout << endl;
        cout << setw(85) << " GENERATION " << generation << endl;                       // initially the generation will be 0
        cout << setw(121);
        cout << "________________________________________________________________________________" << endl;
        cout << setw(42);
        for (int i=0; i<rows; i++)
        {
		    cout << "|";
                for (int j=0; j<columns; j++)
                {
                    cout << grid[i][j] <<  " | ";                                      // now finally display the grid with values 1 and 0
                }
                    cout << endl;
                    cout <<  setw(42) << "|";
                    cout << setw(71);
                    cout << "__|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|" << endl;
                    cout << setw(42);

        }
        cout << endl;

// --> step 1
cout << setw(0);
int lastIndex = 500;                                                                    // always intilize to big size if you are uncertain
int secondary[100];                                                                    // created a secondary array to keep track of the live cells
int last[lastIndex];                                                                   // this varaible shall be used to store the last values 
step++;
lastIndex = 0;
    cout << "------------------------------------------" << endl;
    cout << setw(22) << "STEP " << step << endl << endl;
    cout << "Live cells in the grid are: " << endl;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            if (grid[i][j] == 1)                                                       // this if  will only run for the grid values that 
            {                                                                          // are 1 (the coordinates values read from the file)
            
                secondary[i] = grid[i][j];                                             // printing the live cells and storing them in secondary array
                cout << "(" << i << "," << j << ")" << endl;
                last[lastIndex] = secondary[i];                                         // the last index will be stored in the last array
                lastIndex++;
            }
        }
    }
cout << endl;
cout << "The last index of secondary array is: " << lastIndex-1 << endl;
// ==> step 2
step++;
    cout << "------------------------------------------" << endl;
    cout << setw(22) << "STEP " << step << endl << endl;

int neighbourHood[550];                                                                 // created a neighbourhood array to store neighbourHood values
											     
int grid2[500][500];
k=0;
lastIndex=0;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            if (grid[i][j] == 1)                                                        // this if  will only run for the grid values that 
            {                                                                          // are 1 (the coordinates values read from the file)
            
            cout << "Dead cells of live cells " << "(" << i << "," << j << ")" << "are: " << endl;
            if (checkifCellHasbeenChecked(i-1, j-1, grid2) == false)                    // this function will not run the duplication if that cell has already been inserted
            {
                grid2[i-1][j-1] = 1;                                                    // this would make the location i-1 and j-1 to 1

            // applying the formulas
            neighbourHood[k] = grid[i-1][j-1];                                          // storing the neighbourHood cells in neighbourHood array 

            if (grid[i-1][j-1] == 0)                                                    // if its neighbourHood value is 0 without duplication then execute
            {
                    cout << "(" << i-1 << "," << j-1 << ")" << endl;
                    lastIndex++;                                                        // this would tell that what was the last index when neighbourHood
                                                                                        // would have been successfully inserted in the neighbourHood array
            }
            
            }

            if (checkifCellHasbeenChecked(i-1, j, grid2) == false)
            {
                grid2[i-1][j] = 1;
                neighbourHood[k++] = grid[i-1][j];
            
            if (grid[i-1][j] == 0)
            {
                    cout << "(" << i-1 << "," << j << ")" << endl;
                    lastIndex++;
            }
        
            }

            if (checkifCellHasbeenChecked(i-1, j+1, grid2) == false)
            {
                grid2[i-1][j+1] = 1;
                neighbourHood[k++] = grid[i-1][j+1];

            if (grid[i-1][j+1] == 0)
            {
                    cout << "(" << i-1 << "," << j+1 << ")" << endl;
                    lastIndex++;
            }
        
            }

            if (checkifCellHasbeenChecked(i, j-1, grid2) == false)
            {
                grid2[i][j-1] = 1;
                neighbourHood[k++] = grid[i][j-1];

            if (grid[i][j-1] == 0)
            {
                    cout << "(" << i << "," << j-1 << ")" << endl;
                    lastIndex++;
            }
            
            }

            if (checkifCellHasbeenChecked(i, j+1, grid2) == false)
            {
                grid2[i][j+1] = 1;
                neighbourHood[k++] = grid[i][j+1];

            if (grid[i][j+1] == 0)
            {
                    cout << "(" << i << "," << j+1 << ")" << endl;
                    lastIndex++;
            }
        
            }

            if (checkifCellHasbeenChecked(i+1, j-1, grid2) == false)
            {
                grid2[i+1][j-1] = 1;
                neighbourHood[k++] = grid[i+1][j-1];

            if (grid[i+1][j-1] == 0)
            {
                    cout << "(" << i+1 << "," << j-1 << ")" << endl;
                    lastIndex++;
            }
        
            }

            if (checkifCellHasbeenChecked(i+1, j, grid2) == false)
            {
                grid2[i+1][j] = 1;
                neighbourHood[k++] = grid[i+1][j];

            if (grid[i+1][j] == 0)
            {
                    cout << "(" << i+1 << "," << j << ")" << endl;
                    lastIndex++;
            }
        
            }

            if (checkifCellHasbeenChecked(i+1, j+1, grid2) == false)
            {
                grid2[i+1][j+1] = 1;
                neighbourHood[k++] = grid[i+1][j+1];

            if (grid[i+1][j+1] == 0)
            {
                    cout << "(" << i+1 << "," << j+1 << ")" << endl;
                    lastIndex++;
            }

            }


        }                                                                                       // if ending scope where only those grid values will be accepted which are 1 in grid

    }
}
cout << endl;
cout << "The last index of neighbourHood array is: " << lastIndex-1 << endl;
lastIndex=0;
step++;

cout << "------------------------------------------" << endl;
cout << setw(22) << "STEP " << step << endl << endl;
// ==> step 3
// we have to count the secondary array and the neighbourHood array neighbours live cells only 
k=0;
for (int a=0; a<rows; a++)
{
    for (int b=0; b<columns; b++)
    {
        if (grid[a][b] == 1)
        {
            int count=0;                                                                    // initially count is 0
            secondary[k] = grid[a-1][b-1];
            if (grid[a-1][b-1] == grid[a][b])                                               // if the current secondary grid equal to 1 is equivalent to 
                                                                                            //  other secondary live cells then count 1 othewise don't
            {
                    count++;
            }


            secondary[k++] = grid[a-1][b];

            if (grid[a-1][b] == grid[a][b])
            {

                    count++;
            }

            secondary[k++] = grid[a-1][b+1];

            if (grid[a-1][b+1] == grid[a][b])
            {
                    count++;
            }

            secondary[k++] = grid[a][b-1];


            if (grid[a][b-1] == grid[a][b])
            {
                    count++;
            }

            secondary[k++] = grid[a][b+1];


            if (grid[a][b+1] == grid[a][b])
            {
                    count++;
            }


            secondary[k++] = grid[a+1][b-1];


            if (grid[a+1][b-1] == grid[a][b])
            {
                    count++;
            }


            secondary[k++] = grid[a+1][b];


            if (grid[a+1][b] == grid[a][b])
            {
                    count++;
            }


            secondary[k++] = grid[a+1][b+1];


            if (grid[a+1][b+1] == grid[a][b])
            {
                    count++;
            }

            cout << "Secondary array live neighbor " << "(" << a << "," << b << ")" << " appearead " << count << " time " << endl;
        }                                                                                        // if ending scope where the grid value is 1

    }
}
cout << endl;

// now count live neighbors of neighborHood array
int counter1=0, counter2=0, counter3=0, counter4=0, counter5=0, counter6=0, counter7=0, counter8=0;
int grid3[500][500];                                                                           
int e=0,r=0;                                                                                        // these variables will be used to assign the secondary array neighbours
k=0;
for (int s=0; s<rows; s++)
{
    for (int d=0; d<columns; d++)
    {

        if (grid[s][d] == 1) 
        {
            if (checkifCellHasbeenChecked2(s-1, d-1, grid3) == false)
            {
                grid3[s-1][d-1] = 1; // this would make the location i-1 and j-1 to 1

            // applying the formulas
            neighbourHood[k] = grid[s-1][d-1];

            e=s-1;
            r=d-1;
            if (grid[e][r] == 0)                                                                       // secondary array neighbourHood value will always be 0
            {
                if (grid[e-1][r-1] == 1)                                                             // this would see that the neighbourHood of secondary array has any live cell.
                                                                                                    //  If yes then count otherwise don't count as we only need the count of live cells
                    counter1++;

                if (grid[e-1][r] == 1)
                    counter1++;

                if (grid[e-1][r+1] == 1)
                    counter1++;

                if (grid[e][r-1] == 1)
                    counter1++;

                if (grid[e][r+1] == 1)
                    counter1++;

                if (grid[e+1][r-1] == 1)
                    counter1++;

                if (grid[e+1][r] == 1)
                    counter1++;

                if (grid[e+1][r+1] == 1)
                    counter1++;


            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter1 << " time " << endl;
            counter1=0;                                                                             // initilized it to 0 as for the next secondary array  
                                                                                                    // neighbour we need to start the count from 0
            }
            }
            
            if (checkifCellHasbeenChecked2(s-1, d, grid3) == false)
            {
                grid3[s-1][d] = 1;

            neighbourHood[k++] = grid[s-1][d];
            e=s-1;
            r=d;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                counter2++;

                if (grid[e-1][r] == 1)
                counter2++;

                if (grid[e-1][r+1] == 1)
                counter2++;

                if (grid[e][r-1] == 1)
                counter2++;

                if (grid[e][r+1] == 1)
                counter2++;

                if (grid[e+1][r-1] == 1)
                counter2++;

                if (grid[e+1][r] == 1)
                counter2++;

                if (grid[e+1][r+1] == 1)
                counter2++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter2 << " time " << endl;
            counter2=0;
            }
            }
            
            if (checkifCellHasbeenChecked2(s-1, d+1, grid3) == false)
            {
                grid3[s-1][d+1] = 1;
            
            neighbourHood[k++] = grid[s-1][d+1];
            e=s-1;
            r=d+1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                counter3++;

                if (grid[e-1][r] == 1)
                counter3++;

                if (grid[e-1][r+1] == 1)
                counter3++;

                if (grid[e][r-1] == 1)
                counter3++;

                if (grid[e][r+1] == 1)
                counter3++;

                if (grid[e+1][r-1] == 1)
                counter3++;

                if (grid[e+1][r] == 1)
                counter3++;

                if (grid[e+1][r+1] == 1)
                counter3++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter3 << " time " << endl;
            counter3=0;
            }
            }
            
            if (checkifCellHasbeenChecked2(s, d-1, grid3) == false)
            {
                grid3[s][d-1] = 1;
            
            neighbourHood[k++] = grid[s][d-1];
            e=s;
            r=d-1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                counter4++;

                if (grid[e-1][r] == 1)
                counter4++;

                if (grid[e-1][r+1] == 1)
                counter4++;

                if (grid[e][r-1] == 1)
                counter4++;

                if (grid[e][r+1] == 1)
                counter4++;

                if (grid[e+1][r-1] == 1)
                counter4++;

                if (grid[e+1][r] == 1)
                counter4++;

                if (grid[e+1][r+1] == 1)
                counter4++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter4 << " time " << endl;
            counter4=0;
            }
            }
            
            if (checkifCellHasbeenChecked2(s, d+1, grid3) == false)
            {
                grid3[s][d+1] = 1;
            
            neighbourHood[k++] = grid[s][d+1];
            e=s;
            r=d+1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                counter5++;

                if (grid[e-1][r] == 1)
                counter5++;

                if (grid[e-1][r+1] == 1)
                counter5++;

                if (grid[e][r-1] == 1)
                counter5++;

                if (grid[e][r+1] == 1)
                counter5++;

                if (grid[e+1][r-1] == 1)
                counter5++;

                if (grid[e+1][r] == 1)
                counter5++;

                if (grid[e+1][r+1] == 1)
                counter5++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter5 << " time " << endl;
            counter5=0;
            }
            }
            
            if (checkifCellHasbeenChecked2(s+1, d-1, grid3) == false)
            {
                grid3[s+1][d-1] = 1;
            
            neighbourHood[k++] = grid[s+1][d-1];
            e=s+1;
            r=d-1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                counter6++;

                if (grid[e-1][r] == 1)
                counter6++;

                if (grid[e-1][r+1] == 1)
                counter6++;

                if (grid[e][r-1] == 1)
                counter6++;

                if (grid[e][r+1] == 1)
                counter6++;

                if (grid[e+1][r-1] == 1)
                counter6++;

                if (grid[e+1][r] == 1)
                counter6++;

                if (grid[e+1][r+1] == 1)
                counter6++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter6 << " time " << endl;
            counter6=0;
            }
            }
            
            if (checkifCellHasbeenChecked2(s+1, d, grid3) == false)
            {
                grid3[s+1][d] = 1;
            
            neighbourHood[k++] = grid[s+1][d];
            e=s+1;
            r=d;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                counter7++;

                if (grid[e-1][r] == 1)
                counter7++;

                if (grid[e-1][r+1] == 1)
                counter7++;

                if (grid[e][r-1] == 1)
                counter7++;

                if (grid[e][r+1] == 1)
                counter7++;

                if (grid[e+1][r-1] == 1)
                counter7++;

                if (grid[e+1][r] == 1)
                counter7++;

                if (grid[e+1][r+1] == 1)
                counter7++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter7 << " time " << endl;
            counter7=0;
            }
            }
            
            if (checkifCellHasbeenChecked2(s+1, d+1, grid3) == false)
            {
                grid3[s+1][d+1] = 1;
            
            neighbourHood[k++] = grid[s+1][d+1];
            e=s+1;
            r=d+1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                counter8++;

                if (grid[e-1][r] == 1)
                counter8++;

                if (grid[e-1][r+1] == 1)
                counter8++;

                if (grid[e][r-1] == 1)
                counter8++;

                if (grid[e][r+1] == 1)
                counter8++;

                if (grid[e+1][r-1] == 1)
                counter8++;

                if (grid[e+1][r] == 1)
                counter8++;

                if (grid[e+1][r+1] == 1)
                counter8++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter8 << " time " << endl;
            counter8=0;
            }
            }

        }                                                                                           // if ending scope where the grid value is 1
    }
}
step++;
cout << "------------------------------------------" << endl;
cout << setw(22) << "STEP " << step << endl << endl;

// ==> step 4
// In this step we have to apply rules
lastIndex=0;                                                                                    // after applying the rules cells will be changed so we need to icrement
                                                                                                // the index again so we again initilized it with zero
int n=0;                                                                                        // these will be used in printing and printing1 array to increment the size
int newGrid[rows][columns];                                                                     // the newGrid array will be used to store the previous grid
                                                                                                // values as we need to apply the rules for new grid values

int times=0;                                                                                    // this varaible will be used to know that which cells both secondary 
                                                                                                // as well as neighbour are alive after the rules have been applied

int printing[500];                                                                              // this array will be used to store the grid x coordinate as we are  
                                                                                                // concerned with the order of the values after applying the rules

int printing1[500];                                                                             // this array will be used to store the grid y coordinate as we are  
                                                                                                // concerned with the order of the values after applying the rules
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<columns; j++)
        {
            newGrid[i][j] = grid[i][j];                                                        // the old grid values will be copied to newGrid
        }

    }

k=0;
for (int a=0; a<rows; a++)
{
    for (int b=0; b<columns; b++)
    {
        if (newGrid[a][b] == 1)                                                               // as the grid values are copied to new grid so we are using this now
        {
            int count=0;
            secondary[k] = newGrid[a-1][b-1];
            if (newGrid[a-1][b-1] == newGrid[a][b])                                          // if the current secondary grid equal to 1 is equivalent to 
                                                                                             //  other secondary live cells then count 1 othewise don't

            {
                    count++;
            }


            secondary[k++] = newGrid[a-1][b];

            if (newGrid[a-1][b] == newGrid[a][b])
            {

                    count++;
            }

            secondary[k++] = newGrid[a-1][b+1];

            if (newGrid[a-1][b+1] == newGrid[a][b])
            {
                    count++;
            }

            secondary[k++] = newGrid[a][b-1];


            if (newGrid[a][b-1] == newGrid[a][b])
            {
                    count++;
            }

            secondary[k++] = newGrid[a][b+1];


            if (newGrid[a][b+1] == newGrid[a][b])
            {
                    count++;
            }


            secondary[k++] = newGrid[a+1][b-1];


            if (newGrid[a+1][b-1] == newGrid[a][b])
            {
                    count++;
            }


            secondary[k++] = newGrid[a+1][b];


            if (newGrid[a+1][b] == newGrid[a][b])
            {
                    count++;
            }



            secondary[k++] = newGrid[a+1][b+1];


            if (newGrid[a+1][b+1] == newGrid[a][b])
            {
                    count++;
            }

                if (checkifCellIsNotAlive(count) == true)                                                   // function call to check whether the cell is alive or not
                                                                                                          // depending upon the count --> count depends upon rules
                {
                    // changes are going to be done in the grid not the new grid
                    grid[a][b] = 0;
        
                }

                else if (checkifCellIsNotAlive(count) == false)
                {
                            grid[a][b] = 1;
                            printing[n] = a;                                                            // the a basically x coordinate will be stored in the printing array 
                            printing1[n] = b;                                                           // the b basically y coordinate will be stored in the printing1 array
                            lastIndex++;
                cout << "Secondary array live neighbor " << "(" << a << "," << b << ")" << " appearead " << count << " time " << endl;
                times++;                                                                                // if the function condition is true then times needs to be incremented
                n++;                                                                                    // for size incrementation n also needs to be updated 
                }
                
            count =0;                                                                                   // start counting another live neighbor from 0
            k++;

        }
    }
}

int grid4[500][500];
int q=0,w=0;                                                                                                // these variables will be used to assign the secondary array neighbours
int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0;
k=0;
for (int s=0; s<rows; s++)
{
    for (int d=0; d<columns; d++)
    {

        if (newGrid[s][d] == 1) // The false check would make sure that if only runs if the index of i, j has not run before. Now initially the keepTrackArray woukd be 0.
        {
            
            if (checkifCellHasbeenChecked3(s-1, d-1, grid4) == false)
            {
                grid4[s-1][d-1] = 1; // this would make the location i-1 and j-1 to 1

            // applying the formulas
            neighbourHood[k] = newGrid[s-1][d-1];

            q=s-1;
            w=d-1;
            if (newGrid[q][w] == 0)
            {
                if (newGrid[q-1][w-1] == 1)
                    c1++;

                if (newGrid[q-1][w] == 1)
                    c1++;

                if (newGrid[q-1][w+1] == 1)
                    c1++;

                if (newGrid[q][w-1] == 1)
                    c1++;

                if (newGrid[q][w+1] == 1)
                    c1++;

                if (newGrid[q+1][w-1] == 1)
                    c1++;

                if (newGrid[q+1][w] == 1)
                    c1++;

                if (newGrid[q+1][w+1] == 1)
                    c1++;


            if (checkifCellHasExactly3Neighbors(c1) == true)
            {
                
                grid[q][w] = 1;
                printing[n] = q;
                printing1[n] = w;
                lastIndex++;
                times++;                                                                                      // if the function condition is true then times needs to be incremented
                n++;                                                                                          // for size incrementation n also needs to be updated
            cout << "Secondary array live neighbor " << "(" << q << "," << w << ")" << " appearead " << c1 << " time " << endl;
            c1=0;
            }
            else if (checkifCellHasExactly3Neighbors(c1) == false)
            {
                removeAllElementFromNeighborArray(c1,neighbourHood); // function call
                grid[q][w] = 0;
                
            c1=0;
            }

        }

        }
            if (checkifCellHasbeenChecked3(s-1, d, grid4) == false)
            {
                grid4[s-1][d] = 1;

            neighbourHood[k++] = newGrid[s-1][d];
            q=s-1;
            w=d;
            if (newGrid[q][w] == 0)
            {
                if (newGrid[q-1][w-1] == 1)
                    c2++;

                if (newGrid[q-1][w] == 1)
                    c2++;

                if (newGrid[q-1][w+1] == 1)
                    c2++;

                if (newGrid[q][w-1] == 1)
                    c2++;

                if (newGrid[q][w+1] == 1)
                    c2++;

                if (newGrid[q+1][w-1] == 1)
                    c2++;

                if (newGrid[q+1][w] == 1)
                    c2++;

                if (newGrid[q+1][w+1] == 1)
                    c2++;

            if (checkifCellHasExactly3Neighbors(c2) == true)
            {
            
                grid[q][w] = 1;
                printing[n] = q;
                printing1[n] = w;
                lastIndex++;
                times++;
                n++;
            cout << "Secondary array live neighbor " << "(" << q << "," << w << ")" << " appearead " << c2 << " time " << endl;
            c2=0;
            }
            else if (checkifCellHasExactly3Neighbors(c2) == false)
            {
                removeAllElementFromNeighborArray(c2,neighbourHood); // function call
                grid[q][w] = 0;
                
           c2=0;
            }

            }

            }
            if (checkifCellHasbeenChecked3(s-1, d+1, grid4) == false)
            {
                grid4[s-1][d+1] = 1;
            neighbourHood[k++] = newGrid[s-1][d+1];
            q=s-1;
            w=d+1;
            if (newGrid[q][w] == 0)
            {
                if (newGrid[q-1][w-1] == 1)
                    c3++;

                if (newGrid[q-1][w] == 1)
                    c3++;

                if (newGrid[q-1][w+1] == 1)
                    c3++;

                if (newGrid[q][w-1] == 1)
                    c3++;

                if (newGrid[q][w+1] == 1)
                    c3++;

                if (newGrid[q+1][w-1] == 1)
                    c3++;

                if (newGrid[q+1][w] == 1)
                    c3++;

                if (newGrid[q+1][w+1] == 1)
                    c3++;

            if (checkifCellHasExactly3Neighbors(c3) == true)
            {
            
                grid[q][w] = 1;
                printing[n] = q;
                printing1[n] = w;
                lastIndex++;
                times++;
                n++;
            cout << "Secondary array live neighbor " << "(" << q << "," << w << ")" << " appearead " << c3 << " time " << endl;
            c3=0;
            }
            else if (checkifCellHasExactly3Neighbors(c3) == false)
            {
                removeAllElementFromNeighborArray(c3,neighbourHood); // function call
                grid[q][w] = 0;
            
            c3=0;
            }
            
            }

            }
            if (checkifCellHasbeenChecked3(s, d-1, grid4) == false)
            {
                grid4[s][d-1] = 1;
            neighbourHood[k++] = newGrid[s][d-1];
            q=s;
            w=d-1;
            if (newGrid[q][w] == 0)
            {
                if (newGrid[q-1][w-1] == 1)
                    c4++;

                if (newGrid[q-1][w] == 1)
                    c4++;

                if (newGrid[q-1][w+1] == 1)
                    c4++;

                if (newGrid[q][w-1] == 1)
                    c4++;

                if (newGrid[q][w+1] == 1)
                    c4++;

                if (newGrid[q+1][w-1] == 1)
                    c4++;

                if (newGrid[q+1][w] == 1)
                    c4++;

                if (newGrid[q+1][w+1] == 1)
                    c4++;

            if (checkifCellHasExactly3Neighbors(c4) == true)
            {
            
                grid[q][w] = 1;
                printing[n] = q;
                printing1[n] = w;
                lastIndex++;
                times++;
                n++;
            cout << "Secondary array live neighbor " << "(" << q << "," << w << ")" << " appearead " << c4 << " time " << endl;
            c4=0;
            }
            else if (checkifCellHasExactly3Neighbors(c4) == false)
            {
                removeAllElementFromNeighborArray(c4,neighbourHood); // function call
                grid[q][w] = 0;
                
            c4=0;
            }
            }

            }
            if (checkifCellHasbeenChecked3(s, d+1, grid4) == false)
            {
                grid4[s][d+1] = 1;
            neighbourHood[k++] = newGrid[s][d+1];
            q=s;
            w=d+1;
            if (newGrid[q][w] == 0)
            {
                if (newGrid[q-1][w-1] == 1)
                    c5++;

                if (newGrid[q-1][w] == 1)
                    c5++;

                if (newGrid[q-1][w+1] == 1)
                    c5++;

                if (newGrid[q][w-1] == 1)
                    c5++;

                if (newGrid[q][w+1] == 1)
                    c5++;

                if (newGrid[q+1][w-1] == 1)
                    c5++;

                if (newGrid[q+1][w] == 1)
                    c5++;

                if (newGrid[q+1][w+1] == 1)
                    c5++;

            if (checkifCellHasExactly3Neighbors(c5) == true)
            {
                
                grid[q][w] = 1;
                printing[n] = q;
                printing1[n] = w;
                lastIndex++;
                times++;
                n++;
        
            cout << "Secondary array live neighbor " << "(" << q << "," << w << ")" << " appearead " << c5 << " time " << endl;
            c5=0;
            }
            else if (checkifCellHasExactly3Neighbors(c5) == false)
            {
                removeAllElementFromNeighborArray(c5,neighbourHood); // function call
                grid[q][w] = 0;
                   
            c5=0;
            }
            }

            }
            if (checkifCellHasbeenChecked3(s+1, d-1, grid4) == false)
            {
                grid4[s+1][d-1] = 1;
            neighbourHood[k++] = newGrid[s+1][d-1];
            q=s+1;
            w=d-1;
            if (newGrid[q][w] == 0)
            {
                if (newGrid[q-1][w-1] == 1)
                    c6++;

                if (newGrid[q-1][w] == 1)
                    c6++;

                if (newGrid[q-1][w+1] == 1)
                    c6++;

                if (newGrid[q][w-1] == 1)
                    c6++;

                if (newGrid[q][w+1] == 1)
                    c6++;

                if (newGrid[q+1][w-1] == 1)
                    c6++;

                if (newGrid[q+1][w] == 1)
                    c6++;

                if (newGrid[q+1][w+1] == 1)
                    c6++;

            if (checkifCellHasExactly3Neighbors(c6) == true)
            {
            
                grid[q][w] = 1;
                printing[n] = q;
                printing1[n] = w;
                lastIndex++;
                times++;
                n++;
            
            cout << "Secondary array live neighbor " << "(" << q << "," << w << ")" << " appearead " << c6 << " time " << endl;
            c6=0;
            }
            else if (checkifCellHasExactly3Neighbors(c6) == false)
            {
                removeAllElementFromNeighborArray(c6,neighbourHood); // function call
                grid[q][w] = 0;
                
            
            c6=0;
            }
            }

            }
            if (checkifCellHasbeenChecked3(s+1, d, grid4) == false)
            {
                grid4[s+1][d] = 1;
            neighbourHood[k++] = newGrid[s+1][d];
            q=s+1;
            w=d;
            if (newGrid[q][w] == 0)
            {
                if (newGrid[q-1][w-1] == 1)
                    c7++;

                if (newGrid[q-1][w] == 1)
                    c7++;

                if (newGrid[q-1][w+1] == 1)
                    c7++;

                if (newGrid[q][w-1] == 1)
                    c7++;

                if (newGrid[q][w+1] == 1)
                    c7++;

                if (newGrid[q+1][w-1] == 1)
                    c7++;

                if (newGrid[q+1][w] == 1)
                    c7++;

                if (newGrid[q+1][w+1] == 1)
                    c7++;
            if (checkifCellHasExactly3Neighbors(c7) == true)
            {
                
                grid[q][w] = 1;
                printing[n] = q;
                printing1[n] = w;
                lastIndex++;
                times++;
                n++;
                
            cout << "Secondary array live neighbor " << "(" << q << "," << w << ")" << " appearead " << c7 << " time " << endl;
            c7=0;
            }
            else if (checkifCellHasExactly3Neighbors(c7) == false)
            {
                removeAllElementFromNeighborArray(c7,neighbourHood); // function call
                grid[q][w] = 0;
                
            c7=0;
            }
            }

            }
            if (checkifCellHasbeenChecked3(s+1, d+1, grid4) == false)
            {
                grid4[s+1][d+1] = 1;
            neighbourHood[k++] = newGrid[s+1][d+1];
            q=s+1;
            w=d+1;
            if (newGrid[q][w] == 0)
            {
                if (newGrid[q-1][w-1] == 1)
                    c8++;

                if (newGrid[q-1][w] == 1)
                    c8++;

                if (newGrid[q-1][w+1] == 1)
                    c8++;

                if (newGrid[q][w-1] == 1)
                    c8++;

                if (newGrid[q][w+1] == 1)
                    c8++;

                if (newGrid[q+1][w-1] == 1)
                    c8++;

                if (newGrid[q+1][w] == 1)
                    c8++;

                if (newGrid[q+1][w+1] == 1)
                    c8++;
            if (checkifCellHasExactly3Neighbors(c8) == true)
            {
    
                grid[q][w] = 1;
                printing[n] = q;
                printing1[n] = w;
                lastIndex++;
                times++;
                n++;
                
            cout << "Secondary array live neighbor " << "(" << q << "," << w << ")" << " appearead " << c8 << " time " << endl;
            c8=0;
            }
            else if (checkifCellHasExactly3Neighbors(c8) == false)
            {
                removeAllElementFromNeighborArray(c8,neighbourHood); // function call
                grid[q][w] = 0;
                
            c8=0;
            }

            }

            }

        k++;
        }

    }

}
cout << endl;
generation++;
        cout << setw(85) << " GENERATION " << generation << endl;
        cout << setw(121);
        cout << "________________________________________________________________________________" << endl;
        cout << setw(42);
        for (int i=0; i<rows; i++)
        {
		cout << "|";
            for (int j=0; j<columns; j++)
            {
            	
		
                cout << grid[i][j] <<  " | ";

            }
                cout << endl;
                cout <<  setw(42) << "|";
                cout << setw(71);
                cout << "__|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|" << endl;
                cout << setw(42);

        }
        cout << endl;
cout << setw(0);

ofstream fileName4("initial.txt");
ifstream fileName5("initial.txt");
int time=0;
int printing2[500], printing3[500];                                                     // this will be used when neighbourHood array has exactly 3 counts
cout << "The last index of secondary array is: " << lastIndex-1 << endl;
// --> step 5

for (int loopForGeneration=generation; loopForGeneration<gene; loopForGeneration++)     // this loop is for generations greater than 2
{
    cout << "Generation " << loopForGeneration << endl;				   // this will display the generation that the loop is running
if (loopForGeneration > 1)
    {
        string read;								           // a string variable to read from the file object
        int convert1,convert2;							   // these variables will be used to store the coordinate values
        for (int k=0; k<times; k++)
        {
                    fileName5 >> read;
                    convert1 = stoi(read);						   // the stoi function will convert the variable to integer
                    fileName5 >> read;
                    convert2 = stoi(read);						   // the stoi function will convert the variable to integer
                    printing[k] = convert1;
                    printing1[k] = convert2;
        
        }  
        
    
    }
    
step++;
cout << "------------------------------------------" << endl;
cout << setw(22) << "STEP " << step << endl << endl;

int grid5[500][500];


for (int initialCount =0 ; initialCount< 500; initialCount++) {
    for (int initialCountJ=0; initialCountJ < 500; initialCountJ++) {
        grid5[initialCount][initialCountJ] = 0;
    }
}


k=0;

for (int n=0; n<times; n++)
{
for (int i=0; i<rows; i++)
{                                                                                                                       
    for (int j=0; j<columns; j++)
{    
    
        if (printing[n] == i && printing1[n] == j) // The false check would make sure that if only runs if the index of i, j has not run before. Now initially the keepTrackArray woukd be 0.
        {

            cout << " Dead cells of live cells " << "(" << i << "," << j << ")" << "are: " << endl;
            if (checkifCellHasbeenChecked4(i-1, j-1, grid5) == false)
        {
                grid5[i-1][j-1] = 1; // this would make the location i-1 and j-1 to 1

            // applying the formulas
            neighbourHood[k] = grid[i-1][j-1];


            if (grid[i-1][j-1] == 0)
            {
                    cout << "(" << i-1 << "," << j-1 << ")" << endl;
            }
        }

            if (checkifCellHasbeenChecked4(i-1, j, grid5) == false)
        {
            grid5[i-1][j] = 1;
            neighbourHood[k++] = grid[i-1][j];
            if (grid[i-1][j] == 0)
            {
                    cout << "(" << i-1 << "," << j << ")" << endl;

            }
        }

            if (checkifCellHasbeenChecked4(i-1, j+1, grid5) == false)
        {
            grid5[i-1][j+1] = 1;
            neighbourHood[k++] = grid[i-1][j+1];

            if (grid[i-1][j+1] == 0)
            {
                    cout << "(" << i-1 << "," << j+1 << ")" << endl;
            }
        }

            if (checkifCellHasbeenChecked4(i, j-1, grid5) == false)
        {
            grid5[i][j-1] = 1;
            neighbourHood[k++] = grid[i][j-1];


            if (grid[i][j-1] == 0)
            {
                    cout << "(" << i << "," << j-1 << ")" << endl;
            }
        }

            if (checkifCellHasbeenChecked4(i, j+1, grid5) == false)
        {
            grid5[i][j+1] = 1;
            neighbourHood[k++] = grid[i][j+1];


            if (grid[i][j+1] == 0)
            {
                    cout << "(" << i << "," << j+1 << ")" << endl;
            }
        }

            if (checkifCellHasbeenChecked4(i+1, j-1, grid5) == false)
        {
            grid5[i+1][j-1] = 1;
            neighbourHood[k++] = grid[i+1][j-1];


            if (grid[i+1][j-1] == 0)
            {
                    cout << "(" << i+1 << "," << j-1 << ")" << endl;
            }
        }

            if (checkifCellHasbeenChecked4(i+1, j, grid5) == false)
        {
            grid5[i+1][j] = 1;
            neighbourHood[k++] = grid[i+1][j];


            if (grid[i+1][j] == 0)
            {
                    cout << "(" << i+1 << "," << j << ")" << endl;
            }
        }

            if (checkifCellHasbeenChecked4(i+1, j+1, grid5) == false)
        {
            grid5[i+1][j+1] = 1;
            neighbourHood[k++] = grid[i+1][j+1];


            if (grid[i+1][j+1] == 0)
            {
                    cout << "(" << i+1 << "," << j+1 << ")" << endl;
            }

        }
	k++;
        }
    }
}       
}   

// --> step 6
step++;
cout << "------------------------------------------" << endl;
cout << setw(22) << "STEP " << step << endl << endl;
// In this step we have to count neighbours (live only)
// of secondary array and neighbourHood array

k=0;
for (int n=0; n<times; n++)
{
for (int a=0; a<rows; a++)
{
    for (int b=0; b<columns; b++)
    {
        if (printing[n] == a && printing1[n] == b)
        {
                int count=0;                        // initially count is 0
            neighbourHood[k] = grid[a-1][b-1];
            if (grid[a-1][b-1] == grid[a][b])       // if the current secondary grid is equal to the neighbor then count 1 othewise don't
            {
                    count++;
            }


            neighbourHood[k++] = grid[a-1][b];

            if (grid[a-1][b] == grid[a][b])
            {

                    count++;
            }

            neighbourHood[k++] = grid[a-1][b+1];

            if (grid[a-1][b+1] == grid[a][b])
            {
                    count++;
            }

            neighbourHood[k++] = grid[a][b-1];


            if (grid[a][b-1] == grid[a][b])
            {
                    count++;
            }

            neighbourHood[k++] = grid[a][b+1];


            if (grid[a][b+1] == grid[a][b])
            {
                    count++;
            }


            neighbourHood[k++] = grid[a+1][b-1];


            if (grid[a+1][b-1] == grid[a][b])
            {
                    count++;
            }


            neighbourHood[k++] = grid[a+1][b];


            if (grid[a+1][b] == grid[a][b])
            {
                    count++;
            }



            neighbourHood[k++] = grid[a+1][b+1];


            if (grid[a+1][b+1] == grid[a][b])
            {
                    count++;
            }

            cout << "Secondary array live neighbor " << "(" << a << "," << b << ")" << " appearead ";
            cout << count << " time " << endl;
        }
        k++;
    }
}
}
cout << endl;
// now count live neighbors of neighborHood array
counter1=0, counter2=0, counter3=0, counter4=0, counter5=0, counter6=0, counter7=0, counter8=0;
int grid6[500][500];
for (int initialCount =0 ; initialCount< 500; initialCount++) {
    for (int initialCountJ=0; initialCountJ < 500; initialCountJ++) {
        grid6[initialCount][initialCountJ] = 0;
    }
}
e=0,r=0;
k=0;
for (int n=0; n<times; n++)
{
for (int s=0; s<rows; s++)
{
    for (int d=0; d<columns; d++)
    {

        if (printing[n] == s && printing1[n] == d) // The false check would make sure that if only runs if the index of i, j has not run before. Now initially the keepTrackArray woukd be 0.
        {

            if (checkifCellHasbeenChecked5(s-1, d-1, grid6) == false)
        {
                grid6[s-1][d-1] = 1; // this would make the location i-1 and j-1 to 1

            // applying the formulas
            neighbourHood[k] = grid[s-1][d-1];

            e=s-1;
            r=d-1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                    counter1++;

                if (grid[e-1][r] == 1)
                    counter1++;

                if (grid[e-1][r+1] == 1)
                    counter1++;

                if (grid[e][r-1] == 1)
                    counter1++;

                if (grid[e][r+1] == 1)
                    counter1++;

                if (grid[e+1][r-1] == 1)
                    counter1++;

                if (grid[e+1][r] == 1)
                    counter1++;

                if (grid[e+1][r+1] == 1)
                    counter1++;



            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter1 << " time " << endl;
            counter1=0;
        }
        }
            if (checkifCellHasbeenChecked5(s-1, d, grid6) == false)
        {
            grid6[s-1][d] = 1;

            neighbourHood[k++] = grid[s-1][d];
            e=s-1;
            r=d;
            if (grid[e][r] == 0)
            {
                    if (grid[e-1][r-1] == 1)
                    counter2++;

                if (grid[e-1][r] == 1)
                    counter2++;

                if (grid[e-1][r+1] == 1)
                    counter2++;

                if (grid[e][r-1] == 1)
                    counter2++;

                if (grid[e][r+1] == 1)
                    counter2++;

                if (grid[e+1][r-1] == 1)
                    counter2++;

                if (grid[e+1][r] == 1)
                    counter2++;

                if (grid[e+1][r+1] == 1)
                    counter2++;


            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter2 << " time " << endl;
            counter2=0;
            }
            }
            if (checkifCellHasbeenChecked5(s-1, d+1, grid6) == false)
        {
            grid6[s-1][d+1] = 1;
            neighbourHood[k++] = grid[s-1][d+1];
            e=s-1;
            r=d+1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                    counter3++;

                if (grid[e-1][r] == 1)
                    counter3++;

                if (grid[e-1][r+1] == 1)
                    counter3++;

                if (grid[e][r-1] == 1)
                    counter3++;

                if (grid[e][r+1] == 1)
                    counter3++;

                if (grid[e+1][r-1] == 1)
                    counter3++;

                if (grid[e+1][r] == 1)
                    counter3++;

                if (grid[e+1][r+1] == 1)
                    counter3++;


            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter3 << " time " << endl;
            counter3=0;
            }
            }
            if (checkifCellHasbeenChecked5(s, d-1, grid6) == false)
        {
            grid6[s][d-1] = 1;
            neighbourHood[k++] = grid[s][d-1];
            e=s;
            r=d-1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                    counter4++;

                if (grid[e-1][r] == 1)
                    counter4++;

                if (grid[e-1][r+1] == 1)
                    counter4++;

                if (grid[e][r-1] == 1)
                    counter4++;

                if (grid[e][r+1] == 1)
                    counter4++;

                if (grid[e+1][r-1] == 1)
                    counter4++;

                if (grid[e+1][r] == 1)
                    counter4++;

                if (grid[e+1][r+1] == 1)
                    counter4++;


            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter4 << " time " << endl;
            counter4=0;
            }
            }
            if (checkifCellHasbeenChecked5(s, d+1, grid6) == false)
        {
            grid6[s][d+1] = 1;
            neighbourHood[k++] = grid[s][d+1];
            e=s;
            r=d+1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                    counter5++;

                if (grid[e-1][r] == 1)
                    counter5++;

                if (grid[e-1][r+1] == 1)
                    counter5++;

                if (grid[e][r-1] == 1)
                    counter5++;

                if (grid[e][r+1] == 1)
                    counter5++;

                if (grid[e+1][r-1] == 1)
                    counter5++;

                if (grid[e+1][r] == 1)
                    counter5++;

                if (grid[e+1][r+1] == 1)
                    counter5++;


            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter5 << " time " << endl;
            counter5=0;
            }
            }
            if (checkifCellHasbeenChecked5(s+1, d-1, grid6) == false)
        {
            grid6[s+1][d-1] = 1;
            neighbourHood[k++] = grid[s+1][d-1];
            e=s+1;
            r=d-1;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                    counter6++;

                if (grid[e-1][r] == 1)
                    counter6++;

                if (grid[e-1][r+1] == 1)
                    counter6++;

                if (grid[e][r-1] == 1)
                    counter6++;

                if (grid[e][r+1] == 1)
                    counter6++;

                if (grid[e+1][r-1] == 1)
                    counter6++;

                if (grid[e+1][r] == 1)
                    counter6++;

                if (grid[e+1][r+1] == 1)
                    counter6++;


            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter6 << " time " << endl;
            counter6=0;
            }
            }
            if (checkifCellHasbeenChecked5(s+1, d, grid6) == false)
        {
            grid6[s+1][d] = 1;
            neighbourHood[k++] = grid[s+1][d];
            e=s+1;
            r=d;
            if (grid[e][r] == 0)
            {
                if (grid[e-1][r-1] == 1)
                    counter7++;

                if (grid[e-1][r] == 1)
                    counter7++;

                if (grid[e-1][r+1] == 1)
                    counter7++;

                if (grid[e][r-1] == 1)
                    counter7++;

                if (grid[e][r+1] == 1)
                    counter7++;

                if (grid[e+1][r-1] == 1)
                    counter7++;

                if (grid[e+1][r] == 1)
                    counter7++;

                if (grid[e+1][r+1] == 1)
                    counter7++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter7 << " time " << endl;
            counter7=0;
            }
            }
            if (checkifCellHasbeenChecked5(s+1, d+1, grid6) == false)
        {
            grid6[s+1][d+1] = 1;
            neighbourHood[k++] = grid[s+1][d+1];
            e=s+1;
            r=d+1;
            if (grid[e][r] == 0)
            {
                    if (grid[e-1][r-1] == 1)
                    counter8++;

                if (grid[e-1][r] == 1)
                    counter8++;

                if (grid[e-1][r+1] == 1)
                    counter8++;

                if (grid[e][r-1] == 1)
                    counter8++;

                if (grid[e][r+1] == 1)
                    counter8++;

                if (grid[e+1][r-1] == 1)
                    counter8++;

                if (grid[e+1][r] == 1)
                    counter8++;

                if (grid[e+1][r+1] == 1)
                    counter8++;

            cout << "Nei-array " << "(" << e << "," << r << ")" << " live cell "  << " appeared " << counter8 << " time " << endl;
            counter8=0;
            }
            }

        }
    k++;
    }
}

}
cout << endl;
// this for loop is to initilize all the newGrid values to 0 initially to avoid any errors
for (int i=0; i<rows; i++)
{
    for (int j=0; j<columns; j++)
    {
        newGrid[i][j] = 0;
    }
}    
// --> step 7
step++;
lastIndex=0;
cout << "------------------------------------------" << endl;
cout << setw(22) << "STEP " << step << endl << endl;
// In this step we have to apply rules
// we need the secondary array first to apply the rules

for (int a =0; a< 500; a++) 							// copying the old values to another array
{
        printing2[a] = printing[a];
        printing3[a] = printing1[a];
}

time=0;
int k1=0;									// this varaible is for the count of those values that will be used in the next generation
k=0;
for (int n=0; n<times; n++)
{
for (int i=0; i<rows; i++)
{
    for (int j=0; j<columns; j++)
    {
       
        if (printing2[n] == i && printing3[n] == j)
        {
        	
            int coUnt=0;
            
            neighbourHood[k] = grid[i-1][j-1];
            if (grid[i-1][j-1] == grid[i][j])       // if the current secondary grid is equal to the neighbor then count 1 othewise don't
            {
                    coUnt++;
            }


            neighbourHood[k++] = grid[i-1][j];

            if (grid[i-1][j] == grid[i][j])
            {

                    coUnt++;
            }

            neighbourHood[k++] = grid[i-1][j+1];

            if (grid[i-1][j+1] == grid[i][j])
            {
                    coUnt++;
            }

            neighbourHood[k++] = grid[i][j-1];


            if (grid[i][j-1] == grid[i][j])
            {
                    coUnt++;
            }

            neighbourHood[k++] = grid[i][j+1];


            if (grid[i][j+1] == grid[i][j])
            {
                    coUnt++;
            }


            neighbourHood[k++] = grid[i+1][j-1];


            if (grid[i+1][j-1] == grid[i][j])
            {
                    coUnt++;
            }


            neighbourHood[k++] = grid[i+1][j];


            if (grid[i+1][j] == grid[i][j])
            {
                    coUnt++;
            }


            neighbourHood[k++] = grid[i+1][j+1];


            if (grid[i+1][j+1] == grid[i][j])
            {
                    coUnt++;
            }
                
               if (checkifCellIsAlive2(coUnt) == true)         // function call
                {
                  newGrid[i][j] = 0;
                }

                else if (checkifCellIsAlive2(coUnt) == false)
                {
                           newGrid[i][j] = 1;
                            printing[k1] = i;
                            printing1[k1] = j;
                            k1++;
                            fileName4 << i << " " <<  j << endl;
                            time++;
                           lastIndex++;
                            cout << "Secondary array live neighbor " << "(" << i << "," << j << ")" << " appearead ";
                            cout << coUnt << " time " << endl;
                                if (loopForGeneration >= gene-1)
                                {
                                    outputCount++;
                                }
                                else 
                                {
                                    outputCount=0;
                                }
                                
                }
            
            coUnt =0; // start counting another live neighbor from 0
            k++;

        }
        }
    
}
}

int grid7[500][500];
for (int initialCount =0 ; initialCount< 500; initialCount++) {
    for (int initialCountJ=0; initialCountJ < 500; initialCountJ++) {
        grid7[initialCount][initialCountJ] = 0;
    }
}


c1=0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0;
k=0;

int k2=k1;									// to avoid errors made another varaible to store the previous k1 value
int z=0,x=0;
for (int n=0; n<times; n++)
{
for (int s=0; s<rows; s++)
{
    for (int d=0; d<columns; d++)
    {
        if (printing2[n] == s && printing3[n] == d) // The false check would make sure that if only runs if the index of i, j has not run before. Now initially the keepTrackArray woukd be 0.
        {
            if (checkifCellHasbeenChecked6(s-1, d-1, grid7) == false)
            {
            grid7[s-1][d-1] = 1;
            neighbourHood[k] = grid[s-1][d-1];
            z=s-1;
            x=d-1;
            if (grid[z][x] == 0)
            {
                
                    if (grid[z-1][x-1] == 1)
                    c1++;

                if (grid[z-1][x] == 1)
                    c1++;

                if (grid[z-1][x+1] == 1)
                    c1++;

                if (grid[z][x-1] == 1)
                    c1++;

                if (grid[z][x+1] == 1)
                    c1++;

                if (grid[z+1][x-1] == 1)
                    c1++;

                if (grid[z+1][x] == 1)
                    c1++;

                if (grid[z+1][x+1] == 1)
                    c1++;
                    
            if (checkifCellHasExactly3Neighbors(c1) == true)
            {
    
                newGrid[z][x] = 1;
                k2++;
                printing[k2] = z;
                printing1[k2] = x;
                time++;									// this is being used to see the count of live cells
                fileName4 << z << " " <<  x << endl;
            cout << "Secondary array live neighbor " << "(" << z << "," << x << ")" << " appearead " << c1 << " time " << endl;
            lastIndex++;
            if (loopForGeneration >= gene-1)
            {
            outputCount++;
            }
            else
                                {
                                    outputCount=0;
                                }
                                c1=0;
            }
            else if (checkifCellHasExactly3Neighbors(c1) == false)
            {
                removeAllElementFromNeighborArray2(c1,neighbourHood); // function call
                newGrid[z][x] = 0;
 
            c1=0;
            }

            }
            
            }
            if (checkifCellHasbeenChecked6(s-1, d, grid7) == false)
        {
            grid7[s-1][d] = 1;

            neighbourHood[k++] = grid[s-1][d];
            z=s-1;
            x=d;
            if (grid[z][x] == 0)
            {
                    if (grid[z-1][x-1] == 1)
                    c2++;

                if (grid[z-1][x] == 1)
                    c2++;

                if (grid[z-1][x+1] == 1)
                    c2++;

                if (grid[z][x-1] == 1)
                    c2++;

                if (grid[z][x+1] == 1)
                    c2++;

                if (grid[z+1][x-1] == 1)
                    c2++;

                if (grid[z+1][x] == 1)
                    c2++;

                if (grid[z+1][x+1] == 1)
                    c2++;

            if (checkifCellHasExactly3Neighbors(c2) == true)
            {
            
                newGrid[z][x] = 1;
                k2++;
                printing[k2] = z;
                printing1[k2] = x;
                time++;
                fileName4 << z << " " <<  x << endl;
                
            cout << "Secondary array live neighbor " << "(" << z << "," << x << ")" << " appearead " << c2 << " time " << endl;
            lastIndex++;
            if (loopForGeneration >= gene-1)
                {
                outputCount++;
                }
                else
                                {
                                    outputCount=0;
                                }
                                c2=0;
            }
            else if (checkifCellHasExactly3Neighbors(c2) == false)
            {
                removeAllElementFromNeighborArray2(c2,neighbourHood); // function call
                newGrid[z][x] = 0;
                
            c2=0;
            }
            }
            

            }
            if (checkifCellHasbeenChecked6(s-1, d+1, grid7) == false)
        {
            grid7[s-1][d+1] = 1;
            neighbourHood[k++] = grid[s-1][d+1];
            z=s-1;
            x=d+1;
            if (grid[z][x] == 0)
            {
                if (grid[z-1][x-1] == 1)
                    c3++;

                if (grid[z-1][x] == 1)
                    c3++;

                if (grid[z-1][x+1] == 1)
                    c3++;

                if (grid[z][x-1] == 1)
                    c3++;

                if (grid[z][x+1] == 1)
                    c3++;

                if (grid[z+1][x-1] == 1)
                    c3++;

                if (grid[z+1][x] == 1)
                    c3++;

                if (grid[z+1][x+1] == 1)
                    c3++;

            if (checkifCellHasExactly3Neighbors(c3) == true)
            {
            
                newGrid[z][x] = 1;
                k2++;
                printing[k2] = z;
                printing1[k2] = x;
                time++;
                fileName4 << z << " " <<  x << endl;
                
            cout << "Secondary array live neighbor " << "(" << z << "," << x << ")" << " appearead " << c3 << " time " << endl;
            lastIndex++;
            if (loopForGeneration >= gene-1)
                {
                outputCount++;
                }
                else
                                {
                                    outputCount=0;
                                }
            c3=0;
            }
            else if (checkifCellHasExactly3Neighbors(c3) == false)
            {
                removeAllElementFromNeighborArray2(c3,neighbourHood); // function call
                newGrid[z][x] = 0;
            
            c3=0;
            }
            
            }

            }
            if (checkifCellHasbeenChecked6(s, d-1, grid7) == false)
        {
            grid7[s][d-1] = 1;
            neighbourHood[k++] = grid[s][d-1];
            z=s;
            x=d-1;
            if (grid[z][x] == 0)
            {
                if (grid[z-1][x-1] == 1)
                    c4++;

                if (grid[z-1][x] == 1)
                    c4++;

                if (grid[z-1][x+1] == 1)
                    c4++;

                if (grid[z][x-1] == 1)
                    c4++;

                if (grid[z][x+1] == 1)
                    c4++;

                if (grid[z+1][x-1] == 1)
                    c4++;

                if (grid[z+1][x] == 1)
                    c4++;

                if (grid[z+1][x+1] == 1)
                    c4++;

            if (checkifCellHasExactly3Neighbors(c4) == true)
            {
            
                newGrid[z][x] = 1;
                k2++;
                printing[k2] = z;
                printing1[k2] = x;
                time++;
                fileName4 << z << " " <<  x << endl;
                
            cout << "Secondary array live neighbor " << "(" << z << "," << x << ")" << " appearead " << c4 << " time " << endl;
            lastIndex++;
            if (loopForGeneration >= gene-1)
                {
                outputCount++;
                }
                else
                                {
                                    outputCount=0;
                                }
            c4=0;
            }
            else if (checkifCellHasExactly3Neighbors(c4) == false)
            {
                removeAllElementFromNeighborArray2(c4,neighbourHood); // function call
                newGrid[z][x] = 0;
                
            c4=0;
            }
            
            }

            }
            if (checkifCellHasbeenChecked6(s, d+1, grid7) == false)
        {
            grid7[s][d+1] = 1;
            neighbourHood[k++] = grid[s][d+1];
            z=s;
            x=d+1;
            if (grid[z][x] == 0)
            {
                if (grid[z-1][x-1] == 1)
                    c5++;

                if (grid[z-1][x] == 1)
                    c5++;

                if (grid[z-1][x+1] == 1)
                    c5++;

                if (grid[z][x-1] == 1)
                    c5++;

                if (grid[z][x+1] == 1)
                    c5++;

                if (grid[z+1][x-1] == 1)
                    c5++;

                if (grid[z+1][x] == 1)
                    c5++;

                if (grid[z+1][x+1] == 1)
                    c5++;

            if (checkifCellHasExactly3Neighbors(c5) == true)
            {
                
                newGrid[z][x] = 1;
                k2++;
                printing[k2] = z;
                printing1[k2] = x;
                time++;
                fileName4 << z << " " <<  x << endl;
                
            cout << "Secondary array live neighbor " << "(" << z << "," << x << ")" << " appearead " << c5 << " time " << endl;
            lastIndex++;
            if (loopForGeneration >= gene-1)
                {
                outputCount++;
                }
                else
                                {
                                    outputCount=0;
                                }
            			c5=0;
            }
            else if (checkifCellHasExactly3Neighbors(c5) == false)
            {
                removeAllElementFromNeighborArray2(c5,neighbourHood); // function call
                newGrid[z][x] = 0;
                   
    
            c5=0;
            }
            
            }

            }
            if (checkifCellHasbeenChecked6(s+1, d-1, grid7) == false)
        {
            grid7[s+1][d-1] = 1;
            neighbourHood[k++] = grid[s+1][d-1];
            z=s+1;
            x=d-1;
            if (grid[z][x] == 0)
            {
                if (grid[z-1][x-1] == 1)
                    c6++;

                if (grid[z-1][x] == 1)
                    c6++;

                if (grid[z-1][x+1] == 1)
                    c6++;

                if (grid[z][x-1] == 1)
                    c6++;

                if (grid[z][x+1] == 1)
                    c6++;

                if (grid[z+1][x-1] == 1)
                    c6++;

                if (grid[z+1][x] == 1)
                    c6++;

                if (grid[z+1][x+1] == 1)
                    c6++;

            if (checkifCellHasExactly3Neighbors(c6) == true)
            {
            
                newGrid[z][x] = 1;
                k2++;
                printing[k2] = z;
                printing1[k2] = x;
                time++;
                fileName4 << z << " " <<  x << endl;
                
            cout << "Secondary array live neighbor " << "(" << z << "," << x << ")" << " appearead " << c6 << " time " << endl;
            lastIndex++;
            if (loopForGeneration >= gene-1)
                {
                outputCount++;
                }
                else
                                {
                                    outputCount=0;
                                }
                                c6=0;
            }
            else if (checkifCellHasExactly3Neighbors(c6) == false)
            {
                removeAllElementFromNeighborArray2(c6,neighbourHood); // function call
                newGrid[z][x] = 0;
                
            c6=0;
            }
            
            }

            }
            if (checkifCellHasbeenChecked6(s+1, d, grid7) == false)
        {
            grid7[s+1][d] = 1;
            neighbourHood[k++] = grid[s+1][d];
            z=s+1;
            x=d;
            if (grid[z][x] == 0)
            {
                if (grid[z-1][x-1] == 1)
                    c7++;

                if (grid[z-1][x] == 1)
                    c7++;

                if (grid[z-1][x+1] == 1)
                    c7++;

                if (grid[z][x-1] == 1)
                    c7++;

                if (grid[z][x+1] == 1)
                    c7++;

                if (grid[z+1][x-1] == 1)
                    c7++;

                if (grid[z+1][x] == 1)
                    c7++;

                if (grid[z+1][x+1] == 1)
                    c7++;
            if (checkifCellHasExactly3Neighbors(c7) == true)
            {
                
                newGrid[z][x] = 1;
                k2++;
                printing[k2] = z;
                printing1[k2] = x;
                time++;
                fileName4 << z << " " <<  x << endl;
                
            cout << "Secondary array live neighbor " << "(" << z << "," << x << ")" << " appearead " << c7 << " time " << endl;
            lastIndex++;
            if (loopForGeneration >= gene-1)
                {
                outputCount++;
                }
                else
                                {
                                    outputCount=0;
                                }
                                c7=0;
            }
            else if (checkifCellHasExactly3Neighbors(c7) == false)
            {
                removeAllElementFromNeighborArray2(c7,neighbourHood); // function call
                newGrid[z][x] = 0;
                
                
            c7=0;
            }
            
            }

            }
            if (checkifCellHasbeenChecked6(s+1, d+1, grid7) == false)
        {
            grid7[s+1][d+1] = 1;
            neighbourHood[k++] = grid[s+1][d+1];
            z=s+1;
            x=d+1;
            if (grid[z][x] == 0)
            {
                    if (grid[z-1][x-1] == 1)
                    c8++;

                if (grid[z-1][x] == 1)
                    c8++;

                if (grid[z-1][x+1] == 1)
                    c8++;

                if (grid[z][x-1] == 1)
                    c8++;

                if (grid[z][x+1] == 1)
                    c8++;

                if (grid[z+1][x-1] == 1)
                    c8++;

                if (grid[z+1][x] == 1)
                    c8++;

                if (grid[z+1][x+1] == 1)
                    c8++;
            if (checkifCellHasExactly3Neighbors(c8) == true)
            {
    
                newGrid[z][x] = 1;
                k2++;
                printing[k2] = z;
                printing1[k2] = x;
                time++;
                fileName4 << z << " " <<  x << endl;
                
            cout << "Secondary array live neighbor " << "(" << z << "," << x << ")" << " appearead " << c8 << " time " << endl;
            lastIndex++;
            if (loopForGeneration >= gene-1)
                {
                outputCount++;
                }
                else
                                {
                                    outputCount=0;
                                }
                                c8=0;
            }
            else if (checkifCellHasExactly3Neighbors(c8) == false)
            {
                removeAllElementFromNeighborArray2(c8,neighbourHood); // function call
                newGrid[z][x] = 0;
                
            c8=0;
            }
            
            }

            }

        k++;
        }
        }
    }

}
times = time;                                                       // it started from 1 not 0 the time 
cout << endl;
generation++;

        cout << setw(85) << " GENERATION " << generation << endl;
        cout << setw(121);
        cout << "________________________________________________________________________________" << endl;
        cout << setw(42);
        for (int i=0; i<rows; i++)
        {
		cout << "|";
            for (int j=0; j<columns; j++)
            {
            	
		
                cout << newGrid[i][j] <<  " | ";

            }
                cout << endl;
                cout <<  setw(42) << "|";
                cout << setw(71);
                cout << "__|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|" << endl;
                cout << setw(42);

        }
        cout << endl;

cout << setw(0);
cout << "The last index of secondary array is: " << lastIndex-1 << endl;
cout << setw(0);
for (int i=0; i<rows; i++)
{
    for (int j=0; j<columns; j++)
    {
        grid[i][j] = newGrid[i][j];
    }
}
}

step++;
cout << "------------------------------------------" << endl;
cout << setw(22) << "STEP " << step << endl << endl;
ofstream fileName2("output.txt");
cout << "The output txt file is as follows: " << endl;

    while (!fileName2.eof())
    {
        fileName2 << generation << endl;
        cout << generation << "  <- number of generations " << endl;
        break;
    }

    while (!fileName2.eof())
    {
        fileName2 << outputCount << endl;
        cout << outputCount << "   <- number of live cells " << endl;
        break;
    }
    
        for (int n=0; n<=times; n++)
        {    
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<columns; j++)
            {
                if (grid[i][j] == 1)
                {
                if (printing[n] == i && printing1[n] == j)
                {
                        fileName2 << i << " " << j << endl;           // getting the grid pattern from the file
                        cout << i << " " << j << endl;
                }
                }   
                }
            }
        }
        
        

} // file reading ending scope


bool checkifCellHasbeenChecked6(int s, int d, int grid7[500][500]) // returns true if cellToCheck for example(3,2) is present in neighborhood array, else it would return false which means it was not existed before
{
    if (grid7[s][d] == 1)
    {
        return true;
    }

    else
    {
    return false;
    }
}

bool checkifCellHasbeenChecked5(int s, int d, int grid6[500][500]) // returns true if cellToCheck for example(3,2) is present in neighborhood array, else it would return false which means it was not existed before
{
    if (grid6[s][d] == 1)
    {
        return true;
    }

    else
    {
    return false;
    }
}


bool checkifCellHasbeenChecked4(int s, int d, int grid5[500][500]) // returns true if cellToCheck for example(3,2) is present in neighborhood array, else it would return false which means it was not existed before
{
    if (grid5[s][d] == 1)
    {
        return true;
    }

    else
    {
    return false;
    }
}


// function for step 2
bool checkifCellHasbeenChecked(int i, int j, int grid2[500][500]) // returns true if cellToCheck for example(3,2) is present in neighborhood array, else it would return false which means it was not existed before
{
    if (grid2[i][j] == 1)
    {
        return true;
    }

    else
    {
    return false;
    }
}
// function for step 3
bool checkifCellHasbeenChecked2(int s, int d, int grid3[500][500]) // returns true if cellToCheck for example(3,2) is present in neighborhood array, else it would return false which means it was not existed before
{
    if (grid3[s][d] == 1)
    {
        return true;
    }

    else
    {
    return false;
    }
}
// 3 functions for step 4
//--> 1
// according to the rules if count is less than 2 and greater than 3 then return true which means the cell becomes 0
bool checkifCellIsAlive2(int counter)
{
    if (counter > 3 || counter < 2)
    {

        return true;
    }
    else
    {
        return false;
    }
}
// according to the rules if count is less than 2 and greater than 3 then return true which means the cell becomes 0
bool checkifCellIsNotAlive(int count)
{
    if (count < 2 || count > 3)
    {

        return true;
    }
    else
    {
        return false; // means alive
    }
}
// --> 2
bool checkifCellHasbeenChecked3(int s, int d, int grid4[500][500]) // returns true if cellToCheck for example(3,2) is present in neighborhood array, else it would return false which means it was not existed before
{
    if (grid4[s][d] == 1)
    {
        return true;
    }

    else
    {
    return false;
    }
}
// --> 3
// this function will tell if and neighbor has exactly 3 cells
bool checkifCellHasExactly3Neighbors(int count)
{
    if (count == 3)
    {
        return true;
    }
    else
    {
        return false;
    }

}
// if the count is not equal to 3 of the neighbourHood array live cells then assign -1 to it
int removeAllElementFromNeighborArray(int count, int neighbourHood[])
{
    // we are using c here and it has been declared before the main function
    if (count !=3 && (count > 0))
    {

            neighbourHood[r] = -1;
            
    }

r++;
return neighbourHood[r];
}
// if the count is not equal to 3 of the neighbourHood array live cells then assign -1 to it
int removeAllElementFromNeighborArray2(int count, int neighbourHood[])
{
    // we are using c here and it has been declared before the main function
    if (count !=3 && (count > 0))
    {

            neighbourHood[y] = -1;
           
    }

y++;
return neighbourHood[y];
}
