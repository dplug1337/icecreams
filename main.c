#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char code[50];
    char name[50];
    int weight;
    float price;
}IceCream;

float totalPriceByFirstLetter(IceCream* iceCreamArray, int n, char firstChar)
{
    float totalPrice=0.0;
    for(int i = 0; i<n; i++)
    {
        if (firstChar==iceCreamArray[i].name[0])
        {
            totalPrice += iceCreamArray[i].price;
        }
    }
    printf("The total price of the ice creams starting with ''%c'' is %.2f", firstChar, totalPrice);
    return totalPrice;
}

int main()
{
    int n;
    while(n<=5 || n>=15)
    {
        printf("\nInput number of ice creams between 5 and 15 excluded:");
        scanf("%d",&n);
        if (n<=5 || n>=15)
        {
            printf("\nNot between 5 and 15 excluded !!!");
        }
    }

    IceCream* iceCreamArray = (IceCream*)malloc(n*sizeof(IceCream));

    if (iceCreamArray==NULL)
    {
        printf("Error in allocating memory\n");
        return 1;
    }

    for (int i=0; i<n; i++)
    {
        printf("Please type the information for the %d ice cream.\n",i+1);
        printf("Code:");
        scanf("%s", iceCreamArray[i].code);
        printf("Name:");
        scanf("%s", iceCreamArray[i].name);
        printf("Weight:");
        scanf("%d", &iceCreamArray[i].weight);
        printf("Price:");
        scanf("%f", &iceCreamArray[i].price);
    }

     printf("The data for the ice creams:\n");

        for(int i = 0; i<n; i++)
        {
            printf("Ice cream %d :- Code: %s, Name: %s, Weight: %d, Price: %.2f \n",
                   i+1, iceCreamArray[i].code, iceCreamArray[i].name, iceCreamArray[i].weight, iceCreamArray[i].price);
        }

    free(iceCreamArray);

    totalPriceByFirstLetter(iceCreamArray, n, 'b');
}
