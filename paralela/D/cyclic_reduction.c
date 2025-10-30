//
//  cyclic_reduction.c
//  Tridiagonal solver
//  Authors: Daniel Alfaro and Silvana Rossetto

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int load(double *a, double *b, double *c, double *d, int dim_sist)
{
    for (int i = 0; i < dim_sist; i++)
       if(fscanf(stdin, "%lf", &a[i]) != 1) return -1;
    for (int i = 0; i < dim_sist; i++)
       if(fscanf(stdin, "%lf", &b[i]) != 1) return -1;
    for (int i = 0; i < dim_sist; i++)
       if(fscanf(stdin, "%lf", &c[i]) != 1) return -1;
    for (int i = 0; i < dim_sist; i++)
       if(fscanf(stdin, "%lf", &d[i]) != 1) return -1;
    return 0;
}

void alg_rc(double *a, double *b, double *c, double *d, double *x, int p, int dim_sist)
{   
    int num_iter = p-1;
    int num_eq_iter = dim_sist/2;
    int space = 1;
    int var;
    int i1, i2, i, i_esq, i_dir;
    double tmp1, tmp2, det;

    // reduction stage
    for (int j = 0; j < num_iter; j++)
    {
        var = space;
        space *= 2;

        for (int l = 0; l < num_eq_iter; l++)
        {
       	   i = space * l + space - 1;
           i_esq = i - var;
           i_dir = i + var;
           if (i_dir >= dim_sist) i_dir = dim_sist - 1;
           tmp1 = a[i] / b[i_esq];
           tmp2 = c[i] / b[i_dir];
           b[i] = b[i] - c[i_esq] * tmp1 - a[i_dir] * tmp2;
           d[i] = d[i] - d[i_esq] * tmp1 - d[i_dir] * tmp2;
           a[i] = -a[i_esq] * tmp1;
           c[i] = -c[i_dir] * tmp2;
        }
        num_eq_iter /= 2;

    }

    // solution 2x2 system
    i1 = space - 1;
    i2 = 2 * space - 1;
    det = b[i2]*b[i1]-c[i1]*a[i2];
    x[i1] = (b[i2]*d[i1]-c[i1]*d[i2])/det;
    x[i2] = (d[i2]*b[i1]-d[i1]*a[i2])/det;

    // substitution stage
    int num_sol_iter = 2;
    for (int j = 0; j < num_iter; j++)
    {
        var = space/2;

        for (int l = 0; l < num_sol_iter; l++ )
        {
            int i = space * l + space/2 - 1;

            if (l==0)
                x[i] = (d[i] - c[i]*x[i+var])/b[i];
            else
                x[i] = (d[i] - a[i]*x[i-var] - c[i]*x[i+var])/b[i];

        }
        space /= 2;
        num_sol_iter *= 2;
    }
}

int main(void) {
    int dim_sist, p;

    if(fscanf(stdin, "%d", &p) != 1) {printf("erro\n"); return -1;}
    dim_sist = (int) pow(2,p);    

    double* a = (double*) malloc(dim_sist*sizeof(double));
    double* b = (double*) malloc(dim_sist*sizeof(double));
    double* c = (double*) malloc(dim_sist*sizeof(double));
    double* d = (double*) malloc(dim_sist*sizeof(double));
    double* x = (double*) malloc(dim_sist*sizeof(double));
    
    if ((a==NULL) || (b==NULL) || (c==NULL) || (d==NULL) || (x==NULL))
    {
        printf("Malloc error\n");
        return 1;
    }
        
    if(load(a, b, c, d, dim_sist))
    {
        printf("Load error\n");
        return 1;
    }
    
    alg_rc(a, b, c, d, x, p, dim_sist);
    
    for ( int i = 0; i < dim_sist; i++)
    {
        fprintf(stdout, "%lf ", x[i]);
    }
    
    fprintf(stdout, "\n");
    free(a);
    free(b);
    free(c);
    free(d);
    free(x);
    
    return 0;
}
