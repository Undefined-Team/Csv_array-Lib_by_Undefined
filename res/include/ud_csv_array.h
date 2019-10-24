#ifndef UD_CSV_ARRAY_H
# define UD_CSV_ARRAY_H

// Lib
#include <ud_string.h>
#include <ud_file_array.h>

// Macro
# define ud_csv_set_sep(...)                            ({ char **sep = ud_ptr_set(char*, __VA_ARGS__); (void)ud_csv_param_ctr(ud_csv_sep, sep); })
# define ud_csv_set_trim(...)                           ({ char **trim = ud_ptr_set(char*, __VA_ARGS__); (void)ud_csv_param_ctr(ud_csv_trim, trim); })
# define ud_csv_param_get()                             ud_csv_param_ctr(ud_csv_get, NULL)
# define ud_csv_param_free()                            (void)ud_csv_param_ctr(ud_csv_free, NULL)
/*
# define ud_csv_write(path, csv, ...)  \
({ \
    char *base_headers = {__VA_ARGS__}; \
    if (UD_UT_STATICA_LEN(base_headers))  \
    { \
        char *headers[] = {__VA_ARGS__, NULL}; \
        ud_csv_write_ctr(path, csv, headers); \
    } \
    else ud_csv_write_ctr(path, csv, NULL); \
})*/

# define ud_csva_set_sep(...)                           ud_csv_set_sep(__VA_ARGS__)
# define ud_csva_set_trim(...)                          ud_csv_set_trim(__VA_ARGS__)
# define ud_csva_param_get()                            ud_csv_param_get()

// Structures
typedef enum        {ud_csv_get,ud_csv_free,ud_csv_sep,ud_csv_trim} ud_csv_req;

typedef struct      uds_csv_param {
    char            **sep;
    char            **trim;
}                   ud_csv_param;


// Prototypes
ud_csv_param        ud_csv_param_ctr(ud_csv_req req, char **new_param);

ud_arr              *ud_csva_from_str(ud_arr *str, ud_bool remove_header);
ud_arr              *ud_csva_read(char *path, ud_bool remove_header);

ud_arr              *ud_csva_to_str(ud_arr *csv);
void                ud_csva_write_ctr(char *path, ud_arr *csv, char **headers);

#endif