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

RealVariable solver::operator + (RealVariable const & lhs, double rhs)
{
    RealVariable ret;
    int Int = (int) rhs;
    //int fraction = saparate(rhs);

    ret.a  =  lhs.a + Int;
    ret.b  =  lhs.b ;
    ret.c =  lhs.c;
    return ret;
}


RealVariable solver::operator - (RealVariable const & var1 , RealVariable const & var2)
{
    RealVariable ans;

    return ans;

}

RealVariable solver::operator - (RealVariable const & var , double num)
{
    RealVariable ans;

    return ans;
}


RealVariable solver::operator + (double num , RealVariable const & var)
{
    RealVariable ans;

    return ans;
}

RealVariable solver::operator - (double num , RealVariable const & var)
{
    RealVariable ans;

    return ans;
}

RealVariable solver::operator ^ (RealVariable const & var , int b)
{
    if(b > 2)
        throw std::invalid_argument("ber can't be greater than 2\n");

    RealVariable ans;

    return ans;
}

RealVariable solver::operator * (double num , RealVariable const & var)
{
    RealVariable ans;

    return ans;

}

RealVariable solver::operator / (RealVariable const & var , double num)
{
    RealVariable ans;

    return ans;

}

RealVariable solver::operator == (RealVariable const & var , double num)
{
    RealVariable ans;

    return ans;

}

RealVariable solver::operator == (double num , RealVariable const & var)
{
    RealVariable ans;

    return ans;

}

RealVariable solver::operator == (RealVariable const & var1 , RealVariable const & var2)
{
    RealVariable ans;

    return ans;

}

RealVariable solver::operator*(const RealVariable &var, const RealVariable &var2)
{
    return RealVariable();
}

RealVariable solver::operator*(const RealVariable &var1, const int &var2)
{
    return RealVariable();
}

RealVariable solver::operator^(const RealVariable &var, const RealVariable &var2)
{
    return RealVariable();
}

RealVariable solver::operator/(const double &var, RealVariable num)
{
    return RealVariable();
}

RealVariable solver::operator*(const RealVariable &var1, const double &var2)
{
    return RealVariable();
}

RealVariable solver::operator*(const int &var2, const RealVariable &var1)
{
    return RealVariable();
}


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

ComplexVariable solver::operator + (ComplexVariable const & var1 , ComplexVariable const & var2)
{
    ComplexVariable ans;

    return ans;
}

ComplexVariable solver::operator - (ComplexVariable const & var1 , ComplexVariable const & var2)
{
    ComplexVariable ans;

    return ans;

}


ComplexVariable solver::operator + (ComplexVariable const & var , double num)
{
    ComplexVariable ans;

    return ans;

}

ComplexVariable solver::operator - (ComplexVariable const & var , double num)
{
    ComplexVariable ans;

    return ans;
}

ComplexVariable solver::operator + (ComplexVariable const & var , std::complex<double> num)
{
    ComplexVariable ans;

    return ans;

}

ComplexVariable solver::operator - (ComplexVariable const & var , std::complex<double> num)
{
    ComplexVariable ans;

    return ans;

}

ComplexVariable solver::operator + (double num , ComplexVariable const & var)
{
    ComplexVariable ans;

    return ans;

}


ComplexVariable solver::operator ^ (ComplexVariable const & var , int b)
{
    ComplexVariable ans;

    return ans;
}

ComplexVariable solver::operator * (double num , ComplexVariable const & var)
{
    ComplexVariable ans;

    return ans;

}

ComplexVariable solver::operator / (ComplexVariable const & var , double num)
{
    ComplexVariable ans;

    return ans;

}

ComplexVariable solver::operator == (ComplexVariable const & var1 , ComplexVariable const & var2)
{
    ComplexVariable ans;

    return ans;

}

ComplexVariable solver::operator == (ComplexVariable const & var , double num)
{
    ComplexVariable ans;

    return ans;

}

ComplexVariable solver::operator+(std::complex<double> num, const ComplexVariable &var)
{
    ComplexVariable ans;

    return ans;
}

ComplexVariable solver::operator-(std::complex<double> num, const ComplexVariable &var)
{
    ComplexVariable ans;

    return ans;
}

ComplexVariable solver::operator-(double num, const ComplexVariable &var)
{
    return ComplexVariable();
}

ComplexVariable solver::operator^(const ComplexVariable &var, const ComplexVariable &var2)
{
    return ComplexVariable();
}

ComplexVariable solver::operator*(const ComplexVariable &var, double num)
{
    return ComplexVariable();
}

ComplexVariable solver::operator*(const ComplexVariable &var, const ComplexVariable &var2)
{
    return ComplexVariable();
}

ComplexVariable solver::operator==(double num, const ComplexVariable &var)
{
    return ComplexVariable();
}


double solver::solve(RealVariable var)
{

    ComplexVariable ans;

    return 0.0;
}

std::complex<double> solver::solve(ComplexVariable var)
{
    return 0i;
}


