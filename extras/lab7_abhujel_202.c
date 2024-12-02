/*
Abhisek Bhujel
CS262 Lab Section 202
lab7 : File I/O and Formatting
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* Exit program if the number of arguments is not 3 */
    if (argc != 3)
    {
        printf("Error! Only provide 2 inputs (Total number of arguments should be 3 including the executable).\n");
        return 1;
    }

    /*Assign arguments to input and output*/
    char *input = argv[1];
    char *output = argv[2];

    /*Creating file handles to read and write*/
    FILE *fr = fopen(input, "r");
    FILE *fw = fopen(output, "w");

    /*Throw error message and exit if file open returns NULL */
    if (fr == NULL || fw == NULL)
    {
        printf("Error opening file");
        return -1;
    }

    /*Variables to hold value read from file*/
    char customer[20], customerName[20];
    char account[20], accountNumber[20];
    char reportDate[20], date[20];
    char stockName[20], stock[20];
    char sharesHeld[20];
    char openingPrice[20];
    char highPrice[20];
    char lowPrice[20];
    char closingPrice[20];
    int shares;
    double oPrice, hPrice, lPrice, cPrice, change;

    /*Reading file and assigning values to respective variables*/
    fscanf(fr, "%[^|] | %[^\n]\n", customer, customerName);
    fscanf(fr, "%[^|] | %[^\n]\n", account, accountNumber);
    fscanf(fr, "%[^|] | %[^\n]\n", reportDate, date);
    fscanf(fr, "%[^|] | %[^\n]\n", stockName, stock);
    fscanf(fr, "%[^|] | %d\n", sharesHeld, &shares);
    fscanf(fr, "%[^|] | %lf\n", openingPrice, &oPrice);
    fscanf(fr, "%[^|] | %lf\n", highPrice, &hPrice);
    fscanf(fr, "%[^|] | %lf\n", lowPrice, &lPrice);
    fscanf(fr, "%[^|] | %lf\n", closingPrice, &cPrice);

    /*Determining change in share price and wheather gain or loss occurs*/
    change = (cPrice * shares - oPrice * shares);
    char *gainOrLoss;
    gainOrLoss = change >= 0 ? "Gain" : "Loss";

    /*Writing on a output file with proper formatting*/
    fprintf(fw, "Customer: %s\n", customerName);
    fprintf(fw, "Account: %s\n", accountNumber);
    fprintf(fw, "Reporting Date: %s\n", date);
    fprintf(fw, "%-10s %-15s %-15s %-10s\n", "Stock", "Open Price", "Close Price", gainOrLoss);
    fprintf(fw, "%-10s %-15.2lf %-15.2lf %-10.2lf\n", stock, oPrice, cPrice, change < 0 ? -change : change);

    /*Closing fies*/
    fclose(fr);
    fclose(fw);

    return 0;
}
