#include <stdio.h>

void matrix (int m, int n, int t)
{
  int arr[m][n];
  int i, j, k;

  for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }
  }
  if (t == 0){
            for (i = 0; i < m; i++){
                for (j = n-1; j >= 0; j--){
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
  }
  else if (t == 1){
        for (i = m-1; i >= 0; i--){
            for (j = 0; j < n; j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
  }
}

int main()
{
  int m, n, t;

  scanf("%d %d %d", &m, &n, &t);
  matrix (m, n, t);

  return 0;
}
