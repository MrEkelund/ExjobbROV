/*   Copyright 2005-2015 The MathWorks, Inc. */
/*   Written by Peter Lindskog. */

/* Include libraries. */
#include "mex.h"
#include <math.h>

/* Specify the number of outputs here. */
#define NY 9

/* State equations. */
void compute_dx(double *dx, double *x, double *u, double **p)
{
  /* Retrieve model parameters. */
  double *m, *g, *rho, *V, *lx1, *ly1, *ly2, *lx2, *ly3, *lx5, *ly4,
  *lz6, *zb,  *Kp,  *Kp_dot,  *Kp_abs_p, *Mq, *Mq_dot, *Mq_abs_q,
  *Nr, *Nr_dot, *Nr_abs_r, *Ix, *Iy, *Iz, *Ix_Kp_dot, *Iy_Mq_dot,
  *Iz_Nr_dot, *gam, *mag_n, *mag_e, *mag_d;
  m = p[0];
  g = p[1];
  rho = p[2];
  V = p[3];
  lx1 = p[4];
  ly1 = p[5];
  ly2 = p[6];
  lx2 = p[7];
  ly3 = p[8];
  lx5 = p[9];
  ly4 = p[10];
  lz6 = p[11];
  zb = p[12];
  Kp = p[13];
  Kp_dot = p[14];
  Kp_abs_p = p[15];
  Mq = p[16];
  Mq_dot = p[17];
  Mq_abs_q = p[18];
  Nr = p[19];
  Nr_dot = p[20];
  Nr_abs_r = p[21];
  Ix = p[22];
  Iy = p[23];
  Iz = p[24];
  Ix_Kp_dot = p[25];
  Iy_Mq_dot = p[26];
  Iz_Nr_dot = p[27];
  gam = p[28];
  mag_n = p[29];
  mag_e = p[30];
  mag_d = p[31];

/*  double W, B;
  W = m*g;
  B = W;*/
  double p2, q, r, n, e1, e2, e3;
  p2 = x[0];
  q = x[1];
  r = x[2];
  n = x[3];
  e1 = x[4];
  e2 = x[5];
  e3 = x[6];

  double f1, f2, f3, f4, f5, f6;
  f1 = u[0];
  f2 = u[1];
  f3 = u[2];
  f4 = u[3];
  f5 = u[4];
  f6 = u[5];

  dx[0] = (f1*ly1[0]-f2*ly2[0]+f6*lz6[0]+p2*(Kp[0]+Kp_abs_p[0]*fabs(p2))-Mq_dot[0]*q*r+Nr_dot[0]*q*r+q*r*(Iy[0]-Iz[0])+m[0]*g[0]*zb[0]*(e2*e3*2.0+e1*n*2.0))/Ix_Kp_dot[0];
  dx[1] = (f1*lx1[0]+f2*lx2[0]-f5*lx5[0]+q*(Mq[0]+Mq_abs_q[0]*fabs(q))+Kp_dot[0]*p2*r-Nr_dot[0]*p2*r-p2*r*(Ix[0]-Iz[0])-m[0]*g[0]*zb[0]*(e1*e3*2.0-e2*n*2.0))/Iy_Mq_dot[0];
  dx[2] = (r*(Nr[0]+Nr_abs_r[0]*fabs(r))+f3*ly3[0]-f4*ly4[0]-Kp_dot[0]*p2*q+Mq_dot[0]*p2*q+p2*q*(Ix[0]-Iy[0]))/Iz_Nr_dot[0];
  dx[3] = e1*p2*(-1.0/2.0)-e2*q*(1.0/2.0)-e3*r*(1.0/2.0)-gam[0]*n*(e1*e1+e2*e2+e3*e3+n*n-1.0)*(1.0/2.0);
  dx[4] = e3*q*(-1.0/2.0)+e2*r*(1.0/2.0)+n*p2*(1.0/2.0)-e1*gam[0]*(e1*e1+e2*e2+e3*e3+n*n-1.0)*(1.0/2.0);
  dx[5] = e3*p2*(1.0/2.0)-e1*r*(1.0/2.0)+n*q*(1.0/2.0)-e2*gam[0]*(e1*e1+e2*e2+e3*e3+n*n-1.0)*(1.0/2.0);
  dx[6] = e2*p2*(-1.0/2.0)+e1*q*(1.0/2.0)+n*r*(1.0/2.0)-e3*gam[0]*(e1*e1+e2*e2+e3*e3+n*n-1.0)*(1.0/2.0);
}

/* Output equations. */
void compute_y(double *y, double *x, double *u, double **p)
{
  /* Retrieve model parameters. */
  double *m, *g, *rho, *V, *lx1, *ly1, *ly2, *lx2, *ly3, *lx5, *ly4,
  *lz6, *zb,  *Kp,  *Kp_dot,  *Kp_abs_p, *Mq, *Mq_dot, *Mq_abs_q,
  *Nr, *Nr_dot, *Nr_abs_r, *Ix, *Iy, *Iz, *Ix_Kp_dot, *Iy_Mq_dot,
  *Iz_Nr_dot, *gam, *mag_n, *mag_e, *mag_d;
  m = p[0];
  g = p[1];
  rho = p[2];
  V = p[3];
  lx1 = p[4];
  ly1 = p[5];
  ly2 = p[6];
  lx2 = p[7];
  ly3 = p[8];
  lx5 = p[9];
  ly4 = p[10];
  lz6 = p[11];
  zb = p[12];
  Kp = p[13];
  Kp_dot = p[14];
  Kp_abs_p = p[15];
  Mq = p[16];
  Mq_dot = p[17];
  Mq_abs_q = p[18];
  Nr = p[19];
  Nr_dot = p[20];
  Nr_abs_r = p[21];
  Ix = p[22];
  Iy = p[23];
  Iz = p[24];
  Ix_Kp_dot = p[25];
  Iy_Mq_dot = p[26];
  Iz_Nr_dot = p[27];
  gam = p[28];
  mag_n = p[29];
  mag_e = p[30];
  mag_d = p[31];

/*  double W, B;
  W = m*g;
  B = W;*/
  double p2, q, r, n, e1, e2, e3;
  p2 = x[0];
  q = x[1];
  r = x[2];
  n = x[3];
  e1 = x[4];
  e2 = x[5];
  e3 = x[6];

  y[0] = p2;
  y[1] = q;
  y[2] = r;
  y[3] = e1*e3*g[0]*-2.0+e2*g[0]*n*2.0;
  y[4] = e2*e3*g[0]*-2.0-e1*g[0]*n*2.0;
  y[5] = -g[0]+(e1*e1)*g[0]*2.0+(e2*e2)*g[0]*2.0;
  y[6] = sqrt(mag_e[0]*mag_e[0]+mag_n[0]*mag_n[0])-(e2*e2)*sqrt(mag_e[0]*mag_e[0]+mag_n[0]*mag_n[0])*2.0-(e3*e3)*sqrt(mag_e[0]*mag_e[0]+mag_n[0]*mag_n[0])*2.0+e1*e3*mag_d[0]*2.0-e2*mag_d[0]*n*2.0;
  y[7] = e1*e2*sqrt(mag_e[0]*mag_e[0]+mag_n[0]*mag_n[0])*2.0-e3*n*sqrt(mag_e[0]*mag_e[0]+mag_n[0]*mag_n[0])*2.0+e2*e3*mag_d[0]*2.0+e1*mag_d[0]*n*2.0;
  y[8] = mag_d[0]-(e1*e1)*mag_d[0]*2.0-(e2*e2)*mag_d[0]*2.0+e1*e3*sqrt(mag_e[0]*mag_e[0]+mag_n[0]*mag_n[0])*2.0+e2*n*sqrt(mag_e[0]*mag_e[0]+mag_n[0]*mag_n[0])*2.0;
}



/*----------------------------------------------------------------------- *
   DO NOT MODIFY THE CODE BELOW UNLESS YOU NEED TO PASS ADDITIONAL
   INFORMATION TO COMPUTE_DX AND COMPUTE_Y

   To add extra arguments to compute_dx and compute_y (e.g., size
   information), modify the definitions above and calls below.
 *-----------------------------------------------------------------------*/

void mexFunction(int nlhs, mxArray *plhs[],
                 int nrhs, const mxArray *prhs[])
{
    /* Declaration of input and output arguments. */
    double *x, *u, **p, *dx, *y, *t;
    int     i, np;
    size_t  nu, nx;
    const mxArray *auxvar = NULL; /* Cell array of additional data. */

    if (nrhs < 3) {
        mexErrMsgIdAndTxt("IDNLGREY:ODE_FILE:InvalidSyntax",
        "At least 3 inputs expected (t, u, x).");
    }

    /* Determine if auxiliary variables were passed as last input.  */
    if ((nrhs > 3) && (mxIsCell(prhs[nrhs-1]))) {
        /* Auxiliary variables were passed as input. */
        auxvar = prhs[nrhs-1];
        np = nrhs - 4; /* Number of parameters (could be 0). */
    } else {
        /* Auxiliary variables were not passed. */
        np = nrhs - 3; /* Number of parameters. */
    }

    /* Determine number of inputs and states. */
    nx = mxGetNumberOfElements(prhs[1]); /* Number of states. */
    nu = mxGetNumberOfElements(prhs[2]); /* Number of inputs. */

    /* Obtain double data pointers from mxArrays. */
    t = mxGetPr(prhs[0]);  /* Current time value (scalar). */
    x = mxGetPr(prhs[1]);  /* States at time t. */
    u = mxGetPr(prhs[2]);  /* Inputs at time t. */

    p = mxCalloc(np, sizeof(double*));
    for (i = 0; i < np; i++) {
        p[i] = mxGetPr(prhs[3+i]); /* Parameter arrays. */
    }

    /* Create matrix for the return arguments. */
    plhs[0] = mxCreateDoubleMatrix(nx, 1, mxREAL);
    plhs[1] = mxCreateDoubleMatrix(NY, 1, mxREAL);
    dx      = mxGetPr(plhs[0]); /* State derivative values. */
    y       = mxGetPr(plhs[1]); /* Output values. */

    /*
      Call the state and output update functions.

      Note: You may also pass other inputs that you might need,
      such as number of states (nx) and number of parameters (np).
      You may also omit unused inputs (such as auxvar).

      For example, you may want to use orders nx and nu, but not time (t)
      or auxiliary data (auxvar). You may write these functions as:
          compute_dx(dx, nx, nu, x, u, p);
          compute_y(y, nx, nu, x, u, p);
    */

    /* Call function for state derivative update. */
    compute_dx(dx, x, u, p);

    /* Call function for output update. */
    compute_y(y, x, u, p);

    /* Clean up. */
    mxFree(p);
}
