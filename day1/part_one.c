#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *
 * DAY 1 - Part 1:
 * Something is wrong with global snow production, and you've been selected to take a look. The Elves have even given
 * you a map; on it, they've used stars to mark the top fifty locations that are likely to be having problems.Collect
 * stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is
 * unlocked when you complete the first. Each puzzle grants one star. Good luck!
 *
 * You try to ask why they can't just use a weather machine ("not powerful enough") and where they're even sending you
 * ("the sky") and why your map looks mostly blank ("you sure ask a lot of questions") and hang on did you just say the
 * sky
 * ("of course, where do you think snow comes from") when you realize that the Elves are already loading you into a
 * trebuchet
 * ("please hold still, we need to strap you in").
 *
 * As they're making the final adjustments, they discover that their calibration document (your puzzle input)
 * has been amended by a very young Elf who was apparently just excited to show off her art skills.
 * Consequently, the Elves are having trouble reading the values on the document.
 *
 *
 * The newly-improved calibration document consists of lines of text;
 * each line originally contained a specific calibration value that the Elves now need to recover.
 * On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to
 * form a single two-digit number.
 *
 * For Example:
 *
 * 1abc2
 * pqr3stu8vwx
 * a1b2c3d4e5f
 * treb7uchet
 *
 * In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces
 * 142. Consider your entire calibration document. What is the sum of all of the calibration values?
 *
 * In Ascii digits are the values 48-57
 */

#define MAX_CHARS_PER_LINE 100
#define MAX_LINES 1000

int main(int argc, char *argv[])
{
    char lines[MAX_LINES][MAX_CHARS_PER_LINE];

    if (argc < 2)
    {
        perror("Missing Required Input Files\n");
        return -1;
    }

    char *file_name;
    file_name = argv[1];
    FILE *file = fopen(file_name, "r");

    if (file == NULL)
    {
        perror("Error Opening File");
        return -1;
    }

    int line_count = 0;

    while (!feof(file) && !ferror(file))
    {
        if (fgets(lines[line_count], MAX_CHARS_PER_LINE, file) != NULL)
        {
            line_count++;
        }
    }

    fclose(file);
    int total = 0;

    for (int i = 0; i < line_count; i++)
    {
        char *line = lines[i];
        int line_length = strlen(line);
        char first_digit_char = '0';
        char last_digit_char = '0';
        char concated[3] = {};

        for (int j = 0; j < line_length; j++)
        {
            char c = line[j];

            if(c == '\0'){
                continue;
            }
            
            if (c <= '0' || c > '9')
            {
                continue;
            }
            
            if(first_digit_char == '0')
            {
                first_digit_char = c;
            }

            last_digit_char = c;
        }

        concated[0] = first_digit_char;
        concated[1] = last_digit_char;
        concated[2] = '\0';

        total += atoi(concated);

    }

    printf("total: %d\n", total);

    return 0;
}
