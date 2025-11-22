#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int p_id;
    long MCS;
    char lyrics[100][100];
    int no_of_words;
} Mayabini;

Mayabini FINAL_RESULT[1000] = {{0, 0, {""}, 0}};

Mayabini *takeInput(long long *count)
{
    Mayabini *m;
    printf("Enter the no. of pages: ");
    scanf("%lld", count);
    long long n = *count;
    long long k = 0;
    m = (Mayabini *)malloc(n * sizeof(Mayabini));
    while (k < n)
    {
        char c;
        scanf("%d %ld", &(m[k].p_id), &(m[k].MCS));
        int i = 0, j = 0;
        getchar();
        while ((c = getchar()) != '\n')
        {
            if (j == 0 && (c == ' ' || c == '\t' || c == 0 || c == '\n'))
                continue;
            if (c == ' ')
            {
                m[k].lyrics[i][j] = 0;
                i++;
                j = 0;
            }
            else
            {
                m[k].lyrics[i][j] = c;
                j++;
            }
        }
        m[k].lyrics[i][j] = 0;
        m[k].no_of_words = ++i;
        k++;
    }
    return m;
}

void copyResult(Mayabini source[])
{
    long i;
    for (i = 0L; source[i].p_id != 0; i++)
    {
        FINAL_RESULT[i] = source[i];
        source[i].p_id = 0;
        source[i].MCS = 0L;
        source[i].no_of_words = 0;
        source[i].lyrics[0][0] = 0;
    }
    while (FINAL_RESULT[i].p_id != 0)
    {
        FINAL_RESULT[i].p_id = 0;
        FINAL_RESULT[i].MCS = 0L;
        FINAL_RESULT[i].no_of_words = 0;
        FINAL_RESULT[i].lyrics[0][0] = 0;
        i++;
    }
}

long calculateTotalMCS(Mayabini m[])
{
    long sum = 0L;
    for (long long i = 0LL; m[i].p_id != 0; i++)
    {
        sum += m[i].MCS;
    }
    return sum;
}

int getResult(Mayabini *m, long long n)
{
    if (m == NULL)
        return 0;
    Mayabini *TEMP_RESULT = calloc(n, sizeof(Mayabini));
    long long x = 1, i;
    long max_MCS = 0, current_MCS = 0;

    TEMP_RESULT[0] = m[0];
    for (i = 0; i < n - 1; i++)
    {
        if (!strcmp(strlwr(m[i].lyrics[m[i].no_of_words - 1]), strlwr(m[i + 1].lyrics[0])))
        {
            TEMP_RESULT[x++] = m[i + 1];
        }
        else
        {
            current_MCS = calculateTotalMCS(TEMP_RESULT);
            x = 1;
            if (current_MCS > max_MCS)
            {
                copyResult(TEMP_RESULT);
                max_MCS = current_MCS;
            }
            TEMP_RESULT[0] = m[i + 1];
        }
    }
    current_MCS = calculateTotalMCS(TEMP_RESULT);
    if (current_MCS > max_MCS)
        copyResult(TEMP_RESULT);
    
    free(TEMP_RESULT);
    return 1;
}

void displayResult()
{
    printf("\n%ld\n", calculateTotalMCS(FINAL_RESULT));
    for(long i = 0L; FINAL_RESULT[i].p_id != 0; i++)
        printf("%3d ", FINAL_RESULT[i].p_id);
    putchar('\n');
}

int main()
{
    Mayabini *pages = NULL;
    long long n;
    pages = takeInput(&n);
    getResult(pages, n);
    
    displayResult();

    return 0;
}