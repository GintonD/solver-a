//
// Created by Ginton on 30/04/2020.
//

#include"solver.hpp"
#include<iostream>
#include <math.h>

using namespace std;
using namespace solver;


RealVariable::RealVariable()
{
    this->a = 0;
    this->b = 1;
    this->c = 0;

}

RealVariable::RealVariable(double c , double p , double r)
{
    this->a = c;
    this->b = p;
    this->c = r;

}

RealVariable RealVariable::operator+(RealVariable& rv)
{
    RealVariable ret;
    ret.b = 0;

    ret.a  = this->a + rv.a;
    ret.b  = this->b + rv.b;
    ret.c = this->c + rv.c;

    return ret;
}


RealVariable RealVariable::operator-(RealVariable& rv)
{
    RealVariable ret;    ret.b = 0;

    ret.a  = this->a - rv.a;
    ret.b  = this->b - rv.b;
    ret.c = this->c - rv.c;

    return ret;
}

RealVariable RealVariable::operator()(RealVariable& rv)
{
    RealVariable ret;
    ret.b = 0;

    ret.a = rv.a;
    ret.b = rv.b;
    ret.c = rv.c;

    return ret;

}

/*
 *##### friend operators #####
*/

RealVariable solver::operator + (RealVariable const & rhs , RealVariable const & lhs)
{
    RealVariable ret;   ret.b = 0;

    ret.a  = rhs.a  +lhs.a;
    ret.b  = rhs.b  +lhs.b;
    ret.c = rhs.c +lhs.c;

    return ret;

}

RealVariable solver::operator + (RealVariable const & lhs, double num)
{
    RealVariable ret;
 

    ret.a  =  lhs.a ;
    ret.b  =  lhs.b ;
    ret.c =  lhs.c+num;
    return ret;
}


RealVariable solver::operator - (RealVariable const & var1 , RealVariable const & var2)
{
    RealVariable *c = new RealVariable();
    c->a = var1.a-var2.a;
    c->b = var1.b-var2.b;
    c->c = var1.c-var2.c;


    return *c;



}
RealVariable solver::operator - (double num , RealVariable const & var2)
{
    RealVariable *ans = new RealVariable();
    ans->a = -var2.a;
    ans->b = -var2.b;
    ans->c = -var2.c+num;



    return *ans;
}
RealVariable solver::operator - (RealVariable const & y , double num)
{
    RealVariable *c = new RealVariable();

    c->a = y.a;
    c->b = y.b;
    return *c;
    c->c = y.c -x;
}


RealVariable solver::operator + (double num , RealVariable const & var)
{
    RealVariable *ans = new RealVariable();
    ans->a = var.a;
    ans->b = var.b;
    ans->c = var.c+num;



    return *ans;
}
// back

RealVariable solver::operator^(const RealVariable &var, const RealVariable &var2)
{
    //Not working
    RealVariable *c;
    return *c;
}

RealVariable solver::operator ^ (RealVariable const & _re , int b)
{
    if(b > 2)
        throw std::invalid_argument("ber can't be greater than 2\n");
    RealVariable *c = new RealVariable();
    if (b==0){
        c->a = 0;
        c->b = 0;  // do b to zero
        c->c = 1;
    }
    if (b==1)
        return _re;
        if (b==2) {
     c->a = 1;
     c->b = _re.b-1;  // do b to zero
     c->c = _re.c;
 }

    return *c;




}

RealVariable solver::operator * (double t , RealVariable const & _re)
{
    RealVariable *c = new RealVariable();
    c->a= t* _re.a;
    c->b= t* _re.b;
    c->c = t * _re.c;
    return *c;

}
RealVariable solver::operator*(const RealVariable &var, const double &num)
{
 return num*var;
}

RealVariable solver::operator*(const int &t, const RealVariable &_re)
{
    RealVariable *c = new RealVariable();
    c->a= t* _re.a;
    c->b= t* _re.b;
    c->c = t * _re.c;
    return *c;

}

RealVariable solver::operator / (RealVariable const & var , double num)
{
   if (num==0)
       throw std::invalid_argument("Math Ero 2\n");

    RealVariable *ans = new RealVariable();
    ans->a = var.a/num;
    ans->b = var.b/num;
    ans->c = var.c/num;

    return *ans;
}

RealVariable solver::operator == (RealVariable const & y , double x)
{
    RealVariable *c = new RealVariable();
    c->a = y.a;
    c->b = y.b;
    c->c = y.c -x;
    return *c;

}

RealVariable solver::operator == (double num , RealVariable const & var)
{

    RealVariable *c = new RealVariable();
    c->a = var.a;
    c->b = var.b;
    c->c = var.c -num;
    return *c;
}

RealVariable solver::operator == (RealVariable const & var1 , RealVariable const & var2)
{
    RealVariable *c = new RealVariable();
c->a = var1.a - var2.a;
    c->b = var1.b - var2.b;
    c->c = var1.c - var2.c;


    return *c;

}

RealVariable solver::operator*(const RealVariable &var1, const RealVariable &var2)
{
    if ((var1.a!=0 &&var2.a!=0)  ||(var1.a!=0 &&var2.b!=0) || (var1.b!=0 &&var2.a!=0))
    throw std::invalid_argument("ber can't be greater than 2\n");
    // (only (bx+c)*(bx+c)
    RealVariable *var3 = new RealVariable();
    var3->a = var1.b * var2.b;
    var3->b = var1.b*var2.b + var1.b*var1.c;
    var3->c = var1.c*var2.c;
    return *var3;
}

RealVariable solver::operator*(const RealVariable &var, const int &num)
{
    return num*var;
}

//                      ****Complex****


ComplexVariable::ComplexVariable()
{
    this->a = 0;
    this->b = 1;
    this->c = 0;

}

ComplexVariable ComplexVariable::operator()(ComplexVariable& var)
{
    ComplexVariable ans;

    return ans;

}


ComplexVariable solver::operator - (ComplexVariable const & var1 , ComplexVariable const & var2)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a-var2.a;
    ans->b = var1.b-var2.b;
    ans->c = var1.c-var2.c;
    return *ans;

}
ComplexVariable solver::operator + (ComplexVariable const & var1 , ComplexVariable const & var2)
{

    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a+var2.a;
    ans->b = var1.b+var2.b;
    ans->c = var1.c+var2.c;

    return *ans;
}
ComplexVariable solver::operator + (ComplexVariable const & var1 , double num)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a;
    ans->b = var1.b;
    ans->c = var1.c+num;

    return *ans;

}
ComplexVariable solver::operator + (ComplexVariable const & var1 , std::complex<double> num)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a;
    ans->b = var1.b;
    ans->c = var1.c+num;

    return *ans;
}
ComplexVariable solver::operator + (double num , ComplexVariable const & var1)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a;
    ans->b = var1.b;
    ans->c = var1.c+num;
    return *ans;

}

ComplexVariable solver::operator - (ComplexVariable const & var1 , double num) {
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a;
    ans->b = var1.b;
    ans->c = var1.c - num;

    return *ans;
}
ComplexVariable solver::operator - (ComplexVariable const & var1 , std::complex<double> num)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a;
    ans->b = var1.b;
    ans->c = var1.c - num;
    return *ans;
}

ComplexVariable solver::operator ^ (ComplexVariable const & var , int b)
{

    if(b > 2)
        throw std::invalid_argument("ber can't be greater than 2\n");
    ComplexVariable *c = new ComplexVariable();
    if (b==0){
        c->a = 0;
        c->b = 0;  // do b to zero
        c->c = 1;
    }
    if (b==1)
        return var;
    if (b==2) {
        c->a = 1;
        c->b = 0;  // do b to zero
        c->c = var.c;
    }

    return *c;
}

ComplexVariable solver::operator * (double num , ComplexVariable const & var1)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = num*var1.a;
    ans->b = var1.b*num;
    ans->c = var1.c*num;
    return *ans;
}
ComplexVariable solver::operator*(const ComplexVariable &var, double num)
{
    return num*var;
}

ComplexVariable solver::operator / (ComplexVariable const & var1 , double num)
{
    if (num==0)
        throw std::invalid_argument("Math Error\n");
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a/num;
    ans->b = var1.b/num;
    ans->c = var1.c/num;
    return *ans;

}

ComplexVariable solver::operator == (ComplexVariable const & var1 , ComplexVariable const & var2)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a-var2.a;
    ans->b =  var1.b-var2.b;
    ans->c = var1.c-var2.c;
    return *ans;
}
ComplexVariable solver::operator == (ComplexVariable const & var1 , double num)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = var1.a;
    ans->b =  var1.b;
    ans->c = var1.c-num;
    return *ans;

}

ComplexVariable solver::operator+(std::complex<double> num, const ComplexVariable &var)
{


    return var+num;
}

ComplexVariable solver::operator-(std::complex<double> num, const ComplexVariable &var1)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = -var1.a;
    ans->b =  -var1.b;
    ans->c = num-var1.c;
    return *ans;
}

ComplexVariable solver::operator-(double num, const ComplexVariable &var1)
{
    ComplexVariable *ans = new ComplexVariable();
    ans->a = -var1.a;
    ans->b =  -var1.b;
    ans->c = num-var1.c;
    return *ans;
}

double solver::solve(RealVariable var)
{
    double x=0;
    if (var.a != 0){
    double sqrtSolve = pow(var.b, 2) - 4 * var.a * var.c;
    if (sqrtSolve<0)
        throw std::invalid_argument("no solution\n");

        x = (-(var.b) + sqrt(sqrtSolve)) / (2*var.a);
    }
else
    if(var.a==0 && var.b==0){
        throw std::invalid_argument("Math Error\n");
    }
    else
    x = - (var.c/var.b);

    return x;
}


complex<double> solver::solve(ComplexVariable x) {
    complex<double> ans;
    if (x.a == 0.0) {
        if(x.b == 0.0) throw std::invalid_argument("cant diving by 0");
        ans = -(x.c) / x.b;
        return ans;
    } else if (x.a != 0.0) {
        complex<double> delta = pow(x.b, 2.0) - 4.0 * x.a * x.c;
        if (delta.imag() == 0) {
            if (delta.real() > 0.0) {
                ans = (-x.b + sqrt(delta)) / 2.0 * x.a;
                return ans;
            } else if (delta == 0.0) {
                ans = (-x.b) / 2.0 * x.a;
                return ans;
            } else if (delta.real() < 0.0) {
                ans = ((-x.b)+sqrt(delta))/(2.0*x.a);
                return ans;
            }
        }

    }
    return 0.0;
}



