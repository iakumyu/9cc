#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "引数の値が正しくありません。\n");
        return 1;
    }

    char *p = argv[1];
    printf("コマンドライン引数の最初のポインタ変数pのアドレス（=argv[1]のアドレス）は，%p です\n", p);
    printf("コマンドライン引数の最初のポインタ変数pが指す値（=argv[1]の一文字目）は，%c です\n", *p);
    printf(".intel_syntax noprefix\n");
    printf(".global _main\n");
    printf("_main:\n");
    printf("  mov rax, %ld\n", strtol(p, &p, 10));
    printf("(1).strtol関数でlong型の値に変換したときに、数値として解釈できない文字「+」or「-」のアドレスであるポインタ変数pのアドレスは，%p です\n", p);
    printf("(2).strtol関数でlong型の値に変換したときに、数値として解釈できない文字「+」or「-」のアドレスであるポインタ変数pが指す値は，%c です\n", *p);

    while (*p)
    {
        if (*p == '+')
        {
            p++;
            printf("(3)+だったのでインクリメントしたあとのポインタ変数pのアドレスは，%p です\n", p);
            printf("(4)+だったのでインクリメントしたあとのポインタ変数pが指す値は，%c です\n", *p);
            printf("  add rax, %ld\n", strtol(p, &p, 10));
            printf("(5).strtol関数でlong型の値に変換したときに、数値として解釈できない文字「+」or「-」のアドレスであるポインタ変数pのアドレスは，%p です\n", p);
            printf("(6).strtol関数でlong型の値に変換したときに、数値として解釈できない文字「+」or「-」のアドレスであるポインタ変数pが指す値は，%c です\n", *p);
            continue;
        }

        if (*p == '-')
        {
            p++;
            printf("(7)-だったのでインクリメントしたあとのポインタ変数pのアドレスは，%p です\n", p);
            printf("(8)+だったのでインクリメントしたあとのポインタ変数pが指す値は，%c です\n", *p);
            printf("  sub rax, %ld\n", strtol(p, &p, 10));
            printf("(9).strtol関数でlong型の値に変換したときに、数値として解釈できない文字「+」or「-」のアドレスであるポインタ変数pのアドレスは，%p です\n", p);
            printf("(10).strtol関数でlong型の値に変換したときに、数値として解釈できない文字「+」or「-」のアドレスであるポインタ変数pが指す値は，%c です\n", *p);
            continue;
        }

        fprintf(stderr, "予期せぬ文字です: '%c'\n", *p);
        return 1;
    }

    printf("  ret\n");
    return 0;
}