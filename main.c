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


//function to print the info of the ice cream with specific code
void searchBinaryFile(const char *searchCode, const char *filename)
{
    FILE *filePointer = fopen(filename,"rb");
    if(!filePointer)
    {
        printf("Error in opening %s in read mode", filename);
        return 1;
    }

    int n;

    //reading the number of elements
    if (fread(&n, sizeof(int), 1, filePointer) != 1)
    {
        printf("error reading the number of elements\n");
        fclose(filePointer);
        return 1;
    }

    IceCream IceCreams;
    int found = 0;

    for(int i = 0; i<n; i++)
    {
        if (fread(&IceCreams, sizeof(IceCream), 1, filePointer)!=1)
        {
            printf("Error reading ice cream data\n");
            fclose(filePointer);
            return 1;
        }
        // searching the code
        if (strcmp(IceCreams.code, searchCode) == 0)
        {
            printf("Found Ice Cream:\n");
            printf("Code: %s\n", IceCreams.code);
            printf("Name: %s\n", IceCreams.name);
            printf("Weight: %d\n", IceCreams.weight);
            printf("Price: %.2f\n", IceCreams.price);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Ice cream with code '%s' not found.\n", searchCode);
    }

    fclose(filePointer);

}


//function to calculate total price of all ice creams that start with the parameter letter
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
    printf("The total price of the ice creams starting with ''%c'' is %.2f\n", firstChar, totalPrice);
    return totalPrice;
}


//function to save the iceCreams with less the price and more the weight as a parameter in txt file
int saveToTXT(IceCream* iceCreams, int n, float price, int weight)
{
    FILE *file = fopen("test.txt","w");
    if (file == NULL)
    {
        printf("Error opening the file!\n");
        return 0;
    }
    int count=0;
    for(int i =0; i<n; i++)
    {
        if (iceCreams[i].price<price && iceCreams[i].weight>weight)
        {
            fprintf(file, "%s:%s:%d:%.2f leva\n", iceCreams[i].code,iceCreams[i].name,iceCreams[i].weight,iceCreams[i].price);
            count++;
        }
    }
    fclose(file);
    if (count == 0)
    {
        printf("No ice creams found matching the criteria\n");
    }
    else
    {
        printf("%d ice creams saved to text.txt \n", count);
    }
    return count;
}

//void saveToBIN(char code[50])
//{
//    file* FILEpointer = fopen("IceCream.bin", "r");
//    if (FILEpointer==NULL)
//    {
//        printf("Error in opening the file.\n");
//    }
//
//    for (int i=0;i<)
//    {
//
//    }
//}


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

    totalPriceByFirstLetter(iceCreamArray, n, 'b');

    saveToTXT(iceCreamArray, n, 5.00, 100);



    free(iceCreamArray);

}
