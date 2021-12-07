//
// Created by Екатерина on 05.11.2021.
//

#include "qsolver.h"
#include <math.h>

#include "qsolver.h"
#define	TwoPi  2 * M_PI
const double eps=1e-14;

static double _root3 ( double x )
{
    double s = 1.;
    while ( x < 1. )
    {
        x *= 8.;
        s *= 0.5;
    }
    while ( x > 8. )
    {
        x *= 0.125;
        s *= 2.;
    }
    double r = 1.5;
    r -= 1./3. * ( r - x / ( r * r ) );
    r -= 1./3. * ( r - x / ( r * r ) );
    r -= 1./3. * ( r - x / ( r * r ) );
    r -= 1./3. * ( r - x / ( r * r ) );
    r -= 1./3. * ( r - x / ( r * r ) );
    r -= 1./3. * ( r - x / ( r * r ) );
    return r * s;
}

double root3 ( double x )
{
    if ( x > 0 ) return _root3 ( x ); else
    if ( x < 0 ) return-_root3 (-x ); else
        return 0.;
}

int SolveP3(double *x,double a,double b,double c) {
    double a2 = a*a;
    double q  = (a2 - 3*b)/9;
    double r  = (a*(2*a2-9*b) + 27*c)/54;

    double r2 = r*r;
    double q3 = q*q*q;
    double A,B;
    if (r2 <= (q3 + eps)) {
        double t=r/sqrt(q3);
        if( t<-1) t=-1;
        if( t> 1) t= 1;
        t=acos(t);
        a/=3; q=-2*sqrt(q);
        x[0]=q*cos(t/3)-a;
        x[1]=q*cos((t+TwoPi)/3)-a;
        x[2]=q*cos((t-TwoPi)/3)-a;
        return(3);
    } else {
        A =-root3(fabs(r)+sqrt(r2-q3));
        if( r<0 ) A=-A;
        B = (A==0? 0 : B=q/A);

        a/=3;
        x[0] =(A+B)-a;
        x[1] =-0.5*(A+B)-a;
        x[2] = 0.5*sqrt(3.)*(A-B);
        if(fabs(x[2])<eps) { x[2]=x[1]; return(2); }
        return(1);
    }
}
void  CSqrt( double x, double y, double &a, double &b)
{
    double r  = sqrt(x*x+y*y);
    if( y==0 ) {
        r = sqrt(r);
        if(x>=0) { a=r; b=0; } else { a=0; b=r; }
    } else {
        a = sqrt(0.5*(x+r));
        b = 0.5*y/a;
    }
}
int   SolveP4Bi(double *x, double b, double d)
{
    double D = b*b-4*d;
    if( D>=0 )
    {
        double sD = sqrt(D);
        double x1 = (-b+sD)/2;
        double x2 = (-b-sD)/2;
        if( x2>=0 )
        {
            double sx1 = sqrt(x1);
            double sx2 = sqrt(x2);
            x[0] = -sx1;
            x[1] =  sx1;
            x[2] = -sx2;
            x[3] =  sx2;
            return 4;
        }
        if( x1 < 0 )
        {
            double sx1 = sqrt(-x1);
            double sx2 = sqrt(-x2);
            x[0] =    0;
            x[1] =  sx1;
            x[2] =    0;
            x[3] =  sx2;
            return 0;
        }
        double sx1 = sqrt( x1);
        double sx2 = sqrt(-x2);
        x[0] = -sx1;
        x[1] =  sx1;
        x[2] =    0;
        x[3] =  sx2;
        return 2;
    } else {
        double sD2 = 0.5*sqrt(-D);
        CSqrt(-0.5*b, sD2, x[0],x[1]);
        CSqrt(-0.5*b,-sD2, x[2],x[3]);
        return 0;
    }
}
#define SWAP(a,b) { t=b; b=a; a=t; }
static void  dblSort3( double &a, double &b, double &c)
{
    double t;
    if( a>b ) SWAP(a,b);
    if( c<b ) {
        SWAP(b,c);
        if( a>b ) SWAP(a,b);
    }
}
int   SolveP4De(double *x, double b, double c, double d)
{
    if( fabs(c)<1e-14*(fabs(b)+fabs(d)) ) return SolveP4Bi(x,b,d);

    int res3 = SolveP3( x, 2*b, b*b-4*d, -c*c);

    if( res3>1 )
    {
        dblSort3(x[0], x[1], x[2]);

        if( x[0] > 0)
        {
            double sz1 = sqrt(x[0]);
            double sz2 = sqrt(x[1]);
            double sz3 = sqrt(x[2]);

            if( c>0 )
            {
                x[0] = (-sz1 -sz2 -sz3)/2;
                x[1] = (-sz1 +sz2 +sz3)/2;
                x[2] = (+sz1 -sz2 +sz3)/2;
                x[3] = (+sz1 +sz2 -sz3)/2;
                return 4;
            }

            x[0] = (-sz1 -sz2 +sz3)/2;
            x[1] = (-sz1 +sz2 -sz3)/2;
            x[2] = (+sz1 -sz2 -sz3)/2;
            x[3] = (+sz1 +sz2 +sz3)/2;
            return 4;
        }

        double sz1 = sqrt(-x[0]);
        double sz2 = sqrt(-x[1]);
        double sz3 = sqrt( x[2]);

        if( c>0 )
        {
            x[0] = -sz3/2;
            x[1] = ( sz1 -sz2)/2;
            x[2] =  sz3/2;
            x[3] = (-sz1 -sz2)/2;
            return 0;
        }

        x[0] =   sz3/2;
        x[1] = (-sz1 +sz2)/2;
        x[2] =  -sz3/2;
        x[3] = ( sz1 +sz2)/2;
        return 0;
    }
    if (x[0] < 0) x[0] = 0;
    double sz1 = sqrt(x[0]);
    double szr, szi;
    CSqrt(x[1], x[2], szr, szi);
    if( c>0 )
    {
        x[0] = -sz1/2-szr;
        x[1] = -sz1/2+szr;
        x[2] = sz1/2;
        x[3] = szi;
        return 2;
    }

    x[0] = sz1/2-szr;
    x[1] = sz1/2+szr;
    x[2] = -sz1/2;
    x[3] = szi;
    return 2;
}

double N4Step(double x, double a,double b,double c,double d)
{
    double fxs= ((4*x+3*a)*x+2*b)*x+c;
    if (fxs == 0) return x;
    double fx = (((x+a)*x+b)*x+c)*x+d;
    return x - fx/fxs;
}

int   SolveP4(double *x,double a,double b,double c,double d) {
    double d1 = d + 0.25*a*( 0.25*b*a - 3./64*a*a*a - c);
    double c1 = c + 0.5*a*(0.25*a*a - b);
    double b1 = b - 0.375*a*a;
    int res = SolveP4De( x, b1, c1, d1);
    if( res==4) { x[0]-= a/4; x[1]-= a/4; x[2]-= a/4; x[3]-= a/4; }
    else if (res==2) { x[0]-= a/4; x[1]-= a/4; x[2]-= a/4; }
    else             { x[0]-= a/4; x[2]-= a/4; }

    if( res>0 )
    {
        x[0] = N4Step(x[0], a,b,c,d);
        x[1] = N4Step(x[1], a,b,c,d);
    }
    if( res>2 )
    {
        x[2] = N4Step(x[2], a,b,c,d);
        x[3] = N4Step(x[3], a,b,c,d);
    }
    return res;
}