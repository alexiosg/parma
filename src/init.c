#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

extern void socp_getwork(int *, int *, int *, int *, int *, int *, int *, 
                         int *, int *);
extern int socp( int *, int *, int *, double *, double *, double *, double *,
        double *, double *, double *, double *, int *, double *, int *, int *,
        double *, double *, int *);

static const R_CMethodDef CEntries[] = {
    {"socp_getwork",    (DL_FUNC) &socp_getwork,    9},
    {"socp",    (DL_FUNC) &socp,    18}
};

void R_init_parma(DllInfo *dll)
{
    R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
