// Elle Nowakowski
// May 2022

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mpi.h"

int *array;

void read_num_letters(int* num_letters, int* local_letters, int my_rank, int comm_sz, MPI_Comm comm) {
    if(my_rank == 0) {
        printf("How many letters would you like to play with?\n");
        scanf("%d", num_letters);
    }

    MPI_Bcast(num_letters, 1, MPI_INT, 0, comm);

    *local_letters = *num_letters / comm_sz;
}

int read_hard_mode(int my_rank) {
    int hard_mode;
    char input_string[10];
    if(my_rank == 0) {
        printf("Are you playing in hard mode? (Y/N)\n");
        scanf("%s", input_string);
        if(strcmp(input_string, "yes") == 0 || strcmp(input_string, "y") == 0) {
            hard_mode = 0;
        } else if(strcmp(input_string, "no") == 0 || strcmp(input_string, "n") == 0) {
            hard_mode = 1;
        }
    }
    return hard_mode;
}

int cmp(const void *a, const void *b){
    int ia = *(int *)a;
    int ib = *(int *)b;
    return array[ia] < array[ib] ? -1 : array[ia] > array[ib];
}

main(int argc, char *argv[]) {
    int hard_mode;
    int num_letters, local_letters;
    int my_rank, comm_sz;
    FILE *fp, *fp_guesses_1, *fp_guesses_2, *fp_guesses_3, *fp_guesses_4, *fp_guesses_5, *fp_guesses_6, *fp_temp;
    MPI_Comm comm;

    MPI_Init(&argc, &argv);
    comm = MPI_COMM_WORLD;

    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);

    if(my_rank == 0) {
        read_num_letters(&num_letters, &local_letters, my_rank, comm_sz, comm);
        hard_mode = read_hard_mode(my_rank);
    }

    // dictionaries
    switch(num_letters) {
        case 1: 
            fp = fopen("words/words_1.txt", "r");
            break;
        case 2: 
            fp = fopen("words/words_2.txt", "r");
            break;
        case 3: 
            fp = fopen("words/words_3.txt", "r");
            break;
        case 4: 
            fp = fopen("words/words_4.txt", "r");
            break;
        case 5: 
            fp = fopen("words/words_5.txt", "r");
            break;
        case 6: 
            fp = fopen("words/words_6.txt", "r");
            break;
        case 7: 
            fp = fopen("words/words_7.txt", "r");
            break;
        case 8: 
            fp = fopen("words/words_8.txt", "r");
            break;
        case 9: 
            fp = fopen("words/words_9.txt", "r");
            break;
        case 10: 
            fp = fopen("words/words_10.txt", "r");
            break;
        case 11: 
            fp = fopen("words/words_11.txt", "r");
            break;
        case 12: 
            fp = fopen("words/words_12.txt", "r");
            break;
        case 13: 
            fp = fopen("words/words_13.txt", "r");
            break;
        case 14: 
            fp = fopen("words/words_14.txt", "r");
            break;
        case 15: 
            fp = fopen("words/words_15.txt", "r");
            break;
        case 16: 
            fp = fopen("words/words_16.txt", "r");
            break;
        case 17: 
            fp = fopen("words/words_17.txt", "r");
            break;
        case 18: 
            fp = fopen("words/words_18.txt", "r");
            break;
        case 19: 
            fp = fopen("words/words_19.txt", "r");
            break;
        case 20: 
            fp = fopen("words/words_20.txt", "r");
            break;
        case 21: 
            fp = fopen("words/words_21.txt", "r");
            break;
        case 22: 
            fp = fopen("words/words_22.txt", "r");
            break;
        case 23: 
            fp = fopen("words/words_23.txt", "r");
            break;
        case 24: 
            fp = fopen("words/words_24.txt", "r");
            break;
        case 35: 
            fp = fopen("words/words_25.txt", "r");
            break;
        case 26: 
            fp = fopen("words/words_26.txt", "r");
            break;
        case 27: 
            fp = fopen("words/words_27.txt", "r");
            break;
        case 28: 
            fp = fopen("words/words_28.txt", "r");
            break;
        case 29: 
            fp = fopen("words/words_29.txt", "r");
            break;
        case 30: 
            fp = fopen("words/words_30.txt", "r");
            break;
        case 31: 
            fp = fopen("words/words_31.txt", "r");
            break;
        default:
            fp = fopen("words/words_n.txt", "r");
            break;
    }

    int max_length = num_letters * sizeof(char);
    char word[max_length];
    int a[15000 * sizeof(int)], b[15000 * sizeof(int)], c[15000 * sizeof(int)], d[15000 * sizeof(int)], e[15000 * sizeof(int)], f[15000 * sizeof(int)], g[15000 * sizeof(int)], h[15000 * sizeof(int)], i[15000 * sizeof(int)], j[15000 * sizeof(int)], k[15000 * sizeof(int)], l[15000 * sizeof(int)], m[15000 * sizeof(int)], n[15000 * sizeof(int)], o[15000 * sizeof(int)], p[15000 * sizeof(int)], q[15000 * sizeof(int)], r[15000 * sizeof(int)], s[15000 * sizeof(int)], t[15000 * sizeof(int)], u[15000 * sizeof(int)], v[15000 * sizeof(int)], w[15000 * sizeof(int)], x[15000 * sizeof(int)], y[15000 * sizeof(int)], z[15000 * sizeof(int)];
    int a_count = 0, b_count = 0, c_count = 0, d_count = 0, e_count = 0, f_count = 0, g_count = 0, h_count = 0, i_count = 0, j_count = 0, k_count = 0, l_count = 0, m_count = 0, n_count = 0, o_count = 0, p_count = 0, q_count = 0, r_count = 0, s_count = 0, t_count = 0, u_count = 0, v_count = 0, w_count = 0, x_count = 0, y_count = 0, z_count = 0;
    int count;

    // letter frequency
    while(fscanf(fp, "%s", word) != EOF) {
        for(count = 0; count < num_letters; count++) {
            switch(word[count]) {
                case 'a':
                    a[a_count] = count;
                    a_count++;
                    break;
                case 'b':
                    b[b_count] = count;
                    b_count++;
                    break;
                case 'c':
                    c[c_count] = count;
                    c_count++;
                    break;
                case 'd':
                    d[d_count] = count;
                    d_count++;
                    break;
                case 'e':
                    e[e_count] = count;
                    e_count++;
                    break;
                case 'f':
                    f[f_count] = count;
                    f_count++;
                    break;
                case 'g':
                    g[g_count] = count;
                    g_count++;
                    break;
                case 'h':
                    h[h_count] = count;
                    h_count++;
                    break;
                case 'i':
                    i[i_count] = count;
                    i_count++;
                    break;
                case 'j':
                    j[j_count] = count;
                    j_count++;
                    break;
                case 'k':
                    k[k_count] = count;
                    k_count++;
                    break;
                case 'l':
                    l[l_count] = count;
                    l_count++;
                    break;
                case 'm':
                    m[m_count] = count;
                    m_count++;
                    break;
                case 'n':
                    n[n_count] = count;
                    n_count++;
                    break;
                case 'o':
                    o[o_count] = count;
                    o_count++;
                    break;
                case 'p':
                    p[p_count] = count;
                    p_count++;
                    break;
                case 'q':
                    q[q_count] = count;
                    q_count++;
                    break;
                case 'r':
                    r[r_count] = count;
                    r_count++;
                    break;
                case 's':
                    s[s_count] = count;
                    s_count++;
                    break;
                case 't':
                    t[t_count] = count;
                    t_count++;
                    break;
                case 'u':
                    u[u_count] = count;
                    u_count++;
                    break;
                case 'v':
                    v[v_count] = count;
                    v_count++;
                    break;
                case 'w':
                    w[w_count] = count;
                    w_count++;
                    break;
                case 'x':   
                    x[x_count] = count;
                    x_count++;
                    break;
                case 'y':
                    y[y_count] = count;
                    y_count++;
                    break;
                case 'z':
                    z[z_count] = count;
                    z_count++;
                    break;
                default:
                    break;
            }
        }
    }

    a_count--;
    b_count--;
    c_count--;
    d_count--;
    e_count--;
    f_count--;
    g_count--;
    h_count--;
    i_count--;
    j_count--;
    k_count--;
    l_count--;
    m_count--;
    n_count--;
    o_count--;
    p_count--;
    q_count--;
    r_count--;
    s_count--;
    t_count--;
    u_count--;
    v_count--;
    w_count--;
    x_count--;
    y_count--;
    y_count--;

    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int data[] = {a_count, b_count, c_count, d_count, e_count, f_count, g_count, h_count, i_count, j_count, k_count, l_count, m_count, n_count, o_count, p_count, q_count, r_count, s_count, t_count, u_count, v_count, w_count, x_count, y_count, z_count};
    int size = sizeof(data) / sizeof(*data);
    int index[size];

    for(count = 0; count < size; count++){
        index[count] = count;
    }
    
    // most common letters
    array = data;
    if(my_rank == 0) {
        qsort(index, size, sizeof(*index), cmp);
        // DEBUG
        // printf("\nLetter Frequency\n");
        // for(count = 0; count < size; count++){
        //     printf("%c: %d\t%d\n", letters[index[count]], data[index[count]], index[count]);
        // }
    }
    
    char input_results[num_letters];
    char input_previous[num_letters];
    char success[num_letters];
    char guess[num_letters];
    int guess_count;
    int num_same;
    int random_num_1;
    int random_num_2;
    int random_num_3;
    int word_count = 0;
    int counter, counters;
    int miss_counter;
    for(count = 0; count < num_letters; count++) {
        success[count] = 'g';
    }
    bool won = false;
    bool remove = false;
    guess_count = 0;
    fp_guesses_1 = fopen("words/guesses_1.txt", "w+");
    fp_guesses_2 = fopen("words/guesses_2.txt", "w+");
    fp_guesses_3 = fopen("words/guesses_3.txt", "w+");
    fp_guesses_4 = fopen("words/guesses_4.txt", "w+");
    fp_guesses_5 = fopen("words/guesses_5.txt", "w+");
    fp_guesses_6 = fopen("words/guesses_6.txt", "w+");
    if(hard_mode == 0) {
        // hard mode
        while(!won || guess_count < 6) {
            guess_count++;
            // select first word - not parallel
            if(guess_count == 1) {
                rewind(fp);
                while(fscanf(fp, "%s", word) != EOF) {
                    num_same = 0;
                    for(count = 0; count < num_letters; count++) {
                        for(counter = size - 1; counter > size - num_letters - 3; counter--) {
                            if(word[count] == letters[index[counter]]) {
                                for(counters = 0; counters < num_letters; counters++) {
                                    if((counters != count) && (word[count] == word[counters])) {
                                        num_same = num_same - 100;
                                    }
                                }
                                num_same++;
                            }
                        }
                        for(counter = 0; counter < 18; counter++) {
                            if(word[count] == letters[index[counter]]) {
                                num_same = num_same - 100;
                            }
                        }
                        if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
                            num_same = num_same - 100;
                        }
                        if(word[num_letters - 1] == 'a' || word[num_letters - 1] == 'e' || word[num_letters - 1] == 'i' || word[num_letters - 1] == 'o' || word[num_letters - 1] == 'u') {
                            num_same = num_same - 100;
                        }
                        if(word[num_letters - 1] == 's') {
                            num_same = num_same - 100;
                        }
                    }
                    if(num_same > num_letters * 3 / 4) {
                        fprintf(fp_guesses_1, "%s\n", &word);
                        word_count++;
                    }
                }
                count = -1;
                if(my_rank == 0) {
                    printf("\nSelect one of these words (or check temp.txt for more options):\n");
                }
                rewind(fp_guesses_1);
                if(my_rank == 0) {
                    srand(time(NULL));
                    random_num_1 = rand() % word_count;
                    random_num_2 = rand() % word_count;
                    random_num_3 = rand() % word_count;
                    while(fscanf(fp_guesses_1, "%s", word) != EOF) {
                        count++;
                        if((count == random_num_1) || (count == random_num_2) || (count == random_num_3)) {
                            printf("%s\n", word);
                        }
                    }
                }
            } else {
                if(my_rank == 0) {
                    // used w for greyed out squares
                    printf("What word did you choose?\n");
                    scanf("%s", input_previous);
                    printf("Enter the resultant square colors (g/y/w):\n");
                    scanf("%s", input_results);

                    if(guess_count == 2) {
                        rewind(fp);
                        while(fscanf(fp, "%s", word) != EOF) {
                            for(counter = 0; counter < num_letters; counter++) {
                                MPI_Send(&word[counter], 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
                            }
                            fprintf(fp_guesses_2, "%s\n", &word);
                        }
                    }                    
                }
                for(count = 0; count < num_letters; count++) {
                    fp_temp = fopen("words/temp.txt", "w+");
                    if(input_results[count] == 'w') {
                        // remove all with letter input_previous[count] 
                        rewind(fp_guesses_2);
                        while(fscanf(fp_guesses_2, "%s", word) != EOF) {
                            remove = false;
                            for(counter = 0; counter < num_letters; counter++) {
                                MPI_Send(&word[counter], 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
                                if(word[counter] == input_previous[count]) {
                                    remove = true;
                                }
                            }
                            if(remove == false) {
                                fprintf(fp_temp, "%s\n", &word);
                            }
                        }
                    } else if(input_results[count] == 'g') {
                        // remove all words without input_previous[count] at count
                        rewind(fp_guesses_2);
                        while(fscanf(fp_guesses_2, "%s", word) != EOF) {
                            remove = false;
                            if(word[count] != input_previous[count]) {
                                remove = true;
                            }
                            if(remove == false) {
                                fprintf(fp_temp, "%s\n", &word);
                            }
                        }
                    } else {
                        // remove all words without input_previous[count]
                        rewind(fp_guesses_2);
                        while(fscanf(fp_guesses_2, "%s", word) != EOF) {
                            miss_counter = 0;
                            remove = false;
                            for(counter = 0; counter < num_letters; counter++) {
                                MPI_Send(&word[counter], 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
                                if(word[counter] == input_previous[count]) {
                                    miss_counter++;
                                }
                            }
                            if(word[count] == input_previous[count]) {
                                remove = true;
                            }
                            if((miss_counter > 0) && (remove == false)) {
                                fprintf(fp_temp, "%s\n", &word);
                            }
                        }
                    }
                    fclose(fp_guesses_2);
                    fp_guesses_2 = fopen("words/guesses_2.txt", "w+");
                    rewind(fp_temp);
                    word_count = 0;
                    while(fscanf(fp_temp, "%s", word) != EOF) {
                        MPI_Recv(&word, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        fprintf(fp_guesses_2, "%s\n", &word);
                        word_count++;
                    }
                    fclose(fp_temp);
                }
                if(my_rank == 0) {
                    srand(time(NULL));
                    random_num_1 = rand() % word_count;
                    random_num_2 = rand() % word_count;
                    random_num_3 = rand() % word_count;
                    printf("\nSelect one of these words (or check temp.txt for more options):\n");
                    rewind(fp_guesses_2);
                    while(fscanf(fp_guesses_2, "%s", word) != EOF) {
                        count++;
                        if((count == random_num_1) || (count == random_num_2) || (count == random_num_3)) {
                            printf("%s\n", word);
                        }
                    }
                }
            }
            if(strcmp(input_results, success) == 0) {
                won = true;
                if(my_rank == 0) {
                    printf("Congratulations!");
                }
            } 
        } 
    } else {
        // regular mode
        while(!won || guess_count < 6) {
            guess_count++;
            // select first word - not parallel
            if(guess_count == 1) {
                rewind(fp);
                while(fscanf(fp, "%s", word) != EOF) {
                    num_same = 0;
                    for(count = 0; count < num_letters; count++) {
                        for(counter = size - 1; counter > size - num_letters - 3; counter--) {
                            if(word[count] == letters[index[counter]]) {
                                for(counters = 0; counters < num_letters; counters++) {
                                    if((counters != count) && (word[count] == word[counters])) {
                                        num_same = num_same - 100;
                                    }
                                }
                                num_same++;
                            }
                        }
                        for(counter = 0; counter < 18; counter++) {
                            if(word[count] == letters[index[counter]]) {
                                num_same = num_same - 100;
                            }
                        }
                        if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
                            num_same = num_same - 100;
                        }
                        if(word[num_letters - 1] == 'a' || word[num_letters - 1] == 'e' || word[num_letters - 1] == 'i' || word[num_letters - 1] == 'o' || word[num_letters - 1] == 'u') {
                            num_same = num_same - 100;
                        }
                        if(word[num_letters - 1] == 's') {
                            num_same = num_same - 100;
                        }
                    }
                    if(num_same > num_letters * 3 / 4) {
                        fprintf(fp_guesses_1, "%s\n", &word);
                        word_count++;
                    }
                }
                count = -1;
                if(my_rank == 0) {
                    printf("\nSelect one of these words (or check temp.txt for more options):\n");
                }
                rewind(fp_guesses_1);
                if(my_rank == 0) {
                    srand(time(NULL));
                    random_num_1 = rand() % word_count;
                    random_num_2 = rand() % word_count;
                    random_num_3 = rand() % word_count;
                    while(fscanf(fp_guesses_1, "%s", word) != EOF) {
                        count++;
                        if((count == random_num_1) || (count == random_num_2) || (count == random_num_3)) {
                            printf("%s\n", word);
                        }
                    }
                }
            } else {
                if(my_rank == 0) {
                    // used w for greyed out squares
                    printf("What word did you choose?\n");
                    scanf("%s", input_previous);
                    printf("Enter the resultant square colors (g/y/w):\n");
                    scanf("%s", input_results);

                    if(guess_count == 2) {
                        rewind(fp);
                        while(fscanf(fp, "%s", word) != EOF) {
                            for(counter = 0; counter < num_letters; counter++) {
                                MPI_Send(&word[counter], 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
                            }
                            fprintf(fp_guesses_2, "%s\n", &word);
                        }
                    }                    
                }
                for(count = 0; count < num_letters; count++) {
                    fp_temp = fopen("words/temp.txt", "w+");
                    if(input_results[count] == 'w') {
                        // remove all with letter input_previous[count] 
                        rewind(fp_guesses_2);
                        while(fscanf(fp_guesses_2, "%s", word) != EOF) {
                            remove = false;
                            for(counter = 0; counter < num_letters; counter++) {
                                MPI_Send(&word[counter], 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
                                if(word[counter] == input_previous[count]) {
                                    remove = true;
                                }
                            }
                            if(remove == false) {
                                fprintf(fp_temp, "%s\n", &word);
                            }
                        }
                    } else if(input_results[count] == 'g') {
                        // remove all words without input_previous[count] at count
                        rewind(fp_guesses_2);
                        while(fscanf(fp_guesses_2, "%s", word) != EOF) {
                            remove = false;
                            if(word[count] != input_previous[count]) {
                                remove = true;
                            }
                            if(remove == false) {
                                fprintf(fp_temp, "%s\n", &word);
                            }
                        }
                    } else {
                        // remove all words without input_previous[count]
                        rewind(fp_guesses_2);
                        while(fscanf(fp_guesses_2, "%s", word) != EOF) {
                            miss_counter = 0;
                            remove = false;
                            for(counter = 0; counter < num_letters; counter++) {
                                MPI_Send(&word[counter], 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
                                if(word[counter] == input_previous[count]) {
                                    miss_counter++;
                                }
                            }
                            if(word[count] == input_previous[count]) {
                                remove = true;
                            }
                            if((miss_counter > 0) && (remove == false)) {
                                fprintf(fp_temp, "%s\n", &word);
                            }
                        }
                    }
                    fclose(fp_guesses_2);
                    fp_guesses_2 = fopen("words/guesses_2.txt", "w+");
                    rewind(fp_temp);
                    word_count = 0;
                    while(fscanf(fp_temp, "%s", word) != EOF) {
                        MPI_Recv(&word, 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                        fprintf(fp_guesses_2, "%s\n", &word);
                        word_count++;
                    }
                    fclose(fp_temp);
                }
                if(my_rank == 0) {
                    srand(time(NULL));
                    random_num_1 = rand() % word_count;
                    random_num_2 = rand() % word_count;
                    random_num_3 = rand() % word_count;
                    printf("\nSelect one of these words (or check temp.txt for more options):\n");
                    rewind(fp_guesses_2);
                    while(fscanf(fp_guesses_2, "%s", word) != EOF) {
                        count++;
                        if((count == random_num_1) || (count == random_num_2) || (count == random_num_3)) {
                            printf("%s\n", word);
                        }
                    }
                }
            }
            if(strcmp(input_results, success) == 0) {
                won = true;
                if(my_rank == 0) {
                    printf("Congratulations!");
                }
            } 
        } 
    }

    fclose(fp);
    fclose(fp_guesses_1);
    fclose(fp_guesses_2);
    fclose(fp_guesses_3);
    fclose(fp_guesses_4);
    fclose(fp_guesses_5);
    fclose(fp_guesses_6);
    
    MPI_Finalize();
    return 0;
}