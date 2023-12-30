/* Purpose: Lab 4: Determine Net Profit For a Farmer's Harvest
 * Author: Abdullah Faisal
 * Date: Oct 7th 2023
 * References: 
 * 	Lab Instructions
 * 	Null Character (used in for loop) - https://www.tutorialspoint.com/cprogramming/c_strings.htm
 *	Format Specifier (used in scanf) - https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm
 */


#include <stdio.h>

int main() {
    char input[1000];  // Assuming the input string is not longer than 1000 characters
    scanf("%999[^\n]%*c", input); // Reads input file with format specifier that stops at '\n' or EOF
    
    // Initialize prices and quantities of each crop
    double prices[] = {0.5, 1.25, 3.0, 1.0};  // Prices for C, T, P, L respectively
    double costs[] = {0.05, 0.25, 0.70, 0.30};  // Costs for C, T, P, L respectively
    int total_crops[] = {0, 0, 0, 0};  // Total crops of C, T, P, L planted respectively
    int sellable_crops[] = {0, 0, 0, 0};  // Sellable crops of C, T, P, L respectively

    // Iterate through the input string
    for (int i = 0; input[i] != '\0'; i += 2) {
        char indicator = input[i];
        char crop = input[i + 1];
        int index = -1;

        if (crop == 'C') {
            index = 0;
        } else if (crop == 'T') {
            index = 1;
        } else if (crop == 'P') {
            index = 2;
        } else if (crop == 'L') {
            index = 3;
        }

        if (index != -1) {
            total_crops[index]++;
            if (indicator == '/') {
                sellable_crops[index]++;
            }
        }
    }

    // Calculate total revenue and purchase cost
    double total_sales = 0.0;
    double total_costs = 0.0;
    for (int i = 0; i < 4; i++) {
        total_sales += prices[i] * sellable_crops[i]; // Calculate total sales
        total_costs += costs[i] * total_crops[i]; // Calculate total costs
    }

    // Calculate net profit
    double net_profit = total_sales - total_costs;

    // Print net profit
    if  (net_profit < 0) {
        printf("Net profit: -$%.2lf\n", net_profit * -1);
    } else {
        printf("Net profit: $%.2lf\n", net_profit);
    }
    
    return 0;
}
