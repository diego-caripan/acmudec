#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    double red_proportion;
    double purple_proportion;

    while(cin >> red_proportion)
    {
        purple_proportion = 1 - red_proportion;

        int num_people;
        cin >> num_people;

        double total = 0;
        double prob_red = 0;
        double prob_purple = 0;
        double result = 1;

        while(num_people--)
        {
            char coin_type;
            double prob;


            cin >> coin_type >> prob;

            if(coin_type == 'P')
            {
                total = purple_proportion * prob;
                total += red_proportion * (1 - prob);
                prob_purple = purple_proportion * prob;

                double tmp = prob_purple / total;

                red_proportion = 1 - tmp;
                purple_proportion = tmp;
            }
            else if(coin_type == 'R')
            {
                total = red_proportion * prob;
                total += purple_proportion * (1 - prob);
                prob_red = red_proportion * prob;

                double tmp = prob_red / total;

                red_proportion = tmp;
                purple_proportion = 1 - tmp;
            }

           // printf("%.6f %.6f\n", red_proportion, purple_proportion);
        }

        //double result = prob_red / total;
        printf("%.6f %.6f\n", red_proportion, purple_proportion);
    }

    return 0;
}
