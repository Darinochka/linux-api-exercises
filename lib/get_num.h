#ifndef GET_NUM_H
#define GET_NUM_H
#define GN_NONNEG 01 /* Значение должно быть >= 0 */
#define GN_GT_0 02 /* Значение должно быть > 0 */
/* По умолчанию целые числа являются десятичными */
#define GN_ANY_BASE 0100 /* Можно использовать любое основание –
наподобие strtol(3) */
#define GN_BASE_8 0200 /* Значение выражено в виде восьмеричного числа */
#define GN_BASE_16 0400 /* Значение выражено в виде шестнадцатеричного числа */
long getLong(const char *arg, int flags, const char *name);
int getInt(const char *arg, int flags, const char *name);
#endif
