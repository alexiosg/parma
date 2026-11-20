#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .C calls */
extern int socp(int *, int *, int *, double *, double *, double *, double *, double *, double *, double *, double *, int *, double *, int *, int *, double *, double *, int *);
extern void socp_getwork(int *, int *, int *, int *, int *, int *, int *, int *, int *);

static const R_CMethodDef CEntries[] = {
    {"socp",         (DL_FUNC) &socp,         18},
    {"socp_getwork", (DL_FUNC) &socp_getwork,  9},
    {NULL, NULL, 0}
};

void R_init_parma(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
