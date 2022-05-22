// Elle Nowakowski
// May 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *complete_list, *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp7, *fp8, *fp9, *fp10, *fp11, *fp12, *fp13, *fp14, *fp15, *fp16, *fp17, *fp18, *fp19, *fp20, *fp21, *fp22, *fp23, *fp24, *fp25, *fp26, *fp27, *fp28, *fp29, *fp30, *fp31, *fpn;
    int max_length = 50 * sizeof(char);
    char word[max_length];

    complete_list = fopen("words/all_words.txt", "r");

    fp1 = fopen("words/words_1.txt","w");
    fp2 = fopen("words/words_2.txt","w");
    fp3 = fopen("words/words_3.txt","w");
    fp4 = fopen("words/words_4.txt","w");
    fp5 = fopen("words/words_5.txt","w");
    fp6 = fopen("words/words_6.txt","w");
    fp7 = fopen("words/words_7.txt","w");
    fp8 = fopen("words/words_8.txt","w");
    fp9 = fopen("words/words_9.txt","w");
    fp10 = fopen("words/words_10.txt","w");
    fp11 = fopen("words/words_11.txt","w");
    fp12 = fopen("words/words_12.txt","w");
    fp13 = fopen("words/words_13.txt","w");
    fp14 = fopen("words/words_14.txt","w");
    fp15 = fopen("words/words_15.txt","w");
    fp16 = fopen("words/words_16.txt","w");
    fp17 = fopen("words/words_17.txt","w");
    fp18 = fopen("words/words_18.txt","w");
    fp19 = fopen("words/words_19.txt","w");
    fp20 = fopen("words/words_20.txt","w");
    fp21 = fopen("words/words_21.txt","w");
    fp22 = fopen("words/words_22.txt","w");
    fp23 = fopen("words/words_23.txt","w");
    fp24 = fopen("words/words_24.txt","w");
    fp25 = fopen("words/words_25.txt","w");
    fp26 = fopen("words/words_26.txt","w");
    fp27 = fopen("words/words_27.txt","w");
    fp28 = fopen("words/words_28.txt","w");
    fp29 = fopen("words/words_29.txt","w");
    fp30 = fopen("words/words_30.txt","w");
    fp31 = fopen("words/words_31.txt","w");
    fpn = fopen("words/words_n.txt","w");

    while(fscanf(complete_list, "%s", word) != EOF) {
        switch(strlen(word)) {
            case 1:
                fprintf(fp1, "%s\n", &word);
                break;
            case 2:
                fprintf(fp2, "%s\n", &word);
                break;
            case 3:
                fprintf(fp3, "%s\n", &word);
                break;
            case 4:
                fprintf(fp4, "%s\n", &word);
                break;
            case 5:
                fprintf(fp5, "%s\n", &word);
                break;
            case 6:
                fprintf(fp6, "%s\n", &word);
                break;
            case 7:
                fprintf(fp7, "%s\n", &word);
                break;
            case 8:
                fprintf(fp8, "%s\n", &word);
                break;
            case 9:
                fprintf(fp9, "%s\n", &word);
                break;
            case 10:
                fprintf(fp10, "%s\n", &word);
                break;
            case 11:
                fprintf(fp11, "%s\n", &word);
                break;
            case 12:
                fprintf(fp12, "%s\n", &word);
                break;
            case 13:
                fprintf(fp13, "%s\n", &word);
                break;
            case 14:
                fprintf(fp14, "%s\n", &word);
                break;
            case 15:
                fprintf(fp15, "%s\n", &word);
                break;
            case 16:
                fprintf(fp16, "%s\n", &word);
                break;
            case 17:
                fprintf(fp17, "%s\n", &word);
                break;
            case 18:
                fprintf(fp18, "%s\n", &word);
                break;
            case 19:
                fprintf(fp19, "%s\n", &word);
                break;
            case 20:
                fprintf(fp20, "%s\n", &word);
                break;
            case 21:
                fprintf(fp21, "%s\n", &word);
                break;
            case 22:
                fprintf(fp22, "%s\n", &word);
                break;
            case 23:
                fprintf(fp23, "%s\n", &word);
                break;
            case 24:
                fprintf(fp24, "%s\n", &word);
                break;
            case 25:
                fprintf(fp25, "%s\n", &word);
                break;
            case 26:
                fprintf(fp26, "%s\n", &word);
                break;
            case 27:
                fprintf(fp27, "%s\n", &word);
                break;
            case 28:
                fprintf(fp28, "%s\n", &word);
                break;
            case 29:
                fprintf(fp29, "%s\n", &word);
                break;
            case 30:
                fprintf(fp30, "%s\n", &word);
                break;
            case 31:
                fprintf(fp31, "%s\n", &word);
                break;
            default:
                fprintf(fpn, "%s\n", &word);
                break;
        }
    }

    fclose(complete_list);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);
    fclose(fp6);
    fclose(fp7);
    fclose(fp8);
    fclose(fp9);
    fclose(fp10);
    fclose(fp11);
    fclose(fp12);
    fclose(fp13);
    fclose(fp14);
    fclose(fp15);
    fclose(fp16);
    fclose(fp17);
    fclose(fp18);
    fclose(fp19);
    fclose(fp20);
    fclose(fp21);
    fclose(fp22);
    fclose(fp23);
    fclose(fp24);
    fclose(fp25);
    fclose(fp26);
    fclose(fp27);
    fclose(fp28);
    fclose(fp29);
    fclose(fp30);
    fclose(fp31);
    fclose(fpn);
}