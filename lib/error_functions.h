#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void errMsg (const char *format, ...);

#ifdef __GNUC__
/* Этот макрос блокирует предупреждения компилятора при использовании
    команды 'gcc -Wall', жалующиеся, что "control reaches end of non-void
    function", то есть что управление достигло конца функции, которая
    должна вернуть значение, если мы используем следующие функции для
    прекращения выполнения main() или какой-нибудь другой функции,
    которая должна вернуть значение определенного типа (не void) */
#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit (const char *format, ...) NORETURN;
void err_exit (const char *format, ...) NORETURN;
void errExitEN (int errnum, const char *format, ...) NORETURN;
void fatal (const char *format, ...) NORETURN;
void usageErr (const char *format, ...) NORETURN;
void cmdLineErr (const char *format, ...) NORETURN;
#endif
