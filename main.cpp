#include<iostream>
#include<bitset>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<cmath>

using namespace std;

//this function is for combining the positions where the # of one's is 1
//this function generates 4! = 24 different functions(combinations)
//****************************************************************
//please uncomment the statements of the second 'for' loop in order..
//..to see the combinations. The first statement of the 2nd 'for' loop will ..
//..show you the combination in integer format, while the other two statements..
//..will show you the conservative functions in binary format.
//Please do not forget to uncomment the 'endl' after the 'for' loop
//******************************************************************
void printOne(int outputNumbers[], int allOnes[], int totalCol, int n, int onesCombined[][16])
{
   static int row = 0;
   //ostringstream fileName;
   for(int i=0; i<n; i++)
   {
       // copying value from allOnes array to outputNumbers array because
       // allOnes has the permutations for the rows with a single one
       outputNumbers[int(pow(2,i))] = allOnes[i];
   }

    //fileName << "crf4x4One_" << row << ".txt";
    //ofstream out(fileName.str().c_str(), ios::trunc|ios::out);
    //cout << "[" << row << "] ";
   for(int col = 0; col < totalCol; col++)
   {
      // onesCombined has 24 rows and 16 columns, representing the 24! different functions
      onesCombined[row][col] = outputNumbers[col];
      //string bin = bitset<4>(onesCombined[row][col]).to_string();
      //out << bin << endl;
      //cout << bin << " ";
      //cout << onesCombined[row][col] << " ";
      //cout  << outputNumbers[col] << " ";
   }
   row++;
   //cout << endl;
}


//this function is for combining the positions where the # of one's is 2
//this function generates 6! = 720 functions(combinations)
//****************************************************************
//please uncomment the statements of the second 'for' loop in order..
//..to see the combinations. The first statement of the 2nd 'for' loop will ..
//..show you the combination in integer format, while the other two statements..
//..will show you the conservative functions in binary format.
//Please do not forget to uncomment the 'endl' after the 'for' loop
//******************************************************************
void printTwo(int outputNumbers[], int allTwos[], int totalCol, int n, int twosCombined[][16])
{
   static int row = 0;
   //ostringstream fileName;
   for(int i=0; i < n; i++)
   {
      if(i==0)
	 outputNumbers[3] = allTwos[i];  // outputNumbers[TwosPosition[i]] =
                                   //allTwos[i];  change to this for future.
      else if(i==5)
	 outputNumbers[12] = allTwos[i];
      else if(i==1 || i==2)
	 outputNumbers[i+4] = allTwos[i];
      else
	 outputNumbers[i+6] = allTwos[i];
   }
    //fileName << "crf4x4Two_" << row << ".txt";
    //ofstream out(fileName.str().c_str(), ios::trunc|ios::out);
    //cout << "[" << row << "] " ;
    for(int col = 0; col < totalCol; col++)
    {
        twosCombined[row][col] = outputNumbers[col];
        //string bin = bitset<4>(twosCombined[row][col]).to_string();
        //out << bin << endl;
        //cout << bin << " ";
        //cout << right << setw(2) << twosCombined[row][col] << " ";
   }
    row++;
   //cout << endl;
}

//this function is for combining the positions where the # of one's is 3
//this function generates 4! = 24 different functions
//****************************************************************
//please uncomment the statements of the second 'for' loop in order..
//..to see the combinations. The first statement of the 2nd 'for' loop will ..
//..show you the combination in integer format, while the other two statements..
//..will show you the conservative functions in binary format.
//Please do not forget to uncomment the 'endl' after the 'for' loop
//******************************************************************
void printThree(int outputNumbers[], int allThrees[], int totalCol, int n,
		int threesCombined[][16])
{
   static int row = 0;
   //ostringstream fileName;
   for(int i=0; i<n; i++)
   {
      if(i==0)
	 outputNumbers[7] = allThrees[i];
      else if(i==1)
	 outputNumbers[11] = allThrees[i];
      else
	 outputNumbers[i+11] = allThrees[i];
   }
    //cout << "[" << row << "] " << " ";
    //fileName << "crf4x4Three_" << row << ".txt";
    //ofstream out(fileName.str().c_str(), ios::trunc|ios::out);
    for(int col = 0; col < totalCol; col++)
    {
        threesCombined[row][col] = outputNumbers[col];
       // string bin = bitset<4>(threesCombined[row][col]).to_string();
        //out << bin << endl;
        //cout << bin << " ";
        //cout << right << setw(2) << threesCombined[row][col] << " ";
   }
    row++;
    //cout << endl;
}

void writeToFiles(int combined[][16], int num, int totalCol)
{
    ostringstream fileName;
    fileName << "crf4x4OneThree" << num << ".txt";
    ofstream out(fileName.str().c_str(), ios::trunc|ios::out);
    for(int col = 0; col < totalCol; col++)
    {
        string bin = bitset<4>(combined[num][col]).to_string();
        //out << bin << endl;
        for(int i = 0; i <=3; i++)
        out << bin[i] << " ";
        out << endl;
	    cout << setw(2) << combined[num][col] << " ";
	 }
}


void writeAllToFiles(int **combined, int num, int totalCol)
{
    ostringstream fileName;
    fileName << "crf4x4OneTwoThree" << num << ".txt";
    ofstream out(fileName.str().c_str(), ios::trunc|ios::out);
    for(int col = 0; col < totalCol; col++)
    {
        string bin = bitset<4>(combined[num][col]).to_string();
        //out << bin << endl;
         for(int i = 0; i <=3; i++)
        out << bin[i] << " ";
        out << endl;
	    cout << combined[num][col] << " ";
	 }
}


//this function is for combining the positions where the # of 1's is 1 & 3
//this function generates 24 x 24 = 576 different combination functions
//****************************************************************
//******************************************************************

void printOnesThrees(int totalRow, int totalCol, int onesCombined[][16], int threesCombined[][16],
		   int onesThreesCombined[][16])
{
   int row = 0;
   for(int i = 0; i < totalRow; i++)
   {
      for(int j = 0; j < totalRow; j++)
      {
	 //cout << "[" << row << "]" << " " ;
	 for(int col = 0; col < totalCol; col++)
	 {
	    if(col == 0 || col == 1 || col == 2 || col == 4 || col == 8 ||
	       col == 3 || col == 5 || col == 6 || col == 9 || col == 10 ||
	       col == 12 || col == 15)
	       onesThreesCombined[row][col] = onesCombined[i][col];
	    if(col == 7 || col == 11 || col == 13 || col == 14)
	       onesThreesCombined[row][col] = threesCombined[j][col];
	 }
	 //writeToFiles(onesThreesCombined, row, totalCol);
	 //cout << endl;
	 row ++;
      }
   }
}

//this function is for combining the positions where the # of 1's is 1,2 & 3
//this function generates  576 x 720 = 424720 different combination functions
//****************************************************************
//******************************************************************

void printOnesTwosThrees(int row_13Comb, int row_2Comb, int totalCol, int twosCombined[][16], int onesThreesCombined[][16],
		   int **onesTwosThreesCombined)
{
   //int row_twoComb = 720;
   //int row_oneThreeComb = 576;
   int row = 0;
   for(int i = 0; i < row_2Comb; i++)
   {
      for(int j = 0; j < row_13Comb; j++)
      {
	 cout << "[" << row << "]" << " " ;
	 for(int col = 0; col < totalCol; col++)
	 {
	    if(col == 0 || col == 1 || col == 2 || col == 4 || col == 8 ||
	       col == 7 || col == 11 || col == 13 || col == 14 || col == 15)
	       onesTwosThreesCombined[row][col] = onesThreesCombined[j][col];
	    if(col == 3 || col == 5 || col == 6 || col == 9 ||
	       col == 10 || col == 12)
	       onesTwosThreesCombined[row][col] = twosCombined[i][col];
	    //cout << right << setw(2) << onesTwosThreesCombined[row][col]
	    //<< " ";
	    //string bin =
	     //bitset<4>(onesTwosThreesCombined[row][col]).to_string();
	    //cout << bin << " ";
	 }
	 writeAllToFiles(onesTwosThreesCombined, row, totalCol);
	 cout << endl;
	 row ++;
      }
   }
   }

int main()
{
    int input = 4;
    int noCombiCol = static_cast<int>(pow(2,input)); // 16 combinations for 4 input variables
    int allOnes[] = {1, 2, 4, 8};
    int allTwos[] = {3, 5, 6, 9, 10, 12};
    int allThrees[] = {7, 11, 13, 14};
    int noElements_13 = sizeof(allOnes)/sizeof(allOnes[0]); //number of elements is 4
    int noElements_2 = sizeof(allTwos)/sizeof(allTwos[0]); // number of elements is 6
    int outputNumbers[noCombiCol];
    int noFunc13 = tgamma(noElements_13+1); // 4! = 24 [24 possible functions]
    int noFunc2 = tgamma(noElements_2+1); // 6! = 720 [720 possible functions]
    int noFunComb13 = noFunc13 * noFunc13; // 24 * 24 = 576 functions when combined one with three
    int onesCombined[noFunc13][16], twosCombined[noFunc2][16], threesCombined[noFunc13][16];
    int onesThreesCombined[noFunComb13][16];
    int totalFuncRow = noFunComb13 * noFunc2;
    //int row = 414720, col = 16;
    int **onesTwosThreesCombined = new int*[totalFuncRow];
    for(int i = 0; i < totalFuncRow; i++)
        onesTwosThreesCombined[i] = new int[noCombiCol];

    for( int i = 0; i < noCombiCol; i++)
        outputNumbers[i] = i;
    cout << endl;

//    cout << "Input: " << input << endl;
//    cout << "noCombiCol: " << noCombiCol << endl;
//    cout << "noElements_13: " << noElements_13 << endl;
//    cout << "noElements_2: " << noElements_2 << endl;
//    cout << "noFunc13: " << noFunc13 << endl;
//    cout << "noFunc2: " << noFunc2 << endl;
//    cout << "noFuncCom13: " << noFunComb13 << endl;
//    cout << "totalFuncRow: " << totalFuncRow << endl;
   //int nElementsOneThree = 4;
   //int nElementsTwo = 6;

   bool noOne, noTwo, noThree;
   noOne = noTwo = noThree = true;
   //noTwo = true;
   //noThree = true;

   if(noOne)
   {
      do
      {
          for(short i = 0; i < noElements_13; i++)
          {
              printOne(outputNumbers, allOnes, noCombiCol, noElements_13, onesCombined);
              break;
          }
      }while(next_permutation(allOnes, allOnes+noElements_13));
   }

   for( int i = 0; i < noCombiCol; i++)
      outputNumbers[i] = i;

   if(noTwo)
   {
      do
      {
          for(short i = 0; i < noElements_2; i++)
          {
              printTwo(outputNumbers, allTwos, noCombiCol, noElements_2, twosCombined);
              break;
          }
      }while(next_permutation(allTwos, allTwos+noElements_2));
   }


   for( int i = 0; i < noCombiCol; i++)
      outputNumbers[i] = i;

   if(noThree)
   {
      do
      {
	 for(short i = 0; i < noElements_13; i++)
	 {
	    printThree(outputNumbers, allThrees, noCombiCol, noElements_13,
		       threesCombined);
	    break;
	 }
      }while(next_permutation(allThrees, allThrees+noElements_13));
   }

   printOnesThrees(noFunc13, noCombiCol, onesCombined, threesCombined, onesThreesCombined);

   printOnesTwosThrees(noFunComb13, noFunc2, noCombiCol, twosCombined, onesThreesCombined,
		       onesTwosThreesCombined);

     return 0;
}

