#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG
#define CONSOLE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define OUTPUT_FILE_PATH "Output_1207543476"
#define INPUT_FILE_MODE "r"
#define OUTPUT_FILE_MODE "a+"

FILE *ofp;

/* Return 1 if the difference is negative, otherwise 0.  */
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
    long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
    result->tv_sec = diff / 1000000;
    result->tv_usec = diff % 1000000;

    return (diff<0);
}

void printMatrix(char *arr, int row, int column)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (arr[(i*column) + j] < '9')
			{
				//fprintf(ofp, "%c\t", arr[(i*column) + j]);
#ifdef CONSOLE
				printf("%c\t", arr[(i*column) + j]);
#endif
			}
			else
			{
				//fprintf(ofp, "%d\t", ((int)arr[(i*column) + j])-48);
#ifdef CONSOLE
				printf("%d\t", ((int)arr[(i*column) + j])-48);
#endif
			}
		}
		//fprintf(ofp, "\n");
#ifdef CONSOLE
		printf("\n");
#endif
	}
}

int factorial(int i)
{
	if (1 == i)
	{
		return 1;
	}
	return factorial(i - 1) * i;
}

int combination(int n, int r)
{
	int num = 1;
	int i = 0;
	for (i = n; i>(n - r); i--)
	{
		num = num * i;
	}
	return num / factorial(r);
}

int main(int argc, char **argv)
{
	int N, t, k, v;

	struct timeval timeBegin, timeEnd, timeDiff;
	gettimeofday(&timeBegin, NULL);
	
	ofp = fopen(OUTPUT_FILE_PATH, OUTPUT_FILE_MODE);
	if (NULL == ofp)
	{
		fprintf(stderr, "Opening output file failed.\n");
#ifdef CONSOLE
		printf("Opening output file failed.\n");
#endif
		exit(0);
	}
	scanf("%d %d %d %d", &N, &t, &k, &v);
	//fprintf(ofp, "=======================================\n");
	//fprintf(ofp, "Serial ::: N=%d; t=%d, k=%d, v=%d\n", N, t, k, v);
	//fprintf(ofp, "=======================================\n");
#ifdef CONSOLE
	printf("=======================================\n");
	printf("Serial ::: N=%d; t=%d, k=%d, v=%d\n", N,t,k,v);
	printf("=======================================\n");
#endif

	char *inputArray = (char *)calloc(N * k, sizeof(char));
	
	int pos = 0;
	char c = '0';
	while (EOF != c)
	{
		c = getchar();
		if (' ' != c)
		{
			if ('\n' != c)
			{
				inputArray[pos++] = c;
			}
		}
	}
#ifdef DEBUG
	fprintf(ofp,"Input Matrix\n");
	printMatrix(&inputArray[0], N, k);
#endif
	int combinationOfSymbols = (int)pow(v, t);
#ifdef DEBUG
	fprintf(ofp,"Total Combination Of Symbols = %d\n", combinationOfSymbols);
#endif
	char *elements = (char *)calloc(v, sizeof(char));
	char *Symbols = (char *)calloc(combinationOfSymbols * t, sizeof(char));
	int iLoopIndex = 0, jLoopIndex = 0, kLoopIndex = 0, lLoopIndex = 0;
	if (2 == v)
	{
		int iCount = 0;
		elements[0] = '0';
		elements[1] = '1';
		if (2 == t)
		{
			for (iLoopIndex = 0; iLoopIndex < v; iLoopIndex++)
			{
				for (jLoopIndex = 0; jLoopIndex < v; jLoopIndex++)
				{
					for (kLoopIndex = 0; kLoopIndex < t; kLoopIndex++)
					{
						if (0 == (kLoopIndex % t))
						{
							Symbols[iCount] = elements[iLoopIndex];
						}
						else
						{
							Symbols[iCount] = elements[jLoopIndex];
						}
						iCount++;
					}
				}
			}
		}
		else if (3 == t)
		{
			elements[0] = '0';
			elements[1] = '1';
			elements[2] = '2';
			for (iLoopIndex = 0; iLoopIndex < v; iLoopIndex++)
			{
				for (jLoopIndex = 0; jLoopIndex < v; jLoopIndex++)
				{
					for (kLoopIndex = 0; kLoopIndex < v; kLoopIndex++)
					{
						for (lLoopIndex = 0; lLoopIndex < t; lLoopIndex++)
						{
							if (0 == (lLoopIndex % t))
							{
								Symbols[iCount] = elements[iLoopIndex];
							}
							else if (1 == (lLoopIndex % t))
							{
								Symbols[iCount] = elements[jLoopIndex];
							}
							else if (2 == (lLoopIndex % t))
							{
								Symbols[iCount] = elements[kLoopIndex];
							}
							iCount++;
						}
					}
				}
			}
		}
	}
	else if (3 == v)
	{
		int iCount = 0;
		elements[0] = '0';
		elements[1] = '1';
		elements[2] = '2';
		if (2 == t)
		{
			for (iLoopIndex = 0; iLoopIndex < v; iLoopIndex++)
			{
				for (jLoopIndex = 0; jLoopIndex < v; jLoopIndex++)
				{
					for (kLoopIndex = 0; kLoopIndex < t; kLoopIndex++)
					{
						if (0 == (kLoopIndex % t))
						{
							Symbols[iCount] = elements[iLoopIndex];
						}
						else
						{
							Symbols[iCount] = elements[jLoopIndex];
						}
						iCount++;
					}
				}
			}
		}
		else if (3 == t)
		{
			for (iLoopIndex = 0; iLoopIndex < v; iLoopIndex++)
			{
				for (jLoopIndex = 0; jLoopIndex < v; jLoopIndex++)
				{
					for (kLoopIndex = 0; kLoopIndex < v; kLoopIndex++)
					{
						for (lLoopIndex = 0; lLoopIndex < t; lLoopIndex++)
						{
							if (0 == (lLoopIndex % t))
							{
								Symbols[iCount] = elements[iLoopIndex];
							}
							else if (1 == (lLoopIndex % t))
							{
								Symbols[iCount] = elements[jLoopIndex];
							}
							else if (2 == (lLoopIndex % t))
							{
								Symbols[iCount] = elements[kLoopIndex];
							}
							iCount++;
						}
					}
				}
			}
		}
	}
	int iCount = 0;
	int i = 0;
#ifdef DEBUG
	fprintf(ofp,"Symbols are\n");
	for (i = 0; i<combinationOfSymbols * t; i++)
	{
		if (0 == (iCount % t))
		{
			fprintf(ofp, "%d-->\t", (i / t + 1));
		}
		iCount++;
		fprintf(ofp, "%c", Symbols[i]);
		if (0 == (iCount % t))
		{
			fprintf(ofp, "\n");
		}
	}
#endif
	int noOfSubArrays = combination(k, t);
#ifdef DEBUG
	fprintf(ofp, "Total Number of Sub Arrays = %d\n", noOfSubArrays);
#endif
	int *SubArrays = (int *)calloc(noOfSubArrays * t, sizeof(int));
	if (2 == t)
	{
		int iCount = 0;
		for (iLoopIndex = 1; iLoopIndex <= k; iLoopIndex++)
		{
			for (jLoopIndex = iLoopIndex + 1; jLoopIndex <= k; jLoopIndex++)
			{
				for (kLoopIndex = 0; kLoopIndex < t; kLoopIndex++)
				{
					if (0 == (iCount % t))
					{
						SubArrays[iCount] = iLoopIndex;
					}
					else
					{
						SubArrays[iCount] = jLoopIndex;
					}
					iCount++;
				}
			}
		}
	}
	else if (3 == t)
	{
		int iCount = 0;
		for (iLoopIndex = 1; iLoopIndex <= k; iLoopIndex++)
		{
			for (jLoopIndex = iLoopIndex + 1; jLoopIndex <= k; jLoopIndex++)
			{
				for (kLoopIndex = jLoopIndex + 1; kLoopIndex <= k; kLoopIndex++)
				{
					for (lLoopIndex = 0; lLoopIndex < t; lLoopIndex++)
					{
						if (0 == (iCount % t))
						{
							SubArrays[iCount] = iLoopIndex;
						}
						else if (1 == (iCount % t))
						{
							SubArrays[iCount] = jLoopIndex;
						}
						else if (2 == (iCount % t))
						{
							SubArrays[iCount] = kLoopIndex;
						}
						iCount++;
					}
				}
			}
		}
	}
	iCount = 0;
#ifdef DEBUG
	fprintf(ofp,"SubArrays are\n");
	for (i = 0; i<(noOfSubArrays * t); i++)
	{
		if (0 == (iCount % t))
		{
			fprintf(ofp, "%d-->\t(", (i / t + 1));
		}
		fprintf(ofp, "%d,", SubArrays[i]);
		iCount++;
		if (0 == (iCount % t))
		{
			fprintf(ofp, ")\n", (i / t + 1));
		}
	}
#endif
	int *intermediateArray = (int *)calloc(noOfSubArrays * combinationOfSymbols, sizeof(int));
	for (iLoopIndex = 0; iLoopIndex < noOfSubArrays; iLoopIndex++)
	{
		int firstColumnIndex = SubArrays[t * iLoopIndex];
		int secondColumnIndex = SubArrays[t * iLoopIndex + 1];
		int thirdColumnIndex = SubArrays[t * iLoopIndex + 2];
		char *tempInputArray = (char *)calloc(N*t,sizeof(char));
		for (jLoopIndex = 0; jLoopIndex < N; jLoopIndex++)
		{
			if (2 == t)
			{
				tempInputArray[t*jLoopIndex] = inputArray[k*jLoopIndex + firstColumnIndex - 1] ;
				tempInputArray[t*jLoopIndex + 1] = inputArray[k*jLoopIndex + secondColumnIndex - 1];
				for (kLoopIndex = 0; kLoopIndex < combinationOfSymbols; kLoopIndex++)
				{
					if ( (tempInputArray[t * jLoopIndex] == Symbols[t*kLoopIndex]) && (tempInputArray[t * jLoopIndex + 1] == Symbols[t*kLoopIndex + 1]))
					{
						intermediateArray[(combinationOfSymbols * iLoopIndex) + kLoopIndex]++;
					}
				}
			}
			else if (3 == t)
			{
				tempInputArray[t*jLoopIndex] = inputArray[k*jLoopIndex + firstColumnIndex - 1];
				tempInputArray[t*jLoopIndex + 1] = inputArray[k*jLoopIndex + secondColumnIndex - 1];
				tempInputArray[t*jLoopIndex + 2] = inputArray[k*jLoopIndex + thirdColumnIndex - 1];
				for (kLoopIndex = 0; kLoopIndex < combinationOfSymbols; kLoopIndex++)
				{
					if ((tempInputArray[t*jLoopIndex] == Symbols[t*kLoopIndex]) && (tempInputArray[t*jLoopIndex + 1] == Symbols[t*kLoopIndex + 1]) && (tempInputArray[t*jLoopIndex + 2] == Symbols[t*kLoopIndex + 2]))
					{
						intermediateArray[(combinationOfSymbols * iLoopIndex) + kLoopIndex]++;
					}
				}
			}
		}
		free(tempInputArray);
	}
	char isCoveringArray = '1';
#ifdef DEBUG
	fprintf(ofp, "Intermediate Matrix\n");
#endif
	for (iLoopIndex = 0; iLoopIndex < noOfSubArrays ; iLoopIndex++)
	{
		for (jLoopIndex = 0; jLoopIndex < combinationOfSymbols; jLoopIndex++)
		{
#ifdef DEBUG
			fprintf(ofp, "%d\t", intermediateArray[combinationOfSymbols * iLoopIndex + jLoopIndex]);
#endif
			if (0 == intermediateArray[combinationOfSymbols * iLoopIndex + jLoopIndex])
			{
				isCoveringArray = '0';
			}
		}
#ifdef DEBUG
		fprintf(ofp, "\n");
#endif
	}
	if ('0' == isCoveringArray)
	{
		//fprintf(ofp, "Serial::: No, It is Not a Covering Array\n");
#ifdef CONSOLE
		printf("Serial::: No, It is Not a Covering Array\n");
#endif
	}
	else
	{
		//fprintf(ofp, "Serial::: Yes, It is a Covering Array\n");
#ifdef CONSOLE
		printf("Serial::: Yes, It is a Covering Array\n");
#endif
	}

	if ('1' == isCoveringArray)
	{
		int firstColumnIndex = 0;
		int secondColumnIndex = 0;
		int thirdColumnIndex = 0;

		char *finalArray = (char *)calloc(N*k, sizeof(char));
		memset(finalArray, '0', (N*k*sizeof(char)));
		for (iLoopIndex = 0; iLoopIndex < noOfSubArrays; iLoopIndex++)
		{
			for (jLoopIndex = 0; jLoopIndex < combinationOfSymbols; jLoopIndex++)
			{
				int positionOfOnes = 0;
				int p1_row = 0;
				int p1_column = 0;
				if (1 == intermediateArray[combinationOfSymbols * iLoopIndex + jLoopIndex])
				{
					if (2 == t)
					{
						positionOfOnes = combinationOfSymbols * iLoopIndex + jLoopIndex;
						p1_row = iLoopIndex;
						p1_column = jLoopIndex;
#ifdef DEBUG
						fprintf(ofp, "%d(%d,%d),", positionOfOnes, p1_row, p1_column);
						fprintf(ofp, "{%d,%d}", SubArrays[t*iLoopIndex], SubArrays[t*iLoopIndex + 1]);
						fprintf(ofp, "{%c,%c}\n", Symbols[t*jLoopIndex], Symbols[t*jLoopIndex + 1]);
#endif
						firstColumnIndex = 0;
						secondColumnIndex = 0;
						char *tempInputArray = (char *)calloc(N*t, sizeof(char));
						int jLoopIndex_tempInputArray = 0;
						int tempIndex = 0;
						for (jLoopIndex_tempInputArray = 0; jLoopIndex_tempInputArray < N; jLoopIndex_tempInputArray++)
						{
							firstColumnIndex = SubArrays[t * iLoopIndex];
							secondColumnIndex = SubArrays[t * iLoopIndex + 1];
							tempInputArray[t*jLoopIndex_tempInputArray] = inputArray[k*jLoopIndex_tempInputArray + firstColumnIndex - 1];
							tempInputArray[t*jLoopIndex_tempInputArray + 1] = inputArray[k*jLoopIndex_tempInputArray + secondColumnIndex - 1];
						}
						for (tempIndex = 0; tempIndex < N; tempIndex++)
						{
#ifdef DEBUG
							fprintf(ofp, "%c%c==%c%c\t", Symbols[t*jLoopIndex], Symbols[t*jLoopIndex + 1], tempInputArray[t*tempIndex], tempInputArray[t*tempIndex + 1]);
#endif
							if ((tempInputArray[t*tempIndex] == Symbols[t*jLoopIndex]) && (tempInputArray[t*tempIndex + 1] == Symbols[t*jLoopIndex + 1]))
							{
#ifdef DEBUG
								fprintf(ofp, "Found at Row %d", tempIndex + 1);
#endif
								finalArray[k*tempIndex + firstColumnIndex - 1]++;
								finalArray[k*tempIndex + secondColumnIndex - 1]++;
							}
							else
							{
#ifdef DEBUG
								fprintf(ofp, "Not Found at Row %d", tempIndex + 1);
#endif
							}
#ifdef DEBUG
							fprintf(ofp, "\n");
#endif
						}
#ifdef DEBUG
						printMatrix(finalArray, N, k);
#endif
						free(tempInputArray);
					}
					else if (3 == t)
					{
						positionOfOnes = combinationOfSymbols * iLoopIndex + jLoopIndex;
						p1_row = iLoopIndex;
						p1_column = jLoopIndex;
#ifdef DEBUG
						fprintf(ofp, "%d(%d,%d),", positionOfOnes, p1_row, p1_column);
						fprintf(ofp, "{%d,%d,%d}", SubArrays[t*iLoopIndex], SubArrays[t*iLoopIndex + 1], SubArrays[t*iLoopIndex + 2]);
						fprintf(ofp, "{%c,%c,%c}\n", Symbols[t*jLoopIndex], Symbols[t*jLoopIndex + 1], Symbols[t*jLoopIndex + 2]);
#endif
						firstColumnIndex = 0;
						secondColumnIndex = 0;
						thirdColumnIndex = 0;
						char *tempInputArray = (char *)calloc(N*t, sizeof(char));
						int jLoopIndex_tempInputArray = 0;
						int tempIndex = 0;
						for (jLoopIndex_tempInputArray = 0; jLoopIndex_tempInputArray < N; jLoopIndex_tempInputArray++)
						{
							firstColumnIndex = SubArrays[t * iLoopIndex];
							secondColumnIndex = SubArrays[t * iLoopIndex + 1];
							thirdColumnIndex = SubArrays[t * iLoopIndex + 2];
							tempInputArray[t*jLoopIndex_tempInputArray] = inputArray[k*jLoopIndex_tempInputArray + firstColumnIndex - 1];
							tempInputArray[t*jLoopIndex_tempInputArray + 1] = inputArray[k*jLoopIndex_tempInputArray + secondColumnIndex - 1];
							tempInputArray[t*jLoopIndex_tempInputArray + 2] = inputArray[k*jLoopIndex_tempInputArray + thirdColumnIndex - 1];
						}
						for (tempIndex = 0; tempIndex < N; tempIndex++)
						{
#ifdef DEBUG
							fprintf(ofp, "%c%c%c==%c%c%c\t", Symbols[t*jLoopIndex], Symbols[t*jLoopIndex + 1], Symbols[t*jLoopIndex + 2], tempInputArray[t*tempIndex], tempInputArray[t*tempIndex + 1], tempInputArray[t*tempIndex + 2]);
#endif
							if ((tempInputArray[t*tempIndex] == Symbols[t*jLoopIndex]) && (tempInputArray[t*tempIndex + 1] == Symbols[t*jLoopIndex + 1]) && (tempInputArray[t*tempIndex + 2] == Symbols[t*jLoopIndex + 2]))
							{
#ifdef DEBUG
								fprintf(ofp, "Found at Row %d", tempIndex + 1);
#endif
								finalArray[k*tempIndex + firstColumnIndex - 1]++;
								finalArray[k*tempIndex + secondColumnIndex - 1]++;
								finalArray[k*tempIndex + thirdColumnIndex - 1]++;
							}
							else
							{
#ifdef DEBUG
								fprintf(ofp, "Not Found at Row %d", tempIndex + 1);
#endif
							}
#ifdef DEBUG
							fprintf(ofp, "\n");
#endif
						}
#ifdef DEBUG
						printMatrix(finalArray, N, k);
#endif
						free(tempInputArray);
					}
				}
			}
		}
		//Converting 0 to * for printing in the final Matrix
		for (iLoopIndex = 0; iLoopIndex < N; iLoopIndex++)
		{
			for (jLoopIndex = 0; jLoopIndex < k; jLoopIndex++)
			{
				if ('0' == finalArray[k*iLoopIndex + jLoopIndex])
				{
					finalArray[k*iLoopIndex + jLoopIndex] = '*';
				}
				else
				{
					finalArray[k*iLoopIndex + jLoopIndex] = inputArray[k*iLoopIndex + jLoopIndex];
				}
			}
		}
		//fprintf(ofp, "Don't Care Matrix\n");
#ifdef CONSOLE
		printf("Don't Care Matrix\n");
#endif

		printMatrix(finalArray, N, k);

		//Printing the co-ordinates of Don't Care positions
		//fprintf(ofp, "Don't Care position\n");
#ifdef CONSOLE
		printf("Don't Care position\n");
#endif
		iCount = 0;
		for (iLoopIndex = 0; iLoopIndex < N; iLoopIndex++)
		{
			for (jLoopIndex = 0; jLoopIndex < k; jLoopIndex++)
			{
				if ('*' == finalArray[k*iLoopIndex + jLoopIndex])
				{
					iCount++;
					//fprintf(ofp, "(%d,%d)\t", iLoopIndex + 1, jLoopIndex + 1);
#ifdef CONSOLE
					printf("(%d,%d)\t", iLoopIndex + 1, jLoopIndex + 1);
#endif
				}
			}
		}
		//fprintf(ofp,"\nTotal Number of Don't Cares :: %d\n",iCount);
#ifdef CONSOLE
		printf("\nTotal Number of Don't Cares :: %d\n",iCount);
#endif
		free(finalArray);
	}
	
	free(inputArray);
	free(elements);
	free(Symbols);
	free(SubArrays);
	free(intermediateArray);
	
	gettimeofday(&timeEnd, NULL);
	
	timeval_subtract(&timeDiff, &timeEnd, &timeBegin);

#ifdef CONSOLE
	printf("Serial Time:::%ld.%06ld secs\n", timeDiff.tv_sec, timeDiff.tv_usec);
#endif
	fprintf(ofp, "%ld.%06ld\t", timeDiff.tv_sec, timeDiff.tv_usec);

	fclose(ofp);
	return 0;
}
