#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 *Your calculation isn't quite right. It looks like some of the digits are actually spelled out with letters: 
 one, two, three, four, five, six, seven, eight, and nine also count as valid "digits".

 *Equipped with this new information, you now need to find the real first and last digit on each line. For example:

two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen

In this example, the calibration values are 29, 83, 13, 24, 42, 14, and 76. Adding these together produces 281.
 *
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
                int k = 0;
                int word_index = 0;
                char word_char = '0';
                char word[6] = {};
                char current_char = c;
                while(k < 6){
                    if(current_char > '0' || current_char <= '9') {
                        j += k;
                        break;
                    }
                    k++;
                    word[word_index] = current_char;
                    word[k + 1] = '\0';
                    if(k >= 3) {
                    switch(word){
                        case "one" : {
                            word_char = '1';
                            break;
                        }
                        case "two" : {
                            word_char = '2';
                            break;
                        }
                        case "three" : {
                            word_char = '3';
                            break;
                        }
                        case "four" : {
                            word_char = '4';
                            break;
                        }
                        case "five" : {
                            word_char = '5';
                            break;
                        }
                        case "six" : {
                            word_char = '6';
                            break;
                        }
                        case "seven" : {
                            word_char = '7';
                            break;
                        }
                        case "eight" : {
                            word_char = '8';
                            break;
                        }
                        case "nine" : {
                            word_char = '9';
                            break;
                        }
                        default : {
                            current_char = line[j + 1];
                            continue;
                        }
                    }
                        if(word_char != '0'){
                            if(first_digit_char == '0')
                            {
                                first_digit_char = word_char;
                            }

                            last_digit_char = word_char;
                            break;
                        }


                    }

                } 
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
