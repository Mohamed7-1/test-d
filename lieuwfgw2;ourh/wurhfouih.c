#include<stdio.h>
#include<math.h>




float somme(float a[],float y,int n)
{ 
  float s=0;
 int i;

  for ( i = 0; i<=n; i++)
 {
      s+= a[i]*powf(y,i); 
  }
return s;
}

int main()
{
    float y;
 int i,n;

printf("\nentrez la valeur du n =");
scanf("%d", &n);
float arr[n]; 
 

printf("entrez les valeur de a\n");
for ( i = 0; i <=n; i++)
{
     scanf("%f", &arr[i]);

}



printf("\nentrez la valeur du y =");
scanf("%f", &y);
printf("entrz la valeur de p ");


float fy;

int p;
printf ("\n");

printf("entrz la valeur de p ");
scanf("%d", &p);


for ( i = 0; i <=p;i++)
{
fy = somme(arr,y,n); 

y = fy;
}
printf("la resultat est %.3f", fy);
    return 0;

}
