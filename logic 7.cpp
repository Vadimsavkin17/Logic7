#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


	void DFS(int s,int n, int* vis, int** M)
	{
		vis[s] = 1;
		printf("%d", s);
		
		for (int i = 0; i < n; i++)
		{
			if (M[s][i] == 1 && vis[i] == 0)
			{
				DFS(i,n,&vis[0], &(&M)[0][0]);
			}
		}

	}
	 
	int main()
	{
		int n, i = 0;

		setlocale(LC_ALL, "RUS");
		srand(time(NULL));


		printf("Введите количество вершин графа ");
	
	
		scanf_s("%d", &n);

		int** M =  new int*[n];
		int* vis = new int[n];
	
		for (int i = 0; i < n; i++)
		{
			
				M[i] = new int[n];
				vis[i] = 0;
			
			
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (i == j)
				{
					M[i][j] = 0;
				}
				else if (i != j)
				{
					M[i][j] = rand() % 2;
					M[j][i] = M[i][j];
				}
			}
		}

		printf("Матрица смежности:\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				printf("%d ", M[i][j]);
			}
			printf("\n");
		}

		DFS(0, n, &vis[0], &(&M)[0][0]);

	}
