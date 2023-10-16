#include <stdio.h>

int main() {
    int score;

    //loop to prompt user for NFL scores input
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        //end loop if score less than or equal to 1 is entered
        if (score <= 1) {
            printf("Score must be greater than 1. Thanks for using!\n");
            break;
        }

        //loop through possible scores that have touchdown with 2 point conversion
        for (int td_2 = 0; td_2 <= score / 8; td_2++) {
            //loop through possible scores that have touchdown with 1 point field goal
            for (int td_1 = 0; td_1 <= (score - td_2 * 8) / 7; td_1++) {
                //loop through possible scores with touchdown (no bonus points)
                for (int td = 0; td <= (score - td_2 * 8 - td_1 * 7) / 6; td++) {
                    //loop through possible scores with field goal
                    for (int fg = 0; fg <= (score - td_2 * 8 - td_1 * 7 - td * 6) / 3; fg++) {
                        //loop through possible scores that have safeties
                        for (int sfty = 0; sfty <= (score - td_2 * 8 - td_1 * 7 - td * 6 - fg * 3) / 2; sfty++) {
                            //check if score equals user input and print score if so
                            if (td_2 * 8 + td_1 * 7 + td * 6 + fg * 3 + sfty * 2 == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                    td_2, td_1, td, fg, sfty);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}